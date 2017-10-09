/*
 * imx274.c - imx274 sensor driver
 *
 * Copyright (c) 2016-2017, NVIDIA CORPORATION, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __IMX274_I2C_TABLES__
#define __IMX274_I2C_TABLES__

#include <media/camera_common.h>


#define IMX274_TABLE_WAIT_MS 0
#define IMX274_TABLE_END 1
#define IMX274_WAIT_MS 1
#define IMX274_WAIT_MS_START	15

#define imx274_reg struct reg_8

static const imx274_reg imx274_start[] = {
	{0x3000, 0x00}, /* mode select streaming on */
	{0x303E, 0x02},
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS_START},
	{0x30F4, 0x00},
	{0x3018, 0xA2},
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS_START},
	{IMX274_TABLE_END, 0x00}
};

static const imx274_reg imx274_stop[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x01}, /* mode select streaming off */
	{IMX274_TABLE_END, 0x00}
};

static const imx274_reg tp_colorbars[] = {
	/* test pattern */
	{0x303C, 0x11},
	{0x303D, 0x0B},
	{0x370B, 0x11},
	{0x370E, 0x00},
	{0x377F, 0x01},
	{0x3781, 0x01},
	{IMX274_TABLE_END, 0x00}
};


/* Mode 1 : 3840X2160 10 bits 30fps*/
static const imx274_reg mode_3840X2160[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x12}, /* mode select streaming on */
	/* input freq. 24M */
	{0x3120, 0xF0},
	{0x3122, 0x02},
	{0x3129, 0x9c},
	{0x312A, 0x02},
	{0x312D, 0x02},

	{0x310B, 0x00},
	{0x304C, 0x00},
	{0x304D, 0x03},
	{0x331C, 0x1A},
	{0x3502, 0x02},
	{0x3529, 0x0E},
	{0x352A, 0x0E},
	{0x352B, 0x0E},
	{0x3538, 0x0E},
	{0x3539, 0x0E},
	{0x3553, 0x00},
	{0x357D, 0x05},
	{0x357F, 0x05},
	{0x3581, 0x04},
	{0x3583, 0x76},
	{0x3587, 0x01},
	{0x35BB, 0x0E},
	{0x35BC, 0x0E},
	{0x35BD, 0x0E},
	{0x35BE, 0x0E},
	{0x35BF, 0x0E},
	{0x366E, 0x00},
	{0x366F, 0x00},
	{0x3670, 0x00},
	{0x3671, 0x00},
	{0x30EE, 0x01},
	{0x3304, 0x32},
	{0x3306, 0x32},
	{0x3590, 0x32},
	{0x3686, 0x32},
	/* resolution */
	{0x30E2, 0x01},
	{0x30F6, 0x07},
	{0x30F7, 0x01},
	{0x30F8, 0xC6},
	{0x30F9, 0x11},
	{0x3130, 0x78}, /*WRITE_VSIZE*/
	{0x3131, 0x08},
	{0x3132, 0x70}, /*Y_OUT_SIZE*/
	{0x3133, 0x08},

	/* crop */
	{0x30DD, 0x01}, /*VWIDCUTEN*/
	{0x30DE, 0x08}, /*VWIDCUT*/
	{0x30E0, 0x00}, /*VWINCUTPOS*/
	{0x3037, 0x01}, /*HTRIMMING_EN*/
	{0x3038, 0x0C}, /*HTRIMMING_START*/
	{0x3039, 0x00},
	{0x303A, 0x0C}, /*HTRIMMING_END*/
	{0x303B, 0x0F},

	/* mode setting */
	{0x3004, 0x01},
	{0x3005, 0x01},
	{0x3006, 0x00},
	{0x3007, 0xA2},
	{0x3019, 0x00},
	{0x3A41, 0x08},
	{0x3A42, 0x01},
	{0x3342, 0x0A},
	{0x3343, 0x00},
	{0x3344, 0x16},
	{0x3345, 0x00},
	{0x3528, 0x0E},
	{0x3554, 0x1F},
	{0x3555, 0x01},
	{0x3556, 0x01},
	{0x3557, 0x01},
	{0x3558, 0x01},
	{0x3559, 0x00},
	{0x355A, 0x00},
	{0x35BA, 0x0E},
	{0x366A, 0x1B},
	{0x366B, 0x1A},
	{0x366C, 0x19},
	{0x366D, 0x17},
	{0x33A6, 0x01},
	{0x306B, 0x05},

	{0x300E, 0x01},

	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{IMX274_TABLE_END, 0x0000}
};

/* Mode 1 : 3840X2160 10 bits 60fps*/
static const imx274_reg mode_3840X2160_60fps[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x12}, /* mode select streaming on */
	/* input freq. 24M */
	{0x3120, 0xF0},
	{0x3122, 0x02},
	{0x3129, 0x9c},
	{0x312A, 0x02},
	{0x312D, 0x02},

	{0x310B, 0x00},
	{0x304C, 0x00},
	{0x304D, 0x03},
	{0x331C, 0x1A},
	{0x3502, 0x02},
	{0x3529, 0x0E},
	{0x352A, 0x0E},
	{0x352B, 0x0E},
	{0x3538, 0x0E},
	{0x3539, 0x0E},
	{0x3553, 0x00},
	{0x357D, 0x05},
	{0x357F, 0x05},
	{0x3581, 0x04},
	{0x3583, 0x76},
	{0x3587, 0x01},
	{0x35BB, 0x0E},
	{0x35BC, 0x0E},
	{0x35BD, 0x0E},
	{0x35BE, 0x0E},
	{0x35BF, 0x0E},
	{0x366E, 0x00},
	{0x366F, 0x00},
	{0x3670, 0x00},
	{0x3671, 0x00},
	{0x30EE, 0x01},
	{0x3304, 0x32},
	{0x3306, 0x32},
	{0x3590, 0x32},
	{0x3686, 0x32},
	/* resolution */
	{0x30E2, 0x01},
	{0x30F6, 0x07},
	{0x30F7, 0x01},
	{0x30F8, 0xC6},
	{0x30F9, 0x11},
	{0x3130, 0x78}, /*WRITE_VSIZE*/
	{0x3131, 0x08},
	{0x3132, 0x70}, /*Y_OUT_SIZE*/
	{0x3133, 0x08},

	/* crop */
	{0x30DD, 0x01}, /*VWIDCUTEN*/
	{0x30DE, 0x08}, /*VWIDCUT*/
	{0x30E0, 0x00}, /*VWINCUTPOS*/
	{0x3037, 0x01}, /*HTRIMMING_EN*/
	{0x3038, 0x0C}, /*HTRIMMING_START*/
	{0x3039, 0x00},
	{0x303A, 0x0C}, /*HTRIMMING_END*/
	{0x303B, 0x0F},

	/* mode setting */
	{0x3004, 0x01},
	{0x3005, 0x01},
	{0x3006, 0x00},
	{0x3007, 0x02},
	{0x3019, 0x00},
	{0x3A41, 0x08},
	{0x3A42, 0x01},
	{0x3342, 0x0A},
	{0x3343, 0x00},
	{0x3344, 0x16},
	{0x3345, 0x00},
	{0x3528, 0x0E},
	{0x3554, 0x1F},
	{0x3555, 0x01},
	{0x3556, 0x01},
	{0x3557, 0x01},
	{0x3558, 0x01},
	{0x3559, 0x00},
	{0x355A, 0x00},
	{0x35BA, 0x0E},
	{0x366A, 0x1B},
	{0x366B, 0x1A},
	{0x366C, 0x19},
	{0x366D, 0x17},
	{0x33A6, 0x01},
	{0x306B, 0x05},

	{0x300E, 0x00},

	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{IMX274_TABLE_END, 0x0000}
};

/* Mode1(DOL): 3864x2182 10 bits 30fps DOL-HDR
 * H: LI+3840=3844
 * V: (OB+2166+VBP)*2=4448
 */
static imx274_reg mode_3840X2160_dol_30fps[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x12},
	/*MCLK 24MHz */
	{0x3120, 0xF0},
	{0x3121, 0x00},
	{0x3122, 0x02},
	{0x3129, 0x9C},
	{0x312A, 0x02},
	{0x312D, 0x02},
	{0x310B, 0x00},
	{0x304C, 0x00},
	{0x304D, 0x03},
	{0x331C, 0x1A},
	{0x331D, 0x00},
	{0x3502, 0x02},
	{0x3529, 0x0E},
	{0x352A, 0x0E},
	{0x352B, 0x0E},
	{0x3538, 0x0E},
	{0x3539, 0x0E},
	{0x3553, 0x00},
	{0x357D, 0x05},
	{0x357F, 0x05},
	{0x3581, 0x04},
	{0x3583, 0x76},
	{0x3587, 0x01},
	{0x35BB, 0x0E},
	{0x35BC, 0x0E},
	{0x35BD, 0x0E},
	{0x35BE, 0x0E},
	{0x35BF, 0x0E},
	{0x366E, 0x00},
	{0x366F, 0x00},
	{0x3670, 0x00},
	{0x3671, 0x00},
	{0x30EE, 0x01},
	{0x3304, 0x32},
	{0x3305, 0x00},
	{0x3306, 0x32},
	{0x3307, 0x00},
	{0x3590, 0x32},
	{0x3391, 0x00},
	{0x3686, 0x32},
	{0x3687, 0x00},

	/*Mode Setting*/
	{0x3004, 0x06},
	{0x3005, 0x01},
	{0x3006, 0x00},
	{0x3007, 0x02},
	{0x300E, 0x00},
	{0x3019, 0x31},
	{0x301A, 0x00},
	{0x302E, 0x06},
	{0x302F, 0x00},
	{0x3030, 0x80},
	{0x3031, 0x01},
	{0x3032, 0x32},
	{0x3033, 0x00},
	{0x3041, 0x31},
	{0x3042, 0x07},
	{0x3043, 0x01},
	{0x306B, 0x05},
	{0x30E2, 0x01},
	{0x30E9, 0x01},
	{0x30F6, 0x1C},
	{0x30F7, 0x04},
	{0x30F8, 0xEC},
	{0x30F9, 0x08},
	{0x30FA, 0x00},
	{0x30EE, 0x01},
	{0x3037, 0x01},
	{0x3038, 0x0C},
	{0x3039, 0x00},
	{0x303A, 0x0C},
	{0x303B, 0x0F},
	{0x30DD, 0x01},
	{0x30DE, 0x04},
	{0x30DF, 0x00},
	{0x30E0, 0x02},
	{0x30E1, 0x00},
	{0x3130, 0x7E},
	{0x3131, 0x08},
	{0x3132, 0xA8},
	{0x3133, 0x08},
	{0x3342, 0x0A},
	{0x3343, 0x00},
	{0x3344, 0x16},
	{0x3345, 0x00},
	{0x33A6, 0x01},
	{0x3528, 0x0E},
	{0x3554, 0x1F},
	{0x3555, 0x01},
	{0x3556, 0x01},
	{0x3557, 0x01},
	{0x3558, 0x01},
	{0x3559, 0x00},
	{0x355A, 0x00},
	{0x35BA, 0x0E},
	{0x366A, 0x1B},
	{0x366B, 0x1A},
	{0x366C, 0x19},
	{0x366D, 0x17},
	{0x3A41, 0x08},
	{0x3A42, 0x01},

	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{IMX274_TABLE_END, 0x0000}
};

/* Mode 3(DOL) : 1920x1080 10 bits 60fps DOL-HDR
 * H: LI+1920=1924
 * V: (OB+1080+VBP)*2=2252
 */
static imx274_reg mode_1920X1080_dol_60fps[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x12},
	/*MCLK 24MHz */
	{0x3120, 0xF0},
	{0x3121, 0x00},
	{0x3122, 0x02},
	{0x3129, 0x9C},
	{0x312A, 0x02},
	{0x312D, 0x02},
	{0x310B, 0x00},
	{0x304C, 0x00},
	{0x304D, 0x03},
	{0x331C, 0x1A},
	{0x331D, 0x00},
	{0x3502, 0x02},
	{0x3529, 0x0E},
	{0x352A, 0x0E},
	{0x352B, 0x0E},
	{0x3538, 0x0E},
	{0x3539, 0x0E},
	{0x3553, 0x00},
	{0x357D, 0x05},
	{0x357F, 0x05},
	{0x3581, 0x04},
	{0x3583, 0x76},
	{0x3587, 0x01},
	{0x35BB, 0x0E},
	{0x35BC, 0x0E},
	{0x35BD, 0x0E},
	{0x35BE, 0x0E},
	{0x35BF, 0x0E},
	{0x366E, 0x00},
	{0x366F, 0x00},
	{0x3670, 0x00},
	{0x3671, 0x00},
	{0x30EE, 0x01},
	{0x3304, 0x32},
	{0x3305, 0x00},
	{0x3306, 0x32},
	{0x3307, 0x00},
	{0x3590, 0x32},
	{0x3391, 0x00},
	{0x3686, 0x32},
	{0x3687, 0x00},

	/*Mode Setting*/
	{0x3004, 0x07},
	{0x3005, 0x21},
	{0x3006, 0x00},
	{0x3007, 0xB1},
	{0x300E, 0x00},
	{0x3019, 0x31},
	{0x301A, 0x00},
	{0x302E, 0x06},
	{0x302F, 0x00},
	{0x3030, 0x10},
	{0x3031, 0x00},
	{0x3032, 0x26},
	{0x3033, 0x00},
	{0x3041, 0x31},
	{0x3042, 0x04},
	{0x3043, 0x01},
	{0x306B, 0x05},
	{0x30E2, 0x02},
	{0x30E9, 0x01},
	{0x30F6, 0x10},
	{0x30F7, 0x04},
	{0x30F8, 0x83},
	{0x30F9, 0x04},
	{0x30FA, 0x00},
	{0x30EE, 0x01},
	{0x30DD, 0x01},
	{0x30DE, 0x07},
	{0x30DF, 0x00},
	{0x30E0, 0x04},
	{0x30E1, 0x00},
	{0x3037, 0x01},
	{0x3038, 0x0C},
	{0x3039, 0x00},
	{0x303A, 0x0C},
	{0x303B, 0x0F},
	{0x3130, 0x40},
	{0x3131, 0x04},
	{0x3132, 0x5E},
	{0x3133, 0x04},
	{0x3342, 0x0A},
	{0x3343, 0x00},
	{0x3344, 0x1A},
	{0x3345, 0x00},
	{0x33A6, 0x01},
	{0x3528, 0x0E},
	{0x3554, 0x00},
	{0x3555, 0x01},
	{0x3556, 0x01},
	{0x3557, 0x01},
	{0x3558, 0x01},
	{0x3559, 0x00},
	{0x355A, 0x00},
	{0x35BA, 0x0E},
	{0x366A, 0x1B},
	{0x366B, 0x1A},
	{0x366C, 0x19},
	{0x366D, 0x17},
	{0x3A41, 0x08},
	{0x3A42, 0x01},

	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{IMX274_TABLE_END, 0x0000}
};

/* Mode 3 : 1920X1080 10 bits 60fps*/
static imx274_reg mode_1920X1080[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x12}, /* mode select streaming on */
	/* input freq. 24M */
	{0x3120, 0xF0},
	{0x3122, 0x02},
	{0x3129, 0x9c},
	{0x312A, 0x02},
	{0x312D, 0x02},

	{0x310B, 0x00},
	{0x304C, 0x00},
	{0x304D, 0x03},
	{0x331C, 0x1A},
	{0x3502, 0x02},
	{0x3529, 0x0E},
	{0x352A, 0x0E},
	{0x352B, 0x0E},
	{0x3538, 0x0E},
	{0x3539, 0x0E},
	{0x3553, 0x00},
	{0x357D, 0x05},
	{0x357F, 0x05},
	{0x3581, 0x04},
	{0x3583, 0x76},
	{0x3587, 0x01},
	{0x35BB, 0x0E},
	{0x35BC, 0x0E},
	{0x35BD, 0x0E},
	{0x35BE, 0x0E},
	{0x35BF, 0x0E},
	{0x366E, 0x00},
	{0x366F, 0x00},
	{0x3670, 0x00},
	{0x3671, 0x00},
	{0x30EE, 0x01},
	{0x3304, 0x32},
	{0x3306, 0x32},
	{0x3590, 0x32},
	{0x3686, 0x32},
	/* resolution */
	{0x30E2, 0x02},
	{0x30F6, 0x04},
	{0x30F7, 0x01},
	{0x30F8, 0x0C},
	{0x30F9, 0x12},
	{0x3130, 0x40},
	{0x3131, 0x04},
	{0x3132, 0x38},
	{0x3133, 0x04},

	/* crop */
	{0x30DD, 0x01},
	{0x30DE, 0x07},
	{0x30DF, 0x00},
	{0x30E0, 0x04},
	{0x30E1, 0x00},
	{0x3037, 0x01},
	{0x3038, 0x0C},
	{0x3039, 0x00},
	{0x303A, 0x0C},
	{0x303B, 0x0F},

	/* mode setting */
	{0x3004, 0x02},
	{0x3005, 0x21},
	{0x3006, 0x00},
	{0x3007, 0xB1},
	{0x3019, 0x00},
	{0x3A41, 0x08},
	{0x3A42, 0x01},
	{0x3342, 0x0A},
	{0x3343, 0x00},
	{0x3344, 0x1A},
	{0x3345, 0x00},
	{0x3528, 0x0E},
	{0x3554, 0x00},
	{0x3555, 0x01},
	{0x3556, 0x01},
	{0x3557, 0x01},
	{0x3558, 0x01},
	{0x3559, 0x00},
	{0x355A, 0x00},
	{0x35BA, 0x0E},
	{0x366A, 0x1B},
	{0x366B, 0x1A},
	{0x366C, 0x19},
	{0x366D, 0x17},
	{0x33A6, 0x01},
	{0x306B, 0x05},

	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{IMX274_TABLE_END, 0x0000}
};

/* Mode 5 : 1288X546 10 bits 240fps*/
static const imx274_reg mode_1288x546[] = {
	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{0x3000, 0x12}, /* mode select streaming on */
	/* input freq. 24M */
	{0x3120, 0xF0},
	{0x3122, 0x02},
	{0x3129, 0x9c},
	{0x312A, 0x02},
	{0x312D, 0x02},

	{0x310B, 0x00},
	{0x304C, 0x00},
	{0x304D, 0x03},
	{0x331C, 0x1A},
	{0x3502, 0x02},
	{0x3529, 0x0E},
	{0x352A, 0x0E},
	{0x352B, 0x0E},
	{0x3538, 0x0E},
	{0x3539, 0x0E},
	{0x3553, 0x00},
	{0x357D, 0x05},
	{0x357F, 0x05},
	{0x3581, 0x04},
	{0x3583, 0x76},
	{0x3587, 0x01},
	{0x35BB, 0x0E},
	{0x35BC, 0x0E},
	{0x35BD, 0x0E},
	{0x35BE, 0x0E},
	{0x35BF, 0x0E},
	{0x366E, 0x00},
	{0x366F, 0x00},
	{0x3670, 0x00},
	{0x3671, 0x00},
	{0x30EE, 0x01},
	{0x3304, 0x32},
	{0x3306, 0x32},
	{0x3590, 0x32},
	{0x3686, 0x32},
	/* resolution */
	{0x30E2, 0x04},
	{0x30F6, 0x04}, /* HMAX 260 */
	{0x30F7, 0x01}, /* HMAX */
	{0x30F8, 0x83}, /* VMAX 1155 */
	{0x30F9, 0x04}, /* VMAX */
	{0x30FA, 0x00}, /* VMAX */
	{0x3130, 0x26},
	{0x3131, 0x02},
	{0x3132, 0x22},
	{0x3133, 0x02},
	/* mode setting */
	{0x3004, 0x04},
	{0x3005, 0x31},
	{0x3006, 0x00},
	{0x3007, 0x02},
	{0x3019, 0x00},
	{0x3A41, 0x04},
	{0x3A42, 0x01},
	{0x3342, 0x0A},
	{0x3343, 0x00},
	{0x3344, 0x1A},
	{0x3345, 0x00},
	{0x3528, 0x0E},
	{0x3554, 0x00},
	{0x3555, 0x01},
	{0x3556, 0x01},
	{0x3557, 0x01},
	{0x3558, 0x01},
	{0x3559, 0x00},
	{0x355A, 0x00},
	{0x35BA, 0x0E},
	{0x366A, 0x1B},
	{0x366B, 0x19},
	{0x366C, 0x17},
	{0x366D, 0x17},
	{0x33A6, 0x01},
	{0x306B, 0x05},

	{IMX274_TABLE_WAIT_MS, IMX274_WAIT_MS},
	{IMX274_TABLE_END, 0x0000}
};

enum {
	IMX274_MODE_3840X2160,
	IMX274_MODE_1920X1080,
	IMX274_MODE_3840X2160_DOL_30FPS,
	IMX274_MODE_1920X1080_DOL_60FPS,
	IMX274_MODE_1288X546,
	IMX274_MODE_START_STREAM,
	IMX274_MODE_STOP_STREAM,
	IMX274_MODE_TEST_PATTERN,
};

static const imx274_reg *mode_table[] = {
	[IMX274_MODE_3840X2160] = mode_3840X2160_60fps,
	[IMX274_MODE_1920X1080] = mode_1920X1080,
	[IMX274_MODE_3840X2160_DOL_30FPS] = mode_3840X2160_dol_30fps,
	[IMX274_MODE_1920X1080_DOL_60FPS] = mode_1920X1080_dol_60fps,
	[IMX274_MODE_1288X546] = mode_1288x546,
	[IMX274_MODE_START_STREAM]		= imx274_start,
	[IMX274_MODE_STOP_STREAM]		= imx274_stop,
	[IMX274_MODE_TEST_PATTERN]		= tp_colorbars,
};

static const int imx274_30_fr[] = {
	30,
};

static const int imx274_60_fr[] = {
	60,
};

static const int imx274_240_fr[] = {
	240,
};

static const struct camera_common_frmfmt imx274_frmfmt[] = {
	{{3840, 2160}, imx274_60_fr, 1, 0, IMX274_MODE_3840X2160},
	{{1920, 1080}, imx274_60_fr, 1, 0, IMX274_MODE_1920X1080},
	{{3844, 4448}, imx274_30_fr, 1, 1, IMX274_MODE_3840X2160_DOL_30FPS},
	{{1924, 2252}, imx274_60_fr, 1, 1, IMX274_MODE_1920X1080_DOL_60FPS},
	{{1288, 546}, imx274_240_fr, 1, 0, IMX274_MODE_1288X546},
};
#endif  /* __IMX274_I2C_TABLES__ */
