#include <math.h>


int foo(int rdi) {
    double xmm1 = 0;
    double xmm0;
    int rax;
    double rsp1, rsp2;
    xmm1 = (double) rdi;
    xmm0 = xmm1;
    rsp1 = xmm1;
    xmm0 = log(xmm0);
    rsp2 = xmm0;
    xmm0 = rsp1;
    xmm0 = log(xmm0);
    xmm0 = log(xmm0);
    xmm0 += rsp2;
    xmm0 *= rsp1;
    xmm0 = round(xmm0);
    rax = (int) xmm0;
    return rax;
}
