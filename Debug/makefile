
## CPU OPTIONS ##
EEOPT += __CORTEX_RX__
# CPU Model 
EEOPT += __CORTEX_R4__
# Compiler Type
EEOPT += __CCS__


EEOPT += __RTD_TMS570__
#################

## MCU OPTIONS ## 
EEOPT += __RTD_CYGWIN__
EEOPT += __TI__
EEOPT += __TMS570__

APPBASE := ..
OUTBASE := Debug
#################
### Setting Erika's variables:
# ERIKA_FILES= ../../..
# APPBASE = .
# 
# EEOPT =


RTDRUID_CONFIGURATOR_NUMBER:=1278


EEOPT += DEBUG
EEOPT += __USE_SYSTICK__
EEOPT += __USE_USER_LED__
EEOPT += __TI_DRIVER_LIB__
EEOPT += __ALLOW_NESTED_IRQ__
EEOPT += __USE_DISPLAY__
EEOPT += ENABLE_SYSTEM_TIMER
EEOPT += EE_AS_SCHEDULETABLES__
EEOPT += EE_TIMING_PROTECTION__

EEOPT += __RTD_CYGWIN__
EEOPT += __OO_ECC1__
EEOPT += __OO_EXTENDED_STATUS__
EEOPT += __OO_HAS_ERRORHOOK__
EEOPT += __MULTI__
EEOPT += __OO_NO_ALARMS__
EEOPT += __OO_NO_RESOURCES__
EEOPT += __OO_NO_EVENTS__
EEOPT += __OO_AUTOSTART_TASK__
EEOPT += __ALLOW_NESTED_IRQ__
EEOPT += EE_AS_HAS_PROTECTIONHOOK__
EEOPT += __DISABLE_EEOPT_DEFINES__

ifdef ERIKA_FILES
ifdef EEBASE
    $(warning EEBASE is set, but it has been overridden by ERIKA_FILES)
endif

else # ERIKA_FILES

ifndef EEBASE
        EEBASE := $(shell cygpath `cygpath -ms 'C:\Users\CHANDRASHEKARAN\Documents\source_repo\litmus\sample\ee_files'`)
else
        $(warning The usage of EEBASE is deprecated. Please use ERIKA_FILES)
endif
endif # ERIKA_FILES
# ERIKA_FILES has fulfilled its role. Make sure it's not used inside Erika makefiles
ERIKA_FILES :=
$(info Using erika files in $(EEBASE))

CFLAGS  += 
ASFLAGS += 
LDFLAGS += 
LDDEPS  += 
LIBS    += 


APP_SRCS += eecfg.c code_as_impl.c as_eecfg.c

include $(EEBASE)/pkg/cfg/rules.mk
