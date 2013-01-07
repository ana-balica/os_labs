bits 32			
extern main		
global start	; start if a global function

start:
  call main ; Call our kernel's main() function
  cli        ; Stop interrupts (thats another article?)
  hlt        ; Stop all instructions