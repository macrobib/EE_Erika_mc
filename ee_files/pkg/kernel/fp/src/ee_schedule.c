/* ###*B*###
 * ERIKA Enterprise - a tiny RTOS for small microcontrollers
 *
 * Copyright (C) 2002-2008  Evidence Srl
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
 * Author: 2001 Paolo Gai
 * CVS: $Id: ee_schedule.c,v 1.6 2006/12/03 22:04:56 pj Exp $
 */

#include "ee_internal.h"
#include "../inc/ee_kernel.h"

#ifndef __PRIVATE_SCHEDULER__
int EE_current_tick  = 0;
int EE_fp_next_overrun = 0;

void EE_fp_Schedule(void)
{
  register EE_TID t, current;

  register EE_FREG np_flags;
  np_flags = EE_hal_begin_nested_primitive();

  t = EE_rq_queryfirst();

  if (t != EE_NIL) {
    current = EE_stk_queryfirst();
    if (EE_th_ready_prio[current] < EE_th_ready_prio[t]) {
      /* we have to schedule a ready task */
#if defined(__MULTI__)
      register int flag;

      flag = EE_th_status[t] & EE_WASSTACKED;
#endif
/*MC Change: In addition to calculating the preemption priority of the task, 
 * check if the task is eligible to run (budget high set to -1 says ineligible.
 * */
      EE_sys_ceiling &= ~EE_th_dispatch_prio[current];
      EE_sys_ceiling |= EE_th_ready_prio[current];
      EE_sys_ceiling |= EE_th_dispatch_prio[t];

#if defined(__MULTI__) || defined(__WITH_STATUS__)
      EE_th_status[t] = EE_STACKED;
#endif

#if defined(__MULTI__)
      if (flag)
	EE_hal_stkchange(EE_rq2stk_exchange());
      else
	EE_hal_ready2stacked(EE_rq2stk_exchange());
#else
      EE_hal_ready2stacked(EE_rq2stk_exchange());
#endif

      EE_sys_ceiling &= ~EE_th_ready_prio[current];
      EE_sys_ceiling |= EE_th_dispatch_prio[current];
    }
  }
  
  EE_hal_end_nested_primitive(np_flags);
}

/*Task to monitor budget usage, budget overrun and initiate criticality
 * Event based timer or tick based.? 
 * transition of required.*/
void EE_fp_Sched_Monitor_Budget(void){
  /*Check for time tick wrap*/
  if(EE_fp_next_overrun >= EE_current_tick){
      EE_fp_HandleOverrun();
  }  
}

/*When the task is executed in extended mode, it should relenquish the CPU
 * by calling EE_fp_Sched_Yield to notify of its complition. This will reset
 * the criticality monitor time, mark the current task as not running
 * and set the next release of the task.
 * */
void EE_fp_Sched_Yield(void){
      
}

void EE_fp_Sched_MonitorRelease(void){

}

void EE_fp_HandleOverrun(void){
    /*Handle the overrun scenario.*/
}

#endif
