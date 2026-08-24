int foo(float rdi) {
    float xmm1 = 0
    int * rsp -= 24;
    float xmm1 = static_cast<float>(rdi);
    xmm0 = xmm1;
    *(double*)rsp = xmm1;
    xmm0 = log(xmm0);
    *(rsp + 1) = xmm0;
    xmm0 = *rsp;
    xmm0 = log(xmm0);
    xmm0 = log(xmm0);
    xmm0 += *(rsp + 1);
    xmm0 *= *rsp;
    xmm0 = round(xmm0);
    rsp += 24;
    rax = static_cast<int>(xmm0);
    return rax;
}
