// Computes a special index given a string
// Warning: danger of collision
int eval_position(char * command) {

    int i = 0;
    int index_nr = 0;
    while (command[i] != '\0') {
        index_nr += (int)command[i];
        i++;
    }

    index_nr = index_nr % 16;
    return index_nr;
}


// Extract the string before first occurance of 
// a space char.
void get_command(char full_command[], char command[]) {

    int i = 0;

    while (full_command[i] != '\0') {
        if (full_command[i] != ' ') {
            command[i] = full_command[i];
            i++;
        }
        else break;
    }
    command[i] = '\0';
}


// Extract the argument - string that follows
// after the command
// Ex: `push one two three`
// Argument - `one two three`
void get_argument(char full_command[], char argument[]) {

    int i = 0;
    int j = 0;

    while (full_command[i] != '\0') {
        if (full_command[i] == ' ') {
            i++;
            while (full_command[i] != '\0') {
                argument[j] = full_command[i];
                i++;
                j++;
            }
            argument[j] = '\0';
            break;
        }
        i++;
    }
}


// Wrapper functions to call the cmd_* functions
// Weirdly it is impossible to call them directly
// since compiler says those are `undeclared`
int countdown(char * vidmem, int position, char * args) {

    position = cmd_countdown(vidmem, position);
    return position;
}

int say_vasea(char * vidmem, int position, char * args) {

    position = cmd_say_vasea(vidmem, position);
    return position;
}

int greetme(char * vidmem, int position, char * args) {

	position = cmd_greetme(vidmem, position);
	return position;
}

int greet(char * vidmem, int position, char * args) {

    position = cmd_greet(vidmem, position, args);
}