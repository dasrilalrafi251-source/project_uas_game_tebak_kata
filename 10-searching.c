#include <stdio.h>
#include <string.h>
#include "pustaka.h"

void cariNama() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char name_search[NAME_LEN];
    printf("Masukkan nama yang dicari: ");
    if (fgets(name_search, sizeof(name_search), stdin) == NULL) return;
    name_search[strcspn(name_search, "\n")] = 0;
    hilanginNewLine(name_search);

    FILE *f = fopen(SAVEDATA, "r");
    if (!f) {
        printf("Belum ada data. File '%s' tidak ditemukan.\n", SAVEDATA);
        return;
    }
    Pemain r;
    int found = 0;
    while (fread(&r, sizeof(Pemain), 1, f) == 1) {
        if (strcmp(r.name, name_search) == 0) {
            printf("\n--------------------\n");
            printf("Ditemukan pemain:\n");
            printf("  Nama   : %s\n", r.name);
            printf("  Poin   : %d\n", r.poin);
            printf("  Waktu  : %s\n", r.waktu);
            found = 1;
        }
    }
    if (!found) printf("Tidak ditemukan record dengan nama '%s'.\n", name_search);
    fclose(f);
}