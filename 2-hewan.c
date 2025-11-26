#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void hewan() {
    do {
        //Menentukan pilihan kesulitan  
        printf("\n=====================\n");
        printf("SILAKAN PILIH LEVEL: \n");
        printf("=====================\n");
        printf("1. Mudah\n");
        if (HewanSedang) {printf("2. Sedang\n");} else {printf("%s2. Sedang (5 poin)\n%s", RED, RESET);}
        if (HewanSulit) {printf("3. sulit\n");} else {printf("%s3. sulit (10 poin)\n%s", RED, RESET);}
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
            level = -1; // biar tidak langsung keluar loop
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            continue;
        }

        level = atoi(input);
        
        switch (level) {
            // lLEVEL MUDAH
            case 1: {
                //Menyiapkan perpustakaan jawaban & clue
                char *hewan[2] = {"GAJAH", "KUCING"};
                char *clue[2][3] = {
                    {"Aku hewan darat terbesar di dunia.",
                     "Aku punya belalai panjang dan telinga besar.",
                     "Aku hidup di hutan dan suka berkelompok."},
                    {"Aku hewan peliharaan yang suka tidur.",
                     "Aku mengeong saat lapar.",
                     "Aku suka bermain dengan bola benang."}
                };
                char *clueT[2] = {
                    "Aku punya gading panjang yang bisa dijual mahal (tapi jangan ya!).",
                    "Aku suka makan ikan dan sangat manja."
                };
                
                printf("\nKamu memilih level MUDAH!\n");
                
                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama,nama, RESET);
                    scanf(" %9s", &input); //memilih nomor soal

                    bool valid = true;
                        for (int i = 0; i < strlen(input); i++) {
                            if (!isdigit((unsigned char)input[i])) {
                                valid = false;
                                break;
                            }
                        }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 2.%s\n", RED, RESET);
                        No = -1; // biar tidak langsung keluar loop
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                        }

                    No = atoi(input);

                    if (No < 0 || No > 2) {
                        printf("%sNomor yang kamu pilih tidak ada, coba lagi!%s\n", RED, RESET);
                    }
                } while (No < 0 || No > 2);

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
                    if (strcmp(jawaban, hewan[index]) == 0) {
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
                                if (strcmp(jawaban, hewan[index]) == 0) {
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
                        printf("%sTETOT... Jawbaan anda salah!%s\n", RED, RESET);
                    }
                }
            }
            break;
            // LEVEL SEDANG
            case 2: {
                //memeriksa poin apakah cukup untuk ke level ini
                if (poin >= 5 || HewanSedang) {
                    if (!HewanSedang) {
                        printf("Selamat, anda membuka level sedang\n");
                        poin -= 5;
                        HewanSedang = true;
                    } 
                } else if (poin < 5 && !HewanSedang) {
                    printf("Anda membutuhkan 5 point untuk membuka tingkat level ini\n");
                    break;
                }
                //Menyiapkan perpustakaan jawaban & clue
                char *hewan[2] = {"HARIMAU", "PANDA"};
                char *clue[2][3] = {
                    {"Aku kucing besar yang hidup di hutan.",
                     "Tubuhku belang hitam oranye.",
                     "Aku pemburu yang kuat dan gesit."},
                    {"Aku hewan dari Tiongkok yang suka bambu.",
                     "Tubuhku berwarna hitam putih.",
                     "Aku terlihat lucu dan tenang."}
                };
                char *clueT[2] = {
                                "Aku sering disebut raja hutan di Asia.",
                                "Aku simbol perdamaian dari negeri Tiongkok."
                            };

                printf("\nKamu memilih level SEDANG!\n");

                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama,nama, RESET);
                    scanf(" %9s", &input); //memilih nomor soal

                    bool valid = true;
                        for (int i = 0; i < strlen(input); i++) {
                            if (!isdigit((unsigned char)input[i])) {
                                valid = false;
                                break;
                            }
                        }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 2.%s\n", RED, RESET);
                        No = -1; // biar tidak langsung keluar loop
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                        }

                    No = atoi(input);

                    if (No < 0 || No > 2) {
                        printf("%sNomor yang kamu pilih tidak ada, coba lagi!%s\n", RED, RESET);
                    }
                } while (No < 0 || No > 2);
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
                    if (strcmp(jawaban, hewan[index]) == 0) {
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
                                if (strcmp(jawaban, hewan[index]) == 0) {
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
                        printf("%sTETOT... Jawbaan anda salah!%s\n", RED, RESET);
                    }
                }
            }
            break;
            // LEVEL SULIT
            case 3: {
                //memeriksa poin apakah cukup untuk ke level ini
                if (poin >= 10 || HewanSulit) {
                    if (!HewanSulit) {
                        printf("Selamat, anda membuka level Sulit\n");
                        poin -= 10;
                        HewanSulit = true;
                    } 
                } else if (poin < 10 && !HewanSulit) {
                    printf("Anda membutuhkan 10 point untuk membuka tingkat level ini\n");
                    break;
                }
                //Menyiapkan perpustakaan jawaban & clue
                char *hewan[2] = {"KOMODO", "KANGURU"};
                char *clue[2][3] = {
                    {"Aku reptil terbesar di dunia.",
                     "Aku hanya ditemukan di beberapa pulau di Indonesia.",
                     "Aku bisa berlari cepat dan punya air liur beracun."},
                    {"Aku hewan berkantong dari Australia.",
                     "Aku suka melompat dengan kaki belakang yang kuat.",
                     "Anak-anakku tinggal di dalam kantong di perutku."}
                };
                char *clueT[2] = {
                                "Aku berasal dari Pulau Komodo dan Rinca.",
                                "Aku juga muncul di lambang negara Australia."
                            };

                printf("\nKamu memilih level SULIT!\n");
                    
                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama,nama, RESET);
                    scanf(" %9s", &input); //memilih nomor soal

                    bool valid = true;
                        for (int i = 0; i < strlen(input); i++) {
                            if (!isdigit((unsigned char)input[i])) {
                                valid = false;
                                break;
                            }
                        }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 2.%s\n", RED, RESET);
                        No = -1; // biar tidak langsung keluar loop
                        int c;
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        continue;
                        }

                    No = atoi(input);

                    if (No < 0 || No > 2) {
                        printf("%sNomor yang kamu pilih tidak ada, coba lagi!%s\n", RED, RESET);
                    }
                } while (No < 0 || No > 2);

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
                    if (strcmp(jawaban, hewan[index]) == 0) {
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
                                if (strcmp(jawaban, hewan[index]) == 0) {
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
                        printf("%sTETOT... Jawbaan anda salah!%s\n", RED, RESET);
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
}