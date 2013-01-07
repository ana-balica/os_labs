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

Prerequisites and How to run it
--------------------------------
[lab#1 branch README](https://github.com/ana-balica/os_labs/tree/lab%231)

Resources
-----------
[Prerequisites](http://alisnic.net/blog/os-class-lab1/)

[Lab 3 instructions](http://alisnic.net/blog/os-class-lab3/)