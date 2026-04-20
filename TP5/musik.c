// nama : Deden Ahmad Jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musik.h"

// pabrik node
Musik* createNode(char mood[], char judul[], int durasi, int idTarget){
  // pesan node
  Musik *baru = (Musik*) malloc(sizeof(Musik));
  
  static int counter = 1; // biar auto naik
  if (idTarget == -1)
  {
    baru->id = counter++;
  }else{
    baru->id = idTarget;
  }
  // copy isi node
  strcpy(baru->mood, mood);
  strcpy(baru->judul, judul);
  baru->durasi = durasi;
  
  baru->next = NULL;
  baru->prev = NULL;

  return baru;
}

// fungsi pembantu
int getPriority(char m[]) {
    if (strcmp(m, "Energetic") == 0) return 3;
    if (strcmp(m, "Chill") == 0) return 2;
    if (strcmp(m, "Sad") == 0) return 1;
    return 0;
}

void addSongs(Musik **head, Musik **tail, char mood[], char judul[], int durasi, int idTarget) {
    Musik *baru = createNode(mood, judul, durasi, idTarget);
    if (baru == NULL) return;

    if (*head == NULL) {
        *head = baru;
        *tail = baru;
        printf("\nLagu '%s' berhasil ditambahkan!\n", baru->judul);
        return;
    }

    int priorityBaru = getPriority(baru->mood);
    Musik *temp = *head;

    while (temp != NULL) {
        int priorityTemp = getPriority(temp->mood);

        // Logika Sorting: Mood dulu, baru durasi Descending
        if (priorityBaru > priorityTemp || (priorityBaru == priorityTemp && baru->durasi > temp->durasi)) {
            break;
        }
        temp = temp->next;
    }

    // Logika penyambungan pointer next & prev
    if (temp == *head) {
        baru->next = *head;
        (*head)->prev = baru;
        *head = baru;
    } else if (temp == NULL) {
        (*tail)->next = baru;
        baru->prev = *tail;
        *tail = baru;
    } else {
        baru->next = temp;
        baru->prev = temp->prev;
        temp->prev->next = baru;
        temp->prev = baru;
    }

    printf("\nLagu '%s' berhasil ditambahkan!\n", baru->judul);
}

void tampilPlaylistForward(Musik *head) {
  // variabel pencari
  Musik *temp = head;

  // validasi kalo playlistnya masi kosong
  if (temp == NULL)
  {
    printf("Playlist kosong!!\n");
    return;
  }

  printf("\n--- PLAYLIST (Awal ke Akhir) ---\n");
  // tempt akan terus berjalan sekaligus mencetak
  while (temp != NULL)
  {
    printf("[%d] %-20s | %-10s | %d s\n", temp->id, temp->judul, temp->mood, temp->durasi);
    temp = temp->next;
  }
}

void tampilPlaylistBackward(Musik *head) {
  // variabel pencari
  Musik *temp = head;

  // validasi kalo playlistnya masi kosong
  if (temp == NULL)
  {
    printf("Playlist kosong!!\n");
    return;
  }

  // temp nya biar maju
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  
  // proses print
  printf("\n--- PLAYLIST (Akhir ke Awal) ---\n");
  while (temp != NULL)
  {
    printf("[%d] %-20s | %-10s | %d s\n", temp->id, temp->judul, temp->mood, temp->durasi);
    temp = temp->prev;
  }
}

void updateJudul(Musik **head, char judulBaru[], int targetIdJudul) {
  // variabel buat jalan"
  Musik *temp = *head;
  // tempnya akan berhenti di targetid
  while (temp != NULL && temp->id != targetIdJudul )
  {
    temp = temp->next;
  }

  // kalo target id nya ga ketemu
  if (temp == NULL)
  {
    printf("Data dengan ID %d tidak ditemukan.\n", targetIdJudul);
    return;
  }

  // validasi untuk merubah data judul harus lebih dari 0 kata
  if (strlen(judulBaru) > 0)
  {
    strcpy(temp->judul, judulBaru);
  }

  printf("Judul Berhasil di perbaharui!\n");
}

void updateDurasi(Musik **head, Musik **tail, int durasiBaru, int targetIdDurasi) {
  // variabel buat jalan"
  Musik *temp = *head;
  // tempnya akan berhenti di targetid
  while (temp != NULL && temp->id != targetIdDurasi )
  {
    temp = temp->next;
  }

  // kalo target id nya ga ketemu
  if (temp == NULL)
  {
    printf("Data dengan ID %d tidak ditemukan.\n", targetIdDurasi);
    return;
  }

  // validasi untuk merubah data judul harus lebih dari 0 kata
  if (durasiBaru > 0)
  {
    // simpan data lama beserta idnya
    int idLama = temp->id;
    // untuk menyimpan data lagu sementara
    char m[50], j[100];
    strcpy(m, temp->mood);
    strcpy(j, temp->judul);

    if (temp == *head) {
        *head = (*head)->next;
        if (*head) (*head)->prev = NULL;
        else *tail = NULL; // List jadi kosong
    } else if (temp == *tail) {
        *tail = (*tail)->prev;
        if (*tail) (*tail)->next = NULL;
        else *head = NULL; // List jadi kosong
    } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    addSongs(head, tail, m, j, durasiBaru, idLama);
    printf("Durasi diperbaharui dan posisi playlist disesuaikan!\n");
    tampilPlaylistForward(*head);
  }

}

void hapusAwal(Musik **head, Musik **tail) {
  // untuk kalo datanya kosong
  if (*head == NULL)
  {
    printf("List Kosong, Tidak ada yang di hapus.\n");
    return; 
  }

  // variabel sementara
  Musik *temp = *head;
  if (*head == *tail)
  {
    // hanya satu node
    *head = NULL;
    *tail = NULL;
  }else{
    *head = (*head)->next;
    (*head)->prev = NULL;
  }
  printf("Lagu '%s' dihapus dari urutan pertama.\n", temp->judul);
  free(temp);
}

void hapusAkhir(Musik **head, Musik **tail) {
  // untuk kalo datanya kosong
  if (*head == NULL)
  {
    printf("List Kosong, Tidak ada yang di hapus.\n");
    return; 
  }

  // variabel sementara
  Musik *temp = *tail;
  if (*head == *tail)
  {
    // hanya satu node
    *head = NULL;
    *tail = NULL;
  }else{
    *tail = (*tail)->prev;
    (*tail)->next = NULL;
  }
  printf("Lagu '%s' dihapus dari urutan terakhir.\n", temp->judul);
  free(temp);
}

void hapusBerdasarkanJudul(Musik **head, Musik **tail, char targetJudul[]) {
    // kalo list kosong
    if (*head == NULL) {
        printf("Playlist kosong, tidak ada yang bisa dihapus.\n");
        return;
    }

    Musik *temp = *head;

    // Cari node yang judulnya sama dengan target
    while (temp != NULL && strcmp(temp->judul, targetJudul) != 0) {
        temp = temp->next;
    }

    // kalo judul ga ketemu
    if (temp == NULL) {
        printf("Lagu dengan judul '%s' tidak ditemukan.\n", targetJudul);
        return;
    }

    // Proses penghapusan berdasarkan posisi node
    if (temp == *head) {
        // kalo target adalah node pertama 
        hapusAwal(head, tail);
    } else if (temp == *tail) {
        // kalo target adalah node terakhir
        hapusAkhir(head, tail);
    } else {
        // kalo target berada di tengah 
        temp->prev->next = temp->next; // Sambungin prev ke next
        temp->next->prev = temp->prev; // Sambungin next ke prev
        printf("Lagu '%s' berhasil dihapus dari playlist.\n", temp->judul);
        free(temp);
    }
}