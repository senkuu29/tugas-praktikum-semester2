#include <stdio.h>

void tambahDataBuku()
{
  int isbn;
  char judul[50];
  char kategori[50];

  printf("\n=== TAMBAH DATA BUKU ===\n");
  printf("Masukkan ISBN: ");
  scanf(" %d", &isbn);
  printf("Masukkan Judul: ");
  scanf(" %[^\n]s", judul);
  printf("Masukkan Kategori: ");
  scanf(" %s", kategori);

  printf("\nhasil inputan\n");
  printf("isbn: %d\n", isbn);
  printf("judul: %s\n", judul);
  printf("kategori: %s\n", kategori);
  printf("\n");
}

void tampilkanDataBuku()
{
}

void editDataBuku()
{
}

void hapusDataBuku()
{
}

void tampilkan_menu()
{
  printf("======================================\n");
  printf("\tSISTEM MANAJEMEN DATA BUKU\n");
  printf("======================================\n");
  printf("1. Tambah Data Buku\n");
  printf("2. Tampilkan Data Buku\n");
  printf("3. Edit Data Buku\n");
  printf("4. Hapus Data Buku\n");
  printf("5. Keluar\n");
  printf("======================================\n");
  printf("Pilih Menu: ");
}

int main()
{
  int pilihan;
  do
  {
    tampilkan_menu();
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
      tambahDataBuku();
      break;
    case 2:
      tampilkanDataBuku();
      break;
    case 3:
      editDataBuku();
      break;
    case 4:
      hapusDataBuku();
      break;
    case 5:
      printf("\nTerima kasih! Program selesai.\n");
      break;
    default:
      printf("Pilihan tidak valid! Silakan pilih 1-5.\n");
    }
  } while (pilihan != 5);
  return 0;
}