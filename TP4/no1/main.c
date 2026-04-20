// nama : Deden Ahmad Jamil
// nim : 2501518

// panggil fungsi file
#include "bioskop.c"

int main(){
  // head == kosong
  Film *head = NULL;

  // deklarasi variabel
  int pilihan;
  int subPilihan;
  int n;
  int id;
  int idAcuan;
  char judul[50];
  char jam[30];
  do
  {
    // fitur utama
    printf("\n=== MANAJEMEN BIOSKOP ===\n");
    printf("1. Tambah Film (Awal/akhir/tengah)\n");
    printf("2. Update Data Film\n");
    printf("3. Hapus Film (Awal/Akhir)\n");
    printf("4. Lihat Seluruh Jadwal\n");
    printf("5. Keluar\n");
    printf("Pilih Menu: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      // sub fitur di fitur utama 1
      printf("\n1. Awal\n");
      printf("2. Akhir\n");
      printf("3. Sebelum ID tertentu\n");
      printf("4. Sesudah ID tertentu\n");
      printf("pilih posisi: ");
      scanf(" %d", &subPilihan);
      switch (subPilihan)
      {
        case 1:
          // input data
          printf("ID Film: ");
          scanf("%d",&id);

          // validasi duplikasi
          if (isIdDuplicate(head, id)) {
            printf("Error: ID %d sudah terdaftar. Gunakan ID unik!\n", id);
            break; 
          }

          printf("Judul: ");
          scanf(" %[^\n]", judul);

          printf("Jam tayang: ");
          scanf(" %[^\n]", jam);

          // masukkan data tersebut ke fungsi
          insertAwal(&head, id, judul, jam);
          break;
        case 2:
          // input data
          printf("ID Film: ");
          scanf("%d",&id);

          // validasi duplikasi
          if (isIdDuplicate(head, id)) {
            printf("Error: ID %d sudah terdaftar. Gunakan ID unik!\n", id);
            break; 
          }

          printf("Judul: ");
          scanf(" %[^\n]", judul);

          printf("Jam tayang: ");
          scanf(" %[^\n]", jam);

          // masukan datanya ke fungsi
          insertAkhir(&head, id, judul, jam);
          break;
        case 3:
          // input data
          printf("ID Film: ");
          scanf("%d",&id);

          // validasi duplikasi
          if (isIdDuplicate(head, id)) {
            printf("Error: ID %d sudah terdaftar. Gunakan ID unik!\n", id);
            break; 
          }
          
          printf("Judul: ");
          scanf(" %[^\n]", judul);
          
          printf("Jam tayang: ");
          scanf(" %[^\n]", jam);
          
          printf("Masukkan ID acuan: ");
          scanf("%d",&idAcuan);

          // masukan datanya ke fungsi
          insertSebelum(&head, id, judul, jam, idAcuan);
          break;
        case 4:
          // input data
          printf("ID Film: ");
          scanf("%d",&id);

          // validasi duplikasi
          if (isIdDuplicate(head, id)) {
            printf("Error: ID %d sudah terdaftar. Gunakan ID unik!\n", id);
            break; 
          }
          
          printf("Judul: ");
          scanf(" %[^\n]", judul);
          
          printf("Jam tayang: ");
          scanf(" %[^\n]", jam);
          
          printf("Masukkan ID acuan: ");
          scanf("%d",&idAcuan);

          // masukan datanya ke fungsi
          insertSetelah(&head, id, judul, jam, idAcuan);
          break;
        default:
          break;
        }
        break;
    case 2:
      printf("\nID film yang diupdate: ");
      scanf("%d",&id);

      updateFilm(head,id);
      break;
    case 3:
        printf("\n1. Hapus Awal\n");
        printf("2. Hapus Akhir\n");
        printf("Pilih Menu: ");
        scanf(" %d", &n);
          switch (n)
          {
          case 1:
            deleteAwal(&head);
            break;
            case 2:
            deleteAkhir(&head);
            break;
          default:
            break;
          }
      break;
    case 4:
        printList(head);
      break;
    case 5:
       printf("Program selesai...\n");
      break;
    default:
      break;
    }
  } while (pilihan != 5);
}