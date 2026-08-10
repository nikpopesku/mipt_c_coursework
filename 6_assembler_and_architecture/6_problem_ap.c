// --- on entry edi = x (unsigned) ---
// --- returns 1 if prime, 0 if composite ---
start:

    mov eax, 0 // eax = 0
    cmp edi, 1 //
    jbe composite // if (edi <= 1) goto composite
    cmp edi, 3
    jbe prime // if (edi <= 3) goto prime
    test dil, 1    // if (edi % 2 == 0) goto composite
    je  composite
    mov ecx, 2

loop:


// --- Here something missing ---


    jne     loop

composite:


    mov     eax, 0 //eax = 0
    ret            // return eax

prime:


    mov     eax, 1   // eax = 1
    ret              // return eax