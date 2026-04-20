// nama: deden ahmad jamil
// nim: 2501518

#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10 

// struct buat nyimpen data si pelanggan
typedef struct {
    char nama[50];
    int total_belanja;
} Pelanggan;

// struktur queue
typedef struct {
    Pelanggan data[MAX_SIZE];
    int head;
    int tail;
} Queue;

// prosedur buat inisialisasi queue pas baru dibikin
void initQueue(Queue *q) {
    q->head = -1;
    q->tail = -1;
}

// fungsi cek antrean kosong
int isEmpty(Queue *q) {
    if (q->head == -1 && q->tail == -1) {
        return 1;
    }
    return 0;
}

//fungsi cek antrean penuh
int isFull(Queue *q) {
    if ((q->tail + 1) % MAX_SIZE == q->head) {
        return 1;
    }
    return 0;
}

// Prosedur Enqueue: masukin data pelanggan ke antrean
void enqueue(Queue *q, char *nama, int total) {
    // Kalau head masih -1, berarti ini data pertama
    if (q->head == -1) {
        q->head++;
    }
    // geser tail muter (circular)
    q->tail = (q->tail + 1) % MAX_SIZE;
    
    // Copy string nama dan masukin total belanja ke array
    strcpy(q->data[q->tail].nama, nama);
    q->data[q->tail].total_belanja = total;
}

// prosedur Dequeue
void dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Antrean Kosong\n");
    } else {
        int i = q->head;
        // looping pake while biar bisa muter ngikutin logika
        while (1) {
            printf("Nama: %s - Total: %d\n", q->data[i].nama, q->data[i].total_belanja);
            if (i == q->tail) { // berenti kalau udah nyampe data terakhir
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
    }
}

int main() {
    Queue kasir1, kasir2;
    initQueue(&kasir1);
    initQueue(&kasir2);
    
    int pilihan;
    char nama_input[50];
    int total_input;
    
    do {
        printf("\n1. Tambah Pelanggan\n");
        printf("2. Tampilkan Semua Antrean\n");
        printf("0. Keluar\n\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        
        if (pilihan == 1) {
            printf("Masukkan nama: ");
            scanf("%s", nama_input);
            printf("Masukkan total belanja: ");
            scanf("%d", &total_input);
            
            // cek dulu apakah Kasir 1 masih muat
            if (!isFull(&kasir1)) {
                enqueue(&kasir1, nama_input, total_input);
                printf("%s masuk ke Kasir 1\n", nama_input);
            } else if (!isFull(&kasir2)) {  // Kalau Kasir 1 penuh kasi ke Kasir 2
                enqueue(&kasir2, nama_input, total_input);
                printf("Kasir 1 penuh. %s masuk ke Kasir 2\n", nama_input);
            }else {   // Kalau dua-duanya penuh
                printf("Maaf, Kasir 1 dan Kasir 2 sudah penuh semua!\n");
            }
        } else if (pilihan == 2) {
            if (!isEmpty(&kasir1)) {
                printf("\nDaftar Antrian Kasir 1:\n");
                dequeue(&kasir1);
            }
            if (!isEmpty(&kasir2)) {
                printf("\nDaftar Antrian Kasir 2:\n");
                dequeue(&kasir2);
            }
        }
        
    } while (pilihan != 0);
    
    return 0;
}