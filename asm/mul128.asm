global mul128
section .text

mul128:
    mov rbx, rcx
    mov r9, rdx

    mov rax, [rbx]
    mul qword [r9]
    mov [r8], rax
    mov r10, rdx

    mov rax, [rbx]
    mul qword [r9+8]
    add r10, rax
    adc rdx, 0
    mov r11, rdx

    mov rax, [rbx+8]
    mul qword [r9]
    add r10, rax
    adc r11, rdx

    mov [r8+8], r10

    ret