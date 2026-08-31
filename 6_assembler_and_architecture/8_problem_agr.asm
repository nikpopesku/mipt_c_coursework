foo:
        slli    a5,a1,32  ; a5 = a1 << 32
        srli    t4,a5,30  ; t4 = a5 >> 30
        add     t4,a0,t4  ; t4 = a0 + t4
        lw      t3,0(t4)  ; t3 = t4
        mv      a6,a0     ; a6 = a0
        sext.w  a7,a2     ; asm pseudoinstruction
        bgeu    a1,a2,.L7 ; if (a1 >= a2) goto L7
        slli    t1,a7,2   ; t1 = a7 << 2
        add     a5,a0,t1  ; a5 = a0 + t1
        mv      a4,a7     ; a4 = a7
.L6:
        lw      a3,0(a5)  ; a3 = a5
        add     a2,a6,t1  ; a2 = a6 + t1
        addiw   a4,a4,-1  ; a4 = a4 - 1
        ble     a3,t3,.L5 ; if (a3 <= t3) goto L5
        lw      a0,0(a2)  ; a0 = a2
        addiw   a7,a7,-1  ; a7 = a7 - 1
        sw      a3,0(a2)  ; platform specific a3 = a2
        sw      a0,0(a5)  ; a0 = a5
        slli    t1,a7,2   ; t1 = a7 << 2
.L5:
        addi    a5,a5,-4  ; a5 = a5 - 4
        bltu    a1,a4,.L6 ; if (a1 < a4) goto L6
        lw      t3,0(t4)  ; t3 = a4
        add     a6,a6,t1  ; a6 = a6 + t1
        lw      a5,0(a6)  ; a5 = a6
        sw      t3,0(a6)  ; t3 = a6
        sext.w  a0,a7     ; asm pseudoinstruction
        sw      a5,0(t4)  ; a0 = t4
        ret               ; return a0
.L7:
        slli    t1,a7,2   ; t1 = a7 << 2
        add     a6,a6,t1  ; a6 = a6 + t1
        lw      a5,0(a6)  ; a5 = a6
        sw      t3,0(a6)  ; t3 = a6
        mv      a0,a2     ; a0 = a2
        sw      a5,0(t4)  ; a0 = t4
        ret               ; return a0
