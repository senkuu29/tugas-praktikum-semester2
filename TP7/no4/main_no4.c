// nama : deden ahmad jmail
// nim : 2501518

#include "header_no4.h"

int main() {
    Stack myStack;
    initStack(&myStack);
    
    int desimal;
    
    printf("Input: ");
    scanf("%d", &desimal);
    
    // kalau inputnya 0 langsung cetak 0
    if (desimal == 0) {
        printf("Output: 0\n");
        return 0;
    }
    
    // proses bagi 2 terus-terusan sampai bilangannya habis 0
    while (desimal > 0) {
        int sisa = desimal % 2; // cari sisa bagi (0 atau 1)
        push(&myStack, sisa);   // masukin sisa bagi ke stack
        desimal = desimal / 2;  // angkanya dibagi 2 buat putaran selanjutnya
    }
    
    printf("Output: ");
    while (!isEmpty(&myStack)) {
        printf("%d", pop(&myStack));
    }
    printf("\n");
    
    return 0;
}