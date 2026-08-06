// --- int foo(int *x, int y, int z) ---
// edi = x
// esi = y
// edx = z
// return value = eax
//   .globl  foo
//   .type foo, @function
// foo:
//   // probably int * rdi;
//   xor r8d, r8d       // r8d = 0
//   test  edx, edx     //  if (z == 0)
//   je  .L1            //  goto L1
//   mov eax, edx       // eax = z
//   sub eax, 1         // eax = eax - 1
//   js  .L7            // if (eax < 0) goto L7;
//   cdqe               // rax = eax
//   jmp .L4            // goto L4
// .L5:
//   mov DWORD PTR 4[rdi+rax*4], edx      // rdi[rax + 1] = z
//   sub rax, 1                          // rax = rax - 1
//   test  eax, eax                     // if (eax < 0)
// js  .L1                              // goto L1;
// .L4:
// mov edx, DWORD PTR [rdi+rax*4]       // z = rdi[rax]
// mov r8d, eax                         // r8d = eax
// cmp edx, esi                         // if (z > y)
// jg  .L5                              // goto L5
// add r8d, 1                           // r8d = r8d + 1
// .L1:
// mov eax, r8d //eax = r8d
// ret          //return eax
// .L7:
// mov r8d, edx    // r8d = z;
// jmp .L1         // goto L1

int foo(int *x, int y, int z) {
    int r8d = 0;
    int rax;
    if (z == 0) {
        goto L1;
    }

    rax = z - 1;
    if (rax < 0) goto L7;
    goto L4;

    L5:
        x[rax + 1] = z;
        --rax;
        if (rax < 0) {
            goto L1;
        }
    L4:
        z = x[rax];
        r8d = rax;
        if (z > y) {
            goto L5;
        }
        r8d = r8d + 1;

    L1:
        rax = r8d;
        return rax;
    L7:
        r8d = z;
        goto L1;
}

int main() {

}