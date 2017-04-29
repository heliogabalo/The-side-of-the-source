    .globl _start

_start:
  movl  $_bss_start, %edi
  movl  $_end, %ecx
  subl  %edi, %ecx
  xorl  %eax, %eax
  cld
  rep
  stosb
    call main
