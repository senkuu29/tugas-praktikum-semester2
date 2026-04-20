// nama : deden ahmad jamil
// nim : 2501518

#ifndef MUSIK_H
#define MUSIK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct musik
typedef struct Musik{
  int id;
  int durasi;
  char judul[100];
  char mood[50];
  struct Musik *next;
  struct Musik *prev;
}Musik;

Musik* createNode(char mood[], char judul[], int durasi, int idTarget);
void addSongs(Musik **head, Musik **tail, char mood[], char judul[], int durasi, int idTarget);

void tampilPlaylistForward(Musik *head);
void tampilPlaylistBackward(Musik *head);

void updateJudul(Musik **head, char judulBaru[], int targetIdJudul);
void updateDurasi(Musik **head, Musik **tail, int durasiBaru, int targetIdDurasi);

void hapusAwal(Musik **head, Musik **tail);
void hapusAkhir(Musik **head, Musik **tail);
void hapusBerdasarkanJudul(Musik **head, Musik **tail, char targetJudul[]);

#endif