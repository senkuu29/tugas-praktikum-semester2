// nama    : deden ahmad jamil
// nim     : 2501518
// perihal : program untuk mendata buku

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
  int id;
  char isbn[20];
  char judul[100];
  char kategori[50];
} Buku;

// variabel global
Buku buku_baru[100];
int jumlahBuku = 0;
int nextID = 1;

void tambahDataBuku()
{
  char tempISBN[20];
  printf("\n=== TAMBAH DATA BUKU ===\n");
  printf("Masukkan ISBN: ");
  scanf(" %[^\n]s", tempISBN);

  // validasi isbn
  for (int i = 0; i < jumlahBuku; i++)
  {
    if (strcmp(buku_baru[i].isbn, tempISBN) == 0)
    {
      printf("Error: ISBN %s sudah ada! Data tidak disimpan.\n", tempISBN);
      return;
    }
  }

  buku_baru[jumlahBuku].id = nextID;
  // Jika lolos validasi, simpan ke array pada indeks 'jumlahBuku'
  strcpy(buku_baru[jumlahBuku].isbn, tempISBN);

  printf("Masukkan Judul: ");
  scanf(" %[^\n]s", buku_baru[jumlahBuku].judul);

  printf("Masukkan Kategori: ");
  scanf(" %[^\n]s", buku_baru[jumlahBuku].kategori);

  printf("\nData buku berhasil ditambahkan!\n");
  printf("ID Buku: %d\n", nextID);

  nextID++;
  jumlahBuku++;
  printf("\n");
}

void tampilkanSemuaData()
{
  if (jumlahBuku == 0)
  {
    printf("\nTidak ada data buku\n");
    return;
  }

  printf("\n=== DAFTAR SEMUA BUKU ===\n");
  printf("Index    ISBN             Judul                           Kategori\n");
  printf("==================================================================\n");
  for (int i = 0; i < jumlahBuku; i++)
  {
    printf("%-8d %-16s %-31s %-15s\n", i, buku_baru[i].isbn, buku_baru[i].judul, buku_baru[i].kategori);
  }
}

void tampilkanBerdasarkanKategori()
{
  char tempKategori[50];
  int ditemukan = 0;

  printf("\n=== TAMPILAN BUKU BERDASARKAN KATEGORI ===\n");
  printf("Masukkan Kategori: ");
  scanf(" %[^\n]s", tempKategori);

  for (int i = 0; i < jumlahBuku; i++)
  {
    if (strcasecmp(tempKategori, buku_baru[i].kategori) == 0)
    {
      if (ditemukan == 0)
      {
        printf("\nISBN             Judul                           Kategori\n");
        printf("=========================================================\n");
      }
      printf("%-16s %-31s %-15s\n", buku_baru[i].isbn, buku_baru[i].judul, buku_baru[i].kategori);
      ditemukan = 1;
    }
  }

  if (!ditemukan)
  {
    printf("Kategori tidak ditemukan.\n");
  }
}

void tampilkanDataBuku()
{
  int pilihan;

  printf("\n=== MENU TAMPILKAN DATA ===\n");
  printf("1. Tampilkan Semua Data\n");
  printf("2. Tampilkan Berdasarkan Kategori\n");
  printf("Pilih: ");
  scanf("%d", &pilihan);

  switch (pilihan)
  {
  case 1:
    tampilkanSemuaData();
    break;
  case 2:
    tampilkanBerdasarkanKategori();
    break;
  default:
    printf("Pilihan tidak valid! Silakan pilih 1-2.\n");
    break;
  }
}

void editDataBuku()
{
  // deklarasi variabel
  char tempIsbn[50];
  char isbnBaru[50];
  char judulBaru[50];
  char kategoriBaru[50];

  printf("Masukkan ISBN buku yang akan di edit: ");
  scanf(" %[^\n]s", tempIsbn);

  for (int i = 0; i < jumlahBuku; i++)
  {
    // ngebandingan isi isbn dengan strcmp
    if (strcasecmp(tempIsbn, buku_baru[i].isbn) == 0)
    {
      printf("\nData buku ditemukan:\n");
      printf("ISBN: %s\n", buku_baru[i].isbn);
      printf("Judul: %s\n", buku_baru[i].judul);
      printf("Kategori: %s\n", buku_baru[i].kategori);

      printf("\n--- Masukkan Data Baru ---\n");
      printf("ISBN baru: ");
      scanf(" %[^\n]s", isbnBaru);

      // Validasi ISBN Baru
      for (int j = 0; j < jumlahBuku; j++)
      {
        if (i != j && strcmp(buku_baru[j].isbn, isbnBaru) == 0)
        {
          printf("Error: ISBN %s sudah ada! Edit dibatalkan.\n", isbnBaru);
          return;
        }
      }

      printf("Judul baru: ");
      scanf(" %[^\n]s", judulBaru);
      printf("Kategori baru: ");
      scanf(" %[^\n]s", kategoriBaru);

      // memasukan data baru ke variabel di struct
      strcpy(buku_baru[i].isbn, isbnBaru);
      strcpy(buku_baru[i].judul, judulBaru);
      strcpy(buku_baru[i].kategori, kategoriBaru);

      printf("\nData buku berhasil diupdate!\n");
      return;
    }
  }
  printf("Buku tidak ditemukan.\n");
}

void hapusDataBuku()
{
  // deklar variabel
  int indexHapus;
  char konfirmasi;

  // validasi
  if (jumlahBuku == 0)
  {
    printf("\nTidak ada data buku untuk dihapus.\n");
    return;
  }

  printf("\n=== HAPUS DATA BUKU ===\n");
  printf("--- Data Sebelum Penghapusan ---\n");
  // prosedur untuk menampilkan data semua
  tampilkanSemuaData();

  printf("\nMasukkan index buku yang akan dihapus: ");
  scanf("%d", &indexHapus);

  // validasi
  if (indexHapus < 0 || indexHapus >= jumlahBuku)
  {
    printf("Index tidak valid!\n");
    return;
  }

  printf("\nAnda akan menghapus buku:\n");
  printf("ISBN: %s\n", buku_baru[indexHapus].isbn);
  printf("Judul: %s\n", buku_baru[indexHapus].judul);
  printf("Kategori: %s\n", buku_baru[indexHapus].kategori);

  printf("\nApakah Anda yakin? (y/n): ");
  scanf(" %c", &konfirmasi);

  if (konfirmasi == 'y' || konfirmasi == 'Y')
  {
    // Array digeser/dipadatkan (Aturan Poin 4c)
    for (int i = indexHapus; i < jumlahBuku - 1; i++)
    {
      buku_baru[i] = buku_baru[i + 1];
    }

    jumlahBuku--;
    printf("\nData buku berhasil dihapus!\n");

    printf("\n--- Data Setelah Penghapusan ---\n");
    tampilkanSemuaData();
  }
  else
  {
    printf("Penghapusan dibatalkan.\n");
  }
}

void tampilkan_menu()
{
  printf("\n======================================\n");
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
  // menggunakan do while karena supaya tampil terus
  do
  {
    tampilkan_menu();
    if (scanf("%d", &pilihan) != 1)
    {
      while (getchar() != '\n')
        ; // Clear buffer
      continue;
    }

    // untuk pilihan fitur menggunakan switch case
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