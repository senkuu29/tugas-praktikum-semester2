// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// adt
typedef struct Node {
    int no_rek;
    char nama[50];
    char jenis_transaksi[50];
    struct Node* next; // pointer buat chaining
} Node;

//fungsi hash
int hash(int no_rek) {
    return ((5 * no_rek + 7) % 11) % SIZE;
}

//fungsi insert
void insert(Node** hashTable, int no_rek, char* nama, char* jenis) {
    int index = hash(no_rek); // hitung masuk laci mana
    
    // pesan memori
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->no_rek = no_rek;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jenis_transaksi, jenis);
    newNode->next = NULL;
    
    // kalau lacinya kosong, langsung isi
    if (hashTable[index] == NULL) {
      hashTable[index] = newNode;
    } else {
      // kalau bentrok, telusuri sampai ujung antrean
      Node* temp = hashTable[index];
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode; // kaitin di paling belakang
    }
}

// fungsi print
void printTable(Node** hashTable) {
    printf("\n--- HASIL PEMETAAN SERVER DATABASE ---\n");
    for (int i = 0; i < SIZE; i++) {
      // cuma nampilin slot yang ada isinya aja
      if (hashTable[i] != NULL) {
        printf("Slot Server [%d]:\n", i);
        Node* temp = hashTable[i];
        
        // telusuri dan cetak semua data di laci ini
        while (temp != NULL) {
          printf(" -> [No. Rek: %d | %s | %s]\n", temp->no_rek, temp->nama, temp->jenis_transaksi);
          temp = temp->next;
        }
      }
    }
}

//fungsi main
int main() {
    //5 slot server kosongg
    Node* hashTable[SIZE] = {NULL};
    
    int no_rek;
    char nama[50];
    char jenis[50];
    
    //input 3 data
    for (int i = 0; i < 3; i++) {
      printf("Masukkan No. Rekening : ");
      scanf("%d", &no_rek);
      
      printf("Masukkan Nama Nasabah : ");
      scanf(" %[^\n]", nama);
      
      printf("Masukkan Jenis Transaksi: ");
      scanf(" %[^\n]", jenis);
      
      // masukin ke tabel
      insert(hashTable, no_rek, nama, jenis);
      
      //jarak
      if(i < 2) {
        printf("\n"); 
      }
    }
    //fungsi cetaknya
    printTable(hashTable);
    return 0;
}