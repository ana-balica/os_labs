#include "lib/scheduler.c"

char* vidmem = (char *) 0xb8000;

void wait() {
  int c, d;
  for ( c = 1 ; c <= 32767 ; c++ )
    for ( d = 1 ; d <= 1000 ; d++ );
}

void task0 (void) {
  while (1) {
    yield();
    vidmem[0] = vidmem[0] == 'B' ? 'A' : 'B';
    wait();
  }
}

void task1 (void) {
  while (1) {
    yield();
    vidmem[2] = vidmem[2] == 'B' ? 'A' : 'B';
    wait();
  }
}

int main( void )
{
  vidmem[1] = vidmem[3] = 0x7;
  sched_add_task(task0);
  sched_add_task(task1);
  sched_run();
}