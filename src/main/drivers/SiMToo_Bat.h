/*
 * This file is part of INAV Project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * Alternatively, the contents of this file may be used under the terms
 * of the GNU General Public License Version 3, as described below:
 *
 * This file is free software: you may copy, redistribute and/or modify
 * it under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or (at your
 * option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see http://www.gnu.org/licenses/.
 */

#pragma once

#define SIMTOO_BAT_ADDR         0xB0

// 电压寄存器
#define SIMTOO_BAT_VBAT_REG     0x01    // 电池电压
#define SIMTOO_BAT_VBAT_S1_REG  0x0C    // 单节电池
#define SIMTOO_BAT_VBAT_S2_REG  0x0D    // 单节电池
#define SIMTOO_BAT_VBAT_MAX_REG 0x10    // 电池最大电压

// 电池电量寄存器
#define SIMTOO_BAT_MAH_REG      0x04    // 电池剩余电量 mAh
#define SIMTOO_BAT_MAH_MAX_REG  0x11    // 电池额定容量 mAh

void SiMTooBattSensorVbat_Updata(void);
void SiMTooBattSensorAmperage_Updata(void);
uint16_t SiMTooBattSensorGetVBat(void);
uint16_t SiMTooBattSensorGetAmerperage(void);
void SiMTooBat_Init(void);
