// nama : Deden Ahmad Jamil
// nim : 2501518

#ifndef LISH_H
#define LISH_H

// struct lish
typedef struct Lish{
  int noAntrean;
  char nama[50];
  char pesanan[50];
  struct Lish *next;
}Lish;

Lish* createNode(int noAntrean, char nama[], char pesan[]);

void insertAwal(Lish **head, int noAntrean, char nama[], char pesan[]);
void insertAkhir(Lish **head, int noAntrean, char nama[], char pesan[]);
void insertSebelum(Lish **head, int noAntrean, char nama[], char pesan[], int noAntreanAcuan);
void insertSetelah(Lish **head, int noAntrean, char nama[], char pesan[], int noAntreanAcuan);

void deleteSebelum(Lish **head, int noAntreanAcuan);
void deleteSetelah(Lish **head, int noAntreanAcuan);

void updateLish(Lish *head, int noAntrean);
void printList(Lish *head);


#endif