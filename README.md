OS labwork#2
=======

Goals
------
1.   Make the output to screen easy:
     + implement `putc` (print a character at the current cursor position and increase the position of the cursor)
     + implement `puts` (print a string at the current cursor position, and advance the position of the cursor with the length of the string)
     + implement `clrscr` (clear the screen)
2.   Create a command prompt which can read and parse commands, and will respond to all commands with `you typed: <command>`
     + implement `gets` (get a string from keyboard)
     + when a command is typed, the output should be written below the command and the prompt should be moved below the output.
     + (optional) when the prompt reaches the bottom, the whole text should scroll up, and the prompt should stay at the bottom of the screen. (+10 EXP)

Prerequisites
--------------------------
+ gcc
+ nasm
+ make
+ virtualbox with a DOS OS that boots from an image created by you

On a Linux OS do `sudo apt-get install build-essential nasm`.

How to run it
--------------
1.   cd in the project directory
2.   Run `make`
3.   Run the DOS OS from your virtualbox

Resources
-----------
[Prerequisites](http://alisnic.net/blog/os-class-lab1/)

[Lab 2 instructions](http://alisnic.net/blog/os-class-lab2/)