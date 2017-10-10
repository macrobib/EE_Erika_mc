#include "ee_mc_data.h"
#include "ee.h"
#include "ee_irq.h"
#include "test/assert/inc/ee_assert.h"
//#include "ee_as_timing_prot.h"

/*Directly use PCU registers during testing stages.*/
#ifdef ENABLE_NATIVE_MEASUREMENT
#include "sys_pmu.h"

#define TSIZE2 18
volatile unsigned long cycles_PMU_start, cycles_PMU_measure;
uint8 buffer[20] = {0};
int i_updated = 0;
uint8 SPACE[3] = {' ', '\n', '\r'};/* Separataion characters.*/
uint8 OS_START_MES[TSIZE2] = {'O', 'S', ' ', 'S', 'T', 'A', 'R', 'T', ' '};

/**PMU Measurement APIs.**/
inline void init_time_measurement(){
    _pmuEnableCountersGlobal_();
    _pmuSetCountEvent_(pmuCOUNTER0);
    cycles_PMU_start = _pmuGetEventCount_(pmuCOUNTER0);
}

inline void start_timer(void){
    cycles_PMU_start = 0;
    cycles_PMU_end = 0;
    _pmuStartCounters_(pmuCOUNTER0);
    cycles_PMU_start  =_pmuGetEventCount_(pmuCOUNTER0);
}

inline void stop_timer(void){
    _pmuStopCounters_(pmuCOUNTER0);
    cycles_PMU_measure = (_pmuGetEventCount_(pmuCOUNTER0) - cycles_PMU_start)/180;
    sprintf(&buffer[0], "%ld", cycles_PMU_measure);
}

#endif


/****Protection and Error Hooks****/
ProtectionReturnType ProtectionHook(StatusType Error){
    return PRO_IGNORE;
}

void ErrorHook(StatusType Error){
    return ;
}

#define EE_MAX_ASSERTIONS 10
EE_TYPEASSERTVALUE EE_assertions[EE_MAX_ASSERTIONS];
DeclareEvent(TimerEvent);
DeclareEvent(ButtonEvent);
unsigned char volatile  cycle_stop;
TickType      volatile  g_remaning_budget;

unsigned int volatile assert_count = EE_ASSERT_NIL;

void __NEVER_INLINE__ test_assert(int test)
{
  register int next_assert;
  next_assert = (assert_count == EE_ASSERT_NIL) ? 1 : assert_count + 1;
//  EE_assert(next_assert, test, EE_ASSERT_NIL);
  assert_count = next_assert;
}

void ShutdownHook ( StatusType Error ) {
  TickType loc_remaining_budget = 0;

  test_assert( EE_as_tp_active.active_tp == INVALID_TIMING_PROTECTION );
  test_assert( loc_remaining_budget < g_remaning_budget );

#ifdef EE_TEST_FINISHED_WITH_TP_ERROR
  test_assert( Error == E_OS_PROTECTION_LOCKED );
#else /* EE_TEST_FINISHED_WITH_TP_ERROR */
  test_assert( Error == E_OK );
#endif /* EE_TEST_FINISHED_WITH_TP_ERROR */

  EE_assert_range(0, 1, assert_count);
  EE_assert_last();
}


/*Table 1 task.*/
TASK(Task1){

}

/*Table 1 task.*/
TASK(Task2){

}

/***Table-1 task***/
TASK(Task3){

}

/***Table-2 task***/
TASK(Task4){

}

/***Table-2 task***/
TASK(Task5){

}

/***Table-2 task***/
TASK(Task6){

}


/**** Verification table task.****/

TASK(Task7) {
  TickType loc_remaining_budget = 0;

  test_assert( EE_as_tp_active.active_tp == INVALID_TIMING_PROTECTION );
  test_assert( loc_remaining_budget < g_remaning_budget );
  /* If the Reclamation Time Frames Budget is active the TP timer is active in
     any case */

  g_remaning_budget = loc_remaining_budget;

  /* Unlock TaskPrio1 */
  cycle_stop = 1;
  TerminateTask();
}

/**** Verification table task.****/
TASK(Task8) {
  BudgetType            volatile budget_id;
  TimingProtectionType  volatile tp_id;
  TickType              volatile loc_remaining_budget;

  tp_id = EE_as_tp_active.active_tp;
  budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;
  test_assert( budget_id == EE_as_tp_active.
    active_tp_ROM_ref->execution_budget_index );

  test_assert( loc_remaining_budget == EE_as_tp_budget_data[EE_as_tp_active.
    active_tp_ROM_ref->execution_budget_index].remaining_budget );

  g_remaning_budget = loc_remaining_budget;


  {
    TickType local_res_budget;
    /* Get the Res scheduler */
    budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;
    local_res_budget = EE_as_tp_budget_data[budget_id].remaining_budget;
    test_assert( EE_as_tp_budget_confs[budget_id].budget_value >
      local_res_budget );

    /* OS interrupts doesn't exist */
    SuspendOSInterrupts();

    budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;

    test_assert( EE_as_tp_budget_confs[budget_id].budget_value == 
      EE_as_tp_budget_data[budget_id].remaining_budget);

    ResumeOSInterrupts();

    budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;

    test_assert( EE_as_tp_budget_data[budget_id].remaining_budget <
      local_res_budget );

    tp_id = EE_as_tp_active.active_tp;
    budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;

    test_assert( budget_id == EE_as_tp_active.
      active_tp_ROM_ref->execution_budget_index );

    test_assert( loc_remaining_budget == EE_as_tp_budget_data[budget_id].
      remaining_budget );

    g_remaning_budget = loc_remaining_budget;
  }

  while ( !cycle_stop ) {
    ; /* Just wait... */
  }

  tp_id = EE_as_tp_active.active_tp;
  budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;
  test_assert( budget_id == EE_as_tp_active.active_tp_ROM_ref->
    execution_budget_index );
#ifndef EE_AS_OSAPPLICATIONS__
  /* If OSApplication are not used after the tick interrupt the TASk is
     restored without get budget */
  test_assert( loc_remaining_budget == g_remaning_budget );
#else /* !EE_AS_OSAPPLICATIONS__ */
  /* If OSApplication are used EE_as_TerminateISR2 eat some budget! */
  test_assert( loc_remaining_budget < g_remaning_budget );
#endif /* !EE_AS_OSAPPLICATIONS__ */

  g_remaning_budget = loc_remaining_budget;

  tp_id = EE_as_tp_active.active_tp;
  budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;
  test_assert( budget_id == EE_as_tp_active.active_tp_ROM_ref->
    execution_budget_index );

  test_assert( loc_remaining_budget > g_remaning_budget );

  g_remaning_budget = loc_remaining_budget;

#ifdef EE_TEST_FINISHED_WITH_TP_ERROR
  /* Check that this can interrupt a TASK in a CriticalSection */
  DisableAllInterrupts();

  budget_id = EE_as_tp_active.active_tp_RAM_ref->first_expiring;

  test_assert( EE_as_tp_ROM_refs[EE_AS_TP_ID_FROM_TASK(TaskPrio1)]->
    all_isr_lock_budget_index == budget_id );
  test_assert( EE_as_tp_budget_confs[budget_id].budget_value == 
    EE_as_tp_budget_data[budget_id].remaining_budget);

  while ( 1 ) {
    ;
  }
#else  /* EE_TEST_FINISHED_WITH_TP_ERROR */
  ShutdownOS(E_OK);
#endif /* EE_TEST_FINISHED_WITH_TP_ERROR */

  TerminateTask();
}


/*Defined for Performance counter usage.*/
ISR2(rtiCompare0Interrupt){
    StatusType status;
    return status;
}

/***Main entry point.***/
int main( void )
{
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
