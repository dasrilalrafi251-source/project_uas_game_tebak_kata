#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void negara() {
    do {
        //Menentukan pilihan kesulitan
        printf("\n=====================\n");
        printf("SILAKAN PILIH LEVEL: \n");
        printf("=====================\n");  
        printf("1. Mudah\n");
        if (NegaraSedang) {printf("2. Sedang\n");} else {printf("%s2. Sedang (5 poin)\n%s", RED, RESET);}
        if (NegaraSulit) {printf("3. sulit\n");} else {printf("%s3. sulit (10 poin)\n%s", RED, RESET);}
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
                char *negara[2] = {"MALAYSIA", "JEPANG"};
                char *clue[2][3] = {
                    {"Negara ini berada di kawasan Asia Tenggara dan memiliki banyak hutan tropis.",
                     "Terdiri atas dua wilayah utama yang dipisahkan oleh Laut Cina Selatan.",
                     "Bahasa resminya memiliki banyak kemiripan dengan bahasa Indonesia."},
                    {"Negara kepulauan ini terletak di Asia Timur.",
                     "Negara ini sering mengalami gempa karena berada di cincin api Pasifik.",
                     "Gunung Fuji menjadi simbol terkenal negara ini."}
                };
                char *clueT[2] = {
                                "Gedung kembar tertinggi di dunia, Menara Petronas, berada di negara ini.", 
                                "Salah satu budaya pop-nya mendunia lewat anime dan manga."
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
                    scanf(" %9s", &input); 

                    bool valid = true;
                        for (int i = 0; i < strlen(input); i++) {
                            if (!isdigit((unsigned char)input[i])) {
                                valid = false;
                                break;
                            }
                        }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 2.%s\n", RED, RESET);
                        No = -1; // biar ga keluar loop ini
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
                    if (strcmp(jawaban, negara[index]) == 0) {
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
                                if (strcmp(jawaban, negara[index]) == 0) {
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
                if (poin >= 5 || NegaraSedang) {
                    if (!NegaraSedang) {
                        printf("Selamat, anda membuka level sedang\n");
                        poin -= 5;
                        NegaraSedang = true;
                    } 
                } else if (poin < 5 && !NegaraSedang) {
                    printf("Anda membutuhkan 5 point untuk membuka tingkat level ini\n");
                    break;
                }
                // soal dan jawaban
                char *negara[2] = {"INGGRIS", "SPANYOL"};
                char *clue[2][3] = {
                    {"Negara ini termasuk dalam kawasan Eropa Barat dan memiliki sejarah kerajaan panjang.",
                     "Bahasa resminya digunakan luas di seluruh dunia.",
                     "Raja dan Ratu-nya tinggal di Istana Buckingham."},
                    {"Negara ini terletak di Eropa bagian selatan, di Semenanjung Iberia.",
                     "Bahasa resminya dituturkan di banyak negara di dunia.",
                     "Kota Barcelona dikenal dengan bangunan karya arsitek Antoni Gaudí."}
                };
                char *clueT[2] = {
                                "Salah satu kotanya memiliki jam terkenal bernama Big Ben.", 
                                "Olahraga sepak bola sangat populer di negara ini, dengan klub terkenal seperti Real Madrid danBarcelona."
                            };

                printf("\nKamu memilih level SEDANG!\n");

                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0] Kembali\n");
                    printf("Pilihan %s%s%s: ", warnaNama, nama, RESET);
                    scanf(" %9s", &input); 

                    bool valid = true;
                        for (int i = 0; i < strlen(input); i++) {
                            if (!isdigit((unsigned char)input[i])) {
                                valid = false;
                                break;
                            }
                        }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 2.%s\n", RED, RESET);
                        No = -1; // biar ga keluar loop ini
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
                    if (strcmp(jawaban, negara[index]) == 0) {
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
                                if (strcmp(jawaban, negara[index]) == 0) {
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
                if (poin >= 5 || NegaraSulit) {
                    if (!NegaraSulit) {
                        printf("Selamat, anda membuka level Sulit\n");
                        poin -= 5;
                        NegaraSulit = true;
                    } 
                } else if (poin < 10 && !NegaraSulit) {
                    printf("Anda membutuhkan 10 point untuk membuka tingkat level ini\n");
                    break;
                }
                // soal dan jawaban
                char *negara[2] = {"NEPAL", "MESIR"};
                char *clue[2][3] = {
                    {"Negara ini terletak di Asia Selatan, di antara dua negara besar.",
                     "Negara ini tidak memiliki laut (landlocked country).",
                     "Sebagian besar wilayahnya bergunung-gunung dan merupakan bagian dari Himalaya."},
                    {"Negara ini berada di Afrika bagian timur laut dan dilalui Sungai Nil.",
                     "Pernah menjadi salah satu peradaban tertua di dunia.",
                     "Dikenal dengan peninggalan arkeologi besar yang berbentuk segitiga."}
                };
                char *clueT[2] = {
                                "Gunung Everest dan tempat lahirnya Siddhartha Gautama (Buddha) berada di sini.", 
                                "Bangunan Piramida Giza dan Patung Sphinx menjadi simbol negara ini."
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
                    scanf(" %9s", &input); 

                    bool valid = true;
                        for (int i = 0; i < strlen(input); i++) {
                            if (!isdigit((unsigned char)input[i])) {
                                valid = false;
                                break;
                            }
                        }
                    if (!valid) {
                        printf("\n%sInput tidak valid. Masukkan angka 0 sampai 2.%s\n", RED, RESET);
                        No = -1; // biar ga keluar loop ini
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
                    if (strcmp(jawaban, negara[index]) == 0) {
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
                                if (strcmp(jawaban, negara[index]) == 0) {
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
}