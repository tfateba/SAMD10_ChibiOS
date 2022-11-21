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
 * @file    SAMD10D14AM/samd10_isr.h
 * @brief   SAMD10D14AM ISR handler header.
 *
 * @addtogroup SAMD10D14AM_ISR
 * @{
 */

#ifndef SAMD10_ISR_H
#define SAMD10_ISR_H

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/**
 * @name    ISR Handler names.
 * @{
 */
#define SAMD10_PM_IRQ_HANDLER               Vector40
#define SAMD10_SYSCTRL_IRQ_HANDLER          Vector44
#define SAMD10_WDT_IRQ_HANDLER              Vector48
#define SAMD10_RTC_IRQ_HANDLER              Vector4C
#define SAMD10_EIC_IRQ_HANDLER              Vector50
#define SAMD10_NVMCTRL_IRQ_HANDLER          Vector54
#define SAMD10_DMAC_IRQ_HANDLER             Vector58
#define SAMD10_RESERVED_IRQ_HANDLER         Vector5C
#define SAMD10_EVSYS_IRQ_HANDLER            Vector60
#define SAMD10_SERCOM0_IRQ_HANDLER          Vector64
#define SAMD10_SERCOM1_IRQ_HANDLER          Vector68
#define SAMD10_SERCOM2_IRQ_HANDLER          Vector6C
#define SAMD10_TCC0_IRQ_HANDLER             Vector70
#define SAMD10_TC1_IRQ_HANDLER              Vector74
#define SAMD10_TC2_IRQ_HANDLER              Vector78
#define SAMD10_ADC_IRQ_HANDLER              Vector7C
#define SAMD10_AC_IRQ_HANDLER               Vector80
#define SAMD10_DAC_IRQ_HANDLER              Vector84
#define SAMD10_PTC_IRQ_HANDLER              Vector88

/** @} */

/**
 * @name    ISR numbers
 * @{
 */
#define SAMD10_PM_IRQ_NUMBER                0   /* Power Manager IRQ number.                      */
#define SAMD10_SYSCTRL_IRQ_NUMBER           1   /* System Control IRQ number.                     */
#define SAMD10_WDT_IRQ_NUMBER               2   /* Watchdog Timer IRQ number.                     */
#define SAMD10_RTC_IRQ_NUMBER               3   /* Real Time Clock IRQ number.                    */
#define SAMD10_EIC_IRQ_NUMBER               4   /* External Interrupt Controller IRQ number.      */
#define SAMD10_NVMCTRL_IRQ_NUMBER           5   /* Non Volatile Memory Controller IRQ number.     */
#define SAMD10_DMAC_IRQ_NUMBER              6   /* Direct Memory Access Controller IRQ number.    */
#define SAMD10_RESERVED_IRQ_NUMBER          7   /* Reserved IRQ number.                           */
#define SAMD10_EVSYS_IRQ_NUMBER             8   /* Event System IRQ number.                       */
#define SAMD10_SERCOM0_IRQ_NUMBER           9   /* Serial Communication Controller 0 IRQ number.  */
#define SAMD10_SERCOM1_IRQ_NUMBER           10  /* Serial Communication Controller 1 IRQ number.  */
#define SAMD10_SERCOM2_IRQ_NUMBER           11  /* Serial Communication Controller 2 IRQ number.  */
#define SAMD10_TCC0_IRQ_NUMBER              12  /* Timer Counter for Control 0 IRQ number.        */
#define SAMD10_TC1_IRQ_NUMBER               13  /* Timer Counter 1 IRQ number.                    */
#define SAMD10_TC2_IRQ_NUMBER               14  /* Timer Counter 2 IRQ number.                    */
#define SAMD10_ADC_IRQ_NUMBER               15  /* Analog Digital Converter IRQ number.           */
#define SAMD10_AC_IRQ_NUMBER                16  /* Analog Comparator IRQ number.                  */
#define SAMD10_DAC_IRQ_NUMBER               17  /* Digital Analog Converter IRQ number.           */
#define SAMD10_PTC_IRQ_NUMBER               18  /* Peripheral Touch Controller IRQ number.        */

/** @} */

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
  void irqInit(void);
  void irqDeinit(void);
#ifdef __cplusplus
}
#endif

#endif /* SAMD10_ISR_H */

/** @} */
