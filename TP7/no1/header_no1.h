// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// struktur stack
typedef struct Musik{
    char judul[MAX_SIZE][100]; // 10 lagu, masing-masing max 100 karakter
    int top;
}Musik;

// inisialisasi stack (top = -1 artinya stack kosong)
void initStack(Musik *s) {
    s->top = -1;
}

// fungsi ngecek stack kosong atau nggak
int isEmpty(Musik *s) {
  return s->top == -1; // Kalau top -1 berarti gak ada isinya
}

// push memasukan elemen ke atas stack
void push(Musik *s, char value[]){
    // langkah 1 menegcek stack apakah penuh atau engga
    if (s->top == MAX_SIZE - 1)
    {
      printf("ERROR: Musik Overlow! Musik Sudah Penuh.\n");
      return;
    }

    //  langkah 2 naikan top
    s->top++;

    // langkah 3 simpan nilai keposisi top
    strcpy(s->judul[s->top], value);

    printf("\nLagu '%s' ditambahkan ke playlist.\n", value);
}

// pop mengeluarkan element dari stack
char* pop(Musik *s) {
    // langkah 1 cek musik apakah kosong
    if (s->top == - 1)
      {
        printf("ERROR: Musik Underflow! Musik Sudah kosong.\n");
        return NULL;
      }
    
    // langkah 2 simpan nilai top kevaribel sementara
    char *removedValue = s->judul[s->top];

    // langkah 3 turunkan nilai top (data hilang dari stack)
    s->top--;

    printf("\nLagu '%s' di-skip dari playlist.\n", removedValue);

    // mengembalikan nilai yang dikeluarkan
    return removedValue;
}

// display stack musik
void displayMusik(Musik *s){
  int no = 1; // untuk nomor

  // kalo stack kosong
  if(isEmpty(s)){
    printf("Musik: [KOSONG]\n");
  }

  // display
  printf("\nIsi playlist (dari atas ke bawah):\n");
  for (int i = s->top; i >= 0; i--)
  {
    printf("%d. %s\n", no, s->judul[i]);
    no++;
  }
}

