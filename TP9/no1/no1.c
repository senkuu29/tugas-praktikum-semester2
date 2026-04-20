// nama: deden ahmad jamil
// nim: 2501518

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 

// struktur queue
typedef struct {
    float data[MAX_SIZE];
    int head;
    int tail;
} Queue;

// Prosedur Inisialisasi Queue
void initQueue(Queue *q) {
    q->head = -1;
    q->tail = -1;
}

// fungsi memeriksa apakah queue kosong
int isEmpty(Queue *q) {
    if (q->head == -1 && q->tail == -1) {
        return 1;
    } else {
        return 0;
    }
}

//fungsi memeriksa apakah queue sudah penuh
int isFull(Queue *q) {
    if ((q->tail + 1) % MAX_SIZE == q->head) {
        return 1;
    } else {
        return 0;
    }
}

//prosedur masukin elemen ke antrean (Enqueue)
void enqueue(Queue *q, float value) {
    if (isFull(q)) {
        printf("Antrean Penuh!\n");
    } else {
        if (q->head == -1) {
            q->head++;
        }
        q->tail = (q->tail + 1) % MAX_SIZE;
        q->data[q->tail] = value;
    }
}

// prosedur ngeluarin elemen dari antrean (Dequeue)
void prosesDequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Antrean Kosong!\n");
    } else {
        printf("\nData waktu layanan (menit):\n");
        int i = q->head;
        //looping muter buat nyetak isi queue
        while(1) {
            printf("%.2f ", q->data[i]);
            if (i == q->tail) break;
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");

        // ngitung dan nyetak estimasi waktu tunggu sambil Dequeue
        printf("Estimasi waktu tunggu:\n");
        float waktu_tunggu = 0.0;
        int pelanggan_ke = 1;

        // Keluarin data satu-satu sampe antrean habis
        while (!isEmpty(q)) {
            printf("Pelanggan %d: %.2f menit\n", pelanggan_ke, waktu_tunggu);

            // ambil data waktu layanan dari head
            float removedValue = q->data[q->head];
            
            // tambahin waktu layanan pelanggan ini ke total waktu tunggu pelanggan berikutnya
            waktu_tunggu += removedValue;
            pelanggan_ke++;

            // logika hapus dari queue
            if (q->head == q->tail) {
                q->head = -1;
                q->tail = -1;
            } else {
                q->head = (q->head + 1) % MAX_SIZE;
            }
        }
    }
}

int main() {
    // bikin variabel queue dan inisialisasi
    Queue antrean_kasir;
    initQueue(&antrean_kasir);

    int jumlah_pelanggan;
    printf("Masukkan jumlah pelanggan (max. %d): ", MAX_SIZE);
    scanf("%d", &jumlah_pelanggan);
    printf("\n");
    // looping buat input jumlah barang dan langsung di-enqueue
    for (int i = 0; i < jumlah_pelanggan; i++) {
        int barang;
        printf("Masukkan jumlah barang pelanggan ke-%d: ", i + 1);
        scanf("%d", &barang);

        float waktu_layanan = (30.0 * barang) / 60.0;
        
        enqueue(&antrean_kasir, waktu_layanan);
    }

    prosesDequeue(&antrean_kasir);

    return 0;
}