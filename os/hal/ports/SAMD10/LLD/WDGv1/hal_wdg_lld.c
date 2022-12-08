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
 * @file    hal_wdg_lld.c
 * @brief   SAMD10D14AM watchdog low level driver source.
 *
 * @addtogroup WDT
 * @{
 */

#include "hal.h"

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver local definitions.                                                 */
/*===========================================================================*/

/*===========================================================================*/
/* Driver exported variables.                                                */
/*===========================================================================*/

WDGDriver WDGD1;

/*===========================================================================*/
/* Driver local variables.                                                   */
/*===========================================================================*/

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
 * @brief   Low level WDG driver initialization.
 *
 * @notapi
 */
void wdg_lld_init(void) {

  WDGD1.state = WDG_STOP;
  WDGD1.wdg   = WDT;
  WDGD1.wdg->CTRL.bit.ENABLE = 0;
}

/**
 * @brief   Configures and activates the WDG peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_start(WDGDriver *wdgp) {

  /* Set the WDT period according to the mode. */
  if (wdgp->config->mode == WDT_MODE_WINDOW) {
    wdgp->wdg->CONFIG.bit.WINDOW = wdgp->config->timeoutPeriod;
  }
  else if (wdgp->config->mode == WDT_MODE_NORMAL) {
    wdgp->wdg->CONFIG.bit.PER = wdgp->config->timeoutPeriod;
  }

  /* Start the WDG. */
  wdgp->wdg->CTRL.bit.ENABLE = 1;
}

/**
 * @brief   Deactivates the WDG peripheral.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_stop(WDGDriver *wdgp) {

  wdgp->wdg->CTRL.bit.ENABLE = 0;
}

/**
 * @brief   Reloads WDG period.
 *
 * @param[in] wdgp      pointer to the @p WDGDriver object
 *
 * @notapi
 */
void wdg_lld_reset(WDGDriver * wdgp) {

  wdgp->wdg->CLEAR.bit.CLEAR = WDT_CLEAR_KEY;
}

#endif /* HAL_USE_WDG */

/** @} */
