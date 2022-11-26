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
 * @file    GPIOv1/hal_pal_lld.h
 * @brief   SAMD10 PAL low level driver header.
 *
 * @addtogroup PAL
 * @{
 */

#ifndef HAL_PAL_LLD_H
#define HAL_PAL_LLD_H

#include "samd10_gpio.h"

#if HAL_USE_PAL || defined(__DOXYGEN__)

/*===========================================================================*/
/* Unsupported modes and specific modes                                      */
/*===========================================================================*/

/* Specifies palInit() without parameter, required until all platforms will
   be updated to the new style.*/
#define PAL_NEW_INIT

#undef PAL_MODE_RESET
#undef PAL_MODE_UNCONNECTED
#undef PAL_MODE_INPUT
#undef PAL_MODE_INPUT_PULLUP
#undef PAL_MODE_INPUT_PULLDOWN
#undef PAL_MODE_INPUT_ANALOG
#undef PAL_MODE_OUTPUT_PUSHPULL
#undef PAL_MODE_OUTPUT_OPENDRAIN

/**
 * @name    SAMD10-specific I/O mode flags
 * @{
 */

#define PAL_SAMD10_PORT_DIR_MASK      (1U << 3U)
#define PAL_SAMD10_PORT_DIR_IN        (0U << 3U)
#define PAL_SAMD10_PORT_DIR_OUT       (1U << 3U)

#define PAL_SAMD10_PINCFG_INEN_MASK   (1U << 2U)
#define PAL_SAMD10_PINCFG_INEN_OFF    (0U << 2U)
#define PAL_SAMD10_PINCFG_INEN_ON     (1U << 2U)

#define PAL_SAMD10_PINCFG_PULLEN_MASK (1U << 1U)
#define PAL_SAMD10_PINCFG_PULLEN_OFF  (0U << 1U)
#define PAL_SAMD10_PINCFG_PULLEN_ON   (1U << 1U)

#define PAL_SAMD10_PORT_OUT_MASK      (1U << 0U)
#define PAL_SAMD10_PORT_OUT_OFF       (0U << 0U)
#define PAL_SAMD10_PORT_OUT_ON        (1U << 0U)

/**
 * @name    Standard I/O mode flags
 * @{
 */
/**
 * @brief   Implemented as input.
 */
#define PAL_MODE_RESET                ( PAL_SAMD10_PORT_DIR_IN        | \
                                        PAL_SAMD10_PINCFG_INEN_OFF    | \
                                        PAL_SAMD10_PINCFG_PULLEN_OFF  | \
                                        PAL_SAMD10_PORT_OUT_OFF         \
                                      )

/**
 * @brief   Implemented as analog with analog switch disabled and lock.
 */
#define PAL_MODE_UNCONNECTED          ( PAL_SAMD10_PORT_DIR_IN        | \
                                        PAL_SAMD10_PINCFG_INEN_OFF    | \
                                        PAL_SAMD10_PINCFG_PULLEN_ON   | \
                                        PAL_SAMD10_PORT_OUT_OFF         \
                                      )

/**
 * @brief   Regular input high-Z pad.
 */
#define PAL_MODE_INPUT                ( PAL_SAMD10_PORT_DIR_IN        | \
                                        PAL_SAMD10_PINCFG_INEN_ON     | \
                                        PAL_SAMD10_PINCFG_PULLEN_OFF  | \
                                        PAL_SAMD10_PORT_OUT_OFF         \
                                      )

/**
 * @brief   Input pad with weak pull up resistor.
 */
#define PAL_MODE_INPUT_PULLUP         ( PAL_SAMD10_PORT_DIR_IN        | \
                                        PAL_SAMD10_PINCFG_INEN_ON     | \
                                        PAL_SAMD10_PINCFG_PULLEN_ON   | \
                                        PAL_SAMD10_PORT_OUT_ON          \
                                      )

/**
 * @brief   Input pad with weak pull down resistor.
 */
#define PAL_MODE_INPUT_PULLDOWN       ( PAL_SAMD10_PORT_DIR_IN        | \
                                        PAL_SAMD10_PINCFG_INEN_ON     | \
                                        PAL_SAMD10_PINCFG_PULLEN_ON   | \
                                        PAL_SAMD10_PORT_OUT_OFF         \
                                      )

/**
 * @brief   Analog input mode.
 */
#define PAL_MODE_INPUT_ANALOG  PAL_MODE_RESET

/**
 * @brief   Push-pull output pad.
 */
#define PAL_MODE_OUTPUT_PUSHPULL      ( PAL_SAMD10_PORT_DIR_OUT        | \
                                        PAL_SAMD10_PINCFG_INEN_OFF     | \
                                        PAL_SAMD10_PINCFG_PULLEN_OFF   | \
                                        PAL_SAMD10_PORT_OUT_OFF          \
                                      )
/** @} */

/* Discarded definitions from the ST headers, the PAL driver uses its own
   definitions in order to have an unified handling for all devices.
   Unfortunately the ST headers have no uniform definitions for the same
   objects across the various sub-families.*/
#undef GPIOA
#undef GPIOB
#undef GPIOC
#undef GPIOD
#undef GPIOE
#undef GPIOF
#undef GPIOG
#undef GPIOH
#undef GPIOI
#undef GPIOJ
#undef GPIOK

/**
 * @name    GPIO ports definitions
 * @{
 */
//#define GPIOA                           ((samd10_gpio_t *)GPIOA_BASE)
/** @} */

/*===========================================================================*/
/* I/O Ports Types and constants.                                            */
/*===========================================================================*/

/**
 * @name    Port related definitions
 * @{
 */
/**
 * @brief   Width, in bits, of an I/O port.
 */
#define PAL_IOPORTS_WIDTH 32

/**
 * @brief   Whole port mask.
 * @details This macro specifies all the valid bits into a port.
 */
#define PAL_WHOLE_PORT ((ioportmask_t)0xFFFFFFFF)
/** @} */

/**
 * @name    Line handling macros
 * @{
 */
/**
 * @brief   Forms a line identifier.
 * @details A port/pad pair are encoded into an @p ioline_t type. The encoding
 *          of this type is platform-dependent.
 * @note    In this driver the pad number is encoded in the lower 4 bits of
 *          the GPIO address which are guaranteed to be zero.
 */
#define PAL_LINE(port, pad)                                                 \
  ((ioline_t)((uint32_t)(port)) | ((uint32_t)(pad)))

/**
 * @brief   Decodes a port identifier from a line identifier.
 */
#define PAL_PORT(line)                                                      \
  ((samd10_gpio_t *)(((uint32_t)(line)) & 0xFFFFFFF0U))

/**
 * @brief   Decodes a pad identifier from a line identifier.
 */
#define PAL_PAD(line)                                                       \
  ((uint32_t)((uint32_t)(line) & 0x0000000FU))

/**
 * @brief   Value identifying an invalid line.
 */
#define PAL_NOLINE                      0U
/** @} */

/**
 * @brief   Type of digital I/O port sized unsigned integer.
 */
typedef uint32_t ioportmask_t;

/**
 * @brief   Type of digital I/O modes.
 */
typedef uint32_t iomode_t;

/**
 * @brief   Type of an I/O line.
 */
typedef uint32_t ioline_t;

/**
 * @brief   Type of an event mode.
 */
typedef uint32_t ioeventmode_t;

/**
 * @brief   Type of a port Identifier.
 * @details This type can be a scalar or some kind of pointer, do not make
 *          any assumption about it, use the provided macros when populating
 *          variables of this type.
 */
typedef samd10_gpio_t * ioportid_t;

/**
 * @brief   Type of an pad identifier.
 */
typedef uint32_t iopadid_t;

/*===========================================================================*/
/* I/O Ports Identifiers.                                                    */
/* The low level driver wraps the definitions already present in the SAMD10  */
/* firmware library.                                                         */
/*===========================================================================*/

/**
 * @brief   GPIO port A identifier.
 */
#if SAMD10_HAS_PORTA || defined(__DOXYGEN__)
#define IOPORT1         ((samd10_gpio_t *)PORT_BASE)
#endif

/*===========================================================================*/
/* Implementation, some of the following macros could be implemented as      */
/* functions, if so please put them in pal_lld.c.                            */
/*===========================================================================*/

/**
 * @brief   GPIO ports subsystem initialization.
 *
 * @notapi
 */
#define pal_lld_init() _pal_lld_init()

/**
 * @brief   Reads an I/O port.
 * @details This function is implemented by reading the GPIO IN register, the
 *          implementation has no side effects.
 * @note    This function is not meant to be invoked directly by the application
 *          code.
 *
 * @param[in] port      port identifier
 * @return              The port bits.
 *
 * @notapi
 */
#define pal_lld_readport(port) (PORT->IN.reg)

/**
 * @brief   Reads the output latch.
 * @details This function is implemented by reading the GPIO OUT register, the
 *          implementation has no side effects.
 * @note    This function is not meant to be invoked directly by the application
 *          code.
 *
 * @param[in] port      port identifier
 * @return              The latched logical states.
 *
 * @notapi
 */
#define pal_lld_readlatch(port) (PORT->OUT.reg)

/**
 * @brief   Writes on a I/O port.
 * @details This function is implemented by writing the GPIO OUT register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be written on the specified port
 *
 * @notapi
 */
#define pal_lld_writeport(port, bits)                                         \
  do {                                                                        \
    (void)port;                                                               \
    PORT->OUT.reg = (bits);                                                   \
  } while (false)

/**
 * @brief   Sets a bits mask on a I/O port.
 * @details This function is implemented by writing the GPIO OUTSET register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be ORed on the specified port
 *
 * @notapi
 */
#define pal_lld_setport(port, bits)                                           \
  do {                                                                        \
    (void)port;                                                               \
    PORT->OUTSET.bit.OUTSET = (bits);                                         \
  } while (false)

/**
 * @brief   Clears a bits mask on a I/O port.
 * @details This function is implemented by writing the GPIO OUTCLR register, the
 *          implementation has no side effects.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be cleared on the specified port
 *
 * @notapi
 */
#define pal_lld_clearport(port, bits)                                         \
  do {                                                                        \
    (void)port;                                                               \
    PORT->OUTCLR.bit.OUTCLR = (bits);                                         \
  } while (false)

/**
 * @brief   Toggles a bits mask on a I/O port.
 * @note    The @ref PAL provides a default software implementation of this
 *          functionality, implement this function if can optimize it by using
 *          special hardware functionalities or special coding.
 *
 * @param[in] port      port identifier
 * @param[in] bits      bits to be XORed on the specified port
 *
 * @notapi
 */
#define pal_lld_toggleport(port, bits)                                        \
  do {                                                                        \
    (void)port;                                                               \
    PORT->OUTTGL.bit.OUTTGL = (bits);                                         \
  } while (false)

/**
 * @brief   Pad mode setup.
 * @details This function programs a pad with the specified mode.
 * @note    The operation is not guaranteed to be atomic on all the
 *          architectures, for atomicity and/or portability reasons you may
 *          need to enclose port I/O operations between @p osalSysLock() and
 *          @p osalSysUnlock().
 * @note    Programming an unknown or unsupported mode is silently ignored.
 * @note    The function can be called from any context.
 *
 * @param[in] port      port identifier
 * @param[in] pad       pad number within the port
 * @param[in] mode      pad mode
 *
 * @notapi
 */
#define pal_lld_setpadmode(port, pad, mode)                                 \
  __pal_lld_pad_set_mode(port, pad, mode)

__STATIC_INLINE void __pal_lld_pad_set_mode(ioportid_t port,
                                            iopadid_t pad,
                                            iomode_t mode) {
  uint8_t out     = (uint8_t)((mode & PAL_SAMD10_PORT_OUT_MASK)       >> 0);
  uint8_t pullen  = (uint8_t)((mode & PAL_SAMD10_PINCFG_PULLEN_MASK)  >> 1);
  uint8_t inen    = (uint8_t)((mode & PAL_SAMD10_PINCFG_INEN_MASK)    >> 2);
  uint8_t dir     = (uint8_t)((mode & PAL_SAMD10_PORT_DIR_MASK)       >> 3);

  (void)port;

  PORT->PINCFG[pad].bit.PULLEN  = pullen;
  PORT->PINCFG[pad].bit.INEN    = inen;

  if (dir == 0) {
    PORT->DIRCLR.reg         |= (1 << pad);
  }
  else if (dir == 1) {
    PORT->DIRSET.reg         |= (1 << pad);
  }

  if (out == 0) {
    PORT->OUTCLR.reg         |= (1 << pad);
  }
  else if (out == 1) {
    PORT->OUTSET.reg         |= (1 << pad);
  }
}

#ifdef __cplusplus
extern "C" {
#endif
  void _pal_lld_init(void);
#ifdef __cplusplus
}
#endif

#endif /* HAL_USE_PAL */

#endif /* HAL_PAL_LLD_H */

/** @} */
