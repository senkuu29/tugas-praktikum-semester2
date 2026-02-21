#include <stdio.h>
#include <string.h>

int main()
{
    char kata[50];

    printf("Masukkan kata: ");
    scanf("%s", kata);

    int panjangKata = strlen(kata);

    // Validasi panjang input: minimal 3, maksimal 15 karakter
    if (panjangKata < 3)
    {
        printf("Jumlah karakter tidak boleh kurang dari 3");
        return 0;
    }
    if (panjangKata > 15)
    {
        printf("Jumlah karakter tidak boleh lebih dari 15");
        return 0;
    }

    printf("dari %s menjadi ", kata);

    // Looping buat cek tiap huruf
    for (int i = 0; i < panjangKata; i++)
    {
        // Ganti A jadi 1
        if (kata[i] == 'a' || kata[i] == 'A')
        {
            kata[i] = '1';
        }
        // Ganti E jadi 2
        if (kata[i] == 'e' || kata[i] == 'E')
        {
            kata[i] = '2';
        }
        // Ganti I jadi 3
        if (kata[i] == 'i' || kata[i] == 'I')
        {
            kata[i] = '3';
        }
        // Ganti O jadi 4
        if (kata[i] == 'o' || kata[i] == 'O')
        {
            kata[i] = '4';
        }
        // Ganti U jadi 5
        if (kata[i] == 'u' || kata[i] == 'U')
        {
            kata[i] = '5';
        }
    }

    // cetak hasil
    printf("%s", kata);

    return 0;
}