// nama : deden ahmad jamil
// nim  : 2501518

#include<stdio.h>
#include<stdlib.h>

// struct data wisatawan
typedef struct Data
{
  char nama[50];
  int nomor;
  struct Data *next;
}data;

data *head = NULL;

// prosedur untuk menambahkan data paling awal
void tambahAwalDaftar(data **head){
  //  memesan gerbong baru
  data *baru = (data *) malloc(sizeof(data));

  printf("Masukkan Nama: ");
  scanf(" %[^\n]s", baru->nama);
  printf("Masukkan Nomor Tiket: ");
  scanf(" %d", &baru->nomor);

  // menghubungkan gerbong baru ke bagian awal kereta
  baru->next = *head;
  
  // ini untuk menggeser pointer head agar menunjuk ke gerbong baru
  *head = baru;
  printf("Data berhasil ditambahkan!\n\n");
}

// prosedur untuk menambahkan data di paling akhir
void tambahAkhirDaftar(data **head){
  //  memesan gerbong baru
  data *baru = (data *) malloc(sizeof(data));

  // karena di akhir harus null
  baru->next = NULL;

  printf("Masukkan Nama: ");
  scanf(" %[^\n]s", baru->nama);
  printf("Masukkan Nomor Tiket: ");
  scanf(" %d", &baru->nomor);

  // jika list masi kosong
  if (*head == NULL)
  {
    *head = baru;
  } else {
    data *temp = *head;
    // cari gerbong sampai null
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // menghubungkan gerbong terakhir lama ke gerbong baru
    temp->next = baru;
  }
  printf("Data berhasil ditambahkan!\n\n");
}

// prosedur untuk menambahkan data sebelum data yang kalian inginkan
void tambahSebelum(data **head){
  // validasi awal agar datanya gak kosong
 if (*head == NULL) {
        printf("Daftar masih kosong!\n");
        return;
    }

    data *baru = (data *)malloc(sizeof(data));
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", baru->nama);
    printf("Masukkan Nomor Tiket: ");
    scanf(" %d", &baru->nomor);

    int acuan;
    printf("Data akan ditambahkan sebelum nomor tiket: ");
    scanf("%d", &acuan);

    // ini kalo datanya ada di gerbong pertama
    if ((*head)->nomor == acuan) {
      baru->next = *head;
      *head = baru;
      printf("Data berhasil ditambahkan!\n");
      return;
    }

    // Cari gerbong yang berada tepat sebelum target
    data *temp = *head;
    while (temp->next != NULL && temp->next->nomor != acuan) {
      temp = temp->next;
    }

    // untuk memeriksa apakah targetnya udah sampe di akhir
    if (temp->next == NULL) {
      printf("Nomor tiket %d tidak ditemukan! Data gagal disimpan.\n", acuan);
    } else {
      // Hubungkan node baru di antara temp dan target
      baru->next = temp->next;
      temp->next = baru;
      printf("Data berhasil ditambahkan!\n");
    }
}

// prosedur untuk menambahkan data setelah yang di inginkan
void tambahSetelah(data *head){
  if (head == NULL) {
    printf("Daftar masih kosong!\n");
    return;
  }

  // Pesan memori dan input data baru duluan
    data *baru = (data *) malloc(sizeof(data));
    printf("Masukkan Nama: ");
    scanf(" %[^\n]s", baru->nama);
    printf("Masukkan Nomor Tiket: ");
    scanf(" %d", &baru->nomor); 

    // Baru tanya mau ditaruh setelah siapa
    int acuan;
    printf("Data akan ditambahkan setelah nomor tiket: ");
    scanf("%d", &acuan);

    // Cari posisi tiket acuan
    data *temp = head;
    while (temp != NULL && temp->nomor != acuan) {
      temp = temp->next;
    }

  if (temp == NULL) {
    printf("Nomor tiket %d tidak ditemukan! Data gagal disimpan.\n", acuan);
  } else {
    // Proses nyelipin gerbong
    baru->next = temp->next;
    temp->next = baru;
    printf("Data berhasil ditambahkan!\n");
  }
}

// untuk menampilkan semua data
void tampilkan(data *head){
  data *temp = head;
  int nomor = 1;

  printf("Daftar Wisatawan Kereta Keliling Kampung:\n");
  while (temp != NULL)
  {
    printf("%d. %s - %d\n",nomor, temp->nama, temp->nomor);
    temp = temp->next;
    nomor++;
  }
}

int main(){
  // fitur"
  printf("=== Sistem Manajemen Wisatawan Kereta Keliling Kampung ===\n");
  printf("1. Tambah di Awal Daftar\n");
  printf("2. Tambah di Akhir Daftar\n");
  printf("3. Tambah Sebelum Wisatawan Tertentu\n");
  printf("4. Tambah Setelah Wisatawan Tertentu\n");
  printf("5. Tampilkan Daftar Wisata\n");
  printf("6. Keluar\n");
  
  int pilihan;

  // prulangan untuk memilih fitur
  do
  {
    printf("\nPilih menu: ");
    scanf(" %d", &pilihan);

    switch (pilihan)
    {
    case 1:
      tambahAwalDaftar(&head);
      break;
    case 2:
      tambahAkhirDaftar(&head);
      break;
    case 3:
      tambahSebelum(&head);
      break;
    case 4:
      tambahSetelah(head);
      break;
    case 5:
      tampilkan(head);
      break;
    case 6:
      printf("\nKeluar dari program...\n");
      break;
    default:
      break;
    }
  } while (pilihan != 6);
  
  return 0;
}