// nama : Deden Ahmad Jamil
// nim : 2501518

// panggil fungsi file
#include "lish.c"

int main(){
  // head == kosong
  Lish *head = NULL;

  // deklarasi variabel
  int pilihan, noAntrean, noAntreanAcuan;
  char nama[50], pesanan[50];

    // fitur utama
    printf("\n=== MENU MANAJEMEN ANTRIAN KAFE ===\n");
    printf("1. Insert Awal\n");
    printf("2. Insert Akhir\n");
    printf("3. Insert Sebelum Nomor Tertentu\n");
    printf("4. Insert Sesudah Nomor Tertentu\n");
    printf("5. Delete Sebelum Nomor Tertentu\n");
    printf("6. Delete Sesudah Nomor Tertentu\n");
    printf("7. Update Data\n");
    printf("8. Tampilkan Semua\n");
    printf("9. Keluar\n");
  do
  {
    printf("\nPilihan: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      // input data
        printf("Masukkan No Antrean   : ");
        scanf(" %d",&noAntrean);

        printf("Masukkan Nama         : ");
        scanf(" %[^\n]", nama);

        printf("Masukkan Pesanan      : ");
        scanf(" %[^\n]", pesanan);

      insertAwal(&head, noAntrean, nama, pesanan);
      break;
    case 2:
      // input data
        printf("Masukkan No Antrean   : ");
        scanf(" %d",&noAntrean);

        printf("Masukkan Nama         : ");
        scanf(" %[^\n]", nama);

        printf("Masukkan Pesanan      : ");
        scanf(" %[^\n]", pesanan);
        
      insertAkhir(&head, noAntrean, nama, pesanan);
      break;
    case 3:
      // input data
        printf("Masukkan No Antrean Acuannya  : ");
        scanf(" %d",&noAntreanAcuan);

        printf("Masukkan No Antrean           : ");
        scanf(" %d",&noAntrean);

        printf("Masukkan Nama                 : ");
        scanf(" %[^\n]", nama);

        printf("Masukkan Pesanan              : ");
        scanf(" %[^\n]", pesanan);
        
      insertSebelum(&head, noAntrean, nama, pesanan, noAntreanAcuan);
      break;
    case 4:
      // input data
        printf("Masukkan No Antrean Acuannya  : ");
        scanf(" %d",&noAntreanAcuan);

        printf("Masukkan No Antrean           : ");
        scanf(" %d",&noAntrean);

        printf("Masukkan Nama                 : ");
        scanf(" %[^\n]", nama);

        printf("Masukkan Pesanan              : ");
        scanf(" %[^\n]", pesanan);
        
      insertSetelah(&head, noAntrean, nama, pesanan, noAntreanAcuan);
      break;
    case 5:
        printf("Masukkan No target (sebelum) : ");
        scanf(" %d", &noAntreanAcuan);
        deleteSebelum(&head, noAntreanAcuan);
        break;
      break;
    case 6:
        printf("Masukkan No target (sesudah)  : ");
        scanf(" %d",&noAntreanAcuan);

      deleteSetelah(&head, noAntreanAcuan);
      break;
    case 7:
        printf("Masukkan Nomor yang akan diupdate: ");
        scanf(" %d", &noAntrean);

        updateLish(head, noAntrean);
      break;
    case 8:
      printList(head);
      break;
    case 9:
      printf("Program Selesai...\n");
      break;
    
    default:
      printf("\nPilihan Tidak Sesuai coba Pilih (1-9) !!");
      break;
    }

  } while (pilihan !=9);
}