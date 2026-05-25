// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// struct untuk menyimpan data mahasiswa
typedef struct Node {
    int nim;
    char nama[50];
    float ipk;
    struct Node* next;     // pointer untuk chaining
} Node;

// fungsi hash
int hash(int nim) {
    return nim % SIZE;
}

// tambah mahasiswa
void insert(Node** hashTable, int nim, char* nama, float ipk) {
    int index = hash(nim); // cari posisi laci
    
    // siapin node baru di memori
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    newNode->ipk = ipk;
    newNode->next = NULL;
    
    // kalau laci kosong, langsung masukin
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
        printf("-> Hash = %d, disimpan di slot %d.\n", index, index);
    } else {
        // kalau udah ada isinya, terjadi collision, rantaikan di belakang
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        printf("-> Hash = %d, terjadi collision. Data ditambahkan ke linked list di slot %d.\n", index, index);
    }
}

//cari mahasiswa
void search(Node** hashTable, int nim) {
    int index = hash(nim);
    Node* temp = hashTable[index];
    
    // telusuri rantai di laci tersebut
    while (temp != NULL) {
        if (temp->nim == nim) { // kalau nim-nya cocok
            printf("-> Ditemukan di slot %d: %s (IPK %.2f)\n", index, temp->nama, temp->ipk);
            return; // langsung keluar fungsi
        }
        temp = temp->next; // geser ke node sebelah
    }
    
    // kalau sampai ujung rantai ga ketemu
    printf("-> Data dengan NIM %d tidak ditemukan.\n", nim);
}

// hapus mahasiswa
void deleteNode(Node** hashTable, int nim) {
    int index = hash(nim);
    Node* temp = hashTable[index];
    Node* prev = NULL; // pointer untuk nginget node sebelumnya
    
    printf("-> Menghapus mahasiswa dengan NIM %d...\n", nim);
    
    // kalo data yang mau dihapus ada di urutan pertama
    if (temp != NULL && temp->nim == nim) {
        hashTable[index] = temp->next; // pindahin kepala laci ke node sebelahnya
        free(temp); // hapus
        printf("-> Data berhasil dihapus.\n");
        return;
    }
    
    // data ada di tengah atau akhir, cari dulu
    while (temp != NULL && temp->nim != nim) {
        prev = temp;
        temp = temp->next;
    }
    
    // kalau ditelusuri sampai habis tapi ga ketemu
    if (temp == NULL) {
        printf("-> Data tidak ditemukan.\n");
        return;
    }
    
    // sambungin node sebelum dengan node sesudah, lewati node yang mau dihapus
    prev->next = temp->next;
    free(temp); // hapus
    printf("-> Data berhasil dihapus.\n");
}

// tampilkan semua isi tabel
void display(Node** hashTable) {
    printf("=== ISI HASH TABLE ===\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Slot %d : ", i);
        
        Node* temp = hashTable[i];
        
        // kalau laci kosong
        if (temp == NULL) {
            printf("kosong\n");
        } else {
            // kalau ada isinya, cetak semua yang ada di rantai
            while (temp != NULL) {
                printf("[%d] %s (IPK %.2f)", temp->nim, temp->nama, temp->ipk);
                if (temp->next != NULL) {
                    printf(" -> ");
                }
                temp = temp->next;
            }
            printf("\n");
        }
    }
}


int main() {
    Node* hashTable[SIZE] = {NULL}; //10 laci kosong
    int pilihan, nim;
    char nama[50];
    float ipk;
    
    printf("=== SISTEM HASH TABLE MAHASISWA ===\n");
    printf("Ukuran tabel: 10 slot\n");
    printf("Fungsi hash: NIM %% 10\n\n");
    
    // perulangan menu
    while (1) {
        printf("\nMenu:\n");
        printf("1. Tambah Mahasiswa\n");
        printf("2. Cari Mahasiswa\n");
        printf("3. Hapus Mahasiswa\n");
        printf("4. Tampilkan Tabel\n");
        printf("5. Keluar\n\n");
        
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                printf("Masukkan NIM (8 digit): ");
                scanf("%d", &nim);
                printf("Masukkan nama: ");
                scanf(" %[^\n]", nama);
                printf("Masukkan IPK: ");
                scanf("%f", &ipk);
                insert(hashTable, nim, nama, ipk);
                break;
            case 2:
                printf("Masukkan NIM yang dicari: ");
                scanf("%d", &nim);
                search(hashTable, nim);
                break;
            case 3:
                printf("Masukkan NIM yang akan dihapus: ");
                scanf("%d", &nim);
                deleteNode(hashTable, nim);
                break;
            case 4:
                display(hashTable);
                break;
            case 5:
                printf("Keluar dari program. Dadah!\n");
                return 0;
            default:
                printf("Pilihan tidak ada, coba lagi ya.\n");
        }
    }
    return 0;
}