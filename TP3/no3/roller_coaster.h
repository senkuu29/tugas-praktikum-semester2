// nama : deden ahmad jamil
// nim  : 2501518

#ifndef ROLLER_COASTER_H
#define ROLLER_COASTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struck untuk menyimpan data pengunjung
struct Data {
    char nama[50];
    char kategori[15];
    int tiket;
    struct Data *next;
};

// fungsi untuk membuat gerbong baru di memori heap
struct Data* bikinNode(char nm[], char kt[], int tk) {
    struct Data *baru = (struct Data*)malloc(sizeof(struct Data));
    // salin data yang di input
    strcpy(baru->nama, nm);
    strcpy(baru->kategori, kt);
    baru->tiket = tk;
    baru->next = NULL;
    return baru;
}

// menambah data diawal list logika untuk vip
void tambahDepan(struct Data **head, char nm[], char kt[], int tk) {
    struct Data *baru = bikinNode(nm, kt, tk);
    baru->next = *head; // gerbong lama
    *head = baru;       // gerbong baru
    printf("Peserta %s berhasil ditambahkan!\n", nm);
}

// menambahkan data di akhir list untuk logika reguler
void tambahBelakang(struct Data **head, char nm[], char kt[], int tk) {
    struct Data *baru = bikinNode(nm, kt, tk);
    // kalo kosong gerbong barunya jadi head
    if (*head == NULL) {
        *head = baru;
    } else {
        struct Data *temp = *head;
        // mencari null sampe akhir
        while (temp->next != NULL) temp = temp->next;
        temp->next = baru; // untuk nyambungin gerbong akhir ke gerbong baru
    }
    printf("Peserta %s berhasil ditambahkan!\n", nm);
}

// menyisipkan data sebelum tiket yang di input
void tambahSebelum(struct Data **head, char nm[], char kt[], int tk, int cari) {
    if (*head == NULL) return;
    // kalo posiisi yg disisip udah di depan
    if ((*head)->tiket == cari) {
        tambahDepan(head, nm, kt, tk);
        return;
    }
    struct Data *temp = *head;
    // Mencari node yang berada tepat sebelum tiket target
    while (temp->next != NULL && temp->next->tiket != cari) temp = temp->next;
    if (temp->next != NULL) {
        struct Data *baru = bikinNode(nm, kt, tk);
        baru->next = temp->next; // gerbong baru untuk menunjuk target
        temp->next = baru;       //gerbong sebelumnya menunjuk ke gerbong baru
        printf("Data akan ditambahkan sebelum nomor: %d\n", cari);
        printf("Peserta %s berhasil ditambahkan!\n", nm);
    }
}

// menyisipkan data sesudah nomor tiket tertentuu
void tambahSesudah(struct Data **head, char nm[], char kt[], int tk, int cari) {
    struct Data *temp = *head;
    // mncari gerbong yang ada tiket sesuai targetnya
    while (temp != NULL && temp->tiket != cari) temp = temp->next;
    if (temp != NULL) {
        struct Data *baru = bikinNode(nm, kt, tk);
        baru->next = temp->next;  // gerbong baru mengambil sambungan next dari target
        temp->next = baru;        // gerbong target menunjuk ke gerbong baru
        printf("Data akan ditambahkan setelah nomor: %d\n", cari);
        printf("Peserta %s berhasil ditambahkan!\n", nm);
    }
}
#endif