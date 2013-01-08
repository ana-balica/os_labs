OS labwork#5-6
=======

Goals
------
1.   Have a simple multitasking implemented
2.   Your OS multitasking should have the following functions available:
	 + `void sched_add_task(void* func_ptr)` – add a task to scheduler by giving a function pointer
	 + `void yield(void)` – give control to scheduler in a task
	 + `void sched_run(void)` – start the scheduler

How it works:
-------------
After creating the tasks our OS does the following:
	 + schedules those tasks - adds each task to an array (could be a more reliable data structure, like a queue), saves the register states by using a `setjmp`, initializes the stack pointer and the instruction pointer in order to point to your function.
	 + runs the schedules - meanwhile all the tasks are scheduled to do their job, the scheduler starts by simply running the first task.
	 + the first task is polite enough to give control to the OS and the OS saves the current state of your function, and switches to the next task. 
	 + next task is called and again the same is happens to it (state saving) as to the first task
	 + when again the first task will be given the opportunity to run, it will resume its work from the current state

This is how we have implemented cooperative multitasking.


How to run it
--------------------------------
[lab#1 branch README](https://github.com/ana-balica/os_labs/tree/lab%231)


Resources
-----------
[Prerequisites](http://alisnic.net/blog/os-class-lab1/)

[Lab 5-6 instructions](http://alisnic.net/blog/osclass-lab5-6-implementing-multitasking/)