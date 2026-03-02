// Nama : Deden Ahmad Jamil
// NIM  : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roller_coaster.h"

int main() {
    // deklarasi head itu kosong 
    struct Data *head = NULL;
    int menu, no_tiket, tkt_cari, sub;
    char nm_pengunjung[50], kt_pengunjung[15];

    // fiturnya
    printf("\n=== Sistem Pendataan Wahana Roller Coaster ===\n");
    printf("1. Tambah Pengunjung\n");
    printf("2. Tampilkan Daftar Pengunjung\n");
    printf("3. Keluar\n");

    do {
        printf("\nPilih menu: ");
        scanf("%d", &menu);

        if (menu == 1) {
            printf("Masukkan Nama: ");
            scanf("%s", nm_pengunjung);
            printf("Masukkan Kategori (VIP/Reguler): ");
            scanf("%s", kt_pengunjung);
            printf("Masukkan Nomor Tiket: ");
            scanf("%d", &no_tiket);

            // Cek apakah kategori sudah ada di list untuk memicu menu posisi
            int kategoriAda = 0;
            struct Data *ptr = head;
            while(ptr != NULL) {
                if(strcmp(ptr->kategori, kt_pengunjung) == 0) {
                    kategoriAda = 1; // Jika ditemukan kategori yang sama, flag menjadi 1
                    break;
                }
                ptr = ptr->next;
            }

            if (head == NULL || !kategoriAda) {
                // VIP Depan, Reguler Belakang
                if (strcmp(kt_pengunjung, "VIP") == 0) {
                    tambahDepan(&head, nm_pengunjung, kt_pengunjung, no_tiket);
                } else {
                    tambahBelakang(&head, nm_pengunjung, kt_pengunjung, no_tiket);
                }
            } else {
                // Menu ini muncul hanya jika kategori sudah ada
                printf("1. Tambah Tengah Sebelum Nomor Tiket\n");
                printf("2. Tambah Tengah Setelah Nomor Tiket\n");
                printf("Pilih posisi: ");
                scanf("%d", &sub);

                printf("Masukkan Nomor Tiket Target: ");
                scanf("%d", &tkt_cari);

                if (sub == 1) {
                    tambahSebelum(&head, nm_pengunjung, kt_pengunjung, no_tiket, tkt_cari);
                } else {
                    tambahSesudah(&head, nm_pengunjung, kt_pengunjung, no_tiket, tkt_cari);
                }
            }

        } else if (menu == 2) {
            // Melakukan perulangan dari head hingga gerbong terakhir
            printf("\nDaftar Pengunjung:\n");
            struct Data *temp = head;
            int urutan = 1;
            while (temp != NULL) {
                // cetaknya
                printf("%d. %s - %s - nomor tiket %d\n", urutan++, temp->nama, temp->kategori, temp->tiket);
                temp = temp->next;
            }
        }
    } while (menu != 3);

    printf("Keluar dari program...\n");
    return 0;
}