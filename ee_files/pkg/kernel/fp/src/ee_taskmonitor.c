#include "ee_internal.h"
#include "../inc/ee_kernel.h"
#define CRIT_HIGH 1
#define CRIT_LOW 0


/*Invoked if the task failed to complete execution in given budget
and underwent an overrun scenario.*/
void EE_fp_HandleOverrun(void){
	EE_fp_HandlePriority(CRIT_HIGH);
	EE_fp_UpdateSystemCriticality();
	EE_fp_LogTrace();
}

void EE_fp_HandlePriority(int action){
    if(action){
        EE_fp_IncrementSystemCriticality();
    }
    else{
        EE_fp_DecrementSystemCriticality();
    }
}

//Update the task priorities as per the new criticality.
//Look for the tasks in the ready queue as well as preemption stack.
//Remove the overrun task if lo crit, if high crit update the budget
//and push back to runqueue based on priority.
void EE_fp_IncrementSystemCriticality(){
    EE_TYPEPRIO prio;
    EE_TID p, q;
    volatile int netBudget = 0;
	volatile int curCrit = EE_th_get_system_criticality() + 1;
	volatile int activeTask = EE_fp_CurrentTask();
    EE_th_set_system_criticality(curCrit);
    if(EE_fp_is_eligible(actTask)){
        netBudget = (EE_th_sched_param[actTask][curCrit-1] - 
            EE_active_budget[actTask]);
        if(netBudget <= 0){
            EE_active_budget[actTask] = 0;
            EE_rqremove(actTask);
        }
        else{
            EE_active_budget[actTask] += netBudget;
        }
    }
    p = EE_NIL;
    q = EE_rqfirst;
    q = EE_th_next[q.prio];
    prio = EE_th_ready_prio[q];
    /*Iterate through the task release list and remove the low crit tasks
     * that are pending for future release. EE_th_release_queue.
     * */
    while((q != EE_NULL)){
            if(q.crit < curCrit){
                q.active = 0;
            }
            q = EE_th_next[q.prio];
    }   
}

/*Usually called on run queue being idle. Decrement the criticality by
 * unit value and arm the tasks belonging to the updated criticality.
 * */
void EE_fp_DecrementSystemCriticality(int actTask, int curCrit){

}

/*Return the priority of task for current criticality
 * If the task does not exist at current criticality 0 is returned*/
int EE_fp_is_eligible(EE_TID task){
    return  EE_th_sched_params[task].priority[EE_th_get_system_criticality()];
}
