# nama: deden ahmad jamil
# nim: 2501518

class Film:
    def __init__(self, judul, genre, tahun, rating, sudah_ditonton):
        self.judul = judul
        self.genre = genre
        self.tahun = tahun
        self.rating = rating
        self.sudah_ditonton = sudah_ditonton

    # buat mencetak detail film
    def info(self):
        status = "Sudah ditonton" if self.sudah_ditonton else "Belum ditonton"
        print(f"Judul   : {self.judul}")
        print(f"Genre   : {self.genre}")
        print(f"Tahun   : {self.tahun}")
        print(f"Rating  : {self.rating}/10")
        print(f"Status  : {status}\n")


#fungsi buat nyari film rating tinggi
def tampilkan_rating_tertinggi(koleksi):
    if not koleksi:
        print("Koleksi masih kosong!\n")
        return
    
    # cari nilai rating maksimal dulu
    film_tertinggi = koleksi[0]
    for film in koleksi:
        if film.rating > film_tertinggi.rating:
            film_tertinggi = film
            
    print("Film dengan rating tertinggi:")
    film_tertinggi.info()


def main():
    koleksi_film = []
    genre_set = set()
    identitas_koleksi = [] 

    while True:
        print("===== MENU UTAMA =====")
        print("1. Tambah film baru")
        print("2. Tampilkan semua film")
        print("3. Cari film berdasarkan judul")
        print("4. Hapus film")
        print("5. Filter film berdasarkan genre")
        print("6. Film dengan rating tertinggi")
        print("7. Rekomendasi film")
        print("8. Lihat statistik koleksi")
        print("9. Keluar")
        print("======================")
        
        pilihan = input("Pilih menu (1-9): ")
        print()

        if pilihan == '1':
            print("-- Tambah Film Baru --")
            judul = input("Judul film   : ")
            genre = input("Genre        : ")
            tahun = int(input("Tahun rilis  : "))
            rating = float(input("Rating (1-10): "))
            status_input = input("Sudah ditonton? (ya/tidak): ").lower()
            
            status = True if status_input == 'ya' else False
            
            # bikin objek film baru
            film_baru = Film(judul, genre, tahun, rating, status)
            
            # masukin ke list, set, dan list of tuple
            koleksi_film.append(film_baru)
            genre_set.add(genre)
            
            # bikin tuple (judul, tahun) terus simpen
            identitas = (judul, tahun)
            identitas_koleksi.append(identitas)
            
            print(f"Film '{judul}' berhasil ditambahkan!\n")

        elif pilihan == '2':
            print(f"-- Semua Film ({len(koleksi_film)} judul) --")
            for film in koleksi_film:
                film.info()

        elif pilihan == '3':
            judul_cari = input("Masukkan judul yang dicari: ")
            print()
            ditemukan = False
            for film in koleksi_film:
                if film.judul.lower() == judul_cari.lower():
                    print("Ditemukan 1 film:\n")
                    film.info()
                    ditemukan = True
                    break
            if not ditemukan:
                print("Film tidak ditemukan.\n")

        elif pilihan == '4':
            judul_hapus = input("Masukkan judul film yang ingin dihapus: ")
            dihapus = False
            for film in koleksi_film:
                if film.judul.lower() == judul_hapus.lower():
                    koleksi_film.remove(film)
                    # hapus identitasnyaa biar sinkron
                    identitas_koleksi.remove((film.judul, film.tahun))
                    print(f"Film '{film.judul}' berhasil dihapus.\n")
                    dihapus = True
                    break
            if not dihapus:
                print("Film tidak ditemukan.\n")

        elif pilihan == '5':
            genre_cari = input("Masukkan genre yang ingin ditampilkan: ")
            print(f"\nFilm bergenre '{genre_cari.lower()}':\n")
            ada = False
            for film in koleksi_film:
                if film.genre.lower() == genre_cari.lower():
                    film.info()
                    ada = True
            if not ada:
                print("Tidak ada film dengan genre tersebut.\n")

        elif pilihan == '6':
            # manggil fungsi terpisah
            tampilkan_rating_tertinggi(koleksi_film)

        elif pilihan == '7':
            #vari film yang belum ditonton buat direkomendasikan
            rekomendasi = [f for f in koleksi_film if not f.sudah_ditonton]
            if rekomendasi:
                print("Coba tonton film ini:")
                rekomendasi[0].info()
            else:
                print("Semua film sudah ditonton!\n")

        elif pilihan == '8':
            if not koleksi_film:
                print("Koleksi masih kosong.\n")
                continue
                
            # hitung data unyuk statstik
            total = len(koleksi_film)
            sdh_nonton = sum(1 for f in koleksi_film if f.sudah_ditonton)
            blm_nonton = total - sdh_nonton
            rata_rata = sum(f.rating for f in koleksi_film) / total
            
            #cari genre terbanyak
            frekuensi_genre = {}
            for f in koleksi_film:
                if f.genre in frekuensi_genre:
                    frekuensi_genre[f.genre] += 1
                else:
                    frekuensi_genre[f.genre] = 1
                    
            # ngmbil key dgn value paling gede
            genre_max = max(frekuensi_genre, key=frekuensi_genre.get)
            statistik = {
                'total_film': total,
                'sudah_ditonton': sdh_nonton,
                'belum_ditonton': blm_nonton,
                'rata_rata_rating': round(rata_rata, 1),
                'genre_terbanyak': genre_max,
                'genre_tersedia': genre_set
            }
            
            print("===== STATISTIK KOLEKSI =====")
            for kunci, nilai in statistik.items():
                #biar rapi sejajar titik duanyaaa
                print(f"{kunci:<17} : {nilai}")
            print("=============================\n")

        elif pilihan == '9':
            print("Sampai jumpa!\n")
            break
            
        else:
            print("Pilihan tidak valid, coba lagi.\n")

# jlanin program
if __name__ == "__main__":
    main()