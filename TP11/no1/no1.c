// nama: deden ahmad jamil
// nim: 2501518

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// struct atau adtnya
typedef struct Tree {
  char nama[50];
  struct Tree* child;
  struct Tree* sibling;
}Ntree;

Ntree *createNode (char nama[]){
  // pesan node
  Ntree *baru = (Ntree*) malloc(sizeof(Ntree));
  // input data
  strcpy(baru->nama, nama);

  baru->child = NULL;
  baru->sibling = NULL;

  return baru;
}

// mencari node by nama
Ntree *searchNode(Ntree *root, char *targetNama) {
  if (root == NULL ) return NULL;
  if (strcmp(root->nama, targetNama) == 0) return root;

  // cari anaknya
  Ntree *found = searchNode(root->child, targetNama);
  if (found != NULL) return found;

  // cari saudaranya
  return searchNode(root->sibling, targetNama);
}

void tambahAnggota (Ntree *root, char *namaOrangtua, char *namaAnak) {
  // cari posisi orang tua
  Ntree* parent = searchNode(root, namaOrangtua);

  // kalo orangtua tidak di temukan
  if (root == NULL || parent == NULL){
    printf("error: nama orang tua tidak ditemukan!\n");
    return;
  }

  // kalo orang tua ditemukan buat node anak
  Ntree *baru = createNode(namaAnak);

  // kalo gapunya anak maka langsung di jadikan anak pertama
  if (parent->child == NULL)
  {
    parent->child = baru;
  }else {
    // kalo udah punya anak
    Ntree *temp = parent->child;
    // cari saudaranya sampe paling bontot
    while (temp->sibling != NULL)
    {
      temp = temp->sibling;
    }
    // masukan member baru jadi yg paling bontot
    temp->sibling = baru;
  }
  printf("Berhasil menambahkan %s ke %s\n", namaAnak, namaOrangtua);
}

void printTree(Ntree *root, int temp){
  if (root == NULL) return;

  // Cetak spasi untuk indentasi sesuai level/depth
  for (int i = 0; i < temp; i++) {
    printf("  "); 
  }
  printf("%s\n", root->nama);

  // Rekursi ke anak (level bertambah)
  printTree(root->child, temp + 1);
  
  // Rekursi ke saudara (level tetap)
  printTree(root->sibling, temp);

}

int main(){
  char namaLeluhur[100], namaOrangTua[100], namaAnak[100];
  int pilihan;

  printf("Masukkan nama leluhur (Root): ");
  scanf(" %[^\n]", namaLeluhur);

  // memasukan root/leluhur
  Ntree *root = createNode(namaLeluhur);
  
  do
  {
    printf("\n--- MENU SILSILAH ---\n");
    printf("1. Tambah Anggota\n");
    printf("2. Lihat Silsilah\n");
    printf("3. Keluar\n");
    printf("Pilih menu: ");
    scanf(" %d", &pilihan);
    switch (pilihan)
    {
      case 1:
          printf("Nama Orang Tua: ");
          scanf(" %[^\n]", namaOrangTua);
          printf("Nama Anak: ");
          scanf(" %[^\n]", namaAnak);
          // memasukan data ke fungsi tambah anggota
          tambahAnggota(root, namaOrangTua, namaAnak);
        break;
      case 2:
          printf("\nDATA SILSILAH:\n");
          printTree(root, 0);
        break;
      case 3:
          printf("Keluar program..\n");
        break;
    
    default:
      break;
    }
  } while (pilihan != 3);
  
}