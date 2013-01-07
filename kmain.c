#include <stdio.h>

int main( void )
{  
  char* vidmem = (char *) 0xb8000; // this is the video memory lives
  vidmem[0] = 'H';
  vidmem[1] = 0x7;
  vidmem[2] = 'e';
  vidmem[3] = 0x7;
  vidmem[4] = 'l';
  vidmem[5] = 0x7;
  vidmem[6] = 'l';
  vidmem[7] = 0x7;
  vidmem[8] = '0';
  vidmem[9] = 0x7;

  for(;;); /* Keep the OS running */
}