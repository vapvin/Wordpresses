section .data
    STAR db "*"
    EMPTY db 0x0a

section .text
    global _start

_start:
    mov rax, 1
    mov rdi, 1
    mov rdx, 1
    mov r10, 0
    mov r9, [rsp + 16]

    cmp r9, 0
    je _done

    mov cl, [r9]
    movzx r9, cl
    sub r9, 0x30

    mov r8, r9
    xor r9, r9
    call _syscall

_small:
    cmp r10, r9
    je _up
    mov rsi, STAR
    syscall
    mov rax, 1
    inc r10
    jmp _small

_up:
    cmp r9, r8
    je _down
    mov rsi, EMPTY
    syscall
    mov rax, 1
    mov r10, 0
    add r9, 1
    jmp _small

_down:
    cmp r9, 0
    je _done
    mov rsi, EMPTY
    syscall
    mov rax, 1
    mov r10, 0
    sub r9, 1
    jmp _big

_big:
    cmp r10, r9
    je _down
    mov rsi, STAR
    syscall
    mov rax, 1
    inc r10
    jmp _big

_done:
    mov rax, 60
    mov rdi, 0
    syscall

_syscall:
    syscall
    ret