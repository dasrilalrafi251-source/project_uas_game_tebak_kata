#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void superhero() {
    do {
        //Menentukan pilihan kesulitan
        printf("\n=====================\n");
        printf("SILAKAN PILIH LEVEL: \n");
        printf("=====================\n");  
        printf("1. Mudah\n");
        if (SuperheroSedang) {printf("2. Sedang\n");} else {printf("%s2. Sedang (5 poin)\n%s", RED, RESET);}
        if (SuperheroSulit) {printf("3. sulit\n");} else {printf("%s3. sulit (10 poin)\n%s", RED, RESET);}
        printf("0. kembali\n");
        printf("Level: ");
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
            level = -1; // biar ga keluar loop ini
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        level = atoi(input);
        
        switch (level) {
            // lLEVEL MUDAH
            case 1: {
                // soal dan jawaban
                char *superhero[3] = {"SPIDERMAN", "BATMAN", "IRONMAN"};
                    char *clue[3][3] = {
                        {"Aku sering berayun di antara gedung-gedung tinggi.",
                         "Aku mendapat kekuatan dari gigitan hewan kecil.",
                         "Kostumku berwarna merah dan biru, dengan simbol laba-laba di dada."},
                        {"Aku beraksi di malam hari untuk melindungi kotaku.",
                         "Aku tidak punya kekuatan super, tapi aku punya banyak alat.",
                         "Aku dikenal sebagai The Dark Knight dari Gotham."},
                        {"Aku seorang jenius dan miliarder yang suka teknologi.",
                         "Aku membuat baju baja yang bisa terbang dan menembak.",
                         "Namaku Tony Stark."}
                    };
                    char *clueT[3] = {
                        "9 Huruf dimulai dari S", "6 Huruf dimulai dari B", "7 Huruf dimulai dari I"
                    };
                
                printf("\nKamu memilih level MUDAH!\n");
                
                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[3]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama,nama, RESET);
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
                        No = -1; // biar ga keluar loop ini
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                        }

                    No = atoi(input);

                    if (No < 0 || No > 3) {
                        printf("%sNomor yang kamu pilih tidak ada, coba lagi!%s\n", RED, RESET);
                    }
                } while (No < 0 || No > 3);

                if (No == 0) { break; } 

                printf("\nKAMU MEMILIH NOMOR %d! SEMOGA BERUNTUNG!\n\n", No);

                int index = No - 1; 
                //menampilkan permainan dari clue & menerima input pemain
                for (int i = 0; i < 3; i++) {
                    printf("Clue %d: %s\n", i + 1, clue[index][i]);
                    printf("Jawaban %s%s%s: ", warnaNama, nama, RESET);
                    scanf(" %[^\n]", jawaban); 
                    remove_all_whitespace(jawaban);
                    str_to_upper(jawaban);
                    if (strcmp(jawaban, superhero[index]) == 0) {
                        if (i == 0) {
                            printf("%sBenar! +5 poin%s\n", GREEN, RESET);
                            poin += 5;
                        } else if (i == 1) {
                            printf("%sBenar! +4 poin%s\n", GREEN, RESET);
                            poin += 4;
                        } else if (i == 2){
                            printf("%sBenar! +3 poin%s\n", GREEN, RESET);
                            poin += 3;
                        }
                        break;
                    } else if (i == 2) {//menawarkan clue tambahan dengan adanya hint
                        printf("%sSalah!%s Mau lanjut clue berikutnya? (Iya/Tidak): ", RED, RESET);
                        scanf(" %s", butuhClue);

                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}

                        bool valid = true;
                        for (int i = 0; i < strlen(butuhClue); i++) {
                            if (isdigit((unsigned char)butuhClue[i])) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            printf("\n%sInput tidak valid.%s\n", RED, RESET);
                            break;
                        }

                        if (strcmp(butuhClue, "Iya") == 0 || strcmp(butuhClue, "iya") == 0) {
                            if (hint >=1) {
                                hint -= 1;
                                printf("(-1 hint)\n");

                                printf("\nClue Terakhir: %s.\n", clueT[index]);
                                printf("Jawaban %s%s%s: ", warnaNama, nama, RESET);
                                scanf(" %[^\n]", jawaban); 
                                remove_all_whitespace(jawaban);
                                str_to_upper(jawaban);
                                if (strcmp(jawaban, superhero[index]) == 0) {
                                    printf("Benar! +3 poin\n");
                                    poin += 3;
                                    break;
                                } else {
                                    printf("%sSayang sekali, semua clue sudah habis%s\n", RED, RESET);
                                }
                            } else {
                                printf("%sAnda tidak memiliki Hint!%s\n", RED, RESET);
                            }
                        } else {
                            break;
                        }
                    } else {
                        printf("%sTETOT... Jawaban anda salah!%s\n", RED, RESET);
                    }
                }
            }
            break;
            // LEVEL SEDANG
            case 2: {
                // periksa apakah poin cukup untuk buka 
                if (poin >= 5 || SuperheroSedang) {
                    if (!SuperheroSedang) {
                        printf("Selamat, anda membuka level sedang\n");
                        poin -= 5;
                        SuperheroSedang = true;
                    } 
                } else if (poin < 5 && !SuperheroSedang) {
                    printf("Anda membutuhkan 5 point untuk membuka tingkat level ini\n");
                    break;
                }
                // soal dan jawaban
                char *superhero[3] = {"CAPTAINAMERICA", "WONDERWOMAN", "HULK"};
                    char *clue[3][3] = {
                        {"Aku lahir di masa perang.",
                         "Aku memiliki perisai yang tak mudah hancur.",
                         "Aku sering berkata 'Avengers, assemble!'"},
                        {"Aku berasal dari pulau tersembunyi yang hanya dihuni wanita.",
                         "Aku memiliki tali emas yang bisa memaksa orang berkata jujur.",
                         "Aku adalah prajurit Amazon dari Themyscira."},
                        {"Aku menjadi sangat kuat saat marah.",
                         "Tubuhku berubah warna setiap kali aku kehilangan kendali.",
                         "Don’t make me angry…"}
                    };
                    char *clueT[3] = {"14 Huruf dimulai dari C", "11 Huruf dimulai dari W", "4 Huruf dimulai dari H"};

                printf("\nKamu memilih level SEDANG!\n");

                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[3]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama,nama, RESET);
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
                        No = -1; // biar ga keluar loop ini
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                        }

                    No = atoi(input);

                    if (No < 0 || No > 3) {
                        printf("%sNomor yang kamu pilih tidak ada, coba lagi!%s\n", RED, RESET);
                    }
                } while (No < 0 || No > 3);
                if (No == 0) { break; } 

                printf("\nKAMU MEMILIH NOMOR %d! SEMOGA BERUNTUNG!\n\n", No);

                int index = No - 1;
                //menampilkan permainan dari clue & menerima input pemain 
                for (int i = 0; i < 3; i++) {
                    printf("Clue %d: %s\n", i + 1, clue[index][i]);
                    printf("Jawaban %s%s%s: ", warnaNama, nama, RESET);
                    scanf(" %[^\n]", jawaban); 
                    remove_all_whitespace(jawaban);
                    str_to_upper(jawaban);
                    if (strcmp(jawaban, superhero[index]) == 0) {
                        if (i == 0) {
                            printf("%sBenar! +5 poin%s\n", GREEN, RESET);
                            poin += 5;
                        } else if (i == 1) {
                            printf("%sBenar! +4 poin%s\n", GREEN, RESET);
                            poin += 4;
                        } else if (i == 2){
                            printf("%sBenar! +3 poin%s\n", GREEN, RESET);
                            poin += 3;
                        }
                        break;
                    } else if (i == 2) {//menawarkan clue tambahan dengan adanya hint
                        printf("%sSalah!%s Mau lanjut clue berikutnya? (Iya/Tidak): ", RED, RESET);
                        scanf(" %s", butuhClue);

                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}

                        bool valid = true;
                        for (int i = 0; i < strlen(butuhClue); i++) {
                            if (isdigit((unsigned char)butuhClue[i])) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            printf("\n%sInput tidak valid.%s\n", RED, RESET);
                            break;
                        }

                        if (strcmp(butuhClue, "Iya") == 0 || strcmp(butuhClue, "iya") == 0) {
                            if (hint >=1) {
                                hint -= 1;
                                printf("(-1 hint)\n");

                                printf("\nClue Terakhir: %s.\n", clueT[index]);
                                printf("Jawaban %s%s%s: ", warnaNama, nama, RESET);
                                scanf(" %[^\n]", jawaban); 
                                remove_all_whitespace(jawaban);
                                str_to_upper(jawaban);
                                if (strcmp(jawaban, superhero[index]) == 0) {
                                    printf("Benar! +3 poin\n");
                                    poin += 3;
                                    break;
                                } else {
                                    printf("%sSayang sekali, semua clue sudah habis%s\n", RED, RESET);
                                }
                            } else {
                                printf("%sAnda tidak memiliki Hint!%s\n", RED, RESET);
                            }
                        } else {
                            break;
                        }
                    } else {
                        printf("%sTETOT... Jawaban anda salah!%s\n", RED, RESET);
                    }
                }
            }
            break;
            // LEVEL SULIT
            case 3: {
                // periksa apakah poin cukup untuk buka 
                if (poin >= 5 || SuperheroSulit) {
                    if (!SuperheroSulit) {
                        printf("Selamat, anda membuka level Sulit\n");
                        poin -= 5;
                        SuperheroSulit = true;
                    } 
                } else if (poin < 10 && !SuperheroSulit) {
                    printf("Anda membutuhkan 10 point untuk membuka tingkat level ini\n");
                    break;
                }
                // soal dan jawaban
                char *superhero[3] = {"THOR", "BLACKPANTHER", "SUPERMAN"};
                    char *clue[3][3] = {
                        {"Aku bukan manusia, tapi berasal dari dunia lain.",
                         "Aku memegang senjata yang hanya bisa diangkat oleh yang layak.",
                         "Aku adalah dewa petir dari Asgard."},
                        {"Aku memimpin sebuah kerajaan tersembunyi yang sangat maju.",
                         "Aku memakai kostum hitam dari logam langka bernama vibranium.",
                         "Aku raja Wakanda, dan namaku TChalla."},
                        {"Aku bukan berasal dari Bumi.",
                         "Aku lemah terhadap batu hijau.",
                         "Aku dikenal dengan simbol 'S' di dadaku."}
                    };
                    char *clueT[3] = {"4 Huruf dimulai dari T", "12 Huruf dimulai dari B", "8 Huruf dimulai dari S"};

                printf("\nKamu memilih level SULIT!\n");
                    
                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[3]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama,nama, RESET);
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
                        No = -1; // biar ga keluar loop ini
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                        }

                    No = atoi(input);

                    if (No < 0 || No > 3) {
                        printf("%sNomor yang kamu pilih tidak ada, coba lagi!%s\n", RED, RESET);
                    }
                } while (No < 0 || No > 3);

                if (No == 0) { break; } 

                printf("\nKAMU MEMILIH NOMOR %d! SEMOGA BERUNTUNG!\n\n", No);

                int index = No - 1; 
                //menampilkan permainan dari clue & menerima input pemain
                for (int i = 0; i < 3; i++) {
                    printf("Clue %d: %s\n", i + 1, clue[index][i]);
                    printf("Jawaban %s%s%s: ", warnaNama, nama, RESET);
                    scanf(" %[^\n]", jawaban); 
                    remove_all_whitespace(jawaban);
                    str_to_upper(jawaban);
                    if (strcmp(jawaban, superhero[index]) == 0) {
                        if (i == 0) {
                            printf("%sBenar! +5 poin%s\n", GREEN, RESET);
                            poin += 5;
                        } else if (i == 1) {
                            printf("%sBenar! +4 poin%s\n", GREEN, RESET);
                            poin += 4;
                        } else if (i == 2){
                            printf("%sBenar! +3 poin%s\n", GREEN, RESET);
                            poin += 3;
                        }
                        break;
                    } else if (i == 2) {//menawarkan clue tambahan dengan adanya hint
                        printf("%sSalah!%s Mau lanjut clue berikutnya? (Iya/Tidak): ", RED, RESET);
                        scanf(" %s", butuhClue);
                        
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}

                        bool valid = true;
                        for (int i = 0; i < strlen(butuhClue); i++) {
                            if (isdigit((unsigned char)butuhClue[i])) {
                                valid = false;
                                break;
                            }
                        }
                        if (!valid) {
                            printf("\n%sInput tidak valid.%s\n", RED, RESET);
                            break;
                        }

                        if (strcmp(butuhClue, "Iya") == 0 || strcmp(butuhClue, "iya") == 0) {
                            if (hint >=1) {
                                hint -= 1;
                                printf("(-1 hint)\n");

                                printf("\nClue Terakhir: %s.\n", clueT[index]);
                                printf("Jawaban %s%s%s: ", warnaNama, nama, RESET);
                                scanf(" %[^\n]", jawaban); 
                                remove_all_whitespace(jawaban);
                                str_to_upper(jawaban);
                                if (strcmp(jawaban, superhero[index]) == 0) {
                                    printf("Benar! +3 poin\n");
                                    poin += 3;
                                    break;
                                } else {
                                    printf("%sSayang sekali, semua clue sudah habis%s\n", RED, RESET);
                                }
                            } else {
                                printf("%sAnda tidak memiliki Hint!%s\n", RED, RESET);
                            }
                        } else {
                            break;
                        }
                    } else {
                        printf("%sTETOT... Jawaban anda salah!%s\n", RED, RESET);
                    }
                }
            }
            break;

            default:
                if (level < 0 || level > 3) {
                    printf("%s1 sampai 3 bang%s\n", RED, RESET);
                }
            }
            if (level != 0) {
                printf("\nSilahkan pilih level yang lain!\n");
            }
        } while (level != 0);
    printf("\n");
}