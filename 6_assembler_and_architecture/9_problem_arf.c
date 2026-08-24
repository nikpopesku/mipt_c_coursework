#include <math.h>


int foo(int rdi) {
    double xmm1 = 0;
    double xmm0;
    int rax;
    int *rsp;
    xmm1 = (double) rdi;
    xmm0 = xmm1;
    *rsp = xmm1;
    xmm0 = log(xmm0);
    *(rsp + 1) = xmm0;
    xmm0 = *rsp;
    xmm0 = log(xmm0);
    xmm0 = log(xmm0);
    xmm0 += *(rsp + 1);
    xmm0 *= *rsp;
    xmm0 = round(xmm0);
    rsp += 24;
    rax = (int) xmm0;
    return rax;
}
