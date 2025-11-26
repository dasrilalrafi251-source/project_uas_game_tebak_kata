#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "pustaka.h"

void buah() {
    do {       
        //Menentukan pilihan kesulitan  
        printf("\n=====================\n");
        printf("SILAKAN PILIH LEVEL: \n");
        printf("=====================\n");  
        printf("1. Mudah\n");
        if (BuahSedang) {printf("2. Sedang\n");} else {printf("%s2. Sedang (5 poin)\n%s", RED, RESET);}
        if (BuahSulit) {printf("3. sulit\n");} else {printf("%s3. sulit (10 poin)\n%s", RED, RESET);}
        printf("0. kembali\n");
        printf("Level: \n");
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
            // LEVEL MUDAH
            case 1: {
                //Menyiapkan perpustakaan jawaban & clue
                char *buah[2] = {"PISANG", "APEL"};
                char *clue[2][3] = {
                    {"Buah ini memiliki kulit berwarna kuning saat matang.",
                     "Buah ini sering dijadikan toping ataupun kondimen dalam dessert.",
                     "Kulit buah ini sering membuat karakter kartun terpeleset."},
                    {"Buah ini umumnya berwarna merah tetapi sering dijumpai juga berwarna hijau atau oranye.",
                     "Buah ini biasanya tumbuh di lingkungan dengan cuaca dingin.",
                     "Gambar buah ini dijadikan logo suatu perusahaan teknologi terkenal."}
                };
                char *clueT[2] = {
                                "Buah ini berbentuk panjang melengkung dan tumbuh dalam tandan.", 
                                "Buah ini muncul dalam terjemahan bahasa inggris dari jakun."
                            };
                
                printf("\nKamu memilih level MUDAH!\n");
                
                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0]-Kembali\n");
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
                    if (strcmp(jawaban, buah[index]) == 0) {
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
                    } else if (i == 2) { //menawarkan clue tambahan dengan adanya hint
                        printf("%sSalah!%s Mau lanjut clue berikutnya? (Iya/Tidak): \n", RED, RESET);
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
                                if (strcmp(jawaban, buah[index]) == 0) {
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
                if (poin >= 5 || BuahSedang) {
                    if (!BuahSedang) {
                        printf("Selamat, anda membuka level sedang\n");
                        poin -= 5;
                        BuahSedang = true;
                    } 
                } else if (poin < 5 && !BuahSedang) {
                    printf("Anda membutuhkan 5 point untuk membuka tingkat level ini\n");
                    break;
                }
                //Menyiapkan perpustakaan jawaban & clue
                char *buah[2] = {"KELAPA", "DURIAN"};
                char *clue[2][3] = {
                    {"Buah ini sangat identik dengan iklim tropis.",
                     "Pohon dari buah ini dapat kita jumpai di wilayah pesisir.",
                     "Kulit dari buah ini seing dijadikan sebagai bahan kerajinan."},
                    {"Buah ini memiliki aroma khas yang sangat kuat.",
                     "Kulit dari buah ini tebal, keras, dan dipenuhi duri tajam.",
                     "Terkenal dengan julukan King of Fruits."}
                };
                char *clueT[2] = {
                                "Daging buah ini dijadikan santan untuk berbagai masakan.", 
                                "Di dalam unsur nama dari buah ini terdapat kata duri."
                            };

                printf("\nKamu memilih level SEDANG!\n");

                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0]-Kembali\n");
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
                    if (strcmp(jawaban, buah[index]) == 0) {
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
                                if (strcmp(jawaban, buah[index]) == 0) {
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
                if (poin >= 5 || BuahSulit) {
                    if (!BuahSulit) {
                        printf("Selamat, anda membuka level Sulit\n");
                        poin -= 5;
                        BuahSulit = true;
                    } 
                } else if (poin < 10 && !BuahSulit) {
                    printf("Anda membutuhkan 10 point untuk membuka tingkat level ini\n");
                    break;
                }
                //Menyiapkan perpustakaan jawaban & clue
                char *buah[2] = {"PERSIK", "MANGGIS"};
                char *clue[2][3] = {
                    {"Kulit buah ini memiliki warna oranye kemerahan.",
                     "Buah ini memiiki rasa yang asam serta memberikan sensasi segar.",
                     "Berasal dari negeri tiongkok, sering di asosiasikan dengan cinta."},
                    {"Kulit buah ini terkenal memiliki manfaat bagi kesehatan kulit.",
                     "Daging buah ini berwarna putih dengan rasa asam dan manis.",
                     "Jumlah isi dari buah ini dapat dilihat melalui bagian bawah kulitnya."}
                };
                char *clueT[2] = {
                                "Buah ini memiliki kekerabatan dengan buah plum dan ceri.", 
                                "Buah ini dijuluki sebagai Queen of Fruits."
                            };

                printf("\nKamu memilih level SULIT!\n");
                    
                do {
                    printf("\n=====================\n");
                    printf("SILAKAN PILIH NOMOR: \n");
                    printf("=====================\n");
                    printf("[1]\n");
                    printf("[2]\n");
                    printf("[0]-Kembali\n");
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
                        break;
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
                    if (strcmp(jawaban, buah[index]) == 0) {
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
                                if (strcmp(jawaban, buah[index]) == 0) {
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