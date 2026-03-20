global and128
section .text

and128:
    mov r10, [rcx]
    mov r11, [rdx]
    and r10, r11
    mov [r8], r10

    mov r10, [rcx+8]
    mov r11, [rdx+8]
    and r10, r11
    mov [r8+8], r10

    ret