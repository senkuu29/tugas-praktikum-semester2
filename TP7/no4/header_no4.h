// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 32 // Maksimal 32 bit sesuai permintaan soal

// struct
typedef struct {
    int data[MAX_SIZE]; //int karena cuma angka 0 atau 1
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1; // -1 berarti stack masih kosong melompong
}

// cek apa stack-nya kosong
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// cek apa stack-nya udah penuh
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1; 
}

// masukin sisa bagi (0 atau 1) ke tumpukan paling atas
void push(Stack *s, int value) {
    if (!isFull(s)) {
        s->top++;
        s->data[s->top] = value;
    }
}

// keluarin angka dari tumpukan paling atas
int pop(Stack *s) {
    if (!isEmpty(s)) {
        int removedValue = s->data[s->top];
        s->top--;
        return removedValue;
    }
    return -1; // Kalau kosong balikin -1
}