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
 * @file    hal_wdg_lld.h
 * @brief   WDG driver subsystem low level driver header.
 *
 * @addtogroup WDG
 * @{
 */

#ifndef HAL_WDG_LLD_H
#define HAL_WDG_LLD_H

#if (HAL_USE_WDG == TRUE) || defined(__DOXYGEN__)

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a structure representing an WDG driver.
 */
typedef struct WDGDriver WDGDriver;

/**
 * @brief   Driver configuration structure.
 * @note    It could be empty on some architectures.
 */
typedef struct {
  /**
   * @brief   Configuration of WDT window/nomal mode.
   */
  uint8_t mode;

  /**
   * @brief   Configuration of the WATCHDOG CONFIG register.
   */
  uint8_t timeoutPeriod;
} WDGConfig;

/**
 * @brief   Structure representing an WDG driver.
 */
struct WDGDriver {
  /**
   * @brief   Driver state.
   */
  wdgstate_t           state;
  /**
   * @brief   Current configuration data.
   */
  const WDGConfig      *config;
  /* End of the mandatory fields.*/
  /**
   * @brief   Pointer to the WATCHDOG registers block.
   */
  WDT_TypeDef          *wdg;
};

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/* WDT working Mode.  */
#define WDT_MODE_NORMAL 0x00
#define WDT_MODE_WINDOW 0x01

/* WDT timmeout period. */
#define WDT_TIMEOUT_PERIOD_8    0x0
#define WDT_TIMEOUT_PERIOD_16   0x1
#define WDT_TIMEOUT_PERIOD_32   0x2
#define WDT_TIMEOUT_PERIOD_64   0x3
#define WDT_TIMEOUT_PERIOD_128  0x4
#define WDT_TIMEOUT_PERIOD_256  0x5
#define WDT_TIMEOUT_PERIOD_512  0x6
#define WDT_TIMEOUT_PERIOD_1K   0x7
#define WDT_TIMEOUT_PERIOD_2K   0x8
#define WDT_TIMEOUT_PERIOD_4K   0x9
#define WDT_TIMEOUT_PERIOD_8K   0xA
#define WDT_TIMEOUT_PERIOD_16K  0xB

/* WDT clear key. */
#define WDT_CLEAR_KEY 0xA5

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

extern WDGDriver WDGD1;

#ifdef __cplusplus
extern "C" {
#endif
  void wdg_lld_init(void);
  void wdg_lld_start(WDGDriver *wdgp);
  void wdg_lld_stop(WDGDriver *wdgp);
  void wdg_lld_reset(WDGDriver *wdgp);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_WDG == TRUE */

#endif /* HAL_WDG_LLD_H */

/** @} */
