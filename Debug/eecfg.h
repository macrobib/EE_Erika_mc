#ifndef EECFG_H
#define EECFG_H


#define RTDRUID_CONFIGURATOR_NUMBER 1278



    
    #define EE_MAX_TASK 6
    #define Task1 0
    #define Task2 1
    #define Task3 2
    #define Task4 3
    #define Task5 4
    #define Task6 5
    #define Task7 6
    #define Task8 7

    #define SchedTab1 0
    #define SchedTab2 1

#define system_timer 1

    #define EE_MAX_RESOURCE 0U

    
    #define EE_MAX_ALARM 0U

    
    #define EE_MAX_SCHEDULETABLE 3U

    
    #define EE_MAX_COUNTER_OBJECTS (EE_MAX_ALARM + EE_MAX_SCHEDULETABLE)

    
    #define EE_CPU_CLOCK      180000000U

    
    #define EE_MAX_COUNTER 1U

    
    #define EE_MAX_APPMODE 1U

    
    #define EE_MAX_CPU 1
    #define EE_CURRENTCPU 0

    
    #define EE_MAX_ISR2   0
    #define EE_MAX_ISR_ID 0

#ifndef __DISABLE_EEOPT_DEFINES__

#define __USE_SYSTICK__
#define __USE_USER_LED__
#define __TI_DRIVER_LIB__
#define __ALLOW_NESTED_IRQ__
#define __USE_DISPLAY__
#define ENABLE_SYSTEM_TIMER
#define EE_AS_SCHEDULETABLES__
#define EE_TIMING_PROTECTION__

#define __RTD_CYGWIN__
#define __OO_ECC1__
#define __OO_EXTENDED_STATUS__
#define __OO_HAS_ERRORHOOK__
#define __MULTI__
#define __OO_NO_ALARMS__
#define __OO_NO_RESOURCES__
#define __OO_NO_EVENTS__
#define __OO_AUTOSTART_TASK__
#define __ALLOW_NESTED_IRQ__
#define EE_AS_HAS_PROTECTIONHOOK__

#endif


    #define EE_OO_AUTOSTART_TASK_MODE_OSDEFAULTAPPMODE_SIZE 6


#endif

