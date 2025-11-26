// =========== MENYIAPKAN VARIABEL & PENETAPAN =========== MULAI ================================================================================================
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "pustaka.h"
#include "utilsh.h"

// =========== MAIN =========== MULAI ================================================================================================
int main() {
    int pilihanMenu;
    char pilih[10];

    do {
        printf("\n=========================================\n");
        printf("SELAMAT DATANG DI PERMAINAN TEBAK-TEBAKAN\n");
        printf("=========================================\n");

        if (strlen(nama) == 0) { //mengecek apakah nama sudah ada atau belum
            
            do {
            printf("Masukkan Nama Pemain: ");
            scanf("%[^\n]", nama);
            getchar();
            if (strlen(nama) > 30) {
                printf("\n%sMaksimal Panjang Nama 30 Karakter.%s\n", RED, RESET);
            }
            } while (strlen(nama) > 30);

            if (strcmp(nama, "dewakipastzy123") == 0) {
                poin += 9999999;
            }

            printf("\nHalo, %s%s%s! (Poin: %d)\n", warnaNama, nama, RESET, poin);
        } else {
            // Menampilkan halo kembali beserta poin saat ini
            printf("Halo kembali, %s%s%s! (Poin: %d)\n", warnaNama, nama, RESET, poin);
        }
        
        // tampilin pilihan
        printf("1.SHOP\n");
        printf("2.START\n");
        printf("3.LIHAT HISTORY\n");
        printf("4.EXIT\n");
        printf("Pilihanmu: ");
        scanf(" %9s", &input);

        bool valid = true;
        for (int i = 0; i < strlen(input); i++) {
            if (!isdigit((unsigned char)input[i])) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            printf("\n%sInput tidak valid. Masukkan angka 1, 2, 3, atau 4.%s\n", RED, RESET);
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        pilihanMenu = atoi(input);

        if (pilihanMenu == 2) {
            // panggil fungsi buat tampilin kategori
            List_kategori();
        } else if(pilihanMenu == 1) {
            // panggil sho
            shop();
        } else if (pilihanMenu == 3) {
            int c; while ((c = getchar()) != '\n' && c != EOF);
            // tampilin skor
            loadSkor(); 

            do {
                printf("\n--- MENU HISTORY ---\n");
                printf("1. Mencari player!\n");
                printf("0. Keluar ke Menu Utama\n");
                printf("Pilihan: ");
                scanf(" %9s", &input);

                bool valid = true;
                for (int i = 0; i < strlen(input); i++) {
                    if (!isdigit((unsigned char)input[i])) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) {
                    printf("\n%sInput tidak valid. Pilih 0 atau 1.%s\n", RED, RESET);
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF) {}
                    continue;
                }

                pilihanMenu = atoi(input);

                switch (pilihanMenu) {
                    case 1:
                        // Panggil fungsi searching
                        cariNama();    
                        break;
                    
                    case 0:
                        printf("Kembali ke menu utama...\n");
                        break;
                    
                    default:
                        printf("Pilihan tidak valid.\n");
                }
            } while (pilihanMenu != 0);
            

        } else if(pilihanMenu == 4) {
            printf("\n%sTERIMA KASIH TELAH BERMAIN!%s\n", GREEN, RESET);
            printf("Skor akhir %s%s%s: %d\n", warnaNama, nama, RESET, poin);
            
            // simpen skor ke savedata (panggil fungsi saveSjir)
            saveSkor(); 
            
            break;
        }
        else {
            printf("\n%sPilihan tidak valid. Masukkan 1, 2, 3, atau 4.%s\n", RED, RESET);
        }

    } while (pilihanMenu != 4);

    return 0;
}
// =========== MAIN =========== SELESAI ===============================================================================================