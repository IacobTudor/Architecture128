global mul128Value
section .text

mul128Value:
    mov r9, rdx

    mov r10, [rcx]
    mov r11, [rcx+8]

    mov rax, r10
    mul r9

    mov r12, rax
    mov r13, rdx

    mov rax, r11
    mul r9

    add rax, r13

    mov [r8], r12
    mov [r8+8], rax

    ret