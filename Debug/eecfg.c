#include "ee.h"


    
    DeclareTask(Task1);
    DeclareTask(Task2);
    DeclareTask(Task3);
    DeclareTask(Task4);
    DeclareTask(Task5);
    DeclareTask(Task6);

    const EE_THREAD_PTR EE_hal_thread_body[EE_MAX_TASK] = {
        &EE_oo_thread_stub,		 
        &EE_oo_thread_stub,		 
        &EE_oo_thread_stub,		 
        &EE_oo_thread_stub,		 
        &EE_oo_thread_stub,		 
        &EE_oo_thread_stub 		 

    };

    EE_UINT32 EE_terminate_data[EE_MAX_TASK];

    
    const EE_THREAD_PTR EE_terminate_real_th_body[EE_MAX_TASK] = {
        &FuncTask1,
        &FuncTask2,
        &FuncTask3,
        &FuncTask4,
        &FuncTask5,
        &FuncTask6
    };
    
    const EE_TYPEPRIO EE_th_ready_prio[EE_MAX_TASK] = {
        0x1U,		 
        0x2U,		 
        0x2U,		 
        0x2U,		 
        0x2U,		 
        0x2U 		 
    };

    const EE_TYPEPRIO EE_th_dispatch_prio[EE_MAX_TASK] = {
        0x1U,		 
        0x2U,		 
        0x2U,		 
        0x2U,		 
        0x2U,		 
        0x2U 		 
    };

    
    EE_TYPESTATUS EE_th_status[EE_MAX_TASK] = {
        SUSPENDED,
        SUSPENDED,
        SUSPENDED,
        SUSPENDED,
        SUSPENDED,
        SUSPENDED
    };

    
    EE_TID EE_th_next[EE_MAX_TASK] = {
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL,
        EE_NIL
    };

    
    EE_TID EE_stkfirst = EE_NIL;

    
    EE_TYPEPRIO EE_sys_ceiling= 0x0000U;

    
    
    EE_TYPENACT   EE_th_rnact[EE_MAX_TASK] =
        { 1U, 1U, 1U, 1U, 1U, 1U};

    
    EE_TID EE_rq_first  = EE_NIL;

    #ifndef __OO_NO_CHAINTASK__
        
        EE_TID EE_th_terminate_nextask[EE_MAX_TASK] = {
            EE_NIL,
            EE_NIL,
            EE_NIL,
            EE_NIL,
            EE_NIL,
            EE_NIL
        };
    #endif


    EE_TYPEEVENTMASK EE_th_event_active[EE_MAX_TASK] =
        { 0U, 0U, 0U, 0U, 0U, 0U};    

    EE_TYPEEVENTMASK EE_th_event_waitmask[EE_MAX_TASK] =
        { 0U, 0U, 0U, 0U, 0U, 0U};    

    EE_TYPEBOOL EE_th_waswaiting[EE_MAX_TASK] =
        { EE_FALSE, EE_FALSE, EE_FALSE, EE_FALSE, EE_FALSE, EE_FALSE};

    const EE_TYPEBOOL EE_th_is_extended[EE_MAX_TASK] =
        { EE_FALSE, EE_FALSE, EE_FALSE, EE_FALSE, EE_FALSE, EE_FALSE};


    EE_TYPEAPPMODE EE_ApplicationMode;

    static const EE_TID EE_oo_autostart_task_mode_OSDEFAULTAPPMODE[EE_OO_AUTOSTART_TASK_MODE_OSDEFAULTAPPMODE_SIZE] = 
        { Task1, Task2, Task3, Task4, Task5, Task6 };

    const struct EE_oo_autostart_task_type EE_oo_autostart_task_data[EE_MAX_APPMODE] = {
        { 6U, (const EE_TID (*)[])&EE_oo_autostart_task_mode_OSDEFAULTAPPMODE}
    };

