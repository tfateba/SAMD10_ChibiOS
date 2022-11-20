/**
 * @file    samd10d14am.h
 * @brief   CMSIS device file for the SAMD10D14AM.
 *
 * @defgroup CMSIS_SAMD10D14AM SAMD10D14AM Device File
 * @ingroup CMSIS_DEVICE
 * @{
 */
    
#ifndef SAMD10D14AM_H
#define SAMD10D14AM_H

#include <stdint.h>

/*
 * @brief Configuration of the Cortex-M0+ Processor and Core Peripherals
 */
#define __CM0PLUS_REV          1  /**< Core revision r0p1.                            */
#define __MPU_PRESENT          0  /**< MPU present or not.                            */
#define __VTOR_PRESENT         1  /**< VTOR present or not.                           */
#define __NVIC_PRIO_BITS       2  /**< Number of bits used for Priority Levels.       */
#define __Vendor_SysTickConfig 0  /**< Set to 1 if different SysTick Config is used.  */

/**
 * @brief   Interrupt vector numbers.
 */
typedef enum {
  /**
   * @brief   Cortex-M0+ Processor Exceptions Numbers
   */
  NonMaskableInt_IRQn = -14,      /**<  2 Non Maskable Interrupt.         */
  HardFault_IRQn      = -13,      /**<  3 Hard Fault Interrupt.           */
  SVCall_IRQn         = -5,       /**< 11 SV Call Interrupt.              */
  PendSV_IRQn         = -2,       /**< 14 Pend SV Interrupt.              */
  SysTick_IRQn        = -1,       /**< 15 System Tick Interrupt.          */

  /**
   * @brief   SAMD10D14AM-specific Interrupt Numbers
   */
  PM_IRQn             =  0,       /**< Power Manager.                     */
  SYSCTRL_IRQn        =  1,       /**< System Control.                    */
  WDT_IRQn            =  2,       /**< Watchdog Timer.                    */
  RTC_IRQn            =  3,       /**< Real-Time Counter.                 */
  EIC_IRQn            =  4,       /**< External Interrupt Controller.     */
  NVMCTRL_IRQn        =  5,       /**< Non-Volatile Memory Controller.    */
  DMAC_IRQn           =  6,       /**< Direct Memory Access Controller.   */
  EVSYS_IRQn          =  8,       /**< Event System Interface.            */
  SERCOM0_IRQn        =  9,       /**< Serial Communication Interface 0.  */
  SERCOM1_IRQn        = 10,       /**< Serial Communication Interface 1.  */
  SERCOM2_IRQn        = 11,       /**< Serial Communication Interface 2.  */
  TCC0_IRQn           = 12,       /**< Timer Counter Control 0.           */
  TC1_IRQn            = 13,       /**< Basic Timer Counter 1.             */
  TC2_IRQn            = 14,       /**< Basic Timer Counter 2.             */
  ADC_IRQn            = 15,       /**< Analog Digital Converter.          */
  AC_IRQn             = 16,       /**< Analog Comparators.                */
  DAC_IRQn            = 17,       /**< Digital Analog Converter.          */
  PTC_IRQn            = 18,       /**< Peripheral Touch Controller.       */
  PERIPH_COUNT_IRQn   = 19        /**< Number of peripheral IDs.          */
} IRQn_Type;

#include "core_cm0plus.h"   /* Cortex-M0plus processor and periphrals   */
#include "system_samd10.h"  /* SAMD10 system header                     */
#include <stdint.h>

/**
 * @brief   SAMD10 AC registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SWRST:1;
      uint8_t ENABLE:1;
      uint8_t RUNSTBY:1;
      uint8_t :4;
      uint8_t LPMUX:1;
    } bit;
  } CTRLA;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t START0:1;
      uint8_t START1:1;
      uint8_t :6;
    } bit;
  } CTRLB;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t COMPEO0:1;
      uint16_t COMPEO1:1;
      uint16_t :2;
      uint16_t WINEO0:1;
      uint16_t :3;
      uint16_t COMPEI0:1;
      uint16_t COMPEI1:1;
      uint16_t :6;
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t COMP0:1;
      uint8_t COMP1:1;
      uint8_t :2;
      uint8_t WIN0:1;
      uint8_t :3;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t COMP0:1;
      uint8_t COMP1:1;
      uint8_t :2;
      uint8_t WIN0:1;
      uint8_t :3;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t COMP0:1;
      uint8_t COMP1:1;
      uint8_t :2;
      uint8_t WIN0:1;
      uint8_t :3;
    } bit;
  } INTFLAG;

  uint8_t Reserved1[1];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t STATE0:1;
      uint8_t STATE1:1;
      uint8_t :2;
      uint8_t WSTATE0:2;
      uint8_t :2;
    } bit;
  } STATUSA;
  
  volatile union {
    uint8_t reg;
    struct {
      uint8_t READY0:1;
      uint8_t READY1:1;
      uint8_t :5;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUSB;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t STATE0:1;
      uint8_t STATE1:1;
      uint8_t :2;
      uint8_t WSTATE0:2;
      uint8_t :2;
    } bit;
  } STATUSC;

  uint8_t  Reserved2[1];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t WEN0:1;
      uint8_t WINTSEL0:2;
      uint8_t :5;
    } bit;
  } WINCTRL;

  uint8_t  Reserved3[3];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ENABLE:1;
      uint32_t SINGLE:1;
      uint32_t SPEED:2;
      uint32_t :1;
      uint32_t INTSEL:2;
      uint32_t :1;
      uint32_t MUXNEG:3;
      uint32_t :1;
      uint32_t MUXPOS:2;
      uint32_t :1;
      uint32_t SWAP:1;
      uint32_t OUT:2;
      uint32_t :1;
      uint32_t HYST:1;
      uint32_t :4;
      uint32_t FLEN:3;
      uint32_t :5;
    } bit;
  } COMPCTRL0;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ENABLE:1;
      uint32_t SINGLE:1;
      uint32_t SPEED:2;
      uint32_t :1;
      uint32_t INTSEL:2;
      uint32_t :1;
      uint32_t MUXNEG:3;
      uint32_t :1;
      uint32_t MUXPOS:2;
      uint32_t :1;
      uint32_t SWAP:1;
      uint32_t OUT:2;
      uint32_t :1;
      uint32_t HYST:1;
      uint32_t :4;
      uint32_t FLEN:3;
      uint32_t :5;
    } bit;
  } COMPCTRL1;

  uint8_t  Reserved4[8];

  volatile union {
    uint8_t reg;
    struct {
      uint8_t VALUE:6;
      uint8_t :2;
    } bit;
  } SCALER0;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t VALUE:6;
      uint8_t :2;
    } bit;
  } SCALER1;

} AC_TypeDef;

/**
 * @brief   SAMD10 ADC registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SWRST:1;
      uint8_t ENABLE:1;
      uint8_t RUNSTDBY:1;
      uint8_t :5;
    } bit;
  } CTRLA;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t REFSEL:4;
      uint8_t :3;
      uint8_t REFCOMP:1;
    } bit;
  } REFCTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SAMPLENUM:4;
      uint8_t ADJRES:3;
      uint8_t :1;
    } bit;
  } AVGCTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SAMPLEN:6;
      uint8_t :2;
    } bit;
  } SAMPCTRL;

  volatile union {
    uint16_t reg;
     struct {
      uint16_t DIFFMODE:1;
      uint16_t LEFTADJ:1;
      uint16_t FREERUN:1;
      uint16_t CORREN:1;
      uint16_t RESSEL:2;
      uint16_t :2;
      uint16_t PRESCALER:3;
      uint16_t :5;
    } bit;
  } CTRLB;

  uint8_t  Reserved1[2];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t WINMODE:3;
      uint8_t :5;
    } bit;
  } WINCTRL;

  uint8_t  Reserved2[3];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t FLUSH:1;
      uint8_t START:1;
      uint8_t :6;
    } bit;
  } SWTRIG;

  uint8_t  Reserved3[3];
  volatile union {
    uint32_t reg;
    struct {
      uint32_t MUXPOS:5;
      uint32_t :3;
      uint32_t MUXNEG:5;
      uint32_t :3;
      uint32_t INPUTSCAN:4;
      uint32_t INPUTOFFSET:4;
      uint32_t GAIN:4;
      uint32_t :4;
    } bit;
  } INPUTCTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t STARTEI:1;
      uint8_t SYNCEI:1;
      uint8_t :2;
      uint8_t RESRDYEO:1;
      uint8_t WINMONEO:1;
      uint8_t :2;
    } bit;
  } EVCTRL;

  uint8_t  Reserved4[1];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t RESRDY:1;
      uint8_t OVERRUN:1;
      uint8_t WINMON:1;
      uint8_t SYNCRDY:1;
      uint8_t :4;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t RESRDY:1;
      uint8_t OVERRUN:1;
      uint8_t WINMON:1;
      uint8_t SYNCRDY:1;
      uint8_t :4;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t RESRDY:1;
      uint8_t OVERRUN:1;
      uint8_t WINMON:1;
      uint8_t SYNCRDY:1;
      uint8_t :4;
    } bit;
  } INTFLAG;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :7;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t RESULT:16;
    } bit;
  } RESULT;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t WINLT:16;
    } bit;
  } WINLT;

  uint8_t  Reserved5[2];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t WINUT:16;
    } bit;
  } WINUT;

  uint8_t  Reserved6[2];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t GAINCORR:12;
      uint16_t :4;
    } bit;
  } GAINCORR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t OFFSETCORR:12;
      uint16_t :4;
    } bit;
  } OFFSETCORR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t LINEARITY_CAL:8;
      uint16_t BIAS_CAL:3;
      uint16_t :5;
    } bit;
  } CALIB;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

} ADC_TypeDef;

/**
 * @brief   SAMD10 DAC registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SWRST:1;
      uint8_t ENABLE:1;
      uint8_t RUNSTDBY:1;
      uint8_t :5;
    } bit;
  } CTRLA;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t EOEN:1;
      uint8_t IOEN:1;
      uint8_t LEFTADJ:1;
      uint8_t VPD:1;
      uint8_t BDWP:1;
      uint8_t :1;
      uint8_t REFSEL:2;
    } bit;
  } CTRLB;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t STARTEI:1;
      uint8_t EMPTYEO:1;
      uint8_t :6;
    } bit;
  } EVCTRL;

  uint8_t  Reserved1[1];

  volatile union {
    uint8_t reg;
    struct {
      uint8_t UNDERRUN:1;
      uint8_t EMPTY:1;
      uint8_t SYNCRDY:1;
      uint8_t :5;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t UNDERRUN:1;
      uint8_t EMPTY:1;
      uint8_t SYNCRDY:1;
      uint8_t :5;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t UNDERRUN:1;
      uint8_t EMPTY:1;
      uint8_t SYNCRDY:1;
      uint8_t :5;
    } bit;
  } INTFLAG;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :7;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t DATA:16;
    } bit;
  } DATA;

  uint8_t  Reserved2[2];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t DATABUF:16;
    } bit;
  } DATABUF;

} DAC_TypeDef;

/**
 * @brief   SAMD10 DMAC registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t DMAENABLE:1;
      uint16_t CRCENABLE:1;
      uint16_t :5;
      uint16_t LVLEN0:1;
      uint16_t LVLEN1:1;
      uint16_t LVLEN2:1;
      uint16_t LVLEN3:1;
      uint16_t :4;
    } bit;
  } CTRL;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t CRCBEATSIZE:2;
      uint16_t CRCPOLY:2;
      uint16_t :4;
      uint16_t CRCSRC:6;
      uint16_t :2;
    } bit;
  } CRCCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CRCDATAIN:32;
    } bit;
  } CRCDATAIN;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CRCCHKSUM:32;
    } bit;
  } CRCCHKSUM;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t CRCBUSY:1;
      uint8_t CRCZERO:1;
      uint8_t :6;
    } bit;
  } CRCSTATUS;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t WRBQOS:2;
      uint8_t FQOS:2;
      uint8_t DQOS:2;
      uint8_t :7;
    } bit;
  } QOSCTRL;

  uint8_t  Reserved1[1];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWTRIG0:1;
      uint32_t SWTRIG1:1;
      uint32_t SWTRIG2:1;
      uint32_t SWTRIG3:1;
      uint32_t SWTRIG4:1;
      uint32_t SWTRIG5:1;
      uint32_t :26;
    } bit;
  } SWTRIGCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t LVPRI0:2;
      uint32_t :4;
      uint32_t RRLVLEN0:2;
      uint32_t LVPRI1:2;
      uint32_t :4;
      uint32_t RRLVLEN1:2;
      uint32_t LVPRI2:2;
      uint32_t :4;
      uint32_t RRLVLEN2:2;
      uint32_t LVPRI3:2;
      uint32_t :4;
      uint32_t RRLVLEN3:2;
    } bit;
  } PRICTRL0;

  uint8_t  Reserved2[8];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ID:3;
      uint16_t :5;
      uint16_t TERR:1;
      uint16_t TCMPL:1;
      uint16_t SUSP:1;
      uint16_t :2;
      uint16_t FERR:1;
      uint16_t BUSY:1;
      uint16_t PEND:1;
    } bit;
  } INTPEND;

  uint8_t  Reserved3[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CHINT0:1;
      uint32_t CHINT1:1;
      uint32_t CHINT2:1;
      uint32_t CHINT3:1;
      uint32_t CHINT4:1;
      uint32_t CHINT5:1;
      uint32_t :26;
    } bit;
  } INTSTATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t BUSYCH0:1;
      uint32_t BUSYCH1:1;
      uint32_t BUSYCH2:1;
      uint32_t BUSYCH3:1;
      uint32_t BUSYCH4:1;
      uint32_t BUSYCH5:1;
      uint32_t :26;
    } bit;
  } BUSYCH;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t PENDCH0:1;
      uint32_t PENDCH1:1;
      uint32_t PENDCH2:1;
      uint32_t PENDCH3:1;
      uint32_t PENDCH4:1;
      uint32_t PENDCH5:1;
      uint32_t :26;
    } bit;
  } PENDCH;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t LVLEX0:1;
      uint32_t LVLEX1:1;
      uint32_t LVLEX2:1;
      uint32_t LVLEX3:1;
      uint32_t :4;
      uint32_t ID:5;
      uint32_t :2;
      uint32_t ABUSY:1;
      uint32_t BTCNT:16;
    } bit;
  } ACTIVE;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t BASEADDR:32;
    } bit;
  } BASEADDR;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t WRBADDR:32;
    } bit;
  } WRBADDR;

  uint8_t  Reserved4[3];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t ID:3;
      uint8_t :5;
    } bit;
  } CHID;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t SWRST:1;
      uint8_t ENABLE:1;
      uint8_t :6;
    } bit;
  } CHCTRLA;

  uint8_t  Reserved5[3];

  volatile union {
    uint32_t reg;
    struct {
      uint8_t EVACT:3;
      uint8_t EVIE:1;
      uint8_t EVOE:1;
      uint8_t LVL:2;
      uint8_t :1;
      uint8_t TRIGSRC:5;
      uint8_t :3;
      uint8_t :6;
      uint8_t TRIGACT:2;
      uint8_t CMD:2;
      uint8_t :6;
    } bit;
  } CHCTRLB;

  uint8_t  Reserved6[4];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t TERR:1;
      uint8_t TCMPL:1;
      uint8_t SUSP:1;
      uint8_t :5;
    } bit;
  } CHINTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t TERR:1;
      uint8_t TCMPL:1;
      uint8_t SUSP:1;
      uint8_t :5;
    } bit;
  } CHINTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t TERR:1;
      uint8_t TCMPL:1;
      uint8_t SUSP:1;
      uint8_t :5;
    } bit;
  } CHINTFLAG;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t PEND:1;
      uint8_t BUSY:1;
      uint8_t FERR:1;
      uint8_t :5;
    } bit;
  } CHSTATUS;

} DMAC_TypeDef;

/**
 * @brief   SAMD10 DMA SRAM registers block.
 */
/*
// DMA Controler descriptor.
typedef struct {
  __IO uint16_t BTCTRL;
  __IO uint16_t BTCNT;
  __IO uint32_t SRCADDR;
  __IO uint32_t DSTADDR;
  __IO uint32_t DESCADDR;
} DMACD_TypeDef;
*/

/**
 * @brief   SAMD10 DSU registers block.
 */
/*
typedef struct {
  __O  uint8_t  CTRL;
  __IO uint8_t  STATUSA;
  __I  uint8_t  STATUSB;
       uint8_t   Reserved1[1];
  __IO uint32_t ADDR;
  __IO uint32_t LENGTH;
  __IO uint32_t DATA;
  __IO uint32_t DCC0;
  __IO uint32_t DCC1;
  __I  uint32_t DID;
       uint8_t  Reserved2[212];
  __IO uint32_t DCFG0;
  __IO uint32_t DCFG1;
       uint8_t  Reserved3[3848];
  __I  uint32_t ENTRY0;
  __I  uint32_t ENTRY1;
  __I  uint32_t END;
       uint8_t  Reserved4[4032];
  __I  uint32_t MEMTYPE;
  __I  uint32_t PID4;
  __I  uint32_t PID5;
  __I  uint32_t PID6;
  __I  uint32_t PID7;
  __I  uint32_t PID0;
  __I  uint32_t PID1;
  __I  uint32_t PID2;
  __I  uint32_t PID3;
  __I  uint32_t CID0;
  __I  uint32_t CID1;
  __I  uint32_t CID2;
  __I  uint32_t CID3;
} DSU_TypeDef;
*/

/**
 * @brief   SAMD10 EIC registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SWRST:1;
      uint8_t ENABLE:1;
      uint8_t :6;
    } bit;
  } CTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :7;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t NMISENSE:3;
      uint8_t NMIFILTEN:1;
      uint8_t :4;
    } bit;
  } NMICTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t NMI:1;
      uint8_t :7;
    } bit;
  } NMIFLAG;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t EXTINTEO0:1;
      uint32_t EXTINTEO1:1;
      uint32_t EXTINTEO2:1;
      uint32_t EXTINTEO3:1;
      uint32_t EXTINTEO4:1;
      uint32_t EXTINTEO5:1;
      uint32_t EXTINTEO6:1;
      uint32_t EXTINTEO7:1;
      uint32_t :24;
    } bit;
  } EVCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t EXTINT0:1;
      uint32_t EXTINT1:1;
      uint32_t EXTINT2:1;
      uint32_t EXTINT3:1;
      uint32_t EXTINT4:1;
      uint32_t EXTINT5:1;
      uint32_t EXTINT6:1;
      uint32_t EXTINT7:1;
      uint32_t :24;
    } bit;
  } INTENCLR;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t EXTINT0:1;
      uint32_t EXTINT1:1;
      uint32_t EXTINT2:1;
      uint32_t EXTINT3:1;
      uint32_t EXTINT4:1;
      uint32_t EXTINT5:1;
      uint32_t EXTINT6:1;
      uint32_t EXTINT7:1;
      uint32_t :24;
    } bit;
  } INTENSET;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t EXTINT0:1;
      uint32_t EXTINT1:1;
      uint32_t EXTINT2:1;
      uint32_t EXTINT3:1;
      uint32_t EXTINT4:1;
      uint32_t EXTINT5:1;
      uint32_t EXTINT6:1;
      uint32_t EXTINT7:1;
      uint32_t :24;
    } bit;
  } INTFLAG;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t WAKEUPEN0:1;
      uint32_t WAKEUPEN1:1;
      uint32_t WAKEUPEN2:1;
      uint32_t WAKEUPEN3:1;
      uint32_t WAKEUPEN4:1;
      uint32_t WAKEUPEN5:1;
      uint32_t WAKEUPEN6:1;
      uint32_t WAKEUPEN7:1;
      uint32_t :24;
    } bit;
  } WAKEUP;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SENSE0:3;
      uint32_t FILTEN0:1;
      uint32_t SENSE1:3;
      uint32_t FILTEN1:1;
      uint32_t SENSE2:3;
      uint32_t FILTEN2:1;
      uint32_t SENSE3:3;
      uint32_t FILTEN3:1;
      uint32_t SENSE4:3;
      uint32_t FILTEN4:1;
      uint32_t SENSE5:3;
      uint32_t FILTEN5:1;
      uint32_t SENSE6:3;
      uint32_t FILTEN6:1;
      uint32_t SENSE7:3;
      uint32_t FILTEN7:1;
    } bit;
  } CONFIG0;

} EIC_TypeDef;

/**
 * @brief   SAMD10 EVSYS registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SWRST:1;
      uint8_t :3;
      uint8_t GCLKREQ:1;
      uint8_t :3;
    } bit;
  } CTRL;

  uint8_t  Reserved1[3];
  volatile union {
    uint32_t reg;
    struct {
      uint32_t CHANNEL:3;
      uint32_t :5;
      uint32_t SWEVT:1;
      uint32_t :7;
      uint32_t EVGEN:6;
      uint32_t :2;
      uint32_t PATH:2;
      uint32_t EDGSEL:2;
      uint32_t :4;
    } bit;
  } CHANNEL;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t USER:5;
      uint16_t :3;
      uint16_t CHANNEL:4;
      uint16_t :4;
    } bit;
  } USER;

  uint8_t Reserved2[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t USRRDY0:1;
      uint32_t USRRDY1:1;
      uint32_t USRRDY2:1;
      uint32_t USRRDY3:1;
      uint32_t USRRDY4:1;
      uint32_t USRRDY5:1;
      uint32_t :2;
      uint32_t CHBUSY0:1;
      uint32_t CHBUSY1:1;
      uint32_t CHBUSY2:1;
      uint32_t CHBUSY3:1;
      uint32_t CHBUSY4:1;
      uint32_t CHBUSY5:1;
      uint32_t :18;
    } bit;
  } CHSTATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t OVR0:1;
      uint32_t OVR1:1;
      uint32_t OVR2:1;
      uint32_t OVR3:1;
      uint32_t OVR4:1;
      uint32_t OVR5:1;
      uint32_t :2;
      uint32_t EVD0:1;
      uint32_t EVD1:1;
      uint32_t EVD2:1;
      uint32_t EVD3:1;
      uint32_t EVD4:1;
      uint32_t EVD5:1;
      uint32_t :18;
    } bit;
  } INTENCLR;

  volatile union {
    uint32_t reg;
        struct {
      uint32_t OVR0:1;
      uint32_t OVR1:1;
      uint32_t OVR2:1;
      uint32_t OVR3:1;
      uint32_t OVR4:1;
      uint32_t OVR5:1;
      uint32_t :2;
      uint32_t EVD0:1;
      uint32_t EVD1:1;
      uint32_t EVD2:1;
      uint32_t EVD3:1;
      uint32_t EVD4:1;
      uint32_t EVD5:1;
      uint32_t :18;
    } bit;
  } INTENSET;

  volatile union {
    uint32_t reg;
        struct {
      uint32_t OVR0:1;
      uint32_t OVR1:1;
      uint32_t OVR2:1;
      uint32_t OVR3:1;
      uint32_t OVR4:1;
      uint32_t OVR5:1;
      uint32_t :2;
      uint32_t EVD0:1;
      uint32_t EVD1:1;
      uint32_t EVD2:1;
      uint32_t EVD3:1;
      uint32_t EVD4:1;
      uint32_t EVD5:1;
      uint32_t :18;
    } bit;
  } INTFLAG;

} EVSYS_TypeDef;

/**
 * @brief   SAMD10 GCLK registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SWRST:1;
      uint8_t :7;
    }bit;
  } CTRL;

  volatile union {
     uint8_t reg;
     struct {
       uint8_t :7;
       uint8_t SYNCBUSY:1;
     } bit;
  } STATUS;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ID:6;
      uint16_t :2;
      uint16_t GEN:4;
      uint16_t :2;
      uint16_t CLKEN:1;
      uint16_t WRTLOCK:1;
    } bit;
  } CLKCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ID:4;
      uint32_t :4;
      uint32_t SRC:5;
      uint32_t :3;
      uint32_t GENEN:1;
      uint32_t IDC:1;
      uint32_t OOV:1;
      uint32_t OE:1;
      uint32_t DIVSEL:1;
      uint32_t RUNSTANDBY:1;
      uint32_t :10;
    } bit;
  } GENCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ID:4;
      uint32_t :4;
      uint32_t DIV:16;
      uint32_t :8;
    } bit;
  } GENDIV;

} GCLK_TypeDef;




/*
typedef struct {

} MTB_TypeDef;*/




/**
 * @brief   SAMD10 NVMCTRL registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t CMD:4;
      uint16_t :4;
      uint16_t CMDEX:16;
    } bit;
  } CTRLA;

  uint8_t  Reserved1[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :1;
      uint32_t RWS:4;
      uint32_t :2;
      uint32_t MANW:1;
      uint32_t SLEEPPMR:2;
      uint32_t :6;
      uint32_t READMODE:2;
      uint32_t CACHEDIS:1;
      uint32_t :13;
    } bit;
  } CTRLB;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t NVMP:16;
      uint32_t PSZ:3;
      uint32_t :13;
    } bit;
  } PARAM;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t READY:1;
      uint8_t ERROR:1;
      uint8_t :6;
    } bit;
  } INTENCLR;

  uint8_t  Reserved2[3];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t READY:1;
      uint8_t ERROR:1;
      uint8_t :6;
    } bit;
  } INTENSET;

  uint8_t  Reserved3[3];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t READY:1;
      uint8_t ERROR:1;
      uint8_t :6;
    } bit;
  } INTFLAG;

  uint8_t  Reserved4[3];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t PRM:1;
      uint16_t LOAD:1;
      uint16_t PROGE:1;
      uint16_t LOCKE:1;
      uint16_t NVME:1;
      uint16_t :3;
      uint16_t SB:1;
      uint16_t :7;
    } bit;
  } STATUS;

  uint8_t  Reserved5[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ADDR:22;
      uint32_t :10;
    } bit;
  } ADDR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t LOCK:16;
    } bit;
  } LOCK;

} NVMCTRL_TypeDef;





/*
typedef struct {

} PAC0_TypeDef;

typedef struct {

} PAC1_TypeDef;

typedef struct {

} PAC2_TypeDef;
*/



/**
 * @brief   SAMD10 PM registers block.
 */
typedef struct {

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :2;
      uint8_t CFDEN:1;
      uint8_t :1;
      uint8_t BKUPCLK:1;
      uint8_t :3;
    } bit;
  } CTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t IDLE:2;
      uint8_t :6;
    } bit;
  } SLEEP;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t SETDIS:1;
      uint8_t :7;
    } bit;
  } EXTCTRL;

  uint8_t  Reserved1[5];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CPUDIV:3;
      uint8_t :5;
    } bit;
  } CPUSEL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t APBADIV:3;
      uint8_t :5;
    } bit;
  } APBASEL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t APBBDIV:3;
      uint8_t :5;
    } bit;
  } APBBSEL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t APBCDIV:3;
      uint8_t :5;
    } bit;
  } APBCSEL;

  uint8_t  Reserved2[8];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t HPB0:1;
      uint32_t HPB1:1;
      uint32_t HPB2:1;
      uint32_t DSU:1;
      uint32_t NVMCTRL:1;
      uint32_t DMAC:1;
      uint32_t :26;
    } bit;
  } AHBMASK;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t PAC0:1;
      uint32_t PM:1;
      uint32_t SYSCTRL:1;
      uint32_t GCLK:1;
      uint32_t WDT:1;
      uint32_t RTC:1;
      uint32_t EIC:1;
      uint32_t :25;
    } bit;
  } APBAMASK;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t PAC1:1;
      uint32_t DSU:1;
      uint32_t NVMCTRL:1;
      uint32_t PORT:1;
      uint32_t DMAC:1;
      uint32_t :27;
    } bit;
  } APBBMASK;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t PAC2:1;
      uint32_t EVSYS:1;
      uint32_t SERCOM0:1;
      uint32_t SERCOM1:1;
      uint32_t SERCOM2:1;
      uint32_t TCC0:1;
      uint32_t TC1:1;
      uint32_t TC2:1;
      uint32_t ADC:1;
      uint32_t AC:1;
      uint32_t DAC:1;
      uint32_t :21;
    } bit;
  } APBCMASK;

  uint8_t  Reserved3[16];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CKRDY:1;
      uint8_t CFD:1;
      uint8_t :6;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CKRDY:1;
      uint8_t CFD:1;
      uint8_t :6;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CKRDY:1;
      uint8_t CFD:1;
      uint8_t :6;
    } bit;
  } INTFLAG;

  uint8_t  Reserved4[1];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t POR:1;
      uint8_t BOD12:1;
      uint8_t BOD33:1;
      uint8_t :1;
      uint8_t EXT:1;
      uint8_t WDT:1;
      uint8_t SYST:1;
      uint8_t :1;
    } bit;
  } RCAUSE;

} PM_TypeDef;

/**
 * @brief   SAMD10 GPIO registers block.
 */
typedef struct {

  volatile union {
    uint32_t reg;
    struct {
      uint32_t DIR:32;
    } bit;
  } DIR;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t DIRCLR:32;
    } bit;
  } DIRCLR;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t DIRSET:32;
    } bit;
  } DIRSET;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t DIRTGL:32;
    } bit;
  } DIRTGL;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t OUT:32;
    } bit;
  } OUT;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t OUTCLR:32;
    } bit;
  } OUTCLR;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t OUTSET:32;
    } bit;
  } OUTSET;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t OUTTGL:32;
    } bit;
  } OUTTGL;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t IN0:32;
    } bit;
  } IN;

  volatile union {
    uint32_t   reg;
    struct {
      uint32_t SAMPLING:32;
    } bit;
  } CTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t PINMASK:16;
      uint32_t PMUXEN:1;
      uint32_t INEN:1;
      uint32_t PULLEN:1;
      uint32_t :3;
      uint32_t DRVSTR:1;
      uint32_t :1;
      uint32_t PMUX:4;
      uint32_t WRPMUX:1;
      uint32_t :1;
      uint32_t WRPINCFG:1;
      uint32_t HWSEL:1;
    } bit;
  } WRCONFIG;

  volatile uint8_t    Reserved1[4];
  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX0;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX1;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX2;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX3;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX4;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX5;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX6;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX7;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX8;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX9;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX10;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX11;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX12;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX13;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX14;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXE:4;
      uint8_t PMUXO:4;
    } bit;
  } PMUX15;

volatile union {
    uint8_t reg;
    struct {
      uint8_t PMUXEN:1;
      uint8_t INEN:1;
      uint8_t PULLEN:1;
      uint8_t :3;
      uint8_t DRVSTR:1;
      uint8_t :1;
    } bit;
  } PINCFG[32];

  volatile uint8_t    Reserved2[32];

} PORT_TypeDef;

/**
 * @brief   SAMD10 PTC registers block.
 */
/*
typedef struct {

} PTC_TypeDef;
*/

/**
 * @brief   SAMD10 RTC MODE0 registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t ENABLE:1;
      uint16_t MODE:2;
      uint16_t :3;
      uint16_t MATCHCLR:1;
      uint16_t PRESCALER:4;
      uint16_t :4;
    } bit;
  } CTRL;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ADDR:6;
      uint16_t :8;
      uint16_t RCONT:1;
      uint16_t RREQ:1;
    } bit;
  } READREQ;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t PEREO0:1;
      uint16_t PEREO1:1;
      uint16_t PEREO2:1;
      uint16_t PEREO3:1;
      uint16_t PEREO4:1;
      uint16_t PEREO5:1;
      uint16_t PEREO6:1;
      uint16_t PEREO7:1;
      uint16_t CMPEO0:1;
      uint16_t :6;
      uint16_t OVFEO:1;
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CMP0:1;
      uint8_t :5;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CMP0:1;
      uint8_t :5;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CMP0:1;
      uint8_t :5;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved1[1];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :7;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t VALUE:7;
      uint8_t SIGN:1;
    } bit;
  } FREQCORR;

  uint8_t  Reserved2[3];
  volatile union {
    uint32_t reg;
    struct {
      uint32_t COUNT:32;
    } bit;
  } COUNT;

  uint8_t  Reserved3[4];
  volatile union {
    uint32_t reg;
    struct {
      uint32_t COMP:32;
    } bit;
  } COMP0;

} RTCMODE0_TypeDef;

/**
 * @brief   SAMD10 RTC MODE1 registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t ENABLE:1;
      uint16_t MODE:2;
      uint16_t :4;
      uint16_t PRESCALER:4;
      uint16_t :4;
    } bit;
  } CTRL;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ADDR:6;
      uint16_t :8;
      uint16_t RCONT:1;
      uint16_t RREQ:1;
    } bit;
  } READREQ;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t PEREO0:1;
      uint16_t PEREO1:1;
      uint16_t PEREO2:1;
      uint16_t PEREO3:1;
      uint16_t PEREO4:1;
      uint16_t PEREO5:1;
      uint16_t PEREO6:1;
      uint16_t PEREO7:1;
      uint16_t CMPEO0:1;
      uint16_t CMPEO1:1;
      uint16_t :5;
      uint16_t OVFEO:1;
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CMP0:1;
      uint8_t CMP1:1;
      uint8_t :4;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CMP0:1;
      uint8_t CMP1:1;
      uint8_t :4;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CMP0:1;
      uint8_t CMP1:1;
      uint8_t :4;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved1[1];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :7;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t VALUE:7;
      uint8_t SIGN:1;
    } bit;
  } FREQCORR;

  uint8_t  Reserved2[3];
  volatile union {
    uint16_t reg;
    struct {
      uint16_t COUNT:16;
    } bit;
  } COUNT;

  uint8_t  Reserved3[2];
  volatile union {
    uint16_t reg;
    struct {
      uint16_t PRE:16;
    } bit;
  } PER;

  uint8_t  Reserved4[2];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t COMP0:16;
    } bit;
  } COMP0;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t COMP1:16;
    } bit;
  } COMP1;

} RTCMODE1_TypeDef;


/**
 * @brief   SAMD10 RTC MODE2 registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t ENABLE:1;
      uint16_t MODE:2;
      uint16_t :2;
      uint16_t CLKREP:1;
      uint16_t MATCHCLR:1;
    } bit;
  } CTRL;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ADDR:6;
      uint16_t :2;
      uint16_t :6;
      uint16_t RCONT:1;
      uint16_t RREQ:1;
    } bit;
  } READREQ;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t PEREO0:1;
      uint16_t PEREO1:1;
      uint16_t PEREO2:1;
      uint16_t PEREO3:1;
      uint16_t PEREO4:1;
      uint16_t PEREO5:1;
      uint16_t PEREO6:1;
      uint16_t PEREO7:1;
      uint16_t ALARMEO0:1;
      uint16_t RCONT:6;
      uint16_t OVFEO:1;
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t ALARM0:1;
      uint8_t :5;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t ALARM0:1;
      uint8_t :5;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t ALARM0:1;
      uint8_t :5;
      uint8_t SYNCRDY:1;
      uint8_t OVF:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved1[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :7;
      uint8_t SYBCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t VALUE:7;
      uint8_t SIGN:1;
    } bit;
  } FREQCORR;

  uint8_t  Reserved2[3];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SECOND:6;
      uint32_t MINUTE:6;
      uint32_t HOUR:5;
      uint32_t DAY:5;
      uint32_t MONTH:4;
      uint32_t YEAR:6;
    } bit;
  } CLOCK;

  uint8_t  Reserved3[4];

  volatile union {
    uint16_t reg;
    struct {
      uint32_t SECOND:6;
      uint32_t MINUTE:6;
      uint32_t HOUR:5;
      uint32_t DAY:5;
      uint32_t MONTH:4;
      uint32_t YEAR:6;
    } bit;
  } ALARM;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t SEL:3;
      uint8_t :5;
    } bit;
  } MASK;

} RTCMODE2_TypeDef;

/**
 * @brief   SAMD10 RTC registers block.
 */
typedef struct {
  RTCMODE0_TypeDef  MODE0;
  RTCMODE1_TypeDef  MODE1;
  RTCMODE2_TypeDef  MODE2;
} RTC_TypeDef;

/**
 * @brief   SAMD10 SERCOM UART registers block.
 */
typedef struct {

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t MODE:3;
      uint32_t :2;
      uint32_t RUNSTDBY:1;
      uint32_t IBON:1;
      uint32_t :4;
      uint32_t SAMPR3:3;
      uint32_t TXPO:2;
      uint32_t :2;
      uint32_t RXPO:2;
      uint32_t SAMPA:2;
      uint32_t FORM:4;
      uint32_t CMODE:1;
      uint32_t CPOL:1;
      uint32_t DORD:1;
      uint32_t :1;
    } bit;
  } CTRLA;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CHSIZE:3;
      uint32_t :3;
      uint32_t SBMODE:1;
      uint32_t :1;
      uint32_t COLDEN:1;
      uint32_t SFDE:1;
      uint32_t ENC:1;
      uint32_t :2;
      uint32_t PMODE:1;
      uint32_t :2;
      uint32_t TXEN:1;
      uint32_t RXEN:1;
      uint32_t :14;
    } bit;
  } CTRLB;

  uint8_t  Reserved1[4];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t BAUD:12;
      uint16_t FP:4;
    } bit;
  } BAUD;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t RXPL:8;
    } bit;
  } RXPL;

  uint8_t  Reserved2[5];

  volatile union {
    struct {
      uint8_t DRE:1;
      uint8_t TXC:1;
      uint8_t RXC:1;
      uint8_t RXS:1;    // This bit is define twoce, it can be present or not!!
      uint8_t CTSIC:1;
      uint8_t RXBRK:1;
      uint8_t :1;
      uint8_t ERROR:1;
    } bit;
    uint8_t  reg;
  } INTENCLR;

  uint8_t  Reserved3[1];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DRE:1;
      uint8_t TXC:1;
      uint8_t RXC:1;
      uint8_t RXS:1;    // This bit is define twoce, it can be present or not!!
      uint8_t CTSIC:1;
      uint8_t RXBRK:1;
      uint8_t :1;
      uint8_t ERROR:1;
    } bit;
  } INTENSET;

  uint8_t  Reserved4[1];
  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DRE:1;
      uint8_t TXC:1;
      uint8_t RXC:1;
      uint8_t RXS:1;    // This bit is define twoce, it can be present or not!!
      uint8_t CTSIC:1;
      uint8_t RXBRK:1;
      uint8_t :1;
      uint8_t ERROR:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved5[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t PERR:1;
      uint16_t FERR:1;
      uint16_t BUFOVF:1;
      uint16_t CTS:1;
      uint16_t ISF:1;
      uint16_t COLL:1;
      uint16_t :10;
    } bit;
  } STATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t CTRLB:1;
      uint32_t :29;
      
    } bit;
  } SYNCBUSY;

  uint8_t  Reserved6[8];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t DATA:9;
      uint16_t :7;
    } bit;
  } DATA;

  uint8_t  Reserved7[6];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGSTOP:1;
      uint8_t :7;
    } bit;
  } DBGCTRL; 

} SERCOMUSART_TypeDef;

/**
 * @brief   SAMD10 SERCOM SPI registers block.
 */
typedef struct {

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t MODE:3;
      uint32_t :2;
      uint32_t RUNSTDBY:1;
      uint32_t IBON:1;
      uint32_t :7;
      uint32_t DOPO:2;
      uint32_t :2;
      uint32_t DIPO:2;
      uint32_t :2;
      uint32_t FORM:4;
      uint32_t CPHA:1;
      uint32_t CPOL:1;
      uint32_t DORD:1;
      uint32_t :1;
    } bit;
  } CTRLA;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CHSIZE:3;
      uint32_t :3;
      uint32_t PLOADEN:1;
      uint32_t :1;
      uint32_t :1;
      uint32_t SSDE:1;
      uint32_t :3;
      uint32_t MSSEN:1;
      uint32_t AMODE:2;
      uint32_t :1;
      uint32_t RXEN:1;
      uint32_t :14;
    } bit;
  } CTRLB;

  uint8_t  Reserved1[4];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t BAUD:8;
    } bit;
  } BAUD;

  uint8_t  Reserved2[7];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DRE:1;
      uint8_t TXC:1;
      uint8_t RXC:1;
      uint8_t SSL:1;
      uint8_t :3;
      uint8_t ERROR:1;
    } bit;
  } INTENCLR;

  uint8_t  Reserved3[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DRE:1;
      uint8_t TXC:1;
      uint8_t RXC:1;
      uint8_t SSL:1;
      uint8_t :3;
      uint8_t ERROR:1;
    } bit;
  } INTENSET;

  uint8_t  Reserved4[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DRE:1;
      uint8_t TXC:1;
      uint8_t RXC:1;
      uint8_t SSL:1;
      uint8_t :3;
      uint8_t ERROR:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved5[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t :2;
      uint16_t BUFOVF:1;
      uint16_t :13;
    } bit;
  } STATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t CTRLB:1;
      uint32_t :29;
    } bit;
  } SYNCBUSY;

  uint8_t  Reserved6[4];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ADDR:8;
      uint32_t :8;
      uint32_t ADDRMASK:8;
      uint32_t :8;
    } bit;
  } ADDR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t DATA:9;
      uint16_t :7;
    } bit;
  } DATA;

  uint8_t  Reserved7[4];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGSTOP:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

} SERCOMSPI_TypeDef;









/**
 * @brief   SAMD10 SERCOM I2C SLAVE registers block.
 */
typedef struct {

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t MODE:3;
      uint32_t :2;
      uint32_t RUNSTDBY:1;
      uint32_t :8;
      uint32_t PINOUT:1;
      uint32_t :3;
      uint32_t SDAHOLD:2;
      uint32_t :1;
      uint32_t SEXTTOEN:1;
      uint32_t SPEED:2;
      uint32_t :1;
      uint32_t SCLSM:1;
      uint32_t :2;
      uint32_t LOWTOUT:1;
      uint32_t :1;
    } bit;
  } CTRLA;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :8;
      uint32_t SMEN:1;
      uint32_t GCMD:1;
      uint32_t AACKEN:1;
      uint32_t :3;
      uint32_t AMODE:2;
      uint32_t CMD:2;
      uint32_t ACKACT:1;
      uint32_t :13;
    } bit;
  } CTRLB;

  uint8_t  Reserved1[12];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t PREC:1;
      uint8_t AMATCH:1;
      uint8_t DRDY:1;
      uint8_t :4;
      uint8_t ERROR:1;
    } bit;
  } INTENCLR;

  uint8_t  Reserved2[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t PREC:1;
      uint8_t AMATCH:1;
      uint8_t DRDY:1;
      uint8_t :4;
      uint8_t ERROR:1;
    } bit;
  } INTENSET;

  uint8_t  Reserved3[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t PREC:1;
      uint8_t AMATCH:1;
      uint8_t DRDY:1;
      uint8_t :4;
      uint8_t ERROR:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved4[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t BUSERR:1;
      uint16_t COLL:1;
      uint16_t RXNACK:1;
      uint16_t DIR:1;
      uint16_t SR:1;
      uint16_t :1;
      uint16_t LOWTOUT:1;
      uint16_t CLKHOLD:1;

      uint16_t :1;
      uint16_t SEXTTOUT:1;
      uint16_t HS:1;
      uint16_t :4;
      uint16_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t :29;
    } bit;
  } SYNCBUSY;

  uint8_t  Reserved5[4];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t GENCEN:1;
      uint32_t ADDR:10;
      uint32_t :4;
      uint32_t TENBITEN:1;
      uint32_t :1;
      uint32_t ADDRMASK:10;
      uint32_t :5;
    } bit;
  } ADDR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t DATA:8;
      uint16_t :8;
    } bit;
  } DATA;

} SERCOMI2CSLAVEMODE_TypeDef;

/**
 * @brief   SAMD10 SERCOM I2C MASTER registers block.
 */
typedef struct {

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t MODE:3;
      uint32_t :2;
      uint32_t RUNSTDBY:1;
      uint32_t :8;
      uint32_t PINOUT:1;
      uint32_t :3;
      uint32_t SDAHOLD:2;
      uint32_t MEXTTOEN:1;
      uint32_t SEXTTOEN:1;
      uint32_t SPEED:2;
      uint32_t :1;
      uint32_t SCLSM:1;
      uint32_t INACTOUT:2;
      uint32_t LOWTOUT:1;
      uint32_t :1;
    } bit;
  } CTRLA;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :8;
      uint32_t SMEN:1;
      uint32_t QCEN:1;
      uint32_t :6;
      uint32_t CMD:2;
      uint32_t ACKACT:1;
      uint32_t :13;
    } bit;
  } CTRLB;

  uint8_t  Reserved1[4];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t BAUD:8;
      uint32_t BAUDLOW:8;
      uint32_t HSBAUD:8;
      uint32_t HSBAUDLOW:8;
    } bit;
  } BAUD;

  uint8_t  Reserved2[4];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t MB:1;
      uint8_t SB:1;
      uint8_t :5;
      uint8_t ERROR:1;
    } bit;
  } INTENCLR;

  uint8_t  Reserved3[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t MB:1;
      uint8_t SB:1;
      uint8_t :5;
      uint8_t ERROR:1;
    } bit;
  } INTENSET;

  uint8_t  Reserved4[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t MB:1;
      uint8_t SB:1;
      uint8_t :5;
      uint8_t ERROR:1;
    } bit;
  } INTFLAG;

  uint8_t  Reserved5[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t BUSERR:1;
      uint16_t ARBLOST:1;
      uint16_t RXNACK:1;
      uint16_t :1;
      uint16_t BUSSTATE:2;
      uint16_t LOWTOUT:1;
      uint16_t CLKHOLD:1;
      uint16_t MEXTTOUT:1;
      uint16_t SEXTTOUT:1;
      uint16_t LENERR:1;
      uint16_t :5;
    } bit;
  } STATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t SWRST:1;
      uint32_t ENABLE:1;
      uint32_t SYSOP:1;
      uint32_t :29;
    } bit;
  } SYNCBUSY;

  uint8_t  Reserved6[4];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t ADDR:11;
      uint32_t :2;
      uint32_t LENEN:1;
      uint32_t HS:1;
      uint32_t TENBITEN:1;
      uint32_t LEN:8;
      uint32_t :8;
    } bit;
  } ADDR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t DATA:8;
      uint16_t :8; 
    } bit;
  } DATA;

  uint8_t Reserved7[7];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGSTOP:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

} SERCOMI2CMASTERMODE_TypeDef;

/**
 * @brief   SAMD10 SERCOM I2C registers block.
 */
typedef struct {
  SERCOMI2CSLAVEMODE_TypeDef  SLAVEMODE;
  SERCOMI2CMASTERMODE_TypeDef MASTERMODE;
} SERCOMI2C_TypeDef;

/**
 * @brief   SAMD10 SERCOM registers block.
 */
typedef struct {
  SERCOMUSART_TypeDef USART;
  SERCOMSPI_TypeDef   SPI;
  SERCOMI2C_TypeDef   I2C;
} SERCOM_TypeDef;

/**
 * @brief   SAMD10 SYSCTRL registers block.
 */
typedef struct {

  volatile union {
    uint32_t reg;
    struct {
      uint32_t XOSCRDY:1;
      uint32_t XOSC32KRDY:1;
      uint32_t OSC32KRDY:1;
      uint32_t OSC8MRDY:1;
      uint32_t DFLLRDY:1;
      uint32_t DFLLOOB:1;
      uint32_t DFLLLCKF:1;
      uint32_t DFLLLCKC:1;
      uint32_t DFLLRCS:1;
      uint32_t BOD33RDY:1;
      uint32_t BOD33DET:1;
      uint32_t B33SRDY:1;
      uint32_t :3;
      uint32_t DPLLLCKR:1;
      uint32_t DPLLLCKF:1;
      uint32_t DPLLLTO:1;
      uint32_t :14;
    } bit;
  } INTENCLR;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t XOSCRDY:1;
      uint32_t XOSC32KRDY:1;
      uint32_t OSC32KRDY:1;
      uint32_t OSC8MRDY:1;
      uint32_t DFLLRDY:1;
      uint32_t DFLLOOB:1;
      uint32_t DFLLLCKF:1;
      uint32_t DFLLLCKC:1;
      uint32_t DFLLRCS:1;
      uint32_t BOD33RDY:1;
      uint32_t BOD33DET:1;
      uint32_t B33SRDY:1;
      uint32_t :3;
      uint32_t DPLLLCKR:1;
      uint32_t DPLLLCKF:1;
      uint32_t DPLLLTO:1;
      uint32_t :14;
    } bit;
  } INTENSET;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t XOSCRDY:1;
      uint32_t XOSC32KRDY:1;
      uint32_t OSC32KRDY:1;
      uint32_t OSC8MRDY:1;
      uint32_t DFLLRDY:1;
      uint32_t DFLLOOB:1;
      uint32_t DFLLLCKF:1;
      uint32_t DFLLLCKC:1;
      uint32_t DFLLRCS:1;
      uint32_t BOD33RDY:1;
      uint32_t BOD33DET:1;
      uint32_t B33SRDY:1;
      uint32_t :3;
      uint32_t DPLLLCKR:1;
      uint32_t DPLLLCKF:1;
      uint32_t DPLLLTO:1;
      uint32_t :14;
    } bit;
  } INTFLAG;

  volatile union {
     uint32_t reg;
     struct {
      uint32_t XOSCRDY:1;
      uint32_t XOSC32KRDY:1;
      uint32_t OSC32KRDY:1;
      uint32_t OSC8MRDY:1;
      uint32_t DFLLRDY:1;
      uint32_t DFLLOOB:1;
      uint32_t DFLLLCKF:1;
      uint32_t DFLLLCKC:1;
      uint32_t DFLLRCS:1;
      uint32_t BOD33RDY:1;
      uint32_t BOD33DET:1;
      uint32_t B33SRDY:1;
      uint32_t :3;
      uint32_t DPLLLCKR:1;
      uint32_t DPLLLCKF:1;
      uint32_t DPLLLTO:1;
      uint32_t :14;
    } bit;
  } PCLKSR;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t :1;
      uint16_t ENABLE:1;
      uint16_t XTALEN:1;
      uint16_t :3;
      uint16_t RUNSTDBY:1;
      uint16_t ONDEMAND:1;
      uint16_t GAIN:3;
      uint16_t AMPGC:1;
      uint16_t STARTUP:4;
    } bit;
  } XOSC;

  uint8_t  Reserved1[2];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t :1;
      uint16_t ENABLE:1;
      uint16_t XTALEN:1;
      uint16_t EN32K:1;
      uint16_t EN1K:1;
      uint16_t AAMPEN:1;
      uint16_t RUNSTDBY:1;
      uint16_t ONDEMAND:1;
      uint16_t STARTUP:3;
      uint16_t :1;
      uint16_t WRTLOCK:1;
      uint16_t :3;   
    } bit;
  } XOSC32K;

  uint8_t  Reserved2[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :1;
      uint32_t ENABLE:1;
      uint32_t EN32K:1;
      uint32_t EN1K:1;
      uint32_t :2;
      uint32_t RUNSTDBY:1;
      uint32_t ONDEMAND:1;
      uint32_t STARTUP:3;
      uint32_t :1;
      uint32_t WRTLOCK:1;
      uint32_t :3;
      uint32_t CALIB:7;
      uint32_t :9;
      
    } bit;
  } OSC32K;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CALIB:5;
      uint8_t :2;
      uint8_t WRTLOCK:1;
    } bit;
  } OSCULP32K;

  uint8_t  Reserved3[3];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :1;
      uint32_t ENABLE:1;
      uint32_t :4;
      uint32_t RUNSTDBY:1;
      uint32_t ONDEMAND:1;
      uint32_t PRESC:2;
      uint32_t :6;
      uint32_t CALIB:12;
      uint32_t :2;
      uint32_t FRANGE:2;
    } bit;
  } OSC8M;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t :1;
      uint16_t ENABLE:1;
      uint16_t MODE:1;
      uint16_t STABLE:1;
      uint16_t LLAW:1;
      uint16_t :2;
      uint16_t ONDEMAND:1;
      uint16_t CCDIS:1;
      uint16_t QLDIS:1;
      uint16_t BPLCKC:1;
      uint16_t WAITLOCK:1;
      uint16_t :4;   
    } bit;
  } DFLLCTRL;

  uint8_t  Reserved4[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t FINE:10;
      uint32_t COARSE:6;
      uint32_t DIFF:16;
    } bit;
  } DFLLVAL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t MUL:16;
      uint32_t FSTEP:10;
      uint32_t CSTEP:6;
    } bit;
  } DFLLMUL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :6;
      uint8_t READREQ:1;
    } bit;
  } DFLLSYNC;

  uint8_t  Reserved5[3];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :1;
      uint32_t ENABLE:1;
      uint32_t HYST:1;
      uint32_t ACTION:2;
      uint32_t :1;
      uint32_t RUNSTDBY:1;
      uint32_t :1;
      uint32_t MODE:1;
      uint32_t CEN:1;
      uint32_t :2;
      uint32_t PSEL:4;
      uint32_t LEVEL:6;
      uint32_t :10;
    } bit;
  } BOD33;

  uint8_t  Reserved6[8];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :1;
      uint32_t TSEN:1;
      uint32_t BGOUTEN:1;
      uint32_t :13;
      uint32_t CALIB:11;
      uint32_t :5;
    } bit;
  } VREF;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :1;
      uint8_t ENABLE:1;
      uint8_t :5;
      uint8_t ONDEMAND:1;
    } bit;
  } DPLLCTRLA;
  
  uint8_t  Reserved7[3];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t LDR:12;
      uint32_t :4;
      uint32_t LDRFRAC:4;
      uint32_t :12;
    } bit;
  } DPLLRATIO;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t FILTER:2;
      uint32_t LPEN:1;
      uint32_t WUF:1;
      uint32_t REFCLK:2;
      uint32_t :2;
      uint32_t LTIME:3;
      uint32_t :1;
      uint32_t LBYPASS:1;
      uint32_t :3;
      uint32_t DIV:11;
      uint32_t :5;
    } bit;
  } DPLLCTRLB;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t LOCK:1;
      uint8_t CLKRDY:1;
      uint8_t ENABLE:1;
      uint8_t DIV:1;
      uint8_t :4;
    } bit;
  } DPLLSTATUS;

} SYSCTRL_TypeDef;

/**
 * @brief   SAMD10 TC 8-bit registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t ENABLE:1;
      uint16_t MODE:2;
      uint16_t :1;
      uint16_t WAVEGEN:2;
      uint16_t :1;
      uint16_t PRESCALER:3;
      uint16_t RUNSTDBY:1;
      uint16_t PRESCSYNC:2;
      uint16_t :2;   
    } bit;
  } CTRLA;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ADDR:5;
      uint16_t :3;
      uint16_t :6;
      uint16_t RCONT:1;
      uint16_t RREQ:1;
    } bit;
  } READREQ;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DIR:1;
      uint8_t :1;
      uint8_t ONESHOT:1;
      uint8_t :3;
      uint8_t CMD:2;
    } bit;
  } CTRLBCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DIR:1;
      uint8_t :1;
      uint8_t ONESHOT:1;
      uint8_t :3;
      uint8_t CMD:2;
    } bit;
  } CTRLBSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t INVEN0:1;
      uint8_t INVEN1:1;
      uint8_t :2;
      uint8_t CPTEN0:1;
      uint8_t CPTEN1:1;
      uint8_t :2;
    } bit;
  } CTRLC;

  uint8_t  Reserved1[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  uint8_t  Reserved2[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t EVACT:3;
      uint16_t :1;
      uint16_t TCINV:1;
      uint16_t TCEI:1;
      uint16_t :2;
      uint16_t OVFEO:1;
      uint16_t :3;
      uint16_t MCEO0:1;
      uint16_t MCEO1:1;
      uint16_t :2;   
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTFLAG;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :3;
      uint8_t STOP:1;
      uint8_t SLAVE:1;
      uint8_t :2;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t COUNT:8;
    } bit;
  } COUNT;

  uint8_t  Reserved3[3];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t PER:8;
    } bit;
  } PER;

  uint8_t  Reserved4[3];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CC:8;
    } bit;
  } CC0;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t CC:8;
    } bit;
  } CC1;

} TC8Bits_TypeDef;

/**
 * @brief   SAMD10 TC 16-bit registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t ENABLE:1;
      uint16_t MODE:2;
      uint16_t :1;
      uint16_t WAVEGEN:2;
      uint16_t :1;
      uint16_t PRESCALER:3;
      uint16_t RUNSTDBY:1;
      uint16_t PRESCSYNC:2;
      uint16_t :2;
    } bit;
  } CTRLA;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ADDR:5;
      uint16_t :9;
      uint16_t RCONT:1;
      uint16_t RREQ:1;
    } bit;
  } READREQ;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DIR:1;
      uint8_t :1;
      uint8_t ONESHOT:1;
      uint8_t :3;
      uint8_t CMD:2;
    } bit;
  } CTRLBCLR;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DIR:1;
      uint8_t :1;
      uint8_t ONESHOT:1;
      uint8_t :3;
      uint8_t CMD:2;
    } bit;
  } CTRLBSET;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t INVEN0:1;
      uint8_t INVEN1:1;
      uint8_t :2;
      uint8_t CPTEN0:1;
      uint8_t CPTEN1:1;
      uint8_t :2;
    } bit;
  } CTRLC;
  
  uint8_t  Reserved1[1];

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  uint8_t  Reserved2[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t EVACT:3;
      uint16_t :1;
      uint16_t TCINV:1;
      uint16_t TCEI:1;
      uint16_t :2;
      uint16_t OVFEO:1;
      uint16_t :3;
      uint16_t MCEO0:1;
      uint16_t MCEO1:1;
      uint16_t :2;   
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTFLAG;

  volatile union {
    uint8_t  reg;
    struct {
      uint8_t :3;
      uint8_t STOP:1;
      uint8_t SLAVE:1;
      uint8_t :2;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t COUNT:16;
    } bit;
  } COUNT;

  uint8_t Reserved3[6];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t CC:16;
    } bit;
  } CC0;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t CC:16;
    } bit;
  } CC1;

} TC16Bits_TypeDef;

/**
 * @brief   SAMD10 TC 32-bit registers block.
 */
typedef struct {

  volatile union {
    uint16_t reg;
    struct {
      uint16_t SWRST:1;
      uint16_t ENABLE:1;
      uint16_t MODE:2;
      uint16_t :1;
      uint16_t WAVEGEN:2;
      uint16_t :1;
      uint16_t PRESCALER:3;
      uint16_t RUNSTDBY:1;
      uint16_t PRESCSYNC:2;
      uint16_t :2;   
    } bit;
  } CTRLA;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t ADDR:5;
      uint16_t :3;
      uint16_t :6;
      uint16_t RCONT:1;
      uint16_t RREQ:1;   
    } bit;
  } READREQ;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t DIR:1;
      uint8_t :1;
      uint8_t ONESHOT:1;
      uint8_t :3;
      uint8_t CMD:2;
    } bit;
  } CTRLBCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t DIR:1;
      uint8_t :1;
      uint8_t ONESHOT:1;
      uint8_t :3;
      uint8_t CMD:2;
    } bit;
  } CTRLBSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t INVEN0:1;
      uint8_t INVEN1:1;
      uint8_t :2;
      uint8_t CPTEN0:1;
      uint8_t CPTEN1:1;
      uint8_t :2;
    } bit;
  } CTRLC;

  uint8_t  Reserved1[1];

  volatile union {
    uint8_t reg;
    struct {
      uint8_t DBGRUN:1;
      uint8_t :7;
    } bit;
  } DBGCTRL;

  uint8_t  Reserved2[1];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t EVACT:3;
      uint16_t :1;
      uint16_t TCINV:1;
      uint16_t TCEI:1;
      uint16_t :2;

      uint16_t OVFEO:1;
      uint16_t :3;
      uint16_t MCEO0:1;
      uint16_t MCEO1:1;
      uint16_t :2;   
    } bit;
  } EVCTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t OVF:1;
      uint8_t ERR:1;
      uint8_t :1;
      uint8_t SYNCRDY:1;
      uint8_t MC0:1;
      uint8_t MC1:1;
      uint8_t :2;
    } bit;
  } INTFLAG;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :3;
      uint8_t STOP:1;
      uint8_t SLAVE:1;
      uint8_t :2;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t COUNT:32;
    } bit;
  } COUNT;

  uint8_t  Reserved3[4];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CC:32;
    } bit;
  } CC0;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t CC:32;
    } bit;
  } CC1;

} TC32Bits_TypeDef;

/**
 * @brief   SAMD10 TC registers block.
 */
typedef struct {
  TC8Bits_TypeDef   COUNT8;
  TC16Bits_TypeDef  COUNT16;
  TC32Bits_TypeDef  COUNT32;
} TC_TypeDef;

/**
 * @brief   SAMD10 TCC registers block.
 */
/*
typedef struct {

  volatile union {
    uint32_t  reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CTRLA;

  volatile union {
    uint8_t   reg;
    struct {
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
    } bit;
  } CTRLBCLR;

  volatile union {
    uint8_t   reg;
    struct {
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
    } bit;
  } CTRLBSET;

  uint8_t  Reserved1[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } SYNCBUSY;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } FCTRLA;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } FCTRLB;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } WEXCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } DRVCTRL;

  uint8_t  Reserved2[2];

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
      uint8_t :;
    } bit;
  } DBGCTRL;

  uint8_t  Reserved3[1];

  volatile union {
    uint32_t  reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } EVCTRL;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } INTENCLR;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } INTENSET;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } INTFLAG;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } STATUS;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } COUNT;

  volatile union {
    uint16_t reg;
    struct {
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;

      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;    
    } bit;
  } PATT;

  uint8_t  Reserved4[2];
  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } WAVE;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } PER;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CC0;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CC1;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CC2;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CC3;

  uint8_t  Reserved5[16];

  volatile union {
    uint16_t reg;
    struct {
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;

      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;
      uint16_t :;    
    } bit;
  } PATTB;

  uint8_t  Reserved6[2];

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } WAVEB;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } PERB;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CCB0;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CCB1;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
    } bit;
  } CCB2;

  volatile union {
    uint32_t reg;
    struct {
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;

      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;
      uint32_t :;      
    } bit;
  } CCB3;

} TCC_TypeDef;
*/

/**
 * @brief   SAMD10 WDT registers block.
 */
typedef struct {

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :1;
      uint8_t ENABLE:1;
      uint8_t WEN:1;
      uint8_t :4;
      uint8_t ALWAYSON:1;
    } bit;
  } CTRL;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t PER:4;
      uint8_t WINDOW:4;
    } bit;
  } CONFIG;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t EWOFFSET:4;
      uint8_t :4;
    } bit;
  } EWCTRL;

  uint8_t  Reserved1[1];

  volatile union {
    uint8_t reg;
    struct {
      uint8_t EW:1;
      uint8_t :7;
    } bit;
  } INTENCLR;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t EW:1;
      uint8_t :7;
    } bit;
  } INTENSET;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t EW:1;
      uint8_t :7;
    } bit;
  } INTFLAG;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t :7;
      uint8_t SYNCBUSY:1;
    } bit;
  } STATUS;

  volatile union {
    uint8_t reg;
    struct {
      uint8_t CLEAR:8;
    } bit;
  } CLEAR;

} WDT_TypeDef;

#define FLASH_BASE  ((uint32_t)0x00000000U)  /*!< Embedded FLASH base address.          */
#define SRAM_BASE   ((uint32_t)0x20000000U)  /*!< Embedded SRAM base address.           */
#define PERIPH_BASE ((uint32_t)0x40000000U)  /*!< Peripheral base address.              */

/*!< Peripheral memory map  */
#define AHBAPB_BRIDGEA (PERIPH_BASE + 0x00000000)
#define AHBAPB_BRIDGEB (PERIPH_BASE + 0x01000000)
#define AHBAPB_BRIDGEC (PERIPH_BASE + 0x02000000)

/* AHB-APB Bridge A peripherals.  */
#define PAC0_BASE     (AHBAPB_BRIDGEA + 0x00000000)
#define PM_BASE       (AHBAPB_BRIDGEA + 0x00000400)
#define SYSCTRL_BASE  (AHBAPB_BRIDGEA + 0x00000800)
#define GCLK_BASE     (AHBAPB_BRIDGEA + 0x00000C00)
#define WDT_BASE      (AHBAPB_BRIDGEA + 0x00001000)
#define RTC_BASE      (AHBAPB_BRIDGEA + 0x00001400)
#define EIC_BASE      (AHBAPB_BRIDGEA + 0x00001800)

/* AHB-APB Bridge B peripherals.  */
#define PAC1_BASE     (AHBAPB_BRIDGEB + 0x00000000)
#define DSU_BASE      (AHBAPB_BRIDGEB + 0x00002000)
#define NVMCTRL_BASE  (AHBAPB_BRIDGEB + 0x00004000)
#define PORT_BASE     (AHBAPB_BRIDGEB + 0x00004400)
#define DMAC_BASE     (AHBAPB_BRIDGEB + 0x00004800)
#define MTB_BASE      (AHBAPB_BRIDGEB + 0x00006000)

/* AHB-APB Bridge C peripherals.  */
#define PAC2_BASE     (AHBAPB_BRIDGEC + 0x00000000)
#define EVSYS_BASE    (AHBAPB_BRIDGEC + 0x00000400)
#define SERCOM0_BASE  (AHBAPB_BRIDGEC + 0x00000800)
#define SERCOM1_BASE  (AHBAPB_BRIDGEC + 0x00000C00)
#define SERCOM2_BASE  (AHBAPB_BRIDGEC + 0x00001000)
#define TCC0_BASE     (AHBAPB_BRIDGEC + 0x00001400)
#define TC1_BASE      (AHBAPB_BRIDGEC + 0x00001800)
#define TC2_BASE      (AHBAPB_BRIDGEC + 0x00001C00)
#define ADC_BASE      (AHBAPB_BRIDGEC + 0x00002000)
#define AC_BASE       (AHBAPB_BRIDGEC + 0x00002400)
#define DAC_BASE      (AHBAPB_BRIDGEC + 0x00002800)
#define PTC_BASE      (AHBAPB_BRIDGEC + 0x00002C00)



//#define PAC0  ((PAC_TypeDef *)  PAC0_BASE         )
#define PM      ((PM_TypeDef      *)  PM_BASE     )
#define SYSCTRL ((SYSCTRL_TypeDef *)  SYSCTRL_BASE)
#define GCLK    ((GCLK_TypeDef    *)  GCLK_BASE   )
#define WDT     ((WDT_TypeDef     *)  WDT_BASE    )
#define RTC     ((RTC_TypeDef     *)  RTC_BASE    )
#define EIC     ((EIC_TypeDef     *)  EIC_BASE    )

/* AHB-APB Bridge B peripherals.  */
//#define PAC1    ((PAC1_TypeDef    *)  PAC1_BASE   )
#define DSU     ((DSU_TypeDef     *) DSU_BASE     )
#define NVMCTRL ((NVMCTRL_TypeDef *) NVMCTRL_BASE )
#define PORT    ((PORT_TypeDef    *) PORT_BASE    )
#define DMAC    ((DMAC_TypeDef    *) DMAC_BASE    )
//#define MTB     ((MTB_TypeDef     *) MTB_BASE     )

/* AHB-APB Bridge C peripherals.  */
//#define PAC2    ((PCA2_TypeDef    *) PAC2_BASE    )
#define EVSYS   ((EVSYS_TypeDef   *) EVSYS_BASE   )
#define SERCOM0 ((SERCOM_TypeDef  *) SERCOM0_BASE )
#define SERCOM1 ((SERCOM_TypeDef  *) SERCOM1_BASE )
#define SERCOM2 ((SERCOM_TypeDef  *) SERCOM2_BASE )
#define TCC0    ((TCC_TypeDef     *) TCC0_BASE    )
#define TC1     ((TC_TypeDef      *) TC1_BASE     )
#define TC2     ((TC_TypeDef      *) TC2_BASE     )
#define ADC     ((ADC_TypeDef     *) ADC_BASE     )
#define AC      ((AC_TypeDef      *) AC_BASE      )
#define DAC     ((DAC_TypeDef     *) DAC_BASE     )
#define PTC     ((PTC_TypeDef     *) PTC_BASE     )

#define PORT_DIR_DIR_Pos           (0U)
#define PORT_DIR_DIR_Msk           (0xFFFFFFFF << PORT_DIR_DIR_Pos)
#define PORT_DIR_DIR               PORT_DIR_DIR_Msk

#define PORT_DIRCLR_DIRCLR_Pos     (0U)
#define PORT_DIRCLR_DIRCLR_Msk     (0xFFFFFFFF << PORT_DIRCLR_DIRCLR_Pos)
#define PORT_DIRCLR_DIRCLR         PORT_DIRCLR_DIRCLR_Msk

#define PORT_DIRSET_DIRSET_Pos     (0U)
#define PORT_DIRSET_DIRSET_Msk     (0xFFFFFFFF << PORT_DIRSET_DIRSET_Pos)
#define PORT_DIRSET_DIRSET         PORT_DIRSET_DIRSET_Msk

#define PORT_DIRTGL_DIRTGL_Pos     (0U)
#define PORT_DIRTGL_DIRTGL_Msk     (0xFFFFFFFF << PORT_DIRTGL_DIRTGL_Pos)
#define PORT_DIRTGL_DIRTGL         PORT_DIRTGL_DIRTGL_Msk

#define PORT_OUT_OUT_Pos           (0U)
#define PORT_OUT_OUT_Msk           (0xFFFFFFFF << PORT_OUT_OUT_Pos)
#define PORT_OUT_OUT               PORT_OUT_OUT_Msk

#define PORT_OUTCLR_OUTCLR_Pos     (0U)
#define PORT_OUTCLR_OUTCLR_Msk     (0xFFFFFFFF << PORT_OUTCLR_OUTCLR_Pos)
#define PORT_OUTCLR_OUTCLR         PORT_OUTCLR_OUTCLR_Msk

#define PORT_OUTSET_OUTSET_Pos     (0U)
#define PORT_OUTSET_OUTSET_Msk     (0xFFFFFFFF << PORT_OUTSET_OUTSET_Pos)
#define PORT_OUTSET_OUTSET         PORT_OUTSET_OUTSET_Msk

#define PORT_OUTTGL_OUTTGL_Pos     (0U)
#define PORT_OUTTGL_OUTTGL_Msk     (0xFFFFFFFF << PORT_OUTTGL_OUTTGL_Pos)
#define PORT_OUTTGL_OUTTGL         PORT_OUTTGL_OUTTGL_Msk

#define PORT_IN_IN_Pos             (0U)
#define PORT_IN_IN_Msk             (0xFFFFFFFF << PORT_IN_IN_Pos)
#define PORT_IN_IN                 PORT_IN_IN_Msk

#define PORT_CTRL_CTRL_Pos         (0U)
#define PORT_CTRL_CTRL_Msk         (0xFFFFFFFF << PORT_CTRL_CTRL_Pos)
#define PORT_CTRL_CTRL             PORT_CTRL_CTRL_Msk


#define PORT_WRCONFIG_HWSEL_Pos    (31U)
#define PORT_WRCONFIG_HWSEL_Msk    (0x1 << PORT_WRCONFIG_HWSEL_Pos)
#define PORT_WRCONFIG_HWSEL        PORT_WRCONFIG_HWSEL_Msk

#define PORT_WRCONFIG_WRPINCFG_Pos (30U)
#define PORT_WRCONFIG_WRPINCFG_Msk (0x1 << PORT_WRCONFIG_WRPINCFG_Pos)
#define PORT_WRCONFIG_WRPINCFG     PORT_WRCONFIG_WRPINCFG_Msk

#define PORT_WRCONFIG_WRPMUX_Pos   (28U)
#define PORT_WRCONFIG_WRPMUX_Msk   (0x1 << PORT_WRCONFIG_WRPMUX_Pos)
#define PORT_WRCONFIG_WRPMUX       PORT_WRCONFIG_WRPMUX_Msk

#define PORT_WRCONFIG_PMUX_Pos     (24U)
#define PORT_WRCONFIG_PMUX_Msk     (0xF << PORT_WRCONFIG_PMUX_Pos)
#define PORT_WRCONFIG_PMUX         PORT_WRCONFIG_PMUX_Msk

#define PORT_WRCONFIG_DRVSTR_Pos   (22U)
#define PORT_WRCONFIG_DRVSTR_Msk   (0x1 << PORT_WRCONFIG_DRVSTR_Pos)
#define PORT_WRCONFIG_DRVSTR       PORT_WRCONFIG_DRVSTR_Msk

#define PORT_WRCONFIG_PULLEN_Pos   (18U)
#define PORT_WRCONFIG_PULLEN_Msk   (0x1 << PORT_WRCONFIG_PULLEN_Pos)
#define PORT_WRCONFIG_PULLEN       PORT_WRCONFIG_PULLEN_Msk

#define PORT_WRCONFIG_INEN_Pos     (17U)
#define PORT_WRCONFIG_INEN_Msk     (0x1 << PORT_WRCONFIG_INEN_Pos)
#define PORT_WRCONFIG_INEN         PORT_WRCONFIG_INEN_Msk

#define PORT_WRCONFIG_PMUXEN_Pos   (16U)
#define PORT_WRCONFIG_PMUXEN_Msk   (0x1 << PORT_WRCONFIG_PMUXEN_Pos)
#define PORT_WRCONFIG_PMUXEN       PORT_WRCONFIG_PMUXEN_Msk

#define PORT_WRCONFIG_PINMAK_Pos   (0U)
#define PORT_WRCONFIG_PINMAK_Msk   (0xFFFF << PORT_WRCONFIG_PINMAK_Pos)
#define PORT_WRCONFIG_PINMAK       PORT_WRCONFIG_PINMAK_Msk


/*

#define PORT_PMUX0
#define PORT_PMUX1
#define PORT_PMUX2
#define PORT_PMUX3
#define PORT_PMUX4
#define PORT_PMUX5
#define PORT_PMUX6
#define PORT_PMUX7
#define PORT_PMUX8
#define PORT_PMUX9
#define PORT_PMUX10
#define PORT_PMUX11
#define PORT_PMUX12
#define PORT_PMUX13
#define PORT_PMUX14
#define PORT_PMUX15

#define PORT_PINCFG0
#define PORT_PINCFG1
#define PORT_PINCFG2
#define PORT_PINCFG3
#define PORT_PINCFG4
#define PORT_PINCFG5
#define PORT_PINCFG6
#define PORT_PINCFG7
#define PORT_PINCFG8
#define PORT_PINCFG9
#define PORT_PINCFG10
#define PORT_PINCFG11
#define PORT_PINCFG12
#define PORT_PINCFG13
#define PORT_PINCFG14
#define PORT_PINCFG15
#define PORT_PINCFG16
#define PORT_PINCFG17
#define PORT_PINCFG18
#define PORT_PINCFG19
#define PORT_PINCFG20
#define PORT_PINCFG21
#define PORT_PINCFG22
#define PORT_PINCFG23
#define PORT_PINCFG24
#define PORT_PINCFG25
#define PORT_PINCFG26
#define PORT_PINCFG27
#define PORT_PINCFG28
#define PORT_PINCFG29
#define PORT_PINCFG30
#define PORT_PINCFG31
*/

// Enable
#define WDT_CTRL_ENABLE_Pos        (1U)
#define WDT_CTRL_ENABLE_Msk        (0x01 << WDT_CTRL_ENABLE_Pos)
#define WDT_CTRL_ENABLE            WDT_CTRL_ENABLE_Msk

// Windows Enable
#define WDT_CTRL_WEN_Pos           (2U)
#define WDT_CTRL_WEN_Msk           (0x01 << WDT_CTRL_WEN_Pos)
#define WDT_CTRL_WEN               WDT_CTRL_WEN_Msk

// Always Enable
#define WDT_CTRL_Pos               (7U)
#define WDT_CTRL_Msk               (0x01 << WDT_CTRL_Pos)
#define WDT_CTRL                   WDT_CTRL_Msk


// Windows mode
#define WDT_CONFIG_WINDOW_Pos      (4U)
#define WDT_CONFIG_WINDOW_Msk      (0xF << WDT_CONFIG_WINDOW_Pos)
#define WDT_CONFIG_WINDOW          WDT_CONFIG_WINDOW_Msk

// Normal mode
#define WDT_CONFIG_PER_Pos         (0U)
#define WDT_CONFIG_PER_Msk         (0xF << WDT_CONFIG_PER_Pos)
#define WDT_CONFIG_PER             WDT_CONFIG_PER_Msk

#define WDT_EWCTRL_EWOFFSET_Pos    (0U)
#define WDT_EWCTRL_EWOFFSET_Msk    (0xF << WDT_EWCTRL_EWOFFSET_Pos)
#define WDT_EWCTRL_EWOFFSET        WDT_EWCTRL_EWOFFSET_Msk

#define WDT_INTENCRL_EW_Pos        (0U)
#define WDT_INTENCRL_EW_Msk        (0x1 << WDT_INTENCRL_EW_Pos)
#define WDT_INTENCRL_EW            WDT_INTENCRL_EW_Msk

#define WDT_INTENSET_EW_Pos        (0U)
#define WDT_INTENSET_EW_Msk        (0x1 << WDT_INTENSET_EW_Pos)
#define WDT_INTENSET_EW            WDT_INTENSET_EW_Msk

#define WDT_INTFLAG_EW_Pos         (0U)
#define WDT_INTFLAG_EW_Msk         (0x1 << WDT_INTFLAG_EW_Pos)
#define WDT_INTFLAG_EW             WDT_INTFLAG_EW_Msk

#define WDT_STATUS_SYNCBUSY_Pos    (7U)
#define WDT_STATUS_SYNCBUSY_Msk    (0x1 << WDT_STATUS_SYNCBUSY_Pos)
#define WDT_STATUS_SYNCBUSY        WDT_STATUS_SYNCBUSY_Msk

#define WDT_CLEAR_CLEAR_Pos        (7U)
#define WDT_CLEAR_CLEAR_Msk        (0x1 << WDT_CLEAR_CLEAR_Pos)
#define WDT_CLEAR_CLEAR            WDT_CLEAR_CLEAR_Msk


#define WDT_CLEAR_KEY                                 0xA5

#define WDT_MODE_TIMEOUT_8                            0x0
#define WDT_MODE_TIMEOUT_16                           0x1
#define WDT_MODE_TIMEOUT_32                           0x2
#define WDT_MODE_TIMEOUT_62                           0x3
#define WDT_MODE_TIMEOUT_128                          0x4
#define WDT_MODE_TIMEOUT_256                          0x5
#define WDT_MODE_TIMEOUT_512                          0x6
#define WDT_MODE_TIMEOUT_1K                           0x7
#define WDT_MODE_TIMEOUT_2K                           0x8
#define WDT_MODE_TIMEOUT_4K                           0x9
#define WDT_MODE_TIMEOUT_8K                           0xA
#define WDT_MODE_TIMEOUT_16K                          0xB

#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_8     0x0
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_16    0x1
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_32    0x2
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_64    0x3
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_128   0x4
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_256   0x5
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_512   0x6
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_1K    0x7
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_2K    0x8
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_4K    0x9
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_8K    0xA
#define WDT_EARLY_WARNING_INTERRUPT_TIME_OFFSET_16K   0xB

#endif  /* SAMD10D14AM */
