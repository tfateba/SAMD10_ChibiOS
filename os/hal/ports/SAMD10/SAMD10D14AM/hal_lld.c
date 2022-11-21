/*
    ChibiOS - Copyright (C) 2006..2022 Theodore Ateba

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

/**
 * @file    SAMD10D14AM/hal_lld.c
 * @brief   SAMD10D14AM HAL subsystem low level driver source.
 *
 * @addtogroup HAL
 * @{
 */

#include "hal.h"

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

/**
 * @brief   CMSIS system core clock variable.
 * @note    It is declared in system_samd10d14am.h.
 */
uint32_t SystemCoreClock;

/*===========================================================================*/
/* Driver local variables and types.                                         */
/*===========================================================================*/

#define SAMD10D14AM_CORE_CLK  1000000

/*===========================================================================*/
/* Driver local functions.                                                   */
/*===========================================================================*/

/*===========================================================================*/
/* Driver interrupt handlers.                                                */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported functions.                                                */
/*===========================================================================*/

/**
 * @brief   Low level HAL driver initialization.
 *
 * @notapi
 */
void hal_lld_init(void) {

#if SAMD10_NO_INIT == FALSE
  SystemCoreClock = SAMD10D14AM_CORE_CLK;
#endif /* SAMD10_NO_INIT */

#if defined(SAMD10_DMA_REQUIRED)
  dmaInit();
#endif

  /* Common subsystems initialization.*/
  irqInit();

  // TODO: Disable the WDT here.
}

/** @} */
