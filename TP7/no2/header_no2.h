// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// struktur stack
typedef struct Klinik{
    int kodePrioritas[MAX_SIZE];
    int top;
}Klinik;

// inisialisasi stack (top = -1 artinya stack kosong)
void initStack(Klinik *s) {
    s->top = -1;
}

// fungsi ngecek stack kosong atau nggak
int isEmpty(Klinik *s) {
  return s->top == -1; // Kalau top -1 berarti gak ada isinya
}

// push memasukan elemen ke atas stack
void push(Klinik *s, int value){
    // langkah 1 menegcek stack apakah penuh atau engga
    if (s->top == MAX_SIZE - 1)
    {
      printf("ERROR: Antrean Klinik Overflow! Klinik Sudah Penuh.\n");
      return;
    }

    //  langkah 2 naikan top
    s->top++;

    // langkah 3 simpan nilai keposisi top
    s->kodePrioritas[s->top] = value;
}

// Fungsi pop untuk mengambil elemen dari atas stack
int pop(Klinik *s) {
    if (isEmpty(s)) {
        return -1; // Penanda stack kosong
    }
    int value = s->kodePrioritas[s->top];
    s->top--;
    return value;
}