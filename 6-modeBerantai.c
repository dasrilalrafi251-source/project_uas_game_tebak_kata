#include <stdio.h>
#include <string.h>
#include "pustaka.h"

void tebak_rantai(int nomer) {

    if (nomer == 0) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    
    if (nomer >= 20) {
        printf("Selamat! Anda telah menyelesaikan semua pertanyaan.\n");
        return;
    }

    char *pertanyaan[20] = {
        "Buah berwarna merah kecil yang sering dijadikan topping kue.",
        "Hewan peliharaan yang sering mengeong.",
        "Negara asal menara Eiffel.",
        "Makanan tradisional Indonesia dari kedelai fermentasi.",
        "Superhero yang bisa memanjat dinding dan mengeluarkan jaring.",
        "Hewan laut besar yang memiliki semprotan air di kepalanya.",
        "Planet terbesar di tata surya.",
        "Ibukota dari Inggris.",
        "Benda elektronik untuk bekerja dan mengakses internet serta muat ditaruh di kantong.",
        "Kendaraan yang berjalan di atas rel.",
        "Burung yang bisa menirukan suara manusia adalah burung......",
        "Negara dengan populasi terbesar di dunia.",
        "Olahraga yang menggunakan raket dan kok.",
        "Makanan Jepang yang berbahan nasi dan ikan mentah.",
        "Bahasa resmi yang digunakan di Maroko.",
        "Ikan laut yang mampu menghasilkan listrik.",
        "Gunung tertinggi di Asia Tenggara.",
        "Palung terdalam di dunia adalah palung.....",
        "Negara yang terkurung daratan India dan tidak memiliki pantai.",
        "Bahasa yang digunakan oleh penduduk Greenland."
    };

    char *jawaban[20] = {
        "STROBERI",
        "KUCING",
        "PRANCIS",
        "TEMPE",
        "SPIDERMAN",
        "PAUS",
        "JUPITER",
        "LONDON",
        "HANDPHONE",
        "KERETA",
        "BEO",
        "CHINA",
        "BULUTANGKIS",
        "SUSHI",
        "ARAB",
        "IKANPARILISTRIK",
        "KINABALU",
        "MARIANA",
        "NEPAL",
        "KALAALLISUT"
    };

    char tebakan[100];

    printf("%s\njawaban: ", pertanyaan[nomer]);
    fgets(tebakan, sizeof(tebakan), stdin);
    tebakan[strcspn(tebakan, "\n")] = '\0';
    remove_all_whitespace(tebakan);
    str_to_upper(tebakan);

    if (strcmp(tebakan, jawaban[nomer]) == 0) {
        printf("Jawaban Benar (+2 poin)\n\n");
        poin += 2;
        tebak_rantai(nomer + 1);
    } else {
        printf("Jawaban Salah! Permainan selesai..!");
        return;
    }
}