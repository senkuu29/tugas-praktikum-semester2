// nama : deden ahamad jamil
// nim : 2501518

#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;
typedef struct edge Edge;

// adt edge
struct edge {
  int cost;
  Node *destNode;
  Edge *nextEdge;
};

// adt node
struct node {
  char label;
  Node *nextNode;
  Edge *firstEdge;
  int visited;
};

typedef struct {
    Node *first;
} Graf;

// create node
void createNode(Graf *g, char label) {
    // pesan node
    Node *newNode = (Node*)malloc(sizeof(Node));
    // input node
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

// fungsi cari by label
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
  return NULL; // kalo ga ketemiuu balik dengan membawa null
}

// funhgsi buat ngebungin 2 node dengan edge
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

// variabel globl buat menyimpan rute terbaik
int minCost = 99999;
char bestPath[20];
int bestPathLen = 0;

// pake DFS rekursif
void findShortestPath(Node *curr, Node *dest, int currentCost, char currentPath[], int pathLen) {
    // masukkan label node saat ini ke dalam urutan jalur
    currentPath[pathLen] = curr->label;
    // kunci node agar tidak dikunjungi dua kali dalam satu jalur yang sama
    pathLen++;
    curr->visited = 1; // tandai node sedang dikunjungi

    // cek udh nympe tujuan atau blum
    if (curr == dest) {
      // kalo biaya ini lbih kcil dari rekor biaya terendah sblumnya
        if (currentCost < minCost) {
            // update
            minCost = currentCost;
            bestPathLen = pathLen;
            for (int i = 0; i < pathLen; i++) {
                bestPath[i] = currentPath[i];
            }
        }
    } else {
        // kalo blum nympe cari edge yng nymbung ke node ini
        Edge *e = curr->firstEdge;
        while (e != NULL) {
            // hanya kunjungi node tujuan jika statusnya belum dikunjungi
            if (e->destNode->visited == 0) {
                findShortestPath(e->destNode, dest, currentCost + e->cost, currentPath, pathLen);
            }
            // pindh edge
            e = e->nextEdge;
        }
    }
    // reset agar tdk di gunakan oleh jlur lain
    curr->visited = 0; 
}

//untuk menerjemahkan label char ke string nama kota
void printNamaLokasi(char label) {
  switch(label) {
    case '0': printf("Stasiun Bandung"); break;
    case '1': printf("Wastukencana"); break;
    case '2': printf("Dago"); break;
    case '3': printf("Cihampelas"); break;
    case '4': printf("Pasteur"); break;
    case '5': printf("Ledeng"); break;
    case '6': printf("UPI"); break;
  }
}

int main() {
    Graf *g = (Graf*)malloc(sizeof(Graf));
    g->first = NULL;

    // buat node
    for(char i = '0'; i <= '6'; i++) {
      createNode(g, i);
    }

    // jalur waktu
    createEdge(searchNode(g, '0'), searchNode(g, '4'), 15);
    createEdge(searchNode(g, '0'), searchNode(g, '1'), 10);
    createEdge(searchNode(g, '1'), searchNode(g, '2'), 5);
    createEdge(searchNode(g, '1'), searchNode(g, '3'), 12);
    createEdge(searchNode(g, '2'), searchNode(g, '5'), 20);
    createEdge(searchNode(g, '3'), searchNode(g, '5'), 8);
    createEdge(searchNode(g, '4'), searchNode(g, '3'), 5);
    createEdge(searchNode(g, '5'), searchNode(g, '6'), 10);

    // untuk menampung rute
    char path[20];
    
    // Mulai nyari dari Stasiun 0 ke UPI 6
    findShortestPath(searchNode(g, '0'), searchNode(g, '6'), 0, path, 0);

    printf("=== PENCARIAN RUTE TERCEPAT ===\n");
    printf("Titik Awal : Stasiun Bandung\n");
    printf("Titik Akhir: UPI\n");
    printf("Rute Terbaik: ");
    
    for (int i = 0; i < bestPathLen; i++) {
        printNamaLokasi(bestPath[i]);
        if (i < bestPathLen - 1) printf(" -> ");
    }
    printf("\nTotal Waktu: %d Menit\n", minCost);

    return 0;
}