/*A synthetic schedule table for testing.
 * */
int break_loop = 0;

/*Executes a basic loop of 1ms.*/
void basic_loop(void){
    int i;
    volatile int a;
    for(i = 0; i < 10000; i++){
        a++;
        if(break_loop)
            break;
    }
}

/*Start */
void execute_loop(unsigned int delta){
    int i;
    for(i = 0; i < delta; i++){
        basic_loop();
        if(break_loop){
            break_loop = 0;
            break;
        }
    }
}

void swc_synthetic_task1(void){
    execute_loop(200);
}

void swc_synthetic_task2(void){
    execute_loop(300);
}

void swc_synthetic_task3(void){
    execute_loop(150);
}

void swc_synthetic_task4(void){
    execute_loop(250);
}
