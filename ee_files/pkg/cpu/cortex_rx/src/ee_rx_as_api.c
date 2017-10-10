/*Implements timing protection hooks and handlers for ti_tms570 Hercules based
 * platform.
 * Main Functionality:
 * Check for timing protection access and rights, validity of timing protection.
 * */

void EnableAllInterrupts(void){

}

void DisableAllInterrupts(void){

}

void SuspendAllInterrupts(void){

}

void SuspendOsInterrupts(void){

}

void ResumeOsInterrupts(void){

}

/** Check for task eligibility to run before calling activation. **/
StatusType ActivateTask(TaskType TaskID){

}

/** Task termination with permission check for BCC1, BCC2, ECC1, ECC2**/
StatusType TerminateTask(TaskType TaskID){

}

/*Set task return pointer to a new id after verifying permission, if enabled.*/
StatusType ChainTask(TaskType TaskID){

}

/* Currently the protection handler shall be registered for watchdog timer activation. */
void EE_rx_protection_handler(void){

}

