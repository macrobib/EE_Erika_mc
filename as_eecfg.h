/*
 * as_eecfg.h
 */

#ifndef AS_EECFG_H_
#define AS_EECFG_H_

//extern const EE_oo_counter_object_ROM_type EE_oo_counter_object_ROM[/*EE_COUNTER_ROM_SIZE*/];
#define EE_AS_AUTOSTART_SCHEDULETABLE__
#define EE_ACTION_ROM_SIZE 6
#define EE_AS_AUTOSTART_SCHEDULE_TABLE_MODE_OSDEFAULTAPPMODE_SIZE 1
#define EE_COUNTER_HW_ROM_SIZE 1
#define EE_COUNTER_OBJECTS_ROM_SIZE 2
#define EE_COUNTER_ROM_SIZE 1
//    #define EE_MAX_COUNTER 2
#define EE_EXPIRY_POINTS_ROM_SIZE 6
//    #define EE_OO_AUTOSTART_TASK_MODE_OSDEFAULTAPPMODE_SIZE 1
#define EE_TC_SYSTEM_TOS_SIZE 2
#define EE_MAX_TIMING_BUDGET 10U
#define EE_SYSTEM_TIMER_DEVICE 1

#define OSMAXALLOWEDVALUE 2147483647U
#define OSTICKSPERBASE_system_timer 1U
#define OSMINCYCLE_system_timer 1U
#define OSTICKSPERBASE 1U
#define OSMINCYCLE 1U
#define OSTICKDURATION 1000000
#define EE_SYSTEM_TIMER system_timer
#define EE_KEEP_ALARM_QUEUE_CODE

enum mode_t{
    eLOW,
    eHIGH
};

#endif /* AS_EECFG_H_ */
