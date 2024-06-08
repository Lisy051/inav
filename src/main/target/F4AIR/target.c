/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include "platform.h"
#include "drivers/io.h"
#include "drivers/timer.h"
#include "drivers/timer_def.h"
#include "drivers/pwm_mapping.h"
#include "drivers/bus.h"

timerHardware_t timerHardware[] = {
    DEF_TIM(TIM8,   CH1,  PC6,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S1 
    DEF_TIM(TIM8,   CH2,  PC7,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S2
    DEF_TIM(TIM8,   CH3,  PC8,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S3
    DEF_TIM(TIM8,   CH4,  PC9,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S4

#if defined (F4AIRV100) || defined(F4AIRV150)
    DEF_TIM(TIM12,  CH1,  PB14,     TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S5
    DEF_TIM(TIM12,  CH2,  PB15,     TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S6
#else
    DEF_TIM(TIM4,   CH1,  PB6,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S5
    DEF_TIM(TIM4,   CH2,  PB7,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S6
#endif
    DEF_TIM(TIM3,   CH3,  PB0,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S7
    DEF_TIM(TIM3,   CH4,  PB1,      TIM_USE_OUTPUT_AUTO,  0, 0 ),   // S8

#if defined (F4AIRV200) || defined(F4AIRV200AT)
    DEF_TIM(TIM2,   CH1,  PA0,      TIM_USE_BEEPER,       0, 0 ),   // BEEPER
    DEF_TIM(TIM2,   CH2,  PA1,      TIM_USE_LED,          0, 0 ),   // LED
#endif
};

const int timerHardwareCount = sizeof(timerHardware) / sizeof(timerHardware[0]);
