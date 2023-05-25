/*******************************************************************************
 * Size: 15 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/
#define LV_LVGL_H_INCLUDE_SIMPLE
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef DSEG15
#define DSEG15 1
#endif

#if DSEG15

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xf0,

    /* U+0030 "0" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x7,
    0xfc,

    /* U+0031 "1" */
    0x7f, 0xfc,

    /* U+0032 "2" */
    0x7f, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2,
    0xfe, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x3,
    0xfc,

    /* U+0033 "3" */
    0x7f, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2,
    0xff, 0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x5,
    0xfc,

    /* U+0034 "4" */
    0x0, 0x40, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0xff, 0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4,

    /* U+0035 "5" */
    0x7f, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,
    0xff, 0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x5,
    0xfc,

    /* U+0036 "6" */
    0x7f, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,
    0xff, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x7,
    0xfc,

    /* U+0037 "7" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x0,
    0x1, 0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4,

    /* U+0038 "8" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0xff, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x7,
    0xfc,

    /* U+0039 "9" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0xff, 0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x5,
    0xfc,

    /* U+003A ":" */
    0xc3,

    /* U+0043 "C" */
    0x7f, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,
    0xfe,

    /* U+0045 "E" */
    0x7f, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,
    0xfe, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x3,
    0xfc,

    /* U+004D "M" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x1, 0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6,
    0x0,

    /* U+004E "N" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0x0,

    /* U+004F "O" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0xfe,

    /* U+0053 "S" */
    0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x3, 0xfe,
    0x1, 0x0, 0x80, 0x40, 0x20, 0x10, 0xb, 0xf8,

    /* U+0054 "T" */
    0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x3, 0xfd,
    0x0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x7, 0xf8,

    /* U+00B0 "°" */
    0x7f, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x6, 0x3,
    0xfe
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 48, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 196, .box_w = 7, .box_h = 1, .ofs_x = 3, .ofs_y = 7},
    {.bitmap_index = 2, .adv_w = 0, .box_w = 2, .box_h = 2, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 196, .box_w = 1, .box_h = 14, .ofs_x = 9, .ofs_y = 1},
    {.bitmap_index = 22, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 196, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 72, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 196, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 122, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 139, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 48, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 157, .adv_w = 196, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 196, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 196, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 209, .adv_w = 196, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 196, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 196, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 250, .adv_w = 196, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 7}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xd, 0xe, 0x10, 0x11, 0x12, 0x13, 0x14,
    0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x23, 0x25,
    0x2d, 0x2e, 0x2f, 0x33, 0x34, 0x90
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 145, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 22, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t dseg15 = {
#else
lv_font_t dseg15 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if DSEG15*/

