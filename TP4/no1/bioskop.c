// nama : deden
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bioskop.h"

// untuk membuat node baru yang di ujungnya null
Film* createNode (int id, char judul[], char jam[]) {
  // pesan node 
  Film *baru = (Film*) malloc(sizeof(Film));

  // input nodenya
  baru->id = id;
  strcpy(baru->judul, judul);
  strcpy(baru->jam, jam);

  // node baru alamatnya null
  baru->next = NULL;

  return baru;
}

// nambahin node di paling ujung dan alamatnya harus di nul in
void insertAkhir(Film **head, int id, char judul[], char jam[]) {
  // bikin node memannggil fungsi membuat node
  Film *baru = createNode(id, judul, jam);

  // kalo headnya masi kosong/ nodenya belum ada maka node baru jadi head
  if (*head == NULL)
  {
    *head = baru;
  }else {
    // buat temp untuk jalan" cari node paling ujung
    Film *temp = *head;
    // prulangan ini akan maju terus sampe nemu node yang alamatnya null
    while(temp->next != NULL) {
      temp = temp->next;
    }
    // ketika selesai loop maka temp akan berenti dan kemudia node(baru) akan di simpan disitu
    temp->next = baru;
  }
  printf("Film berhasil ditambahkan di akhir daftar!\n");
}

// untuk masukin node ke paling depan
void insertAwal(Film **head, int id, char judul[], char jam[]) {
  // seperti biasa bikin node baru
  Film *baru = createNode(id, judul, jam);

  // node baru pegang dulu mantan yang punya head
  baru->next = *head;
  // head sekarang pacarnya baru
  *head = baru;
  printf("Film berhasil ditambahkan di awal daftar!\n");
}

// untuk memasukan data sebelum target
void insertSebelum(Film **head, int id, char judul[], char jam[], int idAcuan) {
  Film *baru = createNode(id, judul, jam);

  // kalo head == nul maka node baru jadi head
  if (*head == NULL)
  {
    *head = baru;
    return;
  }

  // kalo idacuan nya itu di node pertama (head)
  if ((*head)->id == idAcuan)
  {
    baru->next = *head;
    *head = baru;
    return;
  }
  
  Film *temp = *head;
  Film *prev = NULL;
  // cari sampai ketemu idacuan nya
  while (temp != NULL && temp->id != idAcuan)
  {
    prev = temp;
    temp = temp->next;
  }
  
  // proses memasukan nodenya
  if (temp != NULL)
  {
    baru->next = temp;   // node baru pegang alamat idacuan
    prev->next = baru;   // prev pegang alamat node baru
  }else {
    printf("Target tidak ditemukan!\n");
    free(baru);
  }
  printf("Film berhasil ditambahkan di sebelum ID: %d!\n", idAcuan);
}

// untuk memasukan node setelah target
void insertSetelah(Film **head, int id, char judul[], char jam[], int idAcuan) {
  Film *baru = createNode(id, judul, jam);

  // kalo head == nul maka node baru jadi head
  if (*head == NULL)
  {
    free(baru);
    return;
  }

  Film *temp = *head;

  // cari sampai ketemu idacuan nya
  while(temp != NULL && temp->id != idAcuan) {
    temp = temp->next;
  }

  // cara nyambunginnya
  if (temp != NULL)
  {
    baru->next = temp->next;  // node baru pegang alamat temp selanjutnya
    temp->next = baru;        // temp sebelumnya pegang node baru
  }else {
    printf("Target tidak ditemukan!\n");
    free(baru);
  }
  printf("Film berhasil ditambahkan di setelah ID: %d!\n", idAcuan);
}

// menampilkan seluruhnya
void printList(Film *head){
    Film *temp = head;
    // validasi
    if(temp == NULL){
        printf("\nJadwal kosong\n");
        return;
    }
    printf("\nDAFTAR JADWAL TAYANG BIOSKOP:\n");
    printf("----------------------------------------\n");
    while(temp != NULL){
      printf("ID: %-3d   | %-15s   | Pukul: %-5s\n", temp->id, temp->judul, temp->jam);        
      temp = temp->next;
    }
    printf("----------------------------------------\n");
}

void updateFilm(Film *head, int id){
    Film *temp = head;

    while(temp != NULL && temp->id != id){
        temp = temp->next;
    }

    if(temp != NULL){
        printf("Judul baru: ");
        scanf(" %[^\n]", temp->judul);

        printf("Jam baru: ");
        scanf(" %[^\n]", temp->jam);
    }else{
        printf("Film tidak ditemukan\n");
    }
    printf("Data berhasil di Update!\n");
}

// prosedur delete paling awal
void deleteAwal(Film **head){
    if(*head == NULL){
        printf("List kosong\n");
        return;
    }

    Film *hapus = *head;
    *head = (*head)->next;
    free(hapus);
    printf("Jadwal awal berhasil dihapus!\n");
}

// prosedur delete paling akhir
void deleteAkhir(Film **head){
    if(*head == NULL){
        printf("List kosong\n");
        return;
    }

    if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    Film *temp = *head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    
    printf("Jadwal terakhir berhasil dihapus!\n");
}

// Fungsi untuk mengecek apakah ID sudah ada (0 = unik, 1 = duplikat)
int isIdDuplicate(Film *head, int id) {
    Film *temp = head;
    while (temp != NULL) {
        if (temp->id == id) {
            return 1; // Ketemu ID yang sama
        }
        temp = temp->next;
    }
    return 0; // ID aman/unik
}