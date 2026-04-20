// nama : deden
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lish.h"

// untuk membuat node baru yang di ujungnya null
Lish* createNode (int noAntrean, char nama[], char pesanan[]) {
  // pesan node 
  Lish *baru = (Lish*) malloc(sizeof(Lish));

  // input nodenya
  baru->noAntrean = noAntrean;
  strcpy(baru->nama, nama);
  strcpy(baru->pesanan, pesanan);

  // node baru alamatnya null
  baru->next = NULL;

  return baru;
}

// untuk masukin node ke paling depan
void insertAwal(Lish **head, int noAntrean, char nama[], char pesanan[]) {
  // seperti biasa bikin node baru
  Lish *baru = createNode(noAntrean, nama, pesanan);

  // node baru pegang dulu mantan yang punya head
  baru->next = *head;
  // head sekarang pacarnya baru
  *head = baru;
  printf("Lish berhasil ditambahkan di awal daftar!\n");
}

// nambahin node di paling ujung dan alamatnya harus di nul in
void insertAkhir(Lish **head, int noAntrean, char nama[], char pesanan[]) {
  // bikin node memannggil fungsi membuat node
  Lish *baru = createNode(noAntrean, nama, pesanan);

  // kalo headnya masi kosong/ nodenya belum ada maka node baru jadi head
  if (*head == NULL)
  {
    *head = baru;
  }else {
    // buat temp untuk jalan" cari node paling ujung
    Lish *temp = *head;
    // prulangan ini akan maju terus sampe nemu node yang alamatnya null
    while(temp->next != NULL) {
      temp = temp->next;
    }
    // ketika selesai loop maka temp akan berenti dan kemudia node(baru) akan di simpan disitu
    temp->next = baru;
  }
  printf("Lish berhasil ditambahkan di akhir daftar!\n");
}

// untuk memasukan data sebelum target
void insertSebelum(Lish **head, int noAntrean, char nama[], char pesanan[], int noAntreanAcuan) {
  Lish *baru = createNode(noAntrean, nama, pesanan);

  // kalo head == nul maka node baru jadi head
  if (*head == NULL)
  {
    *head = baru;
    return;
  }

  // kalo noAntreanacuan nya itu di node pertama (head)
  if ((*head)->noAntrean == noAntreanAcuan)
  {
    baru->next = *head;
    *head = baru;
    return;
  }
  
  Lish *temp = *head;
  Lish *prev = NULL;
  // cari sampai ketemu noAntreanacuan nya
  while (temp != NULL && temp->noAntrean != noAntreanAcuan)
  {
    prev = temp;
    temp = temp->next;
  }
  
  // proses memasukan nodenya
  if (temp != NULL)
  {
    baru->next = temp;   // node baru pegang alamat noAntreanacuan
    prev->next = baru;   // prev pegang alamat node baru
  }else {
    printf("Target tidak ditemukan!\n");
    free(baru);
  }
  printf("Lish berhasil ditambahkan di sebelum noAntrean: %d\n", noAntreanAcuan);
}

// untuk memasukan node setelah target
void insertSetelah(Lish **head, int noAntrean, char nama[], char pesanan[], int noAntreanAcuan) {
  Lish *baru = createNode(noAntrean, nama, pesanan);

  // kalo head == nul maka node baru jadi head
  if (*head == NULL)
  {
    free(baru);
    return;
  }

  Lish *temp = *head;

  // cari sampai ketemu noAntreanacuan nya
  while(temp != NULL && temp->noAntrean != noAntreanAcuan) {
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
  printf("Lish berhasil ditambahkan di setelah noAntrean: %d!\n", noAntreanAcuan);
}

// prosedur hapus node sebelum acuan
void deleteSebelum(Lish **head, int noAntreanAcuan) {
    // Validasi awal: Jika list kosong atau cuma ada 1 node
    if (*head == NULL || (*head)->next == NULL) {
        printf("Gagal: Antrean kosong atau hanya ada 1 data, tidak ada yang bisa dihapus.\n");
        return;
    }

    // Jika target adalah node pertama (head), tidak ada node sebelumnya
    if ((*head)->noAntrean == noAntreanAcuan) {
        printf("Gagal: Target berada di awal, tidak ada data sebelumnya!\n");
        return;
    }

    // Kasus khusus: Jika node yang akan dihapus adalah head (target ada di node kedua)
    if ((*head)->next->noAntrean == noAntreanAcuan) {
        Lish *hapus = *head;
        *head = (*head)->next; // Head geser ke node kedua (si target)
        printf("Data nomor %d (%s) berhasil dihapus!\n", hapus->noAntrean, hapus->nama);
        free(hapus);
        return;
    }

    // Traversal untuk mencari node 2 langkah sebelum target
    Lish *temp = *head;
    while (temp->next->next != NULL && temp->next->next->noAntrean != noAntreanAcuan) {
        temp = temp->next;
    }

    // Eksekusi penghapusan jika target ditemukan
    if (temp->next->next != NULL) {
        Lish *hapus = temp->next;
        temp->next = hapus->next; // Sambungkan temp melewati node yang dihapus
        printf("Data nomor %d (%s) berhasil dihapus!\n", hapus->noAntrean, hapus->nama);
        free(hapus);
    } else {
        printf("Target tidak ditemukan!\n");
    }
}

// prosedur hapus node berdasarkan acuan
void deleteSetelah(Lish **head, int noAntreanAcuan) {
    if (*head == NULL) return;

    Lish *temp = *head;

    // Cari sampai ketemu noAntreanacuan nya
    while(temp != NULL && temp->noAntrean != noAntreanAcuan) {
        temp = temp->next;
    }

    // Pastikan target ditemukan DAN ada node setelahnya untuk dihapus
    if (temp != NULL && temp->next != NULL) {
        Lish *hapus = temp->next;     // Simpan alamat node yang akan dihapus
        temp->next = hapus->next;     // Sambungkan temp ke node setelah hapus
        
        printf("Data nomor %d (%s) berhasil dihapus (setelah %d).\n", hapus->noAntrean, hapus->nama, noAntreanAcuan);
        
        free(hapus);                  //hapus dari memori
    } else {
        printf("Target tidak ditemukan atau tidak ada data setelahnya!\n");
    }
}

// prosedur update
void updateLish(Lish *head, int noAntrean) {
    Lish *temp = head;
    char buffer[100];

    // Cari node
    while (temp != NULL && temp->noAntrean != noAntrean) {
        temp = temp->next;
    }

    if (temp != NULL) {
        // Membersihkan buffer stdin hanya SEKALI untuk membuang \n dari scanf di main
        getchar(); 

        // Update Nama
        printf("Nama baru (kosongkan jika tidak diubah): ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) { 
            buffer[strcspn(buffer, "\n")] = 0; 
            strcpy(temp->nama, buffer);
        }

        // Update Pesanan
        printf("Pesanan baru (kosongkan jika tidak diubah): ");
        fgets(buffer, sizeof(buffer), stdin);
        if (strlen(buffer) > 1) { 
            buffer[strcspn(buffer, "\n")] = 0; 
            strcpy(temp->pesanan, buffer); 
        }
        printf("Data nomor %d berhasil diperbaharui.\n", noAntrean);
    } else {
        printf("Data tidak ditemukan!\n");
    }
}

// menampilkan seluruhnya
void printList(Lish *head){
    Lish *temp = head;
    // validasi
    if(temp == NULL){
        printf("\nJadwal masih kosong !!\n");
        return;
    }
    printf("\nDaftar Antrian Pelanggan:\n");
    
    printf("\nNo     Nama                  Pesanan\n");
    printf("-----------------------------------------\n");
    while(temp != NULL){
      printf("%-3d    %-18s    %-5s\n", temp->noAntrean, temp->nama, temp->pesanan);        
      temp = temp->next;
    }
    printf("-----------------------------------------\n");
}