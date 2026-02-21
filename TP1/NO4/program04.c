#include <stdio.h>
#include <stdbool.h>

bool cekKursi(int kursi[], int no)
{
  if (kursi[no - 1] == 0)
  {
    return true; // Benar, kursi kosong
  }
  else
  {
    return false; // Salah, kursi sudah isi
  }
}

void booking(int kursi[], int no)
{
  kursi[no - 1] = 1; // Ubah jadi terisi
}

int main()
{
  int kursi[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int no;
  char lagi;

  do
  {
    printf("\nMasukkan Nomor Kursi yang ingin dipesan (1-10): ");
    scanf("%d", &no);

    if (cekKursi(kursi, no))
    {
      booking(kursi, no);
      printf(">> Booking Berhasil untuk Kursi No %d!\n", no);
    }
    else
    {
      printf(">> Maaf, kursi nomor %d sudah terisi.\n", no);
    }

    printf("Ingin memesan lagi? (y/n): ");
    scanf(" %c", &lagi);

    if (lagi == 'y')
    {
      printf("\nStatus Kursi [0=Kosong, 1=Isi]\n");
      for (int i = 0; i < 10; i++)
      {
        printf("%d ", kursi[i]);
      }
      printf("\n");
    }

  } while (lagi == 'y');

  return 0;
}