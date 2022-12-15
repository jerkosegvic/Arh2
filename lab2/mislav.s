.intel_syntax noprefix
.global p_asm

p_asm:
    push ebp
    mov ebp, esp
    mov ecx, 0
    mov eax, 0
    mov edx, [ebp+8]
    //eax = zbroj, ecx = brojač, edx = granica
    jmp L2

L1:
    add eax, ecx
    add ecx, 1


L2:
    cmp ecx, edx
    jl L1
    mov esp, ebp
    pop ebp
    ret
