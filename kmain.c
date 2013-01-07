#include "lib/input-output.c"

int main( void )
{  
    char * vidmem = (char *) 0xb8000;
    int position = 0;
    while (1) {
        char * prompt = (char *) ">> ";
        position = puts(prompt, vidmem, position);

        char * input_string;
        input_string = gets(vidmem, position);

        position = newline(vidmem, position);
        char * feedback = (char *) "you typed: ";
        position = puts(feedback, vidmem, position);
        position = puts(input_string, vidmem, position);
        position = newline(vidmem, position);
    }
    return 0;
}