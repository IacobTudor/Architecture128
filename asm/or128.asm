global or128
section .text

or128:
    mov r10, [rcx]
    mov r11, [rdx]
    or r10, r11
    mov [r8], r10

    mov r10, [rcx+8]
    mov r11, [rdx+8]
    or r10, r11
    mov [r8+8], r10

    ret