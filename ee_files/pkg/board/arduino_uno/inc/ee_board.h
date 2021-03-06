/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2014  Evidence Srl
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

/*
 * Author: 2012 Pasquale Buonocunto
 * 	   2014 Giuseppe Serano
 */

#ifndef __INCLUDE_ARDUINO_BOARD_H__
#define __INCLUDE_ARDUINO_BOARD_H__

#ifdef	__ATMEGA328__
#include "mcu/atmel_atmega328/inc/ee_mcu.h"
#endif	/* __ATMEGA328__ */

#ifdef	__ATMEGA__
#include "mcu/atmel_atmega/inc/ee_mcu.h"
#endif	/* __ATMEGA__ */

/*************************************************************************
 BOARD
 *************************************************************************/

__INLINE__ void EE_board_init(void)
{
  EE_arduino_uno_board_init();
}


/*************************************************************************
 LED
 *************************************************************************/

#ifdef	__LED_USED__

/* On ARDUINO there are 3 leds connected through IO Port A */


__INLINE__ void EE_led_on(void) 
{
  EE_arduino_uno_led_on();
}

__INLINE__ void EE_led_off(void) 
{
  EE_arduino_uno_led_off();
}

__INLINE__ void EE_led_toggle(void) 
{
  EE_arduino_uno_led_toggle();
}


#endif	/* __LED_USED__ */

#endif
