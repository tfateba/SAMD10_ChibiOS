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
 * @file    SAMD10D14AM/hal_lld.h
 * @brief   SAMD10D14AM HAL subsystem low level driver header.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef HAL_LLD_H
#define HAL_LLD_H

/*
 * Registry definitions.
 */
#include "samd10_registry.h"

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    Platform identification macros
 * @{
 */
#if defined(SAMD10D14AM) || defined(__DOXYGEN__)
#define PLATFORM_NAME           "SAMD10D14AM"

#else
#error "SAMD10D14AM device not specified"
#endif
/** @} */


/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/


/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*
 * Configuration-related checks.
 */
#if !defined(SAMD10D14AM_MCUCONF)
#error "Using a wrong mcuconf.h file, SAMD10D14AM_MCUCONF not defined"
#endif

/*
 * Board files sanity checks.
 */
/*#if !defined(SAMD10D14AM_XOSCCLK)
#error "SAMD10D14AM_XOSCCLK not defined in board.h"
#endif
*/

/** @} */

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/**
 * @brief   Type of a clock point identifier.
 */
typedef enum clock_index halclkpt_t;

#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) || defined(__DOXYGEN__)
/**
 * @brief   Type of a clock point frequency in Hz.
 */
typedef uint32_t halfreq_t;

/**
 * @brief   Type of a clock configuration structure.
 */
typedef struct {
  uint32_t          dummy;
} halclkcfg_t;
#endif /* defined(HAL_LLD_USE_CLOCK_MANAGEMENT) */

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

/* Various helpers.*/
#include "nvic.h"
#include "cache.h"
#include "samd10_isr.h"

#ifdef __cplusplus
extern "C" {
#endif
  void hal_lld_init(void);
#ifdef __cplusplus
}
#endif

/*===========================================================================*/
/* Driver inline functions.                                                  */
/*===========================================================================*/

__STATIC_INLINE void hal_lld_peripheral_reset(uint32_t mask) {

  (void)mask;
  //RESETS->RESET |=  mask;
}

__STATIC_INLINE void hal_lld_peripheral_unreset(uint32_t mask) {

  (void)mask;
  //RESETS->RESET &= ~mask;
  //while ((RESETS->RESET_DONE & mask) == 0U) {
    /* Waiting for reset.*/
  //}
}

#if defined(HAL_LLD_USE_CLOCK_MANAGEMENT) || defined(__DOXYGEN__)
/**
 * @brief   Switches to a different clock configuration
 *
 * @param[in] ccp       pointer to clock a @p halclkcfg_t structure
 * @return              The clock switch result.
 * @retval false        if the clock switch succeeded
 * @retval true         if the clock switch failed
 *
 * @notapi
 */
__STATIC_INLINE bool hal_lld_clock_switch_mode(const halclkcfg_t *ccp) {

  (void)ccp;

  return false;
}

/**
 * @brief   Returns the frequency of a clock point in Hz.
 *
 * @param[in] clkpt     clock point to be returned
 * @return              The clock point frequency in Hz or zero if the
 *                      frequency is unknown.
 *
 * @notapi
 */
__STATIC_INLINE halfreq_t hal_lld_get_clock_point(halclkpt_t clkpt) {

  osalDbgAssert(clkpt < CLK_COUNT, "invalid clock point");

  return clock_get_hz(clkpt);
}
#endif /* defined(HAL_LLD_USE_CLOCK_MANAGEMENT) */

#endif /* HAL_LLD_H */

/** @} */
