// nama : Deden Ahmad Jamil
// nim : 2501518

#ifndef BIOSKOP_H
#define BIOSKOP_H

// struct Film
typedef struct Film{
  int id;
  char judul[50];
  char jam[30];
  struct Film *next;
}Film;

// pendeklarasian prosedur dan fungsi

Film* createNode(int id, char judul[], char jam[]);

void insertAwal(Film **head, int id, char judul[], char jam[]);
void insertAkhir(Film **head, int id, char judul[], char jam[]);
void insertSebelum(Film **head, int id, char judul[], char jam[], int idAcuan);
void insertSetelah(Film **head, int id, char judul[], char jam[], int idAcuan);

void updateFilm(Film *head, int id);
void deleteAwal(Film **head);
void deleteAkhir(Film **head);

void printList(Film *head);

#endif