global sub128
section .text

sub128:
    mov rax, [rcx]
    sub rax, [rdx]
    mov [r8], rax

    mov rax, [rcx+8]
    sbb rax, [rdx+8]
    mov [r8+8], rax

    ret