#include "io.c"
#include "kbd.c"

// Output a single character 
// @return: the current advanced position of cursor
int putc(char character, char * vidmem, int position) {
    vidmem[position] = character;
    position++;
    vidmem[position] = 0x7;
    position++;
    return position;
}


// Output string
// @return: the current advanced position of cursor
int puts(char * string, char * vidmem, int position) {
    int i = 0;
    while (string[i] != '\0') {
        position = putc(string[i], vidmem, position);
        i++;
    }
    return position;
}


// Clears the screen aka video memory is filled 
// with spaces
void clrscr(char * vidmem, int position) {
    while (position >= 0) {
        vidmem[position] = ' ';
        position -= 2;
    }
    position = 0;
}

// Gets the user input and instantly prints it
// until Enter is pressed 
void gets(char * vidmem, int position, char string[]){
    char c;
    int i = 0;
    while (1) {
        c = getchar();
        if (c == '\n') break;
        position = putc(c, vidmem, position);
        string[i] = c;
        i++;
    }
    string[i] = '\0';
}


// Checks if the cursor on the last row
// and a scroll is needed
// @return 1 (true) or 0 (false)
int mustScroll(int current_row) {
    if (current_row > 24) return 1;
    else return 0;
}


// Scroll down by deleting the first row 
// There are 80 rows (160 bytes)
// @return position one row up
int scroll(char * vidmem, int position) {
    int i;
    for (i = 160; i <= position; i += 2) {
        vidmem[i-160] = vidmem[i];
        vidmem[i] = ' ';
    }
    return position-160;
}


// Sets the cursor the a newline
// @return positon of the cursor
int newline(char * vidmem, int position) {
    int current_row = (int) position/160;
    current_row++;
    if (mustScroll(current_row)) {
        position = scroll(vidmem, position);
        current_row--;
    }
    position = current_row*160;
    return position;
}