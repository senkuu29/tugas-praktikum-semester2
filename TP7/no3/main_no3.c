// nama : deden ahmad jamil
// nim : 2501518

#include "header_no3.h"

int main() {
    Stack myStack;
    initStack(&myStack);
    
    char ekspresi[MAX_SIZE];
    
    printf("Input:\n");
    scanf("%s", ekspresi); // membaca string ekspresi tanpa spasi
    
    printf("\nOutput:\n");
    
    // perulangan untuk mengecek setiap karakter dalam ekspresi
    for (int i = 0; i < strlen(ekspresi); i++) {
      char ch = ekspresi[i];
        
      // jika menemukan kurung buka masukkan
      if (ch == '(' || ch == '{' || ch == '[') {
        push(&myStack, ch);
      } 
      // jika menemukan kurung tutup
    else if (ch == ')' || ch == '}' || ch == ']') {
        // cek jika stack kosong ada kurung tutup tapi tidak ada kurung bukanya
        if (isEmpty(&myStack)) {
          printf("Ekspresi TIDAK VALID - kurung tutup %c tidak memiliki pasangan\n", ch);
          return 0;
        }
          
        // lihat elemen teratas
        char topChar = peek(&myStack);
          
        //cek kalo kurung tutup ch cocok dengan kurung buka teratas topChar
        if (isMatch(topChar, ch)) {
          pop(&myStack); // kalo cocok keluarkan dari stack
        } else {
          // kalo nemu kurung tutup yang engga cocok dengan kurung buka teratas
          printf("Ekspresi TIDAK VALID - kurung tutup %c tidak cocok dengan %c\n", ch, topChar);
          return 0;
        }
      }
    }
    
    // kalo setelah semua karakter diproses stack masih tidak kosong
    if (isEmpty(&myStack)) {
      printf("Ekspresi VALID\n");
    } else {
      printf("Ekspresi TIDAK VALID - kurung buka tidak ditutup\n");
    }
    
    return 0;
}