// nama : deden ahmad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct atau adt
typedef struct Tree {
  int id;
  char nama[50];
  char pangkat[50];
  char lokasi[50];
  struct Tree *left;
  struct Tree *right;
} Tree;

// pabrik node
Tree* createNode(int id, char nama[], char pangkat[], char lokasi[]) {
  // pesan node
  Tree *baru = (Tree*) malloc(sizeof(Tree));
  // input data
  baru->id = id;
  strcpy(baru->nama, nama);
  strcpy(baru->pangkat, pangkat);
  strcpy(baru->lokasi, lokasi);
  baru->left = NULL;
  baru->right = NULL;
  return baru;
}

// fungsi insert
void rekrut(Tree **t, int id, char nama[], char pangkat[], char lokasi[]) {
  // kalo tree masih kosong node baru ini akan menjadi root
  if ((*t) == NULL) {
    (*t) = createNode(id, nama, pangkat, lokasi);
    printf("%s level %d berhasil direkrut sebagai %s!\n", nama, id, pangkat);
    return;
  }

  // kalo id lebih kecil dari node saat ini arahkan ke cabang kiri
  if (id < (*t)->id) {
    if ((*t)->left == NULL) {
      (*t)->left = createNode(id, nama, pangkat, lokasi);
      printf("%s level %d menjadi anak kiri %s!\n", nama, id, (*t)->nama);
    } else {
      rekrut(&((*t)->left), id, nama, pangkat, lokasi);
    }
  } 
  // kalo id lebih besar dari node saat ini arahkan ke cabang kanan
  else if (id > (*t)->id) {
    if ((*t)->right == NULL) {
      (*t)->right = createNode(id, nama, pangkat, lokasi);
      printf("%s level %d menjadi anak kanan %s!\n", nama, id, (*t)->nama);
    } else {
      rekrut(&((*t)->right), id, nama, pangkat, lokasi);
    }
  }
}

// fungsi mencari
Tree* cari(Tree *t, int target) {
  // kalo tree kosong atau data sudah ditemukan kembalikan node tersebut
  if (t == NULL || t->id == target) {
    return t;
  }
  // kalo target lebih kecil dari node saat inilanjutkan pencarian ke kiri
  if (target < t->id) {
    return cari(t->left, target);
  } else {
    // kalo target lebih besar lanjutkan pencarian ke kanan
    return cari(t->right, target);
  }
}

// fungsi menhapus node berserta
Tree* deleteNode(Tree* t, int target) {
  if (t == NULL) return NULL;

  // proses cari posisi node yang akan dihapus
  if (target < t->id) {
    t->left = deleteNode(t->left, target);
  } else if(target > t->id) {
    t->right = deleteNode(t->right, target);
  } else {
    // disini udah ketemu
    Tree* temp;
    
    // kalo tidak ada anak
    if (t->left == NULL && t->right == NULL) {
      printf("%s level %d telah dihapus.\n", t->nama, t->id);
      free(t);
      return NULL;
    }

    //anak kiri di naikan karna kiri prioritas
    if (t->left != NULL) {
      temp = t->left;
      printf("%s level %d telah dihapus. %s menggantikan posisinya!\n", t->nama, t->id, temp->nama);
      printf("%s dipromosikan menjadi %s!\n", temp->nama, t->pangkat);
      strcpy(temp->pangkat, t->pangkat); //wariss
      
      // cari tempat buat subtree kanan
      Tree* sub = temp;
      while (sub->right != NULL) {
        sub = sub->right;
      }
      sub->right = t->right;
      
      free(t);
      return temp;
    } else {
      // kalo tidak ada anak kiri maka anak kanan naik
      temp = t->right;
      printf("%s level %d telah dihapus. %s menggantikan posisinya!\n", t->nama, t->id, temp->nama);
      printf("%s dipromosikan menjadi %s!\n", temp->nama, t->pangkat);
      strcpy(temp->pangkat, t->pangkat);
      
      free(t);
      return temp;
    }
  }
  return t;
}

// menghapus semua node
Tree* hapusSemua(Tree* t) {
  if (t != NULL) {
    hapusSemua(t->left);
    hapusSemua(t->right);
    free(t);
  }
  return NULL;
}

// fungsi display versi pre-order seperti contoh modul
void printTree(Tree* root, int space) {
  if (root == NULL) return;

  // agar menjorok ke dlem
  for (int i = 0; i < space; i++) {
    printf(" ");
  } 
  printf("%s (Pangkat: %s | Level: %d)\n", root->nama, root->pangkat, root->id);
  
  // lanjut traversal ke anak kiri dan kanan dengan nambah spasi
  printTree(root->left, space + 1);
  printTree(root->right, space + 1);
}

// travelsal
// prosedur inspeksi komando untuk menunjukkan alur komando dari atasan ke bawahan
void inspeksiKomando(Tree *t){
  if (t == NULL) return;
  printf(" %d - %s (%s)\n", t->id, t->nama, t->pangkat);
  inspeksiKomando(t->left);
  inspeksiKomando(t->right);
}

// prosedur lapor kekuatan untuk menampilkan data 
// secara berurutan berdasarkan level kekuatan (kecil ke besar)
void laporKekuatan(Tree *t){
  if (t == NULL) return;
  laporKekuatan(t->left);
  printf(" %d - %s (%s)\n", t->id, t->nama, t->pangkat);
  laporKekuatan(t->right);
}

// prosedur protokol evakuasi 
// untuk menampilkan urutan
// evakuasi mulai dari perwira di lapangan (leaf node) sebelum akhirnya komandan (root)
void protokolEvakuasi(Tree *t){
  if (t == NULL) return;
  protokolEvakuasi(t->left);
  protokolEvakuasi(t->right);
  printf(" %d - %s (%s)\n", t->id, t->nama, t->pangkat);
}

int main() {
  Tree* root = NULL;
  int pilihan, id = 0, searchLevel = 0, hapus= 0;
  char nama[50], pangkat[50], lokasi[50];

  do {
    printf("\nPilih: ");
    scanf(" %d", &pilihan);

    switch (pilihan) {
      case 1:
        printf("Masukkan Level Kekuatan: ");
        scanf(" %d", &id);
        printf("Nama: ");
        scanf(" %[^\n]", nama);
        printf("Pangkat: ");
        scanf(" %[^\n]", pangkat);
        printf("Lokasi Tugas: ");
        scanf(" %[^\n]", lokasi);

        rekrut(&root, id, nama, pangkat, lokasi);
        break;
        
      case 2:
        printf("CARI PERWIRA BERDASARKAN LEVEL\n");
        printf("Masukkan Level Kekuatan: ");
        scanf(" %d", &searchLevel);

        Tree* hasilCari = cari(root, searchLevel);
        if (hasilCari != NULL) {
          printf("\nData ditemukan!\n");
          printf("Level: %d | Nama: %s | Pangkat: %s | Lokasi: %s\n", hasilCari->id, hasilCari->nama, hasilCari->pangkat, hasilCari->lokasi);
        } else {
          printf("Data yang dicari gada!\n");
        }
        break;
        
      case 3:
        printf("HAPUS PERWIRA\n");
        printf("Masukkan Level yang akan dihapus: ");
        scanf(" %d", &hapus);

        root = deleteNode(root, hapus);
        break;
        
      case 4:
        printf("BUBARKAN MARINE (Delete All)\n");
        root = hapusSemua(root);
        printf("Semua perwira Marine telah dihapus! Markas Besar kosong.\n");
        break;

      case 5:
        inspeksiKomando(root);
        break;

      case 6:
        laporKekuatan(root); // inorder
        break;

      case 7:
        protokolEvakuasi(root); // posorder
        break;

      case 8:
        printf("keluar program..");
        break;
    }
  } while (pilihan != 0);

  return 0;
}