#include "lib/input-output.c"
#include "lib/cmd.c"

int main( void )
{  
    char * vidmem = (char *) 0xb8000;
    int position = 0;

    // // array of function pointers
    // // the positions are preevaluated
    int (*commands[16])(char * vidmem, int position, char * args);
    commands[1] = countdown;
    commands[7] = greet;
    commands[9] = greetme;
    commands[12] = say_vasea;

    while(1) {

        char full_command[100];
        char command[100];
        char argument[100];
        char * prompt = (char *) ">> ";
        position = puts(prompt, vidmem, position);

        gets(vidmem, position, full_command);
        get_command(full_command, command);
        get_argument(full_command, argument);

        position = newline(vidmem, position);

        int index;
        index = eval_position(command);

        position = (*commands[index])(vidmem, position, argument);
        position = newline(vidmem, position);
    }

    return 0;
}

