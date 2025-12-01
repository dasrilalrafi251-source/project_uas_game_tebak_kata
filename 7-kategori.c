#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void List_kategori() { 
    do {    
        printf("\n========================\n");
        printf("SILAKAN PILIH KATEGORI: \n");
        printf("========================\n");
        printf("1. Buah\n");
        if (gembokHewan) {
            printf("2. Hewan\n");
        } else {
            printf("%s2. Hewan%s (10 poin)\n", RED, RESET);
        }
        if (gembokNegara) {
            printf("3. Negara\n");
        } else {
            printf("%s3. Negara%s (20 poin)\n", RED, RESET);
        }
        if (gembokMakanan_Tradisional) {
            printf("4. Makanan Tradisional\n");
        } else {
            printf("%s4. Makanan Tradisional%s (30 poin)\n", RED, RESET);
        }
        if (gembokSuperhero) {
            printf("5. Superhero\n");
        } else {
            printf("%s5. Superhero%s (40 poin)\n", RED, RESET);
        }
        printf("%s6. MODE BERANTAI%s\n", BLUE, RESET);
        printf("0. Kembali\n");
        printf("Kategori: ");
        scanf(" %9s", &input);

        bool valid = true;
            for (int i = 0; i < strlen(input); i++) {
                if (!isdigit((unsigned char)input[i])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                printf("\n%sInput tidak valid. Masukkan angka 0 sampai 6.%s\n", RED, RESET);
                kategori = -1;
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                continue;
            }

        kategori = atoi(input);

        switch (kategori) { 
            case 1: // BUAH
                printf("\nKamu memilih kategori BUAH\n");
                buah();
                break;
            case 2: // HEWAN
                if (gembokHewan) {
                    printf("\nKamu memilih kategori HEWAN!\n");
                    hewan(); 
                } else if (poin < 10 && !gembokHewan) {
                    printf("\n%sAnda membutuhkan 10 point untuk membuka kategori ini%s\n", RED, RESET);
                } else if (poin >= 10) {                    
                    if (!gembokHewan) {
                    printf("\n%sSelamat, anda membuka kategori HEWAN%s\n", GREEN, RESET);
                    poin -= 10;
                    gembokHewan = true;
                    }
                    hewan();
                }                                
                break;
            case 3: // NEGARA
                if (gembokNegara) {
                    printf("\nKamu memilih kategori NEGARA!\n");
                    negara(); 
                } else if (poin < 20 && !gembokNegara) {
                    printf("\n%sAnda membutuhkan 20 point untuk membuka kategori ini%s\n", RED, RESET);
                } else if (poin >= 20) {                    
                    if (!gembokNegara) {
                    printf("\n%sSelamat, anda membuka kategori NEGARA%s\n", GREEN, RESET);
                    poin -= 20;
                    gembokNegara = true;
                    }
                    negara();
                }                                
                break;
            case 4: // MAKANAN TRADISIONAL
                if (gembokMakanan_Tradisional) {
                    printf("\nKamu memilih kategori MAKANAN TRADISIONAL!\n"); 
                    makanan_tradisional();
                } else if (poin < 30 && !gembokMakanan_Tradisional) {
                    printf("\n%sAnda membutuhkan 30 point untuk membuka kategori ini%s\n", RED, RESET);
                } else if (poin >= 30) { 
                    if (!gembokMakanan_Tradisional) {
                    printf("\n%sSelamat, anda membuka kategori MAKANAN TRADISIONAL%s\n", GREEN, RESET);
                    poin -= 30;
                    gembokMakanan_Tradisional = true;
                    }
                    makanan_tradisional();
                }                               
                break;
            case 5: // SUPERHERO
                if (gembokSuperhero) {
                    printf("\nKamu memilih kategori SUPERHERO!\n");
                    superhero(); 
                } else if (poin < 40 && !gembokSuperhero) {
                    printf("\n%sAnda membutuhkan 40 point untuk membuka kategori ini%s\n", RED, RESET);
                } else if (poin >= 40) { 
                    if (!gembokSuperhero) {
                    printf("\n%sSelamat, anda membuka kategori SUPERHERO%s\n", GREEN, RESET);
                    poin -= 40;
                    gembokSuperhero = true;
                    }
                    superhero();
                }                              
                break;
            case 6: // MODE BERANTAI
                printf("\n======================================\n");
                printf("       ANDA MEMILIH MODE RANTAI       \n");
                printf("======================================\n");  
                printf("Jika jawaban salah, maka permainan akan berakhir\n");
                printf("pada mode rantai, setiap tebakan terdiri dari hanya 1 clue.\n");   
                printf("======================================\n");
                printf("          SEMOGA BERUNTUNG!!          \n");
                printf("======================================\n\n");   
                tebak_rantai(0);
                break; 
            case 0: //kembali ke menu
                break;
            default:
                printf("\n%sInput tidak valid. Masukkan angka 0 sampai 6%s\n", RED, RESET);
                break;
            }
    } while (kategori != 0);
}