// nama : deden ahmad jamil
// nim : 2501518

#include "header_no2.h"

int main(){
    Klinik antrean;
    initStack(&antrean);

    int jumlahPasien;
    printf("Masukkan jumlah pasien: ");
    scanf("%d", &jumlahPasien);

    // validasi jika input jumlah pasien 0
    if (jumlahPasien <= 0) {
        printf("Jumlah pasien tidak valid.\n");
        return 0;
    }

    int tempInput[100]; // varibel sementara untuk menampung input

    printf("Masukkan kode prioritas pasien (dipisah spasi): ");
   // Langkah 1: Simpan semua input ke array sementara
    for (int i = 0; i < jumlahPasien; i++) {
        scanf("%d", &tempInput[i]);
    }

    // langkah 2 Push ke stack secara terbalik (dari kanan ke kiri)
    // supaya elemen pertama (kiri) masuk terakhir dan menjadi TOP
    for (int i = jumlahPasien - 1; i >= 0; i--) {
        push(&antrean, tempInput[i]); 
    }

    int valid = 1; // asumsi awal stack valid 1 = true 0 = false

    // ambil elemen paling atas sebagai pembanding awal
    int prev_val = pop(&antrean);

    // looping selama stack belum kosong
    while (!isEmpty(&antrean)) {
      int curr_val = pop(&antrean); // ambil elemen tepat di bawahnya

      // curr_val adalah elemen bawah prev_val adalah elemen atas
      if (curr_val < prev_val) {
        valid = 0; // langsung tandai tidak valid
        break;     // berhenti karena salah
      }

      // update prev_val untuk pengecekan elemen di bawahnya lagi
      prev_val = curr_val;
    }

    // output hasilnya
    printf("\nOutput:\n");
    if (valid) {
      printf("Urutan antrian VALID - Pasien dengan prioritas tinggi berada di atas.\n");
    } else {
      printf("Urutan antrian TIDAK VALID! Pasien dengan prioritas tinggi tertumpuk di bawah pasien dengan prioritas lebih rendah.\n");
    }

    return 0;
}