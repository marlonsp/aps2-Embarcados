/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include <asf.h>
#include <string.h>
#include "ili9341.h"
#include "lvgl.h"
#include "touch/touch.h"
#include "arm_math.h"

LV_FONT_DECLARE(dseg70);
LV_FONT_DECLARE(dseg40);
LV_FONT_DECLARE(dseg25);
LV_FONT_DECLARE(dseg15);
LV_FONT_DECLARE(dseg10);
LV_FONT_DECLARE(monts15);
LV_FONT_DECLARE(monts10);
LV_IMG_DECLARE(clock);
LV_IMG_DECLARE(fumaca);

// LED
#define LED_RAMP_PIO      PIOC
#define LED_RAMP_PIO_ID   ID_PIOC
#define LED_RAMP_IDX      8
#define LED_RAMP_IDX_MASK (1 << LED_RAMP_IDX)

// Bot�o
#define BUT_RAMP_PIO      PIOA
#define BUT_RAMP_PIO_ID   ID_PIOA
#define BUT_RAMP_IDX  11
#define BUT_RAMP_IDX_MASK (1 << BUT_RAMP_IDX)

#define BUT_TICK_PIO	  PIOA
#define BUT_TICK_PIO_ID   ID_PIOA
#define BUT_TICK_IDX  0
#define BUT_TICK_IDX_MASK (1 << BUT_TICK_IDX)

/************************************************************************/
/* LCD / LVGL                                                           */
/************************************************************************/

// #define LV_HOR_RES_MAX          (320)
// #define LV_VER_RES_MAX          (240)
#define LV_HOR_RES_MAX          (240)
#define LV_VER_RES_MAX          (320)

/*A static or global variable to store the buffers*/
static lv_disp_draw_buf_t disp_buf;

/*Static or global buffer(s). The second buffer is optional*/
static lv_color_t buf_1[LV_HOR_RES_MAX * LV_VER_RES_MAX];
static lv_disp_drv_t disp_drv;          /*A variable to hold the drivers. Must be static or global.*/
static lv_indev_drv_t indev_drv;

static  lv_obj_t * labelBtn1;
static  lv_obj_t * labelBtn2;
static  lv_obj_t * labelBtn3;
static  lv_obj_t * labelBtn4;
static  lv_obj_t * labelBtn5;

SemaphoreHandle_t xMutexLVGL;

lv_obj_t * labelFloor;
lv_obj_t * labelFloorDigit;
lv_obj_t * labelSetValue;
lv_obj_t * labelClock;
lv_obj_t * labelChave;
lv_obj_t * labelHome;
lv_obj_t * labelCelsius;
lv_obj_t * labelCelsius2;
lv_obj_t * labelConfig;
lv_obj_t * labelSet;
lv_obj_t * labelClock2;
lv_obj_t * labelFumaca;
lv_obj_t * labelDia;
lv_obj_t * labelFT;
lv_obj_t * labelFT2;
lv_obj_t * labelVel;

//volatile char flag_rtc_alarm = 0;
typedef struct  {
  uint32_t year;
  uint32_t month;
  uint32_t day;
  uint32_t week;
  uint32_t hour;
  uint32_t minute;
  uint32_t second;
} calendar;

void RTC_init(Rtc *rtc, uint32_t id_rtc, calendar t, uint32_t irq_type);

/************************************************************************/
/* RTOS                                                                 */
/************************************************************************/

#define TASK_SIMULATOR_STACK_SIZE (4096 / sizeof(portSTACK_TYPE))
#define TASK_SIMULATOR_STACK_PRIORITY (tskIDLE_PRIORITY)

#define TASK_LED_STACK_SIZE (4096 / sizeof(portSTACK_TYPE))
#define TASK_LED_STACK_PRIORITY (tskIDLE_PRIORITY)

#define TASK_LCD_STACK_SIZE                (1024*6/sizeof(portSTACK_TYPE))
#define TASK_LCD_STACK_PRIORITY            (tskIDLE_PRIORITY)

#define RAIO 0.508/2
#define VEL_MAX_KMH  5.0f
#define VEL_MIN_KMH  0.5f

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask,  signed char *pcTaskName);
extern void vApplicationIdleHook(void);
extern void vApplicationTickHook(void);
extern void vApplicationMallocFailedHook(void);
extern void xPortSysTickHandler(void);

extern void vApplicationStackOverflowHook(xTaskHandle *pxTask, signed char *pcTaskName) {
	printf("stack overflow %x %s\r\n", pxTask, (portCHAR *)pcTaskName);
	for (;;) {	}
}

extern void vApplicationIdleHook(void) { }

extern void vApplicationTickHook(void) { }

extern void vApplicationMallocFailedHook(void) {
	configASSERT( ( volatile void * ) NULL );
}

/** Semaforo a ser usado pela task led */
SemaphoreHandle_t xSemaphoreBut_RAMP;
SemaphoreHandle_t xSemaphoreLED;

QueueHandle_t xQueueTicks;

void but_callback(void);
float kmh_to_hz(float vel, float raio);
void io_init(void);
void pin_toggle(Pio *pio, uint32_t mask);
/************************************************************************/
/* lvgl                                                                 */
/************************************************************************/

void but_RAMP_callback(void)
{
	 BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	 xSemaphoreGiveFromISR(xSemaphoreBut_RAMP, &xHigherPriorityTaskWoken);
}

void but_TICK_callback(void)
{
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	float vel = 10;
	xQueueSendFromISR(xQueueTicks, &vel, &xHigherPriorityTaskWoken);
}

static void event_handler(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		LV_LOG_USER("Clicked");
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void but2_callback(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		LV_LOG_USER("Clicked");
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void but3_callback(lv_event_t * e) {
	lv_event_code_t code = lv_event_get_code(e);

	if(code == LV_EVENT_CLICKED) {
		LV_LOG_USER("Clicked");
	}
	else if(code == LV_EVENT_VALUE_CHANGED) {
		LV_LOG_USER("Toggled");
	}
}

static void down_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    char *c;
    int temp;
    if(code == LV_EVENT_CLICKED) {
        c = lv_label_get_text(labelSetValue);
        temp = atoi(c);
        lv_label_set_text_fmt(labelSetValue, "%02d", temp - 1);
    }
}

static void up_handler(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    char *c;
    int temp;
    if(code == LV_EVENT_CLICKED) {
        c = lv_label_get_text(labelSetValue);
        temp = atoi(c);
        lv_label_set_text_fmt(labelSetValue, "%02d", temp + 1);
    }
}

void lv_termostato(void) {
	static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_bg_color(&style, lv_color_black());
    lv_style_set_border_color(&style, lv_color_black());
    lv_style_set_border_width(&style, 5);

	labelClock = lv_label_create(lv_scr_act());
	lv_obj_align(labelClock, LV_ALIGN_TOP_MID, 0 , 3);
    lv_obj_set_style_text_font(labelClock, &dseg25, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelClock, lv_color_white(), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(labelClock, "17:45");

	labelVel = lv_label_create(lv_scr_act());
	lv_obj_align(labelVel, LV_ALIGN_TOP_MID, 0 , 40);
    lv_obj_set_style_text_font(labelVel, &dseg25, LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(labelVel, lv_color_white(), LV_STATE_DEFAULT);
    lv_label_set_text_fmt(labelVel, "0");
}

/************************************************************************/
/* TASKS                                                                */
/************************************************************************/

static void task_lcd(void *pvParameters) {
	int px, py;

	lv_termostato();

	for (;;)  {
		xSemaphoreTake( xMutexLVGL, portMAX_DELAY );
		lv_tick_inc(50);
		lv_task_handler();
		xSemaphoreGive( xMutexLVGL );
		vTaskDelay(50);
	}
}

static void task_clock(void *pvParameters) {
	calendar rtc_initial = {2023, 4, 20, 4, 8, 30 ,1};                                            
    RTC_init(RTC, ID_RTC, rtc_initial, RTC_IER_ALREN);  
	uint32_t current_hour, current_min, current_sec;
	uint32_t current_year, current_month, current_day, current_week;
	for (;;)  {
		rtc_get_time(RTC, &current_hour, &current_min, &current_sec);
		rtc_get_date(RTC, &current_year, &current_month, &current_day, &current_week);
		lv_label_set_text_fmt(labelClock, "%02d:%02d", current_hour, current_min);
		vTaskDelay(1000);
		lv_label_set_text_fmt(labelClock, "%02d %02d", current_hour, current_min);
		vTaskDelay(1000);
	}
}

static void task_simulador(void *pvParameters) {


	pmc_enable_periph_clk(ID_PIOC);
	pio_set_output(PIOC, PIO_PC31, 1, 0, 0);

	float vel = VEL_MAX_KMH;
	float f;
	int ramp_up = 1;
	int ramp_status = 0;

	while(1){
		
		if (xSemaphoreTake(xSemaphoreBut_RAMP, 1)) {
			ramp_status = !ramp_status;
			 xSemaphoreGive(xSemaphoreLED);
		}
		pio_clear(PIOC, PIO_PC31);
		delay_ms(1);
		pio_set(PIOC, PIO_PC31);
		
		
		if(ramp_status == 1){
			if (ramp_up) {
				printf("[SIMU] ACELERANDO: %d \n", (int) (10*vel));
				vel += 0.5;
				} else {
				printf("[SIMU] DESACELERANDO: %d \n",  (int) (10*vel));
				vel -= 0.5;
			}

			if (vel >= VEL_MAX_KMH)
			ramp_up = 0;
			else if (vel <= VEL_MIN_KMH)
			ramp_up = 1;
		}
		
		else{
			vel = 5;
			printf("[SIMU] CONSTANTE: %d \n", (int) (10*vel));
		}
		
		f = kmh_to_hz(vel, RAIO);
		int t = 965*(1.0/f); //UTILIZADO 965 como multiplicador ao inv�s de 1000
							 //para compensar o atraso gerado pelo Escalonador do freeRTOS
		
		// xQueueSend(xQueueTicks, &vel, 0);

		delay_ms(t);
	}
	
}

static void task_led(void *pvParameters) {
	 
	int ramp_status = 0;
	float vel;
	rtt_init(RTT, 1);
	while(1){
		
		if (xSemaphoreTake(xSemaphoreLED, 1)) {
			ramp_status = !ramp_status;
		}
		
		if(ramp_status == 1) {
			
			pin_toggle(LED_RAMP_PIO, LED_RAMP_IDX_MASK); 
		}
		
		else {
			pio_set(LED_RAMP_PIO, LED_RAMP_IDX_MASK); 
		}
		if(xQueueReceive(xQueueTicks, &vel, 0)) {
			// printf("[RECEBE] VELOCIDADE RECEBIDA: %d \n", (int) (10*vel));
			uint32_t contagens = rtt_read_timer_value(RTT);
			uint32_t tempo = 1000*contagens/32768;
			uint32_t velocidade = tempo;
			lv_label_set_text_fmt(labelVel, "%d", velocidade);
			rtt_init(RTT, 1);
		}
	}
}

static void task_recebe(void *pvParameters) {
	
	int ramp_status = 0;
	int vel = 0;
	while(1){
		if(xQueueReceive(xQueueTicks, &vel, 0)) {
			// printf("[RECEBE] VELOCIDADE RECEBIDA: %d \n", vel);
			printf("[RECEBE] VELOCIDADE RECEBIDA");
		}
		
	}
}
/************************************************************************/
/* configs                                                              */
/************************************************************************/

void io_init(void)
{

	// Configura led
	pmc_enable_periph_clk(LED_RAMP_PIO_ID);
	pio_configure(LED_RAMP_PIO, PIO_OUTPUT_0, LED_RAMP_IDX_MASK, PIO_DEFAULT);

	// Inicializa clock do perif�rico PIO responsavel pelo botao
	pmc_enable_periph_clk(BUT_RAMP_PIO_ID);
	pmc_enable_periph_clk(BUT_TICK_PIO_ID);

	// Configura PIO para lidar com o pino do bot�o como entrada
	// com pull-up
	pio_configure(BUT_RAMP_PIO, PIO_INPUT, BUT_RAMP_IDX_MASK, PIO_PULLUP);
	pio_set_debounce_filter(BUT_RAMP_PIO, BUT_RAMP_IDX_MASK, 1000);

	pio_configure(BUT_TICK_PIO, PIO_INPUT, BUT_TICK_IDX_MASK, PIO_PULLUP);
	pio_set_debounce_filter(BUT_TICK_PIO, BUT_TICK_IDX_MASK, 1000);

	// Configura interrup��o no pino referente ao botao e associa
	// fun��o de callback caso uma interrup��o for gerada
	// a fun��o de callback � a: but_callback()
	pio_handler_set(BUT_RAMP_PIO,
	BUT_RAMP_PIO_ID,
	BUT_RAMP_IDX_MASK,
	PIO_IT_EDGE,
	but_RAMP_callback);

	pio_handler_set(BUT_TICK_PIO,
	BUT_TICK_PIO_ID,
	BUT_TICK_IDX_MASK,
	PIO_IT_FALL_EDGE,
	but_TICK_callback);

	// Ativa interrup��o e limpa primeira IRQ gerada na ativacao
	pio_enable_interrupt(BUT_RAMP_PIO, BUT_RAMP_IDX_MASK);
	pio_get_interrupt_status(BUT_RAMP_PIO);

	pio_enable_interrupt(BUT_TICK_PIO, BUT_TICK_IDX_MASK);
	pio_get_interrupt_status(BUT_TICK_PIO);
	
	// Configura NVIC para receber interrupcoes do PIO do botao
	// com prioridade 4 (quanto mais pr�ximo de 0 maior)
	NVIC_EnableIRQ(BUT_RAMP_PIO_ID);
	NVIC_SetPriority(BUT_RAMP_PIO_ID, 4); // Prioridade 4
	NVIC_EnableIRQ(BUT_TICK_PIO_ID);
	NVIC_SetPriority(BUT_TICK_PIO_ID, 4); // Prioridade 4
}

/**
* raio 20" => 50,8 cm (diametro) => 0.508/2 = 0.254m (raio)
* w = 2 pi f (m/s)
* v [km/h] = (w*r) / 3.6 = (2 pi f r) / 3.6
* f = v / (2 pi r 3.6)
* Exemplo : 5 km / h = 1.38 m/s
*           f = 0.87Hz
*           t = 1/f => 1/0.87 = 1,149s
*/
float kmh_to_hz(float vel, float raio) {
	float f = vel / (2*PI*raio*3.6);
	return(f);
}

static void configure_lcd(void) {
	/**LCD pin configure on SPI*/
	pio_configure_pin(LCD_SPI_MISO_PIO, LCD_SPI_MISO_FLAGS);  //
	pio_configure_pin(LCD_SPI_MOSI_PIO, LCD_SPI_MOSI_FLAGS);
	pio_configure_pin(LCD_SPI_SPCK_PIO, LCD_SPI_SPCK_FLAGS);
	pio_configure_pin(LCD_SPI_NPCS_PIO, LCD_SPI_NPCS_FLAGS);
	pio_configure_pin(LCD_SPI_RESET_PIO, LCD_SPI_RESET_FLAGS);
	pio_configure_pin(LCD_SPI_CDS_PIO, LCD_SPI_CDS_FLAGS);
	
	ili9341_init();
	ili9341_backlight_on();
}

static void configure_console(void) {
	const usart_serial_options_t uart_serial_options = {
		.baudrate = USART_SERIAL_EXAMPLE_BAUDRATE,
		.charlength = USART_SERIAL_CHAR_LENGTH,
		.paritytype = USART_SERIAL_PARITY,
		.stopbits = USART_SERIAL_STOP_BIT,
	};

	/* Configure console UART. */
	stdio_serial_init(CONSOLE_UART, &uart_serial_options);

	/* Specify that stdout should not be buffered. */
	setbuf(stdout, NULL);
}

void RTC_init(Rtc *rtc, uint32_t id_rtc, calendar t, uint32_t irq_type) {
	/* Configura o PMC */
	pmc_enable_periph_clk(ID_RTC);

	/* Default RTC configuration, 24-hour mode */
	rtc_set_hour_mode(rtc, 0);

	/* Configura data e hora manualmente */
	rtc_set_date(rtc, t.year, t.month, t.day, t.week);
	rtc_set_time(rtc, t.hour, t.minute, t.second);

	/* Configure RTC interrupts */
	NVIC_DisableIRQ(id_rtc);
	NVIC_ClearPendingIRQ(id_rtc);
	NVIC_SetPriority(id_rtc, 4);
	NVIC_EnableIRQ(id_rtc);

	/* Ativa interrupcao via alarme */
	rtc_enable_interrupt(rtc,  irq_type);
}

void pin_toggle(Pio *pio, uint32_t mask) {
	if(pio_get_output_data_status(pio, mask))
	pio_clear(pio, mask);
	else
	pio_set(pio,mask);
}

/************************************************************************/
/* port lvgl                                                            */
/************************************************************************/

void my_flush_cb(lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
	ili9341_set_top_left_limit(area->x1, area->y1);   ili9341_set_bottom_right_limit(area->x2, area->y2);
	ili9341_copy_pixels_to_screen(color_p,  (area->x2 + 1 - area->x1) * (area->y2 + 1 - area->y1));
	
	/* IMPORTANT!!!
	* Inform the graphics library that you are ready with the flushing*/
	lv_disp_flush_ready(disp_drv);
}

void my_input_read(lv_indev_drv_t * drv, lv_indev_data_t*data) {
	int px, py, pressed;
	
	if (readPoint(&px, &py))
		data->state = LV_INDEV_STATE_PRESSED;
	else
		data->state = LV_INDEV_STATE_RELEASED; 
	
	// data->point.x = px;
	// data->point.y = py;
	data->point.x = py;
    data->point.y = 320 - px;
}

void configure_lvgl(void) {
	lv_init();
	lv_disp_draw_buf_init(&disp_buf, buf_1, NULL, LV_HOR_RES_MAX * LV_VER_RES_MAX);
	
	lv_disp_drv_init(&disp_drv);            /*Basic initialization*/
	disp_drv.draw_buf = &disp_buf;          /*Set an initialized buffer*/
	disp_drv.flush_cb = my_flush_cb;        /*Set a flush callback to draw to the display*/
	disp_drv.hor_res = LV_HOR_RES_MAX;      /*Set the horizontal resolution in pixels*/
	disp_drv.ver_res = LV_VER_RES_MAX;      /*Set the vertical resolution in pixels*/

	lv_disp_t * disp;
	disp = lv_disp_drv_register(&disp_drv); /*Register the driver and save the created display objects*/
	
	/* Init input on LVGL */
	lv_indev_drv_init(&indev_drv);
	indev_drv.type = LV_INDEV_TYPE_POINTER;
	indev_drv.read_cb = my_input_read;
	lv_indev_t * my_indev = lv_indev_drv_register(&indev_drv);
}

/************************************************************************/
/* main                                                                 */
/************************************************************************/
int main(void) {
	/* board and sys init */
	board_init();
	sysclk_init();
	configure_console();
	io_init();
	/* Disable the watchdog */                                                                      
    WDT->WDT_MR = WDT_MR_WDDIS;  

	/* LCd, touch and lvgl init*/
	configure_lcd();
	ili9341_set_orientation(ILI9341_FLIP_Y | ILI9341_SWITCH_XY);
	configure_touch();
	configure_lvgl();

	xMutexLVGL = xSemaphoreCreateMutex();
	xQueueTicks = xQueueCreate(100, sizeof(uint32_t));
	if (xQueueTicks == NULL)
    	printf("falha em criar a queue xQueueTicks \n");

	/* Create task to control oled */
	if (xTaskCreate(task_lcd, "LCD", TASK_LCD_STACK_SIZE, NULL, TASK_LCD_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create lcd task\r\n");
	}

	if (xTaskCreate(task_clock, "Clock", TASK_LCD_STACK_SIZE, NULL, TASK_LCD_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create clock task\r\n");
	}
	
	/* Attempt to create a semaphore. */
	xSemaphoreBut_RAMP = xSemaphoreCreateBinary();
	if (xSemaphoreBut_RAMP == NULL)	 printf("falha em criar o semaforo \n");
	/* Attempt to create a semaphore. */
	xSemaphoreLED = xSemaphoreCreateBinary();
	if (xSemaphoreLED == NULL)	 printf("falha em criar o semaforo \n");
	
	if (xTaskCreate(task_simulador, "SIMUL", TASK_SIMULATOR_STACK_SIZE, NULL, TASK_SIMULATOR_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create lcd task\r\n");
	}

	if (xTaskCreate(task_led, "LED", TASK_LED_STACK_SIZE, NULL, TASK_LED_STACK_PRIORITY, NULL) != pdPASS) {
		printf("Failed to create led task\r\n");
	}

	// if (xTaskCreate(task_recebe, "RECEBE", TASK_SIMULATOR_STACK_SIZE, NULL, TASK_SIMULATOR_STACK_PRIORITY, NULL) != pdPASS) {
	// 	printf("Failed to create recebe task\r\n");
	// }
	
	/* Start the scheduler. */
	vTaskStartScheduler();

	while(1){ }
}
