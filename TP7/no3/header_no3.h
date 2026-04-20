// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100 // batas maksimal panjang karakter

// pembuatan struct untuk Stack
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// implementasi Fungsi Dasar Stack
void initStack(Stack *s) {
    s->top = -1; // -1 berarti stack masih kosong melompong
}

// cek apa stack-nya kosong
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// cek apa stack-nya udah penuh
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1; // Penuh kalau top udah mentok di batas
}

//  masukin data baru ke tumpukan paling atas
void push(Stack *s, char value) {
    if (!isFull(s)) {
        s->top++;
        s->data[s->top] = value;
    }
}

// keluarin data dari tumpukan paling atas
char pop(Stack *s) {
    if (!isEmpty(s)) {
        char removedValue = s->data[s->top];
        s->top--;
        return removedValue;
    }
    return '\0'; // Return null char jika kosong
}

// ngintip data paling atas tanpa ngeluarin isinya
char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

// fungsi bantuan untuk mengecek pasangan tanda kurung
bool isMatch(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}