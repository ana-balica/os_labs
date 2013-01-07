#include "lib/input-output.c"
#include "lib/longjmp.c"

// initializare a global instance of struct jmp_buf
static jmp_buf buf;
 

// sample function to show the power of longjmp
void foo(char * vidmem, int position) {

    char * msg = "Inside foo function";
    position = puts(msg, vidmem, position);
    position = newline(vidmem, position);
    longjmp(buf,1);
}


int main( void )
{  
    char * vidmem = (char *) 0xb8000;
    int position = 0;

    char * start_msg = "Starting inside main function";
    position = puts(start_msg, vidmem, position);
    position = newline(vidmem, position);

    int i;
    i = setjmp(buf);

    if (i == 0) {
        foo(vidmem, position);
        char * msg = "Unreachable part of the program";
        position = puts(msg, vidmem, position);
    }
 
    return 0;
}