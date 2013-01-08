#include "longjmp.c"
#include "input-output.c"

#define TASK_STACK_SIZE 512
  
typedef enum {
  TS_RUNNABLE = 1, TS_BLOCKED = 2, TS_ZOMBIE = 3
} task_status_t;


typedef struct {
    jmp_buf       state;
    task_status_t status;
    unsigned char stack[TASK_STACK_SIZE];
} task_t;


task_t tasks[2];
int task_nr = 0;
current_task_nr = 0;


// Add the tasks to an array and
// saves some data for each function
void sched_add_task(void * func_ptr) {

    task_t * task = & tasks[task_nr];
    task_nr++;

    int i;
    i = setjmp(task->state);
    if (!i) {
        unsigned * initial_stack_ptr;
        initial_stack_ptr = (unsigned) task->stack + TASK_STACK_SIZE;

        task->state[0].esp = initial_stack_ptr;
        task->state[0].eip = func_ptr;
        task->state[0].eflags = 0x200; //some magic for longjmp
    }
}


// Runs the first task from the array
void sched_run() {

    current_task_nr = 0;
    longjmp(tasks[0].state, 1);
}


// Switches the tasks (now available only for 2 tasks)
void yield() {

    if (!setjmp(tasks[current_task_nr].state)) {
        if (current_task_nr == 0) {
            current_task_nr = 1;
        }
        else {
            current_task_nr = 0;
        }
        longjmp(tasks[current_task_nr].state, 1);
    }   
}