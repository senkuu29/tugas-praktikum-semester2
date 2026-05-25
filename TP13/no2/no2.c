// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //buat fungsi tolower

#define SIZE 26

// struct
typedef struct Node {
    char kata[50];
    struct Node* next;
} Node;

// fungsi hash
int hash(char *kata) {
  char huruf_awal = tolower(kata[0]); // pastiin huruf kecil
  
  // kalau ternyata yang diinput bukan abjad, amanin lempar ke indeks 0
  if (huruf_awal < 'a' || huruf_awal > 'z') {
    return 0;
  }
  return (huruf_awal - 'a') % SIZE;
}

// prosedur masukin kata ke hash
void insert(Node** hashTable, char *kata) {
    int index = hash(kata);
    // pesan node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // input data node
    strcpy(newNode->kata, kata);
    newNode->next = NULL;
    
    // kalo kosong
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // kalo node udah ada
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
          temp = temp->next;
        }
        temp->next = newNode;
    }
}

// fungsi buat nyari saran
char* cari_saran(Node** hashTable, char* kata_salah) {
  // abaikan kalau katanya cuma 1 huruf
  if (strlen(kata_salah) < 2) return NULL; 

  // cek semua laci dari a sampai z
  for (int i = 0; i < SIZE; i++) {
    Node* temp = hashTable[i];
    while (temp != NULL) {
    // cek apakah sisa hurufnya sama persis
    if (strcmp(temp->kata + 1, kata_salah + 1) == 0) {
      return temp->kata; // ketemu srannya
    }
    temp = temp->next;
    }
  }
  return NULL; // ga ada yg ccok
}

// fungsi buat baca file kamus.txt dan masukin isinya ke tabel
int muat_kamus(Node** hashTable, const char* nama_file) {
  FILE* file = fopen(nama_file, "r");
  if (file == NULL) {
    printf("gagal memuat file '%s'. pastikan filenya sudah dibuat!\n", nama_file);
    return 0; // kalau filenya ga adaaaaa
  }
  
  char buffer[50];
  int jumlah_kata = 0;
  
  // baca kata satu per satu sampai file habis
  while (fscanf(file, "%s", buffer) != EOF) {
    // ubah jadi huruf kecil semua biar seragam
    for(int i = 0; buffer[i]; i++){
      buffer[i] = tolower(buffer[i]);
    }
    insert(hashTable, buffer);
    jumlah_kata++;
  }
  
  fclose(file);
  return jumlah_kata;
}

// prosedur buat nampilin hitung
void tampilkan_statistik(Node** hashTable, int total_kata) {
    float rata_rata = (float)total_kata / SIZE; // hitung rata-rata
    int max_panjang = 0;
    int max_indeks = 0;

    // keliling laci buat nyari slot mana yang paling panjang rantainya
    for (int i = 0; i < SIZE; i++) {
      int panjang = 0;
      Node* temp = hashTable[i];
      while (temp != NULL) {
        panjang++;
        temp = temp->next;
      }
      
      // kalo nemu yang lebih panjang simpen rekornya
      if (panjang > max_panjang) {
        max_panjang = panjang;
        max_indeks = i;
      }
    }

    printf("\nStatistik awal:\n");
    printf("Rata-rata panjang rantai: %.2f\n", rata_rata);
    if (max_panjang > 0) {
      // ubah angka indeks balik jadi huruf karakter
      printf("Slot dengan terbanyak: slot '%c' (%d kata)\n", 'a' + max_indeks, max_panjang);
    }
}

int main() {
    Node* hashTable[SIZE] = {NULL}; // 26 kosong
    
    printf("=== SPELL CHECKER SEDERHANA ===\n");
    printf("Memuat kamus dari file 'kamus.txt'...\n");
    
    int total_kata = muat_kamus(hashTable, "kamus.txt");
    
    // kalau file ga ketemu, berenti
    if (total_kata == 0) return 1; 
    
    printf("%d kata berhasil dimuat ke dalam hash table (ukuran 26).\n", total_kata);
    tampilkan_statistik(hashTable, total_kata);
    
    char kalimat[256];
    
    while (1) {
      printf("\nMasukkan kalimat (ketik 'exit' untuk keluar):\n");
      printf("    ");
      scanf(" %[^\n]", kalimat);
      
      // ubah semua hruff di klimt jadi kecil biar gmpng dicocokin
      for(int i = 0; kalimat[i]; i++) {
        kalimat[i] = tolower(kalimat[i]);
      }
      
      // ngecek apakah mau udahan
      if (strcmp(kalimat, "exit") == 0) {
        printf("Program selesai.\n");
        break;
      }
      
      int benar = 0;
      int salah = 0;
      printf("\nHasil pemeriksaan:\n");
      
      // strtok berfungsi memecah kalimat panjang jadi kata per kata berdasarkan spasi
      char *kata = strtok(kalimat, " ");
      
      while (kata != NULL) {
        int idx = hash(kata);
        Node* temp = hashTable[idx];
        int ketemu = 0; // penanda
        
        // cari kata
        while (temp != NULL) {
          if (strcmp(temp->kata, kata) == 0) {
            ketemu = 1;
            break;
          }
          temp = temp->next;
        }
        
        if (ketemu == 1) {
          printf("'%s': ADA (benar)\n", kata);
          benar++;
        } else {
            // kalau ga ketemu cari saran typo huruf pertamanya
            char* saran = cari_saran(hashTable, kata);
            
            if (saran != NULL) {
              printf("'%s': TIDAK ADA. Mungkin maksud: '%s'?\n", kata, saran);
            } else {
              printf("'%s': TIDAK ADA.\n", kata);
            }
            salah++;
        }
        kata = strtok(NULL, " ");
      }
      
      // cetak
      printf("\nRingkasan:\n");
      printf("Kata benar: %d\n", benar);
      printf("Kata salah : %d\n", salah);
    }
  return 0;
}