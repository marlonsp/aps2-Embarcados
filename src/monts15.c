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

#ifndef MONTS15
#define MONTS15 1
#endif

#if MONTS15

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x1, 0x3, 0x2, 0x6, 0x4, 0xc, 0x8, 0x18,
    0x10, 0x30, 0x30, 0x20, 0x60, 0x40,

    /* U+0030 "0" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x1f, 0x0,

    /* U+0031 "1" */
    0xf3, 0x33, 0x33, 0x33, 0x33,

    /* U+0032 "2" */
    0x7d, 0x8c, 0x18, 0x30, 0xe3, 0x8e, 0x38, 0x61,
    0xfc,

    /* U+0033 "3" */
    0x7e, 0xe, 0xc, 0x18, 0x3e, 0x7, 0x3, 0x3,
    0x46, 0x7c,

    /* U+0034 "4" */
    0x18, 0x30, 0xc3, 0x6, 0xd9, 0xbf, 0x86, 0xc,
    0x18,

    /* U+0035 "5" */
    0x7e, 0x60, 0x60, 0x60, 0x7e, 0x7, 0x3, 0x3,
    0x46, 0x7c,

    /* U+0036 "6" */
    0x3e, 0x62, 0xc0, 0xfc, 0xe6, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+0037 "7" */
    0xff, 0xc6, 0x6, 0xc, 0xc, 0x18, 0x18, 0x30,
    0x30, 0x70,

    /* U+0038 "8" */
    0x3c, 0xe7, 0xc3, 0xe7, 0x7e, 0xe7, 0xc3, 0xc3,
    0xe6, 0x3c,

    /* U+0039 "9" */
    0x3c, 0xe6, 0xc3, 0xc3, 0xe7, 0x7f, 0x3, 0x3,
    0x46, 0x7c,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+0041 "A" */
    0xe, 0x1, 0xc0, 0x6c, 0xd, 0x81, 0x18, 0x63,
    0xf, 0xf3, 0x6, 0x40, 0x58, 0xc,

    /* U+0042 "B" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xfc, 0xc3, 0xc3, 0xc3,
    0xc3, 0xfe,

    /* U+0043 "C" */
    0x1f, 0x8c, 0x26, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x1, 0x80, 0x71, 0x87, 0xe0,

    /* U+0044 "D" */
    0xfe, 0x30, 0xec, 0x1b, 0x3, 0xc0, 0xf0, 0x3c,
    0xf, 0x6, 0xc3, 0xbf, 0x80,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0, 0xc0, 0xc0,
    0xc0, 0xff,

    /* U+0047 "G" */
    0x1f, 0x8c, 0x26, 0x3, 0x0, 0xc0, 0x30, 0x3c,
    0xd, 0x83, 0x30, 0xc7, 0xe0,

    /* U+0049 "I" */
    0xff, 0xff, 0xf0,

    /* U+004D "M" */
    0xe0, 0x7f, 0xf, 0xf0, 0xfd, 0x9b, 0xd9, 0xbc,
    0xf3, 0xcf, 0x3c, 0x63, 0xc6, 0x3c, 0x3,

    /* U+004F "O" */
    0x1f, 0xe, 0x31, 0x83, 0x60, 0x3c, 0x7, 0x80,
    0xf0, 0x1b, 0x6, 0x31, 0x83, 0xe0,

    /* U+0051 "Q" */
    0x1f, 0x7, 0x18, 0x60, 0xcc, 0x6, 0xc0, 0x6c,
    0x6, 0xc0, 0x66, 0xc, 0x31, 0xc1, 0xf0, 0x3,
    0x20, 0x1e,

    /* U+0052 "R" */
    0xfe, 0xc3, 0xc3, 0xc3, 0xc3, 0xfc, 0xcc, 0xc6,
    0xc6, 0xc3,

    /* U+0053 "S" */
    0x3e, 0xc2, 0xc0, 0xe0, 0xfc, 0x3f, 0x7, 0x3,
    0xc3, 0x7c,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc1, 0xe0, 0xf0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x1f, 0x0,

    /* U+0058 "X" */
    0x61, 0x8c, 0xe3, 0x30, 0x78, 0xe, 0x7, 0x81,
    0xe0, 0xcc, 0x61, 0x98, 0x70,

    /* U+00B0 "°" */
    0x74, 0x63, 0x17, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 66, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 114, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 2, .adv_w = 67, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 141, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 17, .adv_w = 165, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 29, .adv_w = 91, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 141, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 43, .adv_w = 139, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 62, .adv_w = 139, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 149, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 136, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 153, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 149, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 70, .box_w = 2, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 178, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 169, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 138, .adv_w = 177, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 188, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 157, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 182, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 75, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 236, .box_w = 12, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 202, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 202, .box_w = 12, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 237, .adv_w = 175, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 151, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 184, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 279, .adv_w = 162, .box_w = 10, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 100, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x21,
    0x22, 0x23, 0x24, 0x25, 0x27, 0x29, 0x2d, 0x2f,
    0x31, 0x32, 0x33, 0x34, 0x35, 0x38, 0x90
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 145, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 31, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    2, 6,
    2, 7,
    2, 8,
    2, 12,
    2, 16,
    2, 27,
    2, 28,
    2, 30,
    3, 5,
    3, 6,
    3, 11,
    3, 12,
    3, 24,
    3, 28,
    3, 29,
    4, 4,
    4, 5,
    4, 9,
    4, 11,
    4, 13,
    4, 14,
    4, 16,
    4, 24,
    4, 27,
    5, 3,
    5, 4,
    5, 16,
    7, 2,
    8, 4,
    9, 6,
    9, 12,
    9, 28,
    9, 31,
    10, 4,
    11, 4,
    12, 2,
    12, 3,
    12, 4,
    12, 9,
    12, 16,
    13, 4,
    14, 3,
    14, 4,
    14, 16,
    15, 28,
    16, 2,
    16, 5,
    16, 6,
    16, 11,
    16, 24,
    16, 28,
    16, 29,
    17, 4,
    17, 16,
    17, 28,
    17, 30,
    18, 2,
    18, 24,
    18, 27,
    20, 24,
    21, 16,
    21, 28,
    21, 30,
    24, 3,
    24, 4,
    24, 16,
    24, 28,
    24, 30,
    26, 28,
    27, 4,
    27, 16,
    28, 2,
    28, 3,
    28, 4,
    28, 9,
    28, 15,
    28, 16,
    28, 24,
    29, 3,
    29, 4,
    29, 16,
    30, 2,
    30, 24,
    31, 9
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -6, -5, -5, -5, -3, -2, -14, -7,
    -3, -7, -2, -4, -5, -14, -4, -67,
    -5, -10, -5, -5, -2, -15, -6, -4,
    -3, -6, -2, -3, -4, -3, -3, -5,
    -6, -3, -3, -6, -16, -14, -5, -10,
    -4, -3, -6, -2, -13, -3, -2, -5,
    -2, -4, -13, -4, -3, -2, -4, -2,
    -2, -4, -1, -2, -2, -2, -1, -5,
    -7, -4, -5, -6, -2, -3, -2, -14,
    -14, -13, -8, -13, -13, -5, -4, -6,
    -4, -6, -6, -6
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 84,
    .glyph_ids_size = 0
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
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
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
const lv_font_t monts15 = {
#else
lv_font_t monts15 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 14,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if MONTS15*/

