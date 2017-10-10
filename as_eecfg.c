/*
 * as_eecfg.c
 *
 * */
#include "ee.h"
#include "as_eecfg.h"
#include "ee_internal.h"
/**Stack definitions**/
#define STACK_1_SIZE 512
#define STACK_2_SIZE 512

//EE_STACK_T EE_STACK_ATTRIB EE_as_stack_1[EE_STACK_WLEN(STACK_1_SIZE)];
#ifdef ENABLE_STANDARD_TASKS

/**Task body definitions.*/
const EE_THREAD_PTR EE_hal_thread_body[EE_MAX_TASK] = {
    &EE_oo_thread_stub,
    &EE_oo_thread_stub,
    &EE_oo_thread_stub,
    &EE_oo_thread_stub,
    &EE_oo_thread_stub,
    &EE_oo_thread_stub
};

const EE_THREAD_PTR EE_terminate_real_th_body[EE_MAX_TASK] = {
  &FuncTask1,
  &FuncTask2,
  &FuncTask3,
  &FuncTask4,
  &FuncTask5,
  &FuncTask6
};

/**task priorities**/
const EE_TYPEPRIO EE_th_ready_prio[EE_MAX_TASK] = {
    0x1U,
    0x2U,
    0x3U,
    0x4U,
    0x5U,
    0x6U
};


/**Indicates task precedence.**/
EE_TID EE_th_next[EE_MAX_TASK] = {
    EE_NIL,
    EE_NIL,
    EE_NIL,
    EE_NIL,
    EE_NIL,
    EE_NIL
};
#endif
/**First stacked task.**/
//EE_TID EE_stkfirst = EE_NIL;

/**Indicates active system criticality**/
EE_TYPECRIT EE_sys_criticality = 0x00U;

//EE_TID EE_rq_first = EE_NIL; /*Indicates run queue head.*/
/******************************************************************************************************************/
/*                      COUNTERS
/******************************************************************************************************************/

/*System timer definition*/
const EE_oo_counter_ROM_type EE_counter_ROM[EE_COUNTER_ROM_SIZE] = {
        2147483647U,
        1U,
        1U
};

 EE_oo_counter_RAM_type EE_counter_RAM[EE_MAX_COUNTER] = {
        0U,
        (EE_TYPECOUNTEROBJECT)-1
};

/*** Data structure representing counter object. ***/
const EE_oo_counter_object_ROM_type EE_oo_counter_object_ROM[EE_COUNTER_OBJECTS_ROM_SIZE] = {
/*Counter name      Counter object      Counter Kind*/
    {system_timer,    SchedTab1,        EE_SCHEDULETABLE},
    {system_timer,    SchedTab2,        EE_SCHEDULETABLE}
};

EE_oo_counter_object_RAM_type EE_oo_counter_object_RAM[EE_COUNTER_OBJECTS_ROM_SIZE];

/**Counter object action representation. **/
const EE_oo_action_ROM_type EE_oo_action_ROM[EE_ACTION_ROM_SIZE] = {
/*Action-Kind        Action-Task     Action-Mask     Callback               Counter-to-increment*/
    {EE_ACTION_TASK, Task1,             0U,         (EE_VOID_CALLBACK)NULL,     INVALID_COUNTER},
    {EE_ACTION_TASK, Task2,             0U,         (EE_VOID_CALLBACK)NULL,     INVALID_COUNTER},
    {EE_ACTION_TASK, Task3,             0U,         (EE_VOID_CALLBACK)NULL,     INVALID_COUNTER},
    {EE_ACTION_TASK, Task4,             0U,         (EE_VOID_CALLBACK)NULL,     INVALID_COUNTER},
    {EE_ACTION_TASK, Task5,             0U,         (EE_VOID_CALLBACK)NULL,     INVALID_COUNTER},
    {EE_ACTION_TASK, Task6,             0U,         (EE_VOID_CALLBACK)NULL,     INVALID_COUNTER}
};

/** Expiry point informations.  **/
const EE_as_Expiry_Point_ROM_type EE_as_Expiry_Point_ROM[EE_EXPIRY_POINTS_ROM_SIZE] = {

    /*Offset Action-first Action-last Max-shorten Max-lengthen*/
    {100,       0U,         1U,         0U,         0U},
    {300,       1U,         2U,         0U,         0U},
    {200,       2U,         3U,         0U,         0U},
    {100,       3U,         4U,         0U,         0U},
    {50 ,       4U,         5U,         0U,         0U},
    {200,       5U,         6U,         0U,         0U},
};

/*** Schedule table ROM Definitions. ***/

const EE_as_Schedule_Table_ROM_type EE_as_Schedule_Table_ROM[EE_MAX_SCHEDULETABLE] = {
    /*First-Expiry Second-Expiry         Sync               Duration        Precision                  Repeated  Appid*/
    {0U,            2U,          EE_SCHEDTABLE_SYNC_NONE,    400,       INVALID_SCHEDULETABLE_PRECISION, 0U},
    {3U,            5U,          EE_SCHEDTABLE_SYNC_NONE,    300,       INVALID_SCHEDULETABLE_PRECISION, 0U}
};

/* High mode definition for running schedule table. */
const EE_as_Schedule_Table_ROM_type EE_as_Schedule_Table_ROM_HIGH[EE_MAX_SCHEDULETABLE] = {
    /*First-Expiry Second-Expiry         Sync               Duration        Precision                  Repeated  Appid*/
    {0U,            2U,         EE_SCHEDTABLE_SYNC_NONE,      400,    INVALID_SCHEDULETABLE_PRECISION,   0U},
    {3U,            5U,         EE_SCHEDTABLE_SYNC_NONE,      300,    INVALID_SCHEDULETABLE_PRECISION,   0U}
};

/***Variable information relating to schedule table.***/
EE_as_Schedule_Table_RAM_type EE_as_Schedule_Table_RAM[EE_MAX_SCHEDULETABLE] = {
            /*Status            Position                     Deviation      Next-Table           Mode-of-operation*/
    {SCHEDULETABLE_STOPPED, INVALID_SCHEDULETABLE_POSITION,     0,      INVALID_SCHEDULETABLE,      eLOW},
    {SCHEDULETABLE_STOPPED, INVALID_SCHEDULETABLE_POSITION,     0,      INVALID_SCHEDULETABLE,      eLOW},
    {SCHEDULETABLE_STOPPED, INVALID_SCHEDULETABLE_POSITION,     0,      INVALID_SCHEDULETABLE,      eLOW}
};

const EE_as_tp_RAM_ref EE_as_tp_RAM_refs[EE_MAX_TASK + EE_MAX_ISR_ID];
const EE_as_tp_ROM_const_ref EE_as_tp_ROM_refs[EE_MAX_TASK + EE_MAX_ISR_ID];
const EE_as_tp_budget_conf_type EE_as_tp_budget_confs[EE_MAX_TIMING_BUDGET];
EE_as_tp_budget_data_type EE_as_tp_budget_data[EE_MAX_TIMING_BUDGET];

EE_UREG EE_cortex_rx_active_tos;
struct EE_TOS  EE_cortex_rx_system_tos[EE_MAX_TASK];
const EE_UREG  EE_std_thread_tos[EE_MAX_TASK + 1];

/*****Schedule table auto start setup******/
static const EE_as_schedule_table_autostart_data EE_as_autostart_schedule_table_mode_OSDEFAULTAPPMODE[EE_AS_AUTOSTART_SCHEDULE_TABLE_MODE_OSDEFAULTAPPMODE_SIZE] = {
    {SchedTab1, EE_ST_START_ABSOLUTE, 0U}
};

const EE_as_schedule_table_autostart_type EE_as_schedule_table_autostart[EE_MAX_APPMODE] = {
    {1U, EE_as_autostart_schedule_table_mode_OSDEFAULTAPPMODE}
};
