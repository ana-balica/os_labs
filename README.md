OS labwork#4
=======

Goals
------
1.   Integrate `setjmp` and `longjmp` in your project
     + This means that you must take the code I made available to you and put in somewhere in your project files so that it will compile, and the functions listed above are available for use.
2.   Show a working example of usage of setjmp and longjmp (+20 EXP)

How it works?
--------------
`setjmp` is placed inside `loader.asm` file. It saves the current state of CPU registers. `longjmp` is placed inside a separate file together with the structure it uses. This function restores the registers state to the moment when `setjmp` was called. 

After the jump `setjmp` will return the value passed to the `longjmp`. Taking into consideration this, we have shown how your program jumps from function `foo` to the `main` function to the place where `setjmp` was called. The returning values is already not 0 but 1, which proves the fact that it never reaches to output the string `Unreachable part of the program`.

Prerequisites and How to run it
--------------------------------
[lab#1 branch README](https://github.com/ana-balica/os_labs/tree/lab%231)


Resources
-----------
[Prerequisites](http://alisnic.net/blog/os-class-lab1/)

[Lab 4 instructions](http://alisnic.net/blog/osclass-lab4/)
