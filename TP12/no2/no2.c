// nama : deden ahamad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct edge Edge;

// ini adt untuk edge atau koneksi antar kota
struct edge {
  int cost;
  Node *destNode;
  Edge *nextEdge;
};

// ini adt untuk node atau kota
struct node {
    char label;
    Node *nextNode;
    Edge *firstEdge;
    int visited;
};

// ini adt untuk graf utama
typedef struct graf {
    Node *first;
} Graf;

// ini fungsi untuk mencari alamat memori node berdasarkan labelnya
Node* searchNode(Graf *g, char labelCari) {
    // dari node pertama di graf
    Node *temp = g->first;
    // loop selama ga kosong
    while (temp != NULL) {
        // apakah node ini sama yang di cari
        if (temp->label == labelCari) {
          // balik alamat nodenya
          return temp;
        }
        // geser node ke berikutnya
        temp = temp->nextNode;
    }
    return NULL; // kalo ga ketemuu balik dengan membawa null
}

// ini prosedur untuk membuat dan menambahkan kota baru ke graf
void createNode(Graf *g, char label) {
    // pesan node
    Node *newNode = (Node*)malloc(sizeof(Node));
    // input node data
    newNode->label = label;
    newNode->nextNode = NULL;
    newNode->firstEdge = NULL;
    newNode->visited = 0;

    // cek apakah graf masih kosong
    if (g->first == NULL) {
        // jika kosong, node baru jadi node pertama
        g->first = newNode;
    } else {
        // jika sudah ada isinya, cari node paling ujung
        Node *temp = g->first;
        while (temp->nextNode != NULL) {
          temp = temp->nextNode;
        } 
        // sambungkan node baru di akhir list
        temp->nextNode = newNode;
    }
}

// ini prosedur untuk menambahkan koneksi antar kota beserta biayanya
void createEdge(Node *start, Node *end, int cost) {
    // memastikan kalo 2 node itu ada
    if (start == NULL || end == NULL) return;
    // pesan edge
    Edge *newEdge = (Edge*)malloc(sizeof(Edge));
    // isi datanya
    newEdge->cost = cost;
    newEdge->destNode = end;
    newEdge->nextEdge = NULL;

    // cek apakah node udh punya edge sblumnya
    if (start->firstEdge == NULL) {
        start->firstEdge = newEdge;
    } else {
        // jika sudah ada, cari posisi paling terakhir di list edgenya
        Edge *temp = start->firstEdge;
        while (temp->nextEdge != NULL) {
          temp = temp->nextEdge;
        }
        // pasang edge baru di ujung list
        temp->nextEdge = newEdge;
    }
}

// ini prosedur untuk mereset status kunjungan sebelum dfs/bfs
void resetVisited(Graf *g) {
    // mulai penelusuran dari node pertama dalam graf
    Node *temp = g->first;
    // telusuri seluruh list node sampai habis
    while (temp != NULL) {
        // ubah status visited kembali ke 0
        temp->visited = 0;
        // pindah ke node selanjutnya dalam list graf
        temp = temp->nextNode;
    }
}

// ini prosedur rekursif untuk algoritma dfs
void processDFS(Node *n) {
  // cek apakah node ada dan belum pernah dikunjungi
  if (n != NULL && n->visited == 0) {
    // cetak label node dan tandai sudah dikunjungi
    printf("%c ", n->label);
    n->visited = 1;

    // ambil jalur edge pertama dari node ini
    Edge *e = n->firstEdge;
    while (e != NULL) {
      // masuk lebih dalam ke node tujuan
      processDFS(e->destNode);
      // pindah ke edge tetangga lainnya
      e = e->nextEdge;
    }
  }
}

// ini prosedur untuk algoritma bfs menggunakan antrean
void searchBFS(Graf *g, char start) {
    Node *s = searchNode(g, start);
    if (s != NULL) {
      Node *queue[100];
      int head = 0, tail = 0;
      
      queue[tail++] = s;
      s->visited = 1;
      
      printf("BFS dari %c: ", start);
      while (head < tail) {
        Node *curr = queue[head++];
        printf("%c ", curr->label);
        
        Edge *e = curr->firstEdge;
        while (e != NULL) {
          if (e->destNode->visited == 0) {
              queue[tail++] = e->destNode;
              e->destNode->visited = 1;
          }
          e = e->nextEdge;
        }
      }
      printf("\n");
    }
    resetVisited(g);
}

// ini prosedur untuk memutus dan menghapus satu arah koneksi
void deleteEdge(Node *start, Node *end) {
    if (start == NULL || end == NULL) return;
    Edge *curr = start->firstEdge;
    Edge *prev = NULL;
    
    while (curr != NULL && curr->destNode != end) {
      prev = curr;
      curr = curr->nextEdge;
    }
    
    if (curr != NULL) {
      if (prev == NULL) start->firstEdge = curr->nextEdge;
      else prev->nextEdge = curr->nextEdge;
      free(curr);
    }
}

// ini prosedur untuk menghapus kota beserta seluruh koneksi keluar dan masuknya
void deleteNode(Graf *g, char deleteLabel) {
    Node *delNode = searchNode(g, deleteLabel);
    if (delNode == NULL) return;

    //hapus semua koneksi yang masuk ke kota ini
    Node *currNode = g->first;
    while (currNode != NULL) {
        if (currNode != delNode) {
          Edge *cEdge = currNode->firstEdge;
          Edge *pEdge = NULL;
          int edgeFound = 0;
          while (cEdge != NULL && edgeFound == 0) {
              if (cEdge->destNode == delNode) {
                edgeFound = 1;
              } else {
                pEdge = cEdge;
                cEdge = cEdge->nextEdge;
              }
          }
          if (edgeFound == 1) {
            if (pEdge == NULL) {
              currNode->firstEdge = cEdge->nextEdge;
            } else {
              pEdge->nextEdge = cEdge->nextEdge;
            }
            free(cEdge);
          }
        }
        currNode = currNode->nextNode;
    }

    // hapus semua koneksi yang keluar dari kota ini
    Edge *delEdge = delNode->firstEdge;
    while (delEdge != NULL) {
        Edge *tempEdge = delEdge;
        delEdge = delEdge->nextEdge;
        free(tempEdge);
    }
    delNode->firstEdge = NULL;

    // lepas simpul kota dari antrean utama graf lalu bebaskan memori
    if (g->first == delNode) {
        g->first = delNode->nextNode;
    } else {
        Node *prevNode = g->first;
        while (prevNode != NULL && prevNode->nextNode != delNode) {
          prevNode = prevNode->nextNode;
        }
        if (prevNode != NULL) {
          prevNode->nextNode = delNode->nextNode;
        }
    }
    free(delNode);
}

// ini prosedur untuk mencetak kondisi graf saat ini
void printGraph(Graf *g) {
    Node *tempNode = g->first;
    printf("=== DAFTAR RUTE ===\n");
    while (tempNode != NULL) {
        printf("Kota %c ", tempNode->label);
        Edge *tempEdge = tempNode->firstEdge;
        if (tempEdge == NULL) {
            printf("(tidak ada koneksi)\n");
        } else {
            printf("-> ");
            while (tempEdge != NULL) {
                printf("%c(biaya:%d) ", tempEdge->destNode->label, tempEdge->cost);
                tempEdge = tempEdge->nextEdge;
            }
            printf("\n");
        }
        tempNode = tempNode->nextNode;
    }
}

int main() {
    // inisialisasi graf kosong
    Graf g = {NULL};
    int n, m, choice, cost;
    char label, src, dest, cityTarget;

    printf("=== SISTEM RUTE PENGIRIMAN PAKET ===\n\n");

    // input jumlah kota dan daftarkan ke sistem
    printf("Masukkan jumlah kota: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nama kota ke-%d (1 huruf): ", i + 1);
        scanf(" %c", &label);
        createNode(&g, label);
    }
    printf("%d kota berhasil ditambahkan.\n\n", n);

    // input jumlah koneksi antar kota beserta biayanya
    printf("Masukkan jumlah koneksi: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Koneksi ke-%d (dari tujuan biaya): ", i + 1);
        scanf(" %c %c %d", &src, &dest, &cost);
        createEdge(searchNode(&g, src), searchNode(&g, dest), cost);
    }
    printf("Koneksi berhasil ditambahkan.\n");

    do {
        printf("\n=====================================\n");
        printf("||         MENU PENGIRIMAN         ||\n");
        printf("=====================================\n");
        printf("|| [1] Tampilkan Semua Rute        ||\n");
        printf("|| [2] Cari Rute DFS               ||\n");
        printf("|| [3] Cari Rute BFS               ||\n");
        printf("|| [4] Hapus Koneksi (Delete Edge) ||\n");
        printf("|| [5] Hapus Kota    (Delete Node) ||\n");
        printf("|| [6] Keluar                      ||\n");
        printf("=====================================\n");
        printf("Pilihan: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
          printGraph(&g);
          break;
        case 2:
            printf("DFS - Masukkan kota awal: ");
            scanf(" %c", &src);
            printf("DFS dari %c: ", src);
            processDFS(searchNode(&g, src));
            resetVisited(&g);
            printf("\n");
          break;
        case 3:
            printf("BFS - Masukkan kota awal: ");
            scanf(" %c", &src);
            searchBFS(&g, src);
          break;
        case 4:
            printf("Hapus Koneksi - Masukkan kota asal dan tujuan: ");
            scanf(" %c %c", &src, &dest);
            deleteEdge(searchNode(&g, src), searchNode(&g, dest));
            printf("Koneksi %c -> %c berhasil dihapus!\n", src, dest);
          break;
        case 5:
            printf("Hapus Kota - Masukkan nama kota: ");
            scanf(" %c", &cityTarget);
            deleteNode(&g, cityTarget);
            printf("Kota '%c' dan semua koneksinya berhasil dihapus!\n", cityTarget);
          break;
        case 6:
          printf("Program selesai. Terima kasih!\n");
          break;
        default:
          break;
        }
    } while (choice != 6);
    return 0;
}