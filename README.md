OS labwork#3
=============

Goals
------
Provide the ability to load a task

In the last labwork, we implemented a command prompt, we need to be able to execute commands in it. This means that when we type `hello` for example, your OS should execute the `cmd_hello` function.

Challenges accepted
--------------------
1.   Load a task without ifs or switches
     + Find a way to execute dynamically the function which the user typed.
2.   Pass parameters to your commands
     + Your kernel must pass command parameters to the command function, this means that the command accepts a char* as a parameter. Your kernel must pass command parameters to the command function, this means that the command accepts a char* as a parameter. To demonstrate this you will need to write a sample comand which greets the user. When I will type `greet Andrei`, the command must output `hello, Andrei!`

How it is done?
-----------------
*Challenge 1*

If you don't want to use conditionals of any type in order to figure out the function to be called according to its string representation, you can do the following:
+    call the functions via it's pointers
+    create an array of pointers to functions
+    each function will be stored in a specific position, for this precompute the index of each function
+    `eval_position` does the computation - sums all numeric values of the ASCII letters and picks the remainder by dividing the number to 16. This means that we can have up to 16 distinct functions.

*Challenge 2*

Each function from the `cmd` directory is called inside a wrapper function. To every function an `char * args` parameter is passed. There is only one function that makes use of it - `greet`.
Before passing the parameter it is necessary of course to split the string till the first occurance of a space. The rest of the string represents the function arguments.

Prerequisites and How to run it
--------------------------------
[lab#1 branch README](https://github.com/ana-balica/os_labs/tree/lab%231)

Resources
-----------
[Prerequisites](http://alisnic.net/blog/os-class-lab1/)

[Lab 3 instructions](http://alisnic.net/blog/os-class-lab3/)
