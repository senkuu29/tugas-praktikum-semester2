#include <stdio.h>
#include <stdlib.h>

// struct data gerbong
typedef struct Data
{
  char kodeGerbong[50];
  char barangBawaan[50];
  struct Data *next;

}data;

// si head(tali) birisi null(belum di iket kemana-mana) kita iket ke gerbong "data"
data *head = NULL;


// untuk menambah data
void tambahData(data **head){
  // memesan gerbong baru
  data *gerbongBaru = (data *) malloc(sizeof(data));

  printf("Masukkan Kode Gerbong: ");
  scanf(" %[^\n]s", gerbongBaru->kodeGerbong);
  printf("Masukkan Barang Bawaan Gerbong: ");
  scanf(" %[^\n]s", gerbongBaru->barangBawaan);

  // jadi gerbong barulah yang paling akhir yg harus di isi null
  gerbongBaru->next = NULL;

  if (*head == NULL)
  {
    *head = gerbongBaru; //resmi sekrang head pegang alamat gerbongBaru
  }else{
    data *temp = *head;
    while (temp->next != NULL )
    {
      temp = temp->next; //temp ini akan maju terus dari head hingga menemukan null
    }
    temp->next = gerbongBaru; // ini ketika uda nemu null maka gerbong baru disitu di simpan
  }
  printf("Data berhasil ditambahkan!\n");
}

// untuk menambahkan data
void tampilkanData(data *head){
  data *temp = head;
  int nomor = 1;

  // validasi ketika belum ada isinya
  if (temp == NULL)
  {
    printf("Belum ada gerbong!!");
  }

  printf("Urutan Gerbong Kereta Logistik:\n");
  while (temp != NULL)
  {
    printf("%d. %s - %s\n", nomor, temp->kodeGerbong, temp->barangBawaan);
    // temp akan terus maju jika temp itu belum menemukan null
    temp = temp->next;
    nomor++;
  }

}

int main(){
  // fitur
  printf("=== Manajemen Daftar Gerbong Kereta Logistik ===\n");
  printf("1. Tambah Data Gerbong\n");
  printf("2. Tampilkan Data Gerbong\n");
  printf("3. Keluar\n");

  int pilihan;
  do
  {
    printf("\nPilih menu: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      tambahData(&head);
      break;
    case 2:
      tampilkanData(head);
      break;
    case 3:
      printf("Keluar dari program...");
      break;
    default:
      break;
    }
  } while (pilihan != 3);

  return 0;
}