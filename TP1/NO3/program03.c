#include <stdio.h>

// Fungsi buat ngitung lele
int hitungLele(int l_lama)
{
  int hasil = l_lama * 3;
  return hasil;
}

// Fungsi buat ngitung nila
int hitungNila(int n_lama, int l_lama)
{
  int hasil = (n_lama - 10) + (l_lama / 2);
  return hasil;
}

// Fungsi buat ngitung gurame
int hitungGurame(int g_lama, int n_baru)
{
  int hasil = g_lama + (n_baru / 3);
  return hasil;
}

int main()
{
  int l, n, g;

  printf("Masukkan jumlah populasi awal:\n");
  scanf("%d %d %d", &l, &n, &g);

  printf("\nBulan ke-1\n");
  printf("Lele = %d\n", l);
  printf("Nila = %d\n", n);
  printf("Gurame = %d\n", g);

  // Simpan data bulan 1 ke variabel bantuan buat ngitung bulan 2
  int l_skrg = l;
  int n_skrg = n;
  int g_skrg = g;

  // Hitung bulan ke-2
  l = hitungLele(l_skrg);
  n = hitungNila(n_skrg, l_skrg);
  g = hitungGurame(g_skrg, n);

  printf("\nBulan ke-2\n");
  printf("Lele = %d\n", l);
  printf("Nila = %d\n", n);
  printf("Gurame = %d\n", g);

  return 0;
}