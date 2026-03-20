global add128
section .text

add128:
    mov rax, [rcx]
    add rax, [rdx]
    mov [r8], rax

    mov rax, [rcx+8]
    adc rax, [rdx+8]
    mov [r8+8], rax

    ret