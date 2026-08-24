.globl  foo
  .type foo, @function
foo:
  mov       edi, edi   ; can be ignored
  pxor      xmm1, xmm1 ; xmm1 = 0
  sub       rsp, 24    ;rsp pointer - i can ignore in this func
  cvtsi2sd  xmm1, rdi  ; xmm1 = static_cast<float>(rdi)
  movapd    xmm0, xmm1 ; xmm0 = xmm1
  movsd     QWORD PTR [rsp], xmm1
  call      log      ; log(xmm0) probably
  movsd     QWORD PTR [rsp+8], xmm0
  movsd     xmm0, QWORD PTR [rsp]
  call      log;  log(xmm0)
  call      log   log(xmm0)
  addsd     xmm0, QWORD PTR [rsp+8]  ; xmm0 += smth on the stack
  mulsd     xmm0, QWORD PTR [rsp]    ; xmm0 *= smth on the stack
  call      round;      ;round(xmm0)
  add       rsp, 24     ; rsp += 24
  cvttsd2si rax, xmm0   ; rax = static_cast<int>(xmm0)
  ret                   ; return rax