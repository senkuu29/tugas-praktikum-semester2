#include <stdio.h>

typedef struct
{
  int harga;
  int terjual;
} DataBuku;

void isiData(DataBuku daftar[], int banyak)
{
  for (int i = 0; i < banyak; i++)
  {
    printf("Harga Buku ke-%d: ", i + 1);
    scanf("%d", &daftar[i].harga);
    printf("Jumlah Terjual ke-%d: ", i + 1);
    scanf("%d", &daftar[i].terjual);
  }
}

/*
  Fungsi buat hitung total uang dari semua penjualan buku
  Sekalian nyimpen total buku yang terjual lewat pointer
*/
int hitungPenjualan(DataBuku daftar[], int banyak, int *totalBukuTerjual)
{
  int totalUang = 0;
  *totalBukuTerjual = 0;

  for (int i = 0; i < banyak; i++)
  {
    totalUang += daftar[i].harga * daftar[i].terjual;
    *totalBukuTerjual += daftar[i].terjual;
  }

  return totalUang;
}

void cetakLaporan(int totalUang, int rataHarga)
{
  printf("\n=== LAPORAN PENJUALAN ===\n");
  printf("Total Penjualan: Rp %d\n", totalUang);
  printf("Rata-rata Harga Buku: Rp %d\n", rataHarga);
}

int main()
{
  int jumlahJenis;
  DataBuku daftarBuku[50];

  printf("Masukkan jumlah jenis buku: ");
  scanf("%d", &jumlahJenis);

  isiData(daftarBuku, jumlahJenis);

  int totalTerjual;
  int totalUang = hitungPenjualan(daftarBuku, jumlahJenis, &totalTerjual);

  // hitung rata-rata harga per jenis buku
  int totalHarga = 0;
  for (int i = 0; i < jumlahJenis; i++)
  {
    totalHarga += daftarBuku[i].harga;
  }
  int rataHarga = totalHarga / jumlahJenis;

  cetakLaporan(totalUang, rataHarga);

  return 0;
}
