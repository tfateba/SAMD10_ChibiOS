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
 * @file    SAMD10D14AM/samd10_registry.h
 * @brief   SAMD10D14AM capabilities registry.
 *
 * @addtogroup HAL
 * @{
 */

#ifndef SAMD10_REGISTRY_H
#define SAMD10_REGISTRY_H

#if !defined(SAMD10D14AM) || defined(__DOXYGEN__)
#define SAMD10D14AM
#endif
/*===========================================================================*/
/* Platform capabilities.                                                    */
/*===========================================================================*/

/* Cores. */
#if defined(SAMD10D14AM)
#define SAMD10_HAS_M0                       TRUE
#endif

/**
 * @name    SAMD10D14AM capabilities
 * @{
 */

/* PAC attributes.      */
#define SAMD10_HAS_PAC0     TRUE
#define SAMD10_HAS_PAC1     TRUE
#define SAMD10_HAS_PAC2     TRUE

/* EVSYS attributes.    */
#define SAMD10_HAS_EVSYS    TRUE

/* SERCOM attributes.   */
#define SAMD10_HAS_SERCOM0  TRUE
#define SAMD10_HAS_SERCOM1  TRUE
#define SAMD10_HAS_SERCOM2  TRUE

/* TCC attributes.      */
#define SAMD10_HAS_TCC      TRUE

/* TC attributes.       */
#define SAMD10_HAS_TC1      TRUE
#define SAMD10_HAS_TC2      TRUE

/* ADC attributes.      */
#define SAMD10_HAS_ADC      TRUE

/* AC attributes.       */
#define SAMD10_HAS_AC       TRUE

/* DAC attributes.      */
#define SAMD10_HAS_DAC      TRUE

/* PTC attributes.      */
#define SAMD10_HAS_PTC      TRUE

/* DSU attributes.      */
#define SAMD10_HAS_DSU      TRUE

/* NVMCTRL attributes.  */
#define SAMD10_HAS_NVMCTRL  TRUE

/* PORT attributes.     */
#define SAMD10_HAS_PORTA   TRUE
#define SAMD10_HAS_PORTB   FALSE
#define SAMD10_HAS_PORTC   FALSE

/* DMAC attributes.     */
#define SAMD10_HAS_DMAC     TRUE

/* MTB attributes.      */
#define SAMD10_HAS_MTB      TRUE

/* PM attributes.       */
#define SAMD10_HAS_PM       TRUE

/* SYSCTRL attributes.  */
#define SAMD10_HAS_SYSCTRL  TRUE

/* GCLK attributes.     */
#define SAMD10_HAS_GCLK     TRUE

/* WDT attributes.      */
#define SAMD10_HAS_WDT      TRUE

/* EIC attributes.      */
#define SAMD10_HAS_EIC      TRUE

/** @} */

#endif /* SAMD10_REGISTRY_H */

/** @} */
