#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void makanan_tradisional() {
    do { 
        //Menentukan pilihan kesulitan
        printf("\n=====================\n");
        printf("SILAKAN PILIH LEVEL: \n");
        printf("=====================\n");  
        printf("1. Mudah\n");
        if (makananSedang) {printf("2. Sedang\n");} else {printf("%s2. Sedang (5 poin)\n%s", RED, RESET);}
        if (makananSulit) {printf("3. sulit\n");} else {printf("%s3. sulit (10 poin)\n%s", RED, RESET);}
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
                char *makanan[2] = {"NASIGORENG", "RENDANG"};
                char *clue[2][3] = {
                    {"Makanan ini sangat populer di Indonesia biasanya banyak dijual dimalem hari dan makanan ini digoreng.",
                     "Bahan utamanya adalah nasi yang digoreng bersama bumbu, telur, dan irisan daging/sayuran.",
                     "Sering dimakan untuk sarapan, makan siang, atau makan malam."},
                    {"Makanan ini berasal dari Minangkabau, Sumatera Barat Biasanya ada di rumah makan padang.",
                     "Daging (biasanya sapi) dimasak dalam santan dan rempah-rempah dalam waktu yang sangat lama.",
                     "Memiliki tekstur kering dan kaya rasa, pernah dinobatkan sebagai makanan terlezat di dunia."}
                };
                char *clueT[2] = {
                    "Bisa disajikan dengan kerupuk dan acar, dan bumbu kecap.", 
                    "Proses memasaknya bisa memakan waktu hingga empat jam atau lebih."
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
                    if (strcmp(jawaban, makanan[index]) == 0) {
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
                                if (strcmp(jawaban, makanan[index]) == 0) {
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
                if (poin >= 5 || makananSedang) {
                    if (!makananSedang) {
                        printf("Selamat, anda membuka level sedang\n");
                        poin -= 5;
                        makananSedang = true;
                    } 
                } else if (poin < 5 && !makananSedang) {
                    printf("Anda membutuhkan 5 point untuk membuka tingkat level ini\n");
                    break;
                }
                // soal dan jawaban
                char *makanan[2] = {"SATE", "RAWON"}; 
                char *clue[2][3] = {
                    {"Makanan ini berupa potongan daging yang ditusuk dan dipanggang di atas bara api.",
                     "Biasanya disajikan dengan bumbu kacang atau kecap.",
                     "Terdapat banyak variasi nama berdasarkan jenis daging dan daerah asalnya, seperti Madura atau Padang."},
                    {"Makanan berkuah ini berasal dari Jawa Timur, khususnya Surabaya.",
                     "Kuahnya berwarna gelap/hitam karena menggunakan bumbu khas yaitu kluwek.",
                     "Sering disajikan dengan tauge, telur asin, dan sambal."}
                };
                char *clueT[2] = {
                    "Saat proses pembakarannya sering dikipasi agar matang merata.", 
                    "Daging yang digunakan untuk kuah ini adalah daging sapi, dan rasanya gurih manis."
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
                    if (strcmp(jawaban, makanan[index]) == 0) {
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
                                if (strcmp(jawaban, makanan[index]) == 0) {
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
                if (poin >= 5 || makananSulit) {
                    if (!makananSulit) {
                        printf("Selamat, anda membuka level Sulit\n");
                        poin -= 5;
                        makananSulit = true;
                    } 
                } else if (poin < 10 && !makananSulit) {
                    printf("Anda membutuhkan 10 point untuk membuka tingkat level ini\n");
                    break;
                }
                // soal dan jawaban
                char *makanan[2] = {"GUDEG", "PEMPEK"};
                char *clue[2][3] = {
                    {"Makanan ini berasal dari Yogyakarta dan Jawa Tengah.",
                     "Bahan utamanya adalah nangka muda yang dimasak dengan santan dan gula merah.",
                     "Memiliki rasa dominan manis, dan disajikan dengan krecek serta telur/ayam."},
                    {"Makanan ini berasal dari Palembang, Sumatera Selatan.",
                     "Terbuat dari adonan daging ikan yang digiling dan tepung sagu.",
                     "Disajikan dengan kuah cuka berwarna hitam kecoklatan yang pedas, asam, dan manis."}
                };
                char *clueT[2] = {
                    "Proses pembuatannya bisa memakan waktu berjam-jam (dimasak semalam).", 
                    "Bentuknya bermacam-macam, seperti kapal selam, lenjer, atau bulat."
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
                    if (strcmp(jawaban, makanan[index]) == 0) {
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
                                if (strcmp(jawaban, makanan[index]) == 0) {
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