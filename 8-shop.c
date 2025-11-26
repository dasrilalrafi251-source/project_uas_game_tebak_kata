#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void shop(){ 

    do {
    printf("\n======================\n");
    printf("SELAMAT DATANG DI SHOP\n");
    printf("======================\n");

        printf("1. SKIN NAMA\n");
        printf("2. HINT\n");
        printf("3. CEK POIN & HINT\n");
        printf("0. Kembali\n");
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
                printf("\n%sInput tidak valid. Masukkan angka 0 sampai 3.%s\n", RED, RESET);
                shopy = -1;
                int c;
                while ((c = getchar()) != '\n' && c != EOF) {}
                continue;
            }
            if (shopy == 0){
                printf("\nSilahkan Datang Kembali\n");
           }

        shopy = atoi(input);

        if(shopy == 1){
            do {
                printf("\n===========\n");
                printf("PILIH WARNA\n");
                printf("===========\n");
                if (green) {
                    printf("1. %sHIJAU%s\n", GREEN, RESET);
                } else {
                    printf("1. %sHIJAU%s (20 poin)\n", GREEN, RESET);
                }
                if (red) {
                    printf("2. %sMERAH%s\n", RED, RESET);
                } else {
                    printf("2. %sMERAH%s (20 poin)\n", RED, RESET);
                }
                if (blue) {
                    printf("3. %sBIRU%s\n", BLUE, RESET);
                } else {
                    printf("3. %sBIRU%s (20 poin)\n", BLUE, RESET);
                }
                if (purple) {
                    printf("4. %sUNGU%s\n", PURPLE, RESET);
                } else {
                    printf("4. %sUNGU%s (20 poin)\n", PURPLE, RESET);
                }
                if (yellow) {
                    printf("5. %sKUNING%s\n", YELLOW, RESET);
                } else {
                    printf("5. %sKUNING%s (20 poin)\n", YELLOW, RESET);
                }
                printf("6. %sDEFAULT (0 poin)\n", RESET);
                printf("0.Kembali\n");
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
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 6.%s\n", RED, RESET);
                        warna = -1;
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                    }

                    warna = atoi(input);
            
                if (warna == 0){
                    printf("\nSilahkan Datang Kembali\n");

                } else if (warna == 6) {
                    if (green || red | blue || purple || yellow) {
                    strcpy(warnaNama, RESET);
                    printf("\n%sWarna nama berhasil diganti!%s \n", GREEN, RESET);
                    printf("\n=========================================\n");
                    printf("Hai, %s%s%s! Namamu Balik Semula\n", warnaNama, nama, RESET);
                    printf("=========================================\n");
                    } else if (!green || !yellow || !red || !purple || !blue) {
                        printf("\n%sWarna nama tidak berubah!%s \n", YELLOW, RESET);
                        printf("=========================================\n");
                        printf("Hai, %s%s%s! Namamu tidak ada perubahan\n", warnaNama, nama, RESET);
                        printf("=========================================\n");
                    }

                } else if (warna > 0 && warna < 6) { // ubah warna 
                    switch (warna) {
                        case 1: 
                            if (!green && poin >= 20) {
                                printf("%sSelamat, kamu membeli skin warna hijau%s\n", GREEN, RESET);
                                poin -= 20;
                                green = true;
                            } else if (!green && poin < 20) {
                                printf("%sPoin kamu tidak cukup untuk membeli warna hijau%s\n", RED, RESET);
                                break;
                            } else {
                                printf("%sKamu sudah memiliki warna hijau%s\n", GREEN, RESET);
                            }
                            strcpy(warnaNama, GREEN);
                            break;
                        
                        case 2: 
                            if (!red && poin >= 20) {
                                printf("%sSelamat, kamu membeli skin warna merah%s\n", GREEN, RESET);
                                poin -= 20;
                                red = true;
                            } else if (!red && poin < 20) {
                                printf("%sPoin kamu tidak cukup untuk membeli warna merah%s\n", RED, RESET);
                                break;
                            } else {
                                printf("%sKamu sudah memiliki warna merah%s\n", GREEN, RESET);
                            }
                            strcpy(warnaNama, RED);
                            break;
                        
                        case 3:
                            if (!blue && poin >= 20) {
                                printf("%sSelamat, kamu membeli skin warna biru%s\n", GREEN, RESET);
                                poin -= 20;
                                blue = true;
                            } else if (!blue && poin < 20) {
                                printf("%sPoin kamu tidak cukup untuk membeli warna biru%s\n", RED, RESET);
                                break;
                            } else {
                                printf("%sKamu sudah memiliki warna biru%s\n", GREEN, RESET);
                            }
                            strcpy(warnaNama, BLUE);
                            break;
                        
                        case 4:
                            if (!purple && poin >= 20) {
                                printf("%sSelamat, kamu membeli skin warna ungu%s\n", GREEN, RESET);
                                poin -= 20;
                                purple = true;
                            } else if (!purple && poin < 20) {
                                printf("%sPoin kamu tidak cukup untuk membeli warna ungu%s\n", RED, RESET);
                                break;
                            } else {
                                printf("%sKamu sudah memiliki warna ungu%s\n", GREEN, RESET);
                            }
                            strcpy(warnaNama, PURPLE);
                            break;
                        
                        case 5:
                            if (!yellow && poin >= 20) {
                                printf("%sSelamat, kamu membeli skin warna kuning%s\n", GREEN, RESET);
                                poin -= 20;
                                yellow = true;
                            } else if (!yellow && poin < 20) {
                                printf("%sPoin kamu tidak cukup untuk membeli warna kuning%s\n", RED, RESET);
                                break;
                            } else {
                                printf("%sKamu sudah memiliki warna kuning%s\n", GREEN, RESET);
                            }
                            strcpy(warnaNama, YELLOW);
                            break;
                        
                        default:
                            printf("%sPilihan warna tidak valid.%s\n", RED, RESET);
                            break;
                    }
                
                
                } else if (poin < 20) {
                    printf("%sPoin anda tidak cukup%s\n", RED, RESET);
                } else {
                    printf("%sPilihan tidak valid.%s\n", RED, RESET);
                }
            }while (warna != 0);
        
        } else if (shopy == 2) {
            do {
                printf("\n===========\n");
                printf("TOKO HINT\n");
                printf("===========\n");
                printf("1. 1 hint (2 poin)\n");
                printf("2. 5 hint (10 poin)\n");
                printf("3. 10 hint (15 poin)\n");
                printf("0. Kembali\n");
                printf("Pilih jumlah HINT yang mau dibeli: ");
                scanf(" %9s", &input);

                bool valid = true;
                for (int i = 0; i < strlen(input); i++) {
                if (!isdigit((unsigned char)input[i])) {
                    valid = false;
                    break;
                        }
                    }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 3.%s\n", RED, RESET);
                        belihint = -1;
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                    }

                    belihint = atoi(input);
                
                switch (belihint) {
                case 1: 
                    if (poin >= 2) {
                        printf("%sBerhasil membeli 1 HINT%s\n", GREEN, RESET);
                        poin -= 2;
                        hint += 1;
                    } else {
                        printf("%sPoin anda tidak cukup%s\n", RED, RESET);
                    }
                    break;
                case 2:
                    if (poin >= 10) {
                        printf("%sBerhasil membeli 5 HINT%s\n", GREEN, RESET);
                        poin -= 10;
                        hint += 5;
                    } else {
                        printf("%sPoin anda tidak cukup%s\n", RED, RESET);
                    }
                break;
                case 3:
                    if (poin >= 15) {
                        printf("%sBerhasil membeli 10 HINT%s\n", GREEN, RESET);
                        poin -= 15;
                        hint += 10;
                    } else {
                        printf("%sPoin anda tidak cukup%s\n", RED, RESET);
                    }
                default:
                    break;
                }
            } while (belihint != 0);

        } else if(shopy == 3) {
            printf("\n=========================================\n");
            printf("Hai, %s%s%s!\n", warnaNama, nama, RESET);
            printf("Total poinmu: %d\n", poin);
            printf("Total hint: %d\n", hint);
            printf("=========================================\n\n");
        } else if (shopy == 0) {
            break;
        } else {
            printf("\n%sInput tidak valid, silahkan pilih kembali!%s\n", RED, RESET);
        }
    } while (shopy != 0);
}