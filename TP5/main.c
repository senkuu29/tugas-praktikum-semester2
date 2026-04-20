// nama : Deden Ahmad Jamil
// nim : 2501518

#include "musik.h"

int main() {
  Musik *head = NULL;
  Musik *tail = NULL;

  // deklarasi variabel
  int pilihan, durasi, targetIdJudul, targetIdDurasi, durasiBaru;
  char mood[50], judul[100], judulBaru[100];
  do
  {
    printf("\n=== MYVIBE PLAYLIST MANAGER ===\n");
    printf("1. Tambah Lagu\n");
    printf("2. Tampil Playlist (Forward)\n");
    printf("3. Tampil Playlist (Backward)\n");
    printf("4. Update Judul\n");
    printf("5. Update Durasi (Re-sort)\n");
    printf("6. Hapus Lagu Pertama\n");
    printf("7. Hapus Lagu Terakhir\n");
    printf("8. Hapus Berdasarkan Judul\n");
    printf("0. Keluar\n");
    printf("pilih: ");
    scanf(" %d", &pilihan);
    switch (pilihan)
    {
    case 1:
      // input data
      printf("Mood (Energetic/Chill/Sad): ");
      scanf(" %[^\n]", mood);
        // validasi mood
        if (strcmp(mood, "Energetic")!= 0 && strcmp(mood, "Chill")!= 0 && strcmp(mood, "Sad")!= 0)
        {
          printf("Warning: Mood tidak valid!!\n");
          break;
        }
        printf("Judul: ");
        scanf(" %[^\n]", judul);
        
        printf("Durasi (detik): ");
        scanf(" %d", &durasi);
        // memanggil fungsi addSongs
        addSongs(&head, &tail, mood, judul, durasi,-1);
        break;
    case 2:
      tampilPlaylistForward(head);
    break;
    case 3:
      tampilPlaylistBackward(head);
    break;
    case 4:
      // input
      printf("Masukkan ID Lagu: ");
      scanf(" %d", &targetIdJudul);

      printf("Masukan Judul Baru: ");
      scanf(" %[^\n]", judulBaru);
      
      updateJudul(&head, judulBaru, targetIdJudul);
    break;
    case 5:
      // input
      printf("Masukkan ID Lagu: ");
      scanf("%d", &targetIdDurasi);
      
      printf("Masukkan Durasi Baru (detik): ");
      scanf("%d", &durasiBaru);

      updateDurasi(&head, &tail, durasiBaru, targetIdDurasi);
    break;
    case 6:
        hapusAwal(&head, &tail);
    break;
    case 7:
        hapusAkhir(&head, &tail);
    break;
    case 8:
      printf("Masukkan Judul Lagu: ");
      scanf(" %[^\n]", judul);

      hapusBerdasarkanJudul(&head, &tail, judul);
    break;
    default:
      break;
    }
    
  } while (pilihan != 0);
}
