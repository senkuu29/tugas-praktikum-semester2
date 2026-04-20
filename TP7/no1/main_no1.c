// nama : deden ahmad jamil
// nim : 2501518

#include "header_no1.h"

int main(){
  Musik myMusik;
  initStack(&myMusik);

  push(&myMusik, "April cover ahdanWahyudin");
  push(&myMusik, "high cortisol");
  push(&myMusik, "Sahur Kang Gufron");
  pop(&myMusik);                                   // pop atau mengeluarkan
  push(&myMusik, "Tentang cinta");
  push(&myMusik, "Untuk Perempuan yang sedang dalam pelukan");

  displayMusik(&myMusik);
  return 0;
}