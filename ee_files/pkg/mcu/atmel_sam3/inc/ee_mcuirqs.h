/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2013  Evidence Srl
 *
 * This file is part of ERIKA Enterprise.
 *
 * ERIKA Enterprise is free software; you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation,
 * (with a special exception described below).
 *
 * Linking this code statically or dynamically with other modules is
 * making a combined work based on this code.  Thus, the terms and
 * conditions of the GNU General Public License cover the whole
 * combination.
 *
 * As a special exception, the copyright holders of this library give you
 * permission to link this code with independent modules to produce an
 * executable, regardless of the license terms of these independent
 * modules, and to copy and distribute the resulting executable under
 * terms of your choice, provided that you also meet, for each linked
 * independent module, the terms and conditions of the license of that
 * module.  An independent module is a module which is not derived from
 * or based on this library.  If you modify this code, you may extend
 * this exception to your version of the code, but you are not
 * obligated to do so.  If you do not wish to do so, delete this
 * exception statement from your version.
 *
 * ERIKA Enterprise is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with ERIKA Enterprise; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 * ###*E*### */

/** 
 *  @file	ee_irq.h
 *  @brief	MCU IRQ Sources.
 *  @author	Giuseppe Serano
 *  @date	2011
 */ 

/* MM: Check!!! */
#ifndef __INCLUDE_ATMEL_SAM3_IRQ_SOURCES_H__
#define __INCLUDE_ATMEL_SAM3_IRQ_SOURCES_H__

/* MM: To be rewritten with SAM3 vector table!!! */
#warning Wrong vector table match

#if defined( __ATMEL_SAM3__ )


#ifdef	EE_CORTEX_MX_WWDG_ISR
#define	EE_CORTEX_MX_INT_00_ISR		EE_CORTEX_MX_WWDG_ISR
#ifdef	EE_CORTEX_MX_WWDG_ISR_PRI
#define	EE_CORTEX_MX_INT_00_ISR_PRI	EE_CORTEX_MX_WWDG_ISR_PRI
#endif	/* EE_CORTEX_MX_WWDG_ISR_PRI */
#endif	/* EE_CORTEX_MX_WWDG_ISR */


#ifdef	EE_CORTEX_MX_PVD_ISR
#define	EE_CORTEX_MX_INT_01_ISR		EE_CORTEX_MX_PVD_ISR
#ifdef	EE_CORTEX_MX_PVD_ISR_PRI
#define	EE_CORTEX_MX_INT_01_ISR_PRI	EE_CORTEX_MX_PVD_ISR_PRI
#endif	/* EE_CORTEX_MX_PVD_ISR_PRI */
#endif	/* EE_CORTEX_MX_PVD_ISR */


#ifdef	EE_CORTEX_MX_TAMP_STAMP_ISR
#define	EE_CORTEX_MX_INT_02_ISR		EE_CORTEX_MX_TAMP_STAMP_ISR
#ifdef	EE_CORTEX_MX_TAMP_STAMP_ISR_PRI
#define	EE_CORTEX_MX_INT_02_ISR_PRI	EE_CORTEX_MX_TAMP_STAMP_ISR_PRI
#endif	/* EE_CORTEX_MX_TAMP_STAMP_ISR_PRI */
#endif	/* EE_CORTEX_MX_TAMP_STAMP_ISR */


#ifdef	EE_CORTEX_MX_RTC_WKUP_ISR
#define	EE_CORTEX_MX_INT_03_ISR		EE_CORTEX_MX_RTC_WKUP_ISR
#ifdef	EE_CORTEX_MX_RTC_WKUP_ISR_PRI
#define	EE_CORTEX_MX_INT_03_ISR_PRI	EE_CORTEX_MX_RTC_WKUP_ISR_PRI
#endif	/* EE_CORTEX_MX_RTC_WKUP_ISR_PRI */
#endif	/* EE_CORTEX_MX_RTC_WKUP_ISR */


#ifdef	EE_CORTEX_MX_FLASH_ISR
#define	EE_CORTEX_MX_INT_04_ISR		EE_CORTEX_MX_FLASH_ISR
#ifdef	EE_CORTEX_MX_FLASH_ISR_PRI
#define	EE_CORTEX_MX_INT_04_ISR_PRI	EE_CORTEX_MX_FLASH_ISR_PRI
#endif	/* EE_CORTEX_MX_FLASH_ISR_PRI */
#endif	/* EE_CORTEX_MX_FLASH_ISR */


#ifdef	EE_CORTEX_MX_RCC_ISR
#define	EE_CORTEX_MX_INT_05_ISR		EE_CORTEX_MX_RCC_ISR
#ifdef	EE_CORTEX_MX_RCC_ISR_PRI
#define	EE_CORTEX_MX_INT_05_ISR_PRI	EE_CORTEX_MX_RCC_ISR_PRI
#endif	/* EE_CORTEX_MX_RCC_ISR_PRI */
#endif	/* EE_CORTEX_MX_RCC_ISR */


#ifdef	EE_CORTEX_MX_EXTI0_ISR
#define	EE_CORTEX_MX_INT_06_ISR		EE_CORTEX_MX_EXTI0_ISR
#ifdef	EE_CORTEX_MX_EXTI0_ISR_PRI
#define	EE_CORTEX_MX_INT_06_ISR_PRI	EE_CORTEX_MX_EXTI0_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI0_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI0_ISR */


#ifdef	EE_CORTEX_MX_EXTI1_ISR
#define	EE_CORTEX_MX_INT_07_ISR		EE_CORTEX_MX_EXTI1_ISR
#ifdef	EE_CORTEX_MX_EXTI1_ISR_PRI
#define	EE_CORTEX_MX_INT_07_ISR_PRI	EE_CORTEX_MX_EXTI1_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI1_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI1_ISR */


#ifdef	EE_CORTEX_MX_EXTI2_ISR
#define	EE_CORTEX_MX_INT_08_ISR		EE_CORTEX_MX_EXTI2_ISR
#ifdef	EE_CORTEX_MX_EXTI2_ISR_PRI
#define	EE_CORTEX_MX_INT_08_ISR_PRI	EE_CORTEX_MX_EXTI2_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI2_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI2_ISR */


#ifdef	EE_CORTEX_MX_EXTI3_ISR
#define	EE_CORTEX_MX_INT_09_ISR		EE_CORTEX_MX_EXTI3_ISR
#ifdef	EE_CORTEX_MX_EXTI3_ISR_PRI
#define	EE_CORTEX_MX_INT_09_ISR_PRI	EE_CORTEX_MX_EXTI3_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI3_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI3_ISR */


#ifdef	EE_CORTEX_MX_EXTI4_ISR
#define	EE_CORTEX_MX_INT_0A_ISR		EE_CORTEX_MX_EXTI4_ISR
#ifdef	EE_CORTEX_MX_EXTI4_ISR_PRI
#define	EE_CORTEX_MX_INT_0A_ISR_PRI	EE_CORTEX_MX_EXTI4_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI4_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI4_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM0_ISR
#define	EE_CORTEX_MX_INT_0B_ISR		EE_CORTEX_MX_DMA1_STREAM0_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM0_ISR_PRI
#define	EE_CORTEX_MX_INT_0B_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM0_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM0_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM0_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM1_ISR
#define	EE_CORTEX_MX_INT_0C_ISR		EE_CORTEX_MX_DMA1_STREAM1_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM1_ISR_PRI
#define	EE_CORTEX_MX_INT_0C_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM1_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM1_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM1_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM2_ISR
#define	EE_CORTEX_MX_INT_0D_ISR		EE_CORTEX_MX_DMA1_STREAM2_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM2_ISR_PRI
#define	EE_CORTEX_MX_INT_0D_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM2_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM2_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM2_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM3_ISR
#define	EE_CORTEX_MX_INT_0E_ISR		EE_CORTEX_MX_DMA1_STREAM3_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM3_ISR_PRI
#define	EE_CORTEX_MX_INT_0E_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM3_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM3_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM3_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM4_ISR
#define	EE_CORTEX_MX_INT_0F_ISR		EE_CORTEX_MX_DMA1_STREAM4_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM4_ISR_PRI
#define	EE_CORTEX_MX_INT_0F_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM4_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM4_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM4_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM5_ISR
#define	EE_CORTEX_MX_INT_10_ISR		EE_CORTEX_MX_DMA1_STREAM5_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM5_ISR_PRI
#define	EE_CORTEX_MX_INT_10_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM5_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM5_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM5_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM6_ISR
#define	EE_CORTEX_MX_INT_11_ISR		EE_CORTEX_MX_DMA1_STREAM6_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM6_ISR_PRI
#define	EE_CORTEX_MX_INT_11_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM6_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM6_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM6_ISR */


#ifdef	EE_CORTEX_MX_ADC_ISR
#define	EE_CORTEX_MX_INT_12_ISR		EE_CORTEX_MX_ADC_ISR
#ifdef	EE_CORTEX_MX_ADC_ISR_PRI
#define	EE_CORTEX_MX_INT_12_ISR_PRI	EE_CORTEX_MX_ADC_ISR_PRI
#endif	/* EE_CORTEX_MX_ADC_ISR_PRI */
#endif	/* EE_CORTEX_MX_ADC_ISR */


#ifdef	EE_CORTEX_MX_CAN1_TX_ISR
#define	EE_CORTEX_MX_INT_13_ISR		EE_CORTEX_MX_INT_0_ISR
#ifdef	EE_CORTEX_MX_CAN1_TX_ISR_PRI
#define	EE_CORTEX_MX_INT_13_ISR_PRI	EE_CORTEX_MX_CAN1_TX_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN1_TX_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN1_TX_ISR */


#ifdef	EE_CORTEX_MX_CAN1_RX0_ISR
#define	EE_CORTEX_MX_INT_14_ISR		EE_CORTEX_MX_INT_0_ISR
#ifdef	EE_CORTEX_MX_CAN1_RX0_ISR_PRI
#define	EE_CORTEX_MX_INT_14_ISR_PRI	EE_CORTEX_MX_CAN1_RX0_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN1_RX0_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN1_RX0_ISR */


#ifdef	EE_CORTEX_MX_CAN1_RX1_ISR
#define	EE_CORTEX_MX_INT_15_ISR		EE_CORTEX_MX_CAN1_RX1_ISR
#ifdef	EE_CORTEX_MX_CAN1_RX1_ISR_PRI
#define	EE_CORTEX_MX_INT_15_ISR_PRI	EE_CORTEX_MX_CAN1_RX1_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN1_RX1_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN1_RX1_ISR */


#ifdef	EE_CORTEX_MX_CAN1_SCE_ISR
#define	EE_CORTEX_MX_INT_16_ISR		EE_CORTEX_MX_CAN1_SCE_ISR
#ifdef	EE_CORTEX_MX_CAN1_SCE_ISR_PRI
#define	EE_CORTEX_MX_INT_16_ISR_PRI	EE_CORTEX_MX_CAN1_SCE_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN1_SCE_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN1_SCE_ISR */


#ifdef	EE_CORTEX_MX_EXTI9_5_ISR
#define	EE_CORTEX_MX_INT_17_ISR		EE_CORTEX_MX_EXTI9_5_ISR
#ifdef	EE_CORTEX_MX_EXTI9_5_ISR_PRI
#define	EE_CORTEX_MX_INT_17_ISR_PRI	EE_CORTEX_MX_EXTI9_5_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI9_5_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI9_5_ISR */


#ifdef	EE_CORTEX_MX_TIM1_BRK_TIM9_ISR
#define	EE_CORTEX_MX_INT_18_ISR		EE_CORTEX_MX_TIM1_BRK_TIM9_ISR
#ifdef	EE_CORTEX_MX_TIM1_BRK_TIM9_ISR_PRI
#define	EE_CORTEX_MX_INT_18_ISR_PRI	EE_CORTEX_MX_TIM1_BRK_TIM9_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM1_BRK_TIM9_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM1_BRK_TIM9_ISR */


#ifdef	EE_CORTEX_MX_TIM1_UP_TIM10_ISR
#define	EE_CORTEX_MX_INT_19_ISR		EE_CORTEX_MX_TIM1_UP_TIM10_ISR
#ifdef	EE_CORTEX_MX_TIM1_UP_TIM10_ISR_PRI
#define	EE_CORTEX_MX_INT_19_ISR_PRI	EE_CORTEX_MX_TIM1_UP_TIM10_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM1_UP_TIM10_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM1_UP_TIM10_ISR */


#ifdef	EE_CORTEX_MX_TIM1_TRG_COM_TIM11_ISR
#define	EE_CORTEX_MX_INT_1A_ISR		EE_CORTEX_MX_TIM1_TRG_COM_TIM11_ISR
#ifdef	EE_CORTEX_MX_TIM1_TRG_COM_TIM11_ISR_PRI
#define	EE_CORTEX_MX_INT_1A_ISR_PRI	EE_CORTEX_MX_TIM1_TRG_COM_TIM11_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM1_TRG_COM_TIM11_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM1_TRG_COM_TIM11_ISR */


#ifdef	EE_CORTEX_MX_TIM1_CC_ISR
#define	EE_CORTEX_MX_INT_1B_ISR		EE_CORTEX_MX_TIM1_CC_ISR
#ifdef	EE_CORTEX_MX_TIM1_CC_ISR_PRI
#define	EE_CORTEX_MX_INT_1B_ISR_PRI	EE_CORTEX_MX_TIM1_CC_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM1_CC_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM1_CC_ISR */


#ifdef	EE_CORTEX_MX_TIM2_ISR
#define	EE_CORTEX_MX_INT_1C_ISR		EE_CORTEX_MX_TIM2_ISR
#ifdef	EE_CORTEX_MX_TIM2_ISR_PRI
#define	EE_CORTEX_MX_INT_1C_ISR_PRI	EE_CORTEX_MX_TIM2_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM2_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM2_ISR */


#ifdef	EE_CORTEX_MX_TIM3_ISR
#define	EE_CORTEX_MX_INT_1D_ISR		EE_CORTEX_MX_TIM3_ISR
#ifdef	EE_CORTEX_MX_TIM3_ISR_PRI
#define	EE_CORTEX_MX_INT_1D_ISR_PRI	EE_CORTEX_MX_TIM3_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM3_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM3_ISR */


#ifdef	EE_CORTEX_MX_TIM4_ISR
#define	EE_CORTEX_MX_INT_1E_ISR		EE_CORTEX_MX_TIM4_ISR
#ifdef	EE_CORTEX_MX_TIM4_ISR_PRI
#define	EE_CORTEX_MX_INT_1E_ISR_PRI	EE_CORTEX_MX_TIM4_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM4_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM4_ISR */


#ifdef	EE_CORTEX_MX_I2C1_EV_ISR
#define	EE_CORTEX_MX_INT_1F_ISR		EE_CORTEX_MX_I2C1_EV_ISR
#ifdef	EE_CORTEX_MX_I2C1_EV_ISR_PRI
#define	EE_CORTEX_MX_INT_1F_ISR_PRI	EE_CORTEX_MX_I2C1_EV_ISR_PRI
#endif	/* EE_CORTEX_MX_I2C1_EV_ISR_PRI */
#endif	/* EE_CORTEX_MX_I2C1_EV_ISR */


#ifdef	EE_CORTEX_MX_I2C1_ER_ISR
#define	EE_CORTEX_MX_INT_20_ISR		EE_CORTEX_MX_I2C1_ER_ISR
#ifdef	EE_CORTEX_MX_I2C1_ER_ISR_PRI
#define	EE_CORTEX_MX_INT_20_ISR_PRI	EE_CORTEX_MX_I2C1_ER_ISR_PRI
#endif	/* EE_CORTEX_MX_I2C1_ER_ISR_PRI */
#endif	/* EE_CORTEX_MX_I2C1_ER_ISR */


#ifdef	EE_CORTEX_MX_I2C2_EV_ISR
#define	EE_CORTEX_MX_INT_21_ISR		EE_CORTEX_MX_I2C2_EV_ISR
#ifdef	EE_CORTEX_MX_I2C2_EV_ISR_PRI
#define	EE_CORTEX_MX_INT_21_ISR_PRI	EE_CORTEX_MX_I2C2_EV_ISR_PRI
#endif	/* EE_CORTEX_MX_I2C2_EV_ISR_PRI */
#endif	/* EE_CORTEX_MX_I2C2_EV_ISR */


#ifdef	EE_CORTEX_MX_I2C2_ER_ISR
#define	EE_CORTEX_MX_INT_22_ISR		EE_CORTEX_MX_I2C2_ER_ISR
#ifdef	EE_CORTEX_MX_I2C2_ER_ISR_PRI
#define	EE_CORTEX_MX_INT_22_ISR_PRI	EE_CORTEX_MX_I2C2_ER_ISR_PRI
#endif	/* EE_CORTEX_MX_I2C2_ER_ISR_PRI */
#endif	/* EE_CORTEX_MX_I2C2_ER_ISR */


#ifdef	EE_CORTEX_MX_SPI1_ISR
#define	EE_CORTEX_MX_INT_23_ISR		EE_CORTEX_MX_SPI1_ISR
#ifdef	EE_CORTEX_MX_SPI1_ISR_PRI
#define	EE_CORTEX_MX_INT_23_ISR_PRI	EE_CORTEX_MX_SPI1_ISR_PRI
#endif	/* EE_CORTEX_MX_SPI1_ISR_PRI */
#endif	/* EE_CORTEX_MX_SPI1_ISR */


#ifdef	EE_CORTEX_MX_SPI2_ISR
#define	EE_CORTEX_MX_INT_24_ISR		EE_CORTEX_MX_SPI2_ISR
#ifdef	EE_CORTEX_MX_SPI2_ISR_PRI
#define	EE_CORTEX_MX_INT_24_ISR_PRI	EE_CORTEX_MX_SPI2_ISR_PRI
#endif	/* EE_CORTEX_MX_SPI2_ISR_PRI */
#endif	/* EE_CORTEX_MX_SPI2_ISR */


#ifdef	EE_CORTEX_MX_USART1_ISR
#define	EE_CORTEX_MX_INT_25_ISR		EE_CORTEX_MX_USART1_ISR
#ifdef	EE_CORTEX_MX_USART1_ISR_PRI
#define	EE_CORTEX_MX_INT_25_ISR_PRI	EE_CORTEX_MX_USART1_ISR_PRI
#endif	/* EE_CORTEX_MX_USART1_ISR_PRI */
#endif	/* EE_CORTEX_MX_USART1_ISR */


#ifdef	EE_CORTEX_MX_USART2_ISR
#define	EE_CORTEX_MX_INT_26_ISR		EE_CORTEX_MX_USART2_ISR
#ifdef	EE_CORTEX_MX_USART2_ISR_PRI
#define	EE_CORTEX_MX_INT_26_ISR_PRI	EE_CORTEX_MX_USART2_ISR_PRI
#endif	/* EE_CORTEX_MX_USART2_ISR_PRI */
#endif	/* EE_CORTEX_MX_USART2_ISR */


#ifdef	EE_CORTEX_MX_USART3_ISR
#define	EE_CORTEX_MX_INT_27_ISR		EE_CORTEX_MX_USART3_ISR
#ifdef	EE_CORTEX_MX_USART3_ISR_PRI
#define	EE_CORTEX_MX_INT_27_ISR_PRI	EE_CORTEX_MX_USART3_ISR_PRI
#endif	/* EE_CORTEX_MX_USART3_ISR_PRI */
#endif	/* EE_CORTEX_MX_USART3_ISR */


#ifdef	EE_CORTEX_MX_EXTI15_10_ISR
#define	EE_CORTEX_MX_INT_28_ISR		EE_CORTEX_MX_EXTI15_10_ISR
#ifdef	EE_CORTEX_MX_EXTI15_10_ISR_PRI
#define	EE_CORTEX_MX_INT_28_ISR_PRI	EE_CORTEX_MX_EXTI15_10_ISR_PRI
#endif	/* EE_CORTEX_MX_EXTI15_10_ISR_PRI */
#endif	/* EE_CORTEX_MX_EXTI15_10_ISR */


#ifdef	EE_CORTEX_MX_RTC_ALARM_ISR
#define	EE_CORTEX_MX_INT_29_ISR		EE_CORTEX_MX_RTC_ALARM_ISR
#ifdef	EE_CORTEX_MX_RTC_ALARM_ISR_PRI
#define	EE_CORTEX_MX_INT_29_ISR_PRI	EE_CORTEX_MX_RTC_ALARM_ISR_PRI
#endif	/* EE_CORTEX_MX_RTC_ALARM_ISR_PRI */
#endif	/* EE_CORTEX_MX_RTC_ALARM_ISR */


#ifdef	EE_CORTEX_MX_OTG_FS_WKUP_ISR
#define	EE_CORTEX_MX_INT_2A_ISR		EE_CORTEX_MX_OTG_FS_WKUP_ISR
#ifdef	EE_CORTEX_MX_OTG_FS_WKUP_ISR_PRI
#define	EE_CORTEX_MX_INT_2A_ISR_PRI	EE_CORTEX_MX_OTG_FS_WKUP_ISR_PRI
#endif	/* EE_CORTEX_MX_OTG_FS_WKUP_ISR_PRI */
#endif	/* EE_CORTEX_MX_OTG_FS_WKUP_ISR */


#ifdef	EE_CORTEX_MX_TIM8_BRK_TIM12_ISR
#define	EE_CORTEX_MX_INT_2B_ISR		EE_CORTEX_MX_TIM8_BRK_TIM12_ISR
#ifdef	EE_CORTEX_MX_TIM8_BRK_TIM12_ISR_PRI
#define	EE_CORTEX_MX_INT_2B_ISR_PRI	EE_CORTEX_MX_TIM8_BRK_TIM12_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM8_BRK_TIM12_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM8_BRK_TIM12_ISR */


#ifdef	EE_CORTEX_MX_TIM8_UP_TIM13_ISR
#define	EE_CORTEX_MX_INT_2C_ISR		EE_CORTEX_MX_TIM8_UP_TIM13_ISR
#ifdef	EE_CORTEX_MX_TIM8_UP_TIM13_ISR_PRI
#define	EE_CORTEX_MX_INT_2C_ISR_PRI	EE_CORTEX_MX_TIM8_UP_TIM13_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM8_UP_TIM13_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM8_UP_TIM13_ISR */


#ifdef	EE_CORTEX_MX_TIM8_TRG_COM_TIM14_ISR
#define	EE_CORTEX_MX_INT_2D_ISR		EE_CORTEX_MX_TIM8_TRG_COM_TIM14_ISR
#ifdef	EE_CORTEX_MX_TIM8_TRG_COM_TIM14_ISR_PRI
#define	EE_CORTEX_MX_INT_2D_ISR_PRI	EE_CORTEX_MX_TIM8_TRG_COM_TIM14_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM8_TRG_COM_TIM14_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM8_TRG_COM_TIM14_ISR */


#ifdef	EE_CORTEX_MX_TIM8_CC_INT_ISR
#define	EE_CORTEX_MX_INT_2E_ISR		EE_CORTEX_MX_TIM8_CC_INT_ISR
#ifdef	EE_CORTEX_MX_TIM8_CC_INT_ISR_PRI
#define	EE_CORTEX_MX_INT_2E_ISR_PRI	EE_CORTEX_MX_TIM8_CC_INT_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM8_CC_INT_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM8_CC_INT_ISR */


#ifdef	EE_CORTEX_MX_DMA1_STREAM7_ISR
#define	EE_CORTEX_MX_INT_2F_ISR		EE_CORTEX_MX_DMA1_STREAM7_ISR
#ifdef	EE_CORTEX_MX_DMA1_STREAM7_ISR_PRI
#define	EE_CORTEX_MX_INT_2F_ISR_PRI	EE_CORTEX_MX_DMA1_STREAM7_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA1_STREAM7_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA1_STREAM7_ISR */


#ifdef	EE_CORTEX_MX_FSMC_ISR
#define	EE_CORTEX_MX_INT_30_ISR		EE_CORTEX_MX_FSMC_ISR
#ifdef	EE_CORTEX_MX_FSMC_ISR_PRI
#define	EE_CORTEX_MX_INT_30_ISR_PRI	EE_CORTEX_MX_FSMC_ISR_PRI
#endif	/* EE_CORTEX_MX_FSMC_ISR_PRI */
#endif	/* EE_CORTEX_MX_FSMC_ISR */


#ifdef	EE_CORTEX_MX_SDIO_ISR
#define	EE_CORTEX_MX_INT_31_ISR		EE_CORTEX_MX_SDIO_ISR
#ifdef	EE_CORTEX_MX_SDIO_ISR_PRI
#define	EE_CORTEX_MX_INT_31_ISR_PRI	EE_CORTEX_MX_SDIO_ISR_PRI
#endif	/* EE_CORTEX_MX_SDIO_ISR_PRI */
#endif	/* EE_CORTEX_MX_SDIO_ISR */


#ifdef	EE_CORTEX_MX_TIM5_ISR
#define	EE_CORTEX_MX_INT_32_ISR		EE_CORTEX_MX_TIM5_ISR
#ifdef	EE_CORTEX_MX_TIM5_ISR_PRI
#define	EE_CORTEX_MX_INT_32_ISR_PRI	EE_CORTEX_MX_TIM5_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM5_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM5_ISR */


#ifdef	EE_CORTEX_MX_SPI3_ISR
#define	EE_CORTEX_MX_INT_33_ISR		EE_CORTEX_MX_SPI3_ISR
#ifdef	EE_CORTEX_MX_SPI3_ISR_PRI
#define	EE_CORTEX_MX_INT_33_ISR_PRI	EE_CORTEX_MX_SPI3_ISR_PRI
#endif	/* EE_CORTEX_MX_SPI3_ISR_PRI */
#endif	/* EE_CORTEX_MX_SPI3_ISR */


#ifdef	EE_CORTEX_MX_UART4_ISR
#define	EE_CORTEX_MX_INT_34_ISR		EE_CORTEX_MX_UART4_ISR
#ifdef	EE_CORTEX_MX_UART4_ISR_PRI
#define	EE_CORTEX_MX_INT_34_ISR_PRI	EE_CORTEX_MX_UART4_ISR_PRI
#endif	/* EE_CORTEX_MX_UART4_ISR_PRI */
#endif	/* EE_CORTEX_MX_UART4_ISR */


#ifdef	EE_CORTEX_MX_UART5_ISR
#define	EE_CORTEX_MX_INT_35_ISR		EE_CORTEX_MX_UART5_ISR
#ifdef	EE_CORTEX_MX_UART5_ISR_PRI
#define	EE_CORTEX_MX_INT_35_ISR_PRI	EE_CORTEX_MX_UART5_ISR_PRI
#endif	/* EE_CORTEX_MX_UART5_ISR_PRI */
#endif	/* EE_CORTEX_MX_UART5_ISR */


#ifdef	EE_CORTEX_MX_TIM6_DAC_ISR
#define	EE_CORTEX_MX_INT_36_ISR		EE_CORTEX_MX_TIM6_DAC_ISR
#ifdef	EE_CORTEX_MX_TIM6_DAC_ISR_PRI
#define	EE_CORTEX_MX_INT_36_ISR_PRI	EE_CORTEX_MX_TIM6_DAC_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM6_DAC_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM6_DAC_ISR */


#ifdef	EE_CORTEX_MX_TIM7_ISR
#define	EE_CORTEX_MX_INT_37_ISR		EE_CORTEX_MX_TIM7_ISR
#ifdef	EE_CORTEX_MX_TIM7_ISR_PRI
#define	EE_CORTEX_MX_INT_37_ISR_PRI	EE_CORTEX_MX_TIM7_ISR_PRI
#endif	/* EE_CORTEX_MX_TIM7_ISR_PRI */
#endif	/* EE_CORTEX_MX_TIM7_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM0_ISR
#define	EE_CORTEX_MX_INT_38_ISR		EE_CORTEX_MX_DMA2_STREAM0_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM0_ISR_PRI
#define	EE_CORTEX_MX_INT_38_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM0_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM0_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM0_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM1_ISR
#define	EE_CORTEX_MX_INT_39_ISR		EE_CORTEX_MX_DMA2_STREAM1_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM1_ISR_PRI
#define	EE_CORTEX_MX_INT_39_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM1_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM1_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM1_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM2_ISR
#define	EE_CORTEX_MX_INT_3A_ISR		EE_CORTEX_MX_DMA2_STREAM2_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM2_ISR_PRI
#define	EE_CORTEX_MX_INT_3A_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM2_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM2_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM2_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM3_ISR
#define	EE_CORTEX_MX_INT_3B_ISR		EE_CORTEX_MX_DMA2_STREAM3_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM3_ISR_PRI
#define	EE_CORTEX_MX_INT_3B_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM3_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM3_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM3_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM4_ISR
#define	EE_CORTEX_MX_INT_3C_ISR		EE_CORTEX_MX_DMA2_STREAM4_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM4_ISR_PRI
#define	EE_CORTEX_MX_INT_3C_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM4_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM4_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM4_ISR */


#ifdef	EE_CORTEX_MX_ETH_ISR
#define	EE_CORTEX_MX_INT_3D_ISR		EE_CORTEX_MX_ETH_ISR
#ifdef	EE_CORTEX_MX_ETH_ISR_PRI
#define	EE_CORTEX_MX_INT_3D_ISR_PRI	EE_CORTEX_MX_ETH_ISR_PRI
#endif	/* EE_CORTEX_MX_ETH_ISR_PRI */
#endif	/* EE_CORTEX_MX_ETH_ISR */


#ifdef	EE_CORTEX_MX_ETH_WKUP_ISR
#define	EE_CORTEX_MX_INT_3E_ISR		EE_CORTEX_MX_ETH_WKUP_ISR
#ifdef	EE_CORTEX_MX_ETH_WKUP_ISR_PRI
#define	EE_CORTEX_MX_INT_3E_ISR_PRI	EE_CORTEX_MX_ETH_WKUP_ISR_PRI
#endif	/* EE_CORTEX_MX_ETH_WKUP_ISR_PRI */
#endif	/* EE_CORTEX_MX_ETH_WKUP_ISR */


#ifdef	EE_CORTEX_MX_CAN2_TX_ISR
#define	EE_CORTEX_MX_INT_3F_ISR		EE_CORTEX_MX_CAN2_TX_ISR
#ifdef	EE_CORTEX_MX_CAN2_TX_ISR_PRI
#define	EE_CORTEX_MX_INT_3F_ISR_PRI	EE_CORTEX_MX_CAN2_TX_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN2_TX_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN2_TX_ISR */


#ifdef	EE_CORTEX_MX_CAN2_RX0_ISR
#define	EE_CORTEX_MX_INT_40_ISR		EE_CORTEX_MX_CAN2_RX0_ISR
#ifdef	EE_CORTEX_MX_CAN2_RX0_ISR_PRI
#define	EE_CORTEX_MX_INT_40_ISR_PRI	EE_CORTEX_MX_CAN2_RX0_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN2_RX0_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN2_RX0_ISR */


#ifdef	EE_CORTEX_MX_CAN2_RX1_ISR
#define	EE_CORTEX_MX_INT_41_ISR		EE_CORTEX_MX_CAN2_RX1_ISR
#ifdef	EE_CORTEX_MX_CAN2_RX1_ISR_PRI
#define	EE_CORTEX_MX_INT_41_ISR_PRI	EE_CORTEX_MX_CAN2_RX1_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN2_RX1_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN2_RX1_ISR */


#ifdef	EE_CORTEX_MX_CAN2_SCE_ISR
#define	EE_CORTEX_MX_INT_42_ISR		EE_CORTEX_MX_CAN2_SCE_ISR
#ifdef	EE_CORTEX_MX_CAN2_SCE_ISR_PRI
#define	EE_CORTEX_MX_INT_42_ISR_PRI	EE_CORTEX_MX_CAN2_SCE_ISR_PRI
#endif	/* EE_CORTEX_MX_CAN2_SCE_ISR_PRI */
#endif	/* EE_CORTEX_MX_CAN2_SCE_ISR */


#ifdef	EE_CORTEX_MX_OTG_FS_ISR
#define	EE_CORTEX_MX_INT_43_ISR		EE_CORTEX_MX_OTG_FS_ISR
#ifdef	EE_CORTEX_MX_OTG_FS_ISR_PRI
#define	EE_CORTEX_MX_INT_43_ISR_PRI	EE_CORTEX_MX_OTG_FS_ISR_PRI
#endif	/* EE_CORTEX_MX_OTG_FS_ISR_PRI */
#endif	/* EE_CORTEX_MX_OTG_FS_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM5_ISR
#define	EE_CORTEX_MX_INT_44_ISR		EE_CORTEX_MX_DMA2_STREAM5_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM5_ISR_PRI
#define	EE_CORTEX_MX_INT_44_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM5_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM5_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM5_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM6_ISR
#define	EE_CORTEX_MX_INT_45_ISR		EE_CORTEX_MX_DMA2_STREAM6_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM6_ISR_PRI
#define	EE_CORTEX_MX_INT_45_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM6_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM6_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM6_ISR */


#ifdef	EE_CORTEX_MX_DMA2_STREAM7_ISR
#define	EE_CORTEX_MX_INT_46_ISR		EE_CORTEX_MX_DMA2_STREAM7_ISR
#ifdef	EE_CORTEX_MX_DMA2_STREAM7_ISR_PRI
#define	EE_CORTEX_MX_INT_46_ISR_PRI	EE_CORTEX_MX_DMA2_STREAM7_ISR_PRI
#endif	/* EE_CORTEX_MX_DMA2_STREAM7_ISR_PRI */
#endif	/* EE_CORTEX_MX_DMA2_STREAM7_ISR */


#ifdef	EE_CORTEX_MX_USART6_ISR
#define	EE_CORTEX_MX_INT_47_ISR		EE_CORTEX_MX_USART6_ISR
#ifdef	EE_CORTEX_MX_USART6_ISR_PRI
#define	EE_CORTEX_MX_INT_47_ISR_PRI	EE_CORTEX_MX_USART6_ISR_PRI
#endif	/* EE_CORTEX_MX_USART6_ISR_PRI */
#endif	/* EE_CORTEX_MX_USART6_ISR */


#ifdef	EE_CORTEX_MX_I2C3_EV_ISR
#define	EE_CORTEX_MX_INT_48_ISR		EE_CORTEX_MX_I2C3_EV_ISR
#ifdef	EE_CORTEX_MX_I2C3_EV_ISR_PRI
#define	EE_CORTEX_MX_INT_48_ISR_PRI	EE_CORTEX_MX_I2C3_EV_ISR_PRI
#endif	/* EE_CORTEX_MX_I2C3_EV_ISR_PRI */
#endif	/* EE_CORTEX_MX_I2C3_EV_ISR */


#ifdef	EE_CORTEX_MX_I2C3_ER_ISR
#define	EE_CORTEX_MX_INT_49_ISR		EE_CORTEX_MX_I2C3_ER_ISR
#ifdef	EE_CORTEX_MX_I2C3_ER_ISR_PRI
#define	EE_CORTEX_MX_INT_49_ISR_PRI	EE_CORTEX_MX_I2C3_ER_ISR_PRI
#endif	/* EE_CORTEX_MX_I2C3_ER_ISR_PRI */
#endif	/* EE_CORTEX_MX_I2C3_ER_ISR */


#ifdef	EE_CORTEX_MX_OTG_HS_EP1_OUT_ISR
#define	EE_CORTEX_MX_INT_4A_ISR		EE_CORTEX_MX_OTG_HS_EP1_OUT_ISR
#ifdef	EE_CORTEX_MX_OTG_HS_EP1_OUT_ISR_PRI
#define	EE_CORTEX_MX_INT_4A_ISR_PRI	EE_CORTEX_MX_OTG_HS_EP1_OUT_ISR_PRI
#endif	/* EE_CORTEX_MX_OTG_HS_EP1_OUT_ISR_PRI */
#endif	/* EE_CORTEX_MX_OTG_HS_EP1_OUT_ISR */


#ifdef	EE_CORTEX_MX_OTG_HS_EP1_IN_ISR
#define	EE_CORTEX_MX_INT_4B_ISR		EE_CORTEX_MX_OTG_HS_EP1_IN_ISR
#ifdef	EE_CORTEX_MX_OTG_HS_EP1_IN_ISR_PRI
#define	EE_CORTEX_MX_INT_4B_ISR_PRI	EE_CORTEX_MX_OTG_HS_EP1_IN_ISR_PRI
#endif	/* EE_CORTEX_MX_OTG_HS_EP1_IN_ISR_PRI */
#endif	/* EE_CORTEX_MX_OTG_HS_EP1_IN_ISR */


#ifdef	EE_CORTEX_MX_OTG_HS_WKUP_ISR
#define	EE_CORTEX_MX_INT_4C_ISR		EE_CORTEX_MX_OTG_HS_WKUP_ISR
#ifdef	EE_CORTEX_MX_OTG_HS_WKUP_ISR_PRI
#define	EE_CORTEX_MX_INT_4C_ISR_PRI	EE_CORTEX_MX_OTG_HS_WKUP_ISR_PRI
#endif	/* EE_CORTEX_MX_OTG_HS_WKUP_ISR_PRI */
#endif	/* EE_CORTEX_MX_OTG_HS_WKUP_ISR */


#ifdef	EE_CORTEX_MX_OTG_HS_ISR
#define	EE_CORTEX_MX_INT_4D_ISR		EE_CORTEX_MX_OTG_HS_ISR
#ifdef	EE_CORTEX_MX_OTG_HS_ISR_PRI
#define	EE_CORTEX_MX_INT_4D_ISR_PRI	EE_CORTEX_MX_OTG_HS_ISR_PRI
#endif	/* EE_CORTEX_MX_OTG_HS_ISR_PRI */
#endif	/* EE_CORTEX_MX_OTG_HS_ISR */


#ifdef	EE_CORTEX_MX_DCMI_ISR
#define	EE_CORTEX_MX_INT_4E_ISR		EE_CORTEX_MX_DCMI_ISR
#ifdef	EE_CORTEX_MX_DCMI_ISR_PRI
#define	EE_CORTEX_MX_INT_4E_ISR_PRI	EE_CORTEX_MX_DCMI_ISR_PRI
#endif	/* EE_CORTEX_MX_DCMI_ISR_PRI */
#endif	/* EE_CORTEX_MX_DCMI_ISR */


#ifdef	EE_CORTEX_MX_CRYP_ISR
#define	EE_CORTEX_MX_INT_4F_ISR		EE_CORTEX_MX_CRYP_ISR
#ifdef	EE_CORTEX_MX_CRYP_ISR_PRI
#define	EE_CORTEX_MX_INT_4F_ISR_PRI	EE_CORTEX_MX_CRYP_ISR_PRI
#endif	/* EE_CORTEX_MX_CRYP_ISR_PRI */
#endif	/* EE_CORTEX_MX_CRYP_ISR */


#ifdef	EE_CORTEX_MX_HASH_RNG_ISR
#define	EE_CORTEX_MX_INT_50_ISR		EE_CORTEX_MX_HASH_RNG_ISR
#ifdef	EE_CORTEX_MX_HASH_RNG_ISR_PRI
#define	EE_CORTEX_MX_INT_50_ISR_PRI	EE_CORTEX_MX_HASH_RNG_ISR_PRI
#endif	/* EE_CORTEX_MX_HASH_RNG_ISR_PRI */
#endif	/* EE_CORTEX_MX_HASH_RNG_ISR */


#ifdef	EE_CORTEX_MX_FPU_M4_ISR
#define	EE_CORTEX_MX_INT_51_ISR		EE_CORTEX_MX_FPU_M4_ISR
#ifdef	EE_CORTEX_MX_FPU_M4_ISR_PRI
#define	EE_CORTEX_MX_INT_51_ISR_PRI	EE_CORTEX_MX_FPU_M4_ISR_PRI
#endif	/* EE_CORTEX_MX_FPU_M4_ISR_PRI */
#endif	/* EE_CORTEX_MX_FPU_M4_ISR */


#endif	/* __ATMEL_SAM3__ */

#endif /* __INCLUDE_ATMEL_SAM3_IRQ_SOURCES_H__ */
