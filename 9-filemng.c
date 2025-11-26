#include <stdio.h>
#include <time.h>
#include <string.h>
#include "pustaka.h"

void saveSkor() {
    if (strlen(nama) == 0) return;

    FILE *f = fopen("scores.dat", "ab");
    if (!f) return;

    Pemain dataBaru;
    
    strcpy(dataBaru.name, nama);
    dataBaru.name[strcspn(dataBaru.name, "\n")] = 0;
    dataBaru.poin = poin;

    time_t t = time(NULL); 
    struct tm tm = *localtime(&t);
    sprintf(dataBaru.waktu, "%02d-%02d-%d %02d:%02d", 
            tm.tm_mday,
            tm.tm_mon + 1,
            tm.tm_year + 1900, 
            tm.tm_hour,
            tm.tm_min);

    fwrite(&dataBaru, sizeof(Pemain), 1, f);
    fclose(f);
}

void loadSkor() {
    FILE *f = fopen("scores.dat", "rb");
    if (f == NULL) {
        printf("\n%sBelum ada skor yang tersimpan.%s\n", YELLOW, RESET);
        return;
    }

    Pemain semuaSkor[200]; 
    int jumlahSkor = 0;
    Pemain tempRead;
    while (fread(&tempRead, sizeof(Pemain), 1, f) == 1 && jumlahSkor < 200) {
        semuaSkor[jumlahSkor] = tempRead;
        jumlahSkor++;
    }
    fclose(f); 

    if (jumlahSkor == 0) {
        printf("\n%sFile ada tapi kosong.%s\n", YELLOW, RESET);
        return;
    }

    Pemain buatNuker;
    for (int i = 0; i < jumlahSkor - 1; i++) {
        for (int j = 0; j < jumlahSkor - i - 1; j++) {
            if (semuaSkor[j].poin < semuaSkor[j+1].poin) {
                buatNuker = semuaSkor[j];
                semuaSkor[j] = semuaSkor[j+1];
                semuaSkor[j+1] = buatNuker;
            }
        }
    }

    printf("\n%s--- DAFTAR 10 SKOR TERTINGGI ---%s\n", CYAN, RESET);
    for (int i = 0; i < 10; i++) {
        printf("%s%2d. %-15s (Skor: %d) [%s]%s\n",
       (i == 0) ? YELLOW : RESET,
            i + 1, 
            semuaSkor[i].name, 
            semuaSkor[i].poin,
            semuaSkor[i].waktu,
            RESET);
    }
    printf("%s---------------------------------%s\n", CYAN, RESET);
}