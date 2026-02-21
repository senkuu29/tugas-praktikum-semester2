#include <stdio.h>

int HitungTotalDenda(int dataHari[])
{
  int totalHari = 0;
  int i;

  // Jumlahkan semua hari terlambat
  for (i = 0; i < 5; i++)
  {
    totalHari = totalHari + dataHari[i];
  }

  // Denda 1000 per hari
  return totalHari * 1000;
}

// Prosedur bayardenda (Mengubah nilai di index jadi 0/lunas)
void bayardenda(int dataHari[], int index)
{
  dataHari[index] = 0;
}

// Prosedur tamppildata (Menampilkan isi array)
void tamppildata(int dataHari[])
{
  int i;
  printf("[ ");
  for (i = 0; i < 5; i++)
  {
    printf("%d ", dataHari[i]);
  }
  printf("]");
}

int main()
{
  int dataHari[5];
  int i, pilihan, index_bayar;
  int total_rupiah;

  printf("Silakan input hari keterlambatan untuk 5 mahasiswa:\n");
  for (i = 0; i < 5; i++)
  {
    printf("Mahasiswa index ke-%d: ", i);
    scanf("%d", &dataHari[i]);
  }
  printf("\nData berhasil disimpan.\n");

  do
  {
    printf("\n--------------------------------\n");
    printf("           MENU UTAMA           \n");
    printf("--------------------------------\n");
    printf("1. Lihat Data & Total Potensi Denda\n");
    printf("2. Bayar Denda\n");
    printf("3. Keluar Aplikasi\n");
    printf("Pilihan Anda (1-3): ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
    {
      printf("\n--- LAPORAN DATA ---\n");
      printf("Data Keterlambatan: ");
      tamppildata(dataHari);
      printf(" hari\n");

      total_rupiah = HitungTotalDenda(dataHari);
      printf("-> Total Potensi Denda: Rp %d\n", total_rupiah);
    }
    else if (pilihan == 2)
    {
      printf("\n--- PEMBAYARAN DENDA ---\n");
      printf("Data Keterlambatan: ");
      tamppildata(dataHari);
      printf(" hari\n");

      printf("Masukkan Index Mahasiswa yang ingin membayar (0-4): ");
      scanf("%d", &index_bayar);

      // Panggil prosedur bayar
      bayardenda(dataHari, index_bayar);

      printf("\n>> [SUKSES] Mahasiswa index ke-%d telah lunas.\n", index_bayar);
    }
  } while (pilihan != 3);

  return 0;
}