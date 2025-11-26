#include <stdbool.h>

#ifndef PUSTAKA_H
#define PUSTAKA_H

#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"
#define PURPLE "\033[1;35m"
#define CYAN "\033[1;36m"
#define WHITE "\033[1;37m"
#define NAME_LEN 50
#define SAVEDATA "scores.dat"

void str_to_upper(char* str);
void remove_all_whitespace(char *str);
void hilanginNewLine(char *s);
void buah();
void hewan();
void negara();
void makanan_tradisional();
void superhero();
void tebak_rantai(int nomer);
void List_kategori();
void shop();
void saveSkor();
void loadSkor();
void cariNama();

extern bool green;
extern bool red;
extern bool blue;
extern bool purple;
extern bool yellow;
extern bool gembokHewan;
extern bool gembokNegara;
extern bool gembokMakanan_Tradisional;
extern bool gembokSuperhero;
extern bool BuahSedang;
extern bool BuahSulit;
extern bool HewanSedang;
extern bool HewanSulit;
extern bool NegaraSedang;
extern bool NegaraSulit;
extern bool makananSedang;
extern bool makananSulit;
extern bool SuperheroSedang;
extern bool SuperheroSulit;

extern char jawaban[50];
extern char butuhClue[10];
extern char lanjut[5];
extern char nama[50];
extern char input[10];
extern char warnaNama[10];

extern int poin;
extern int hint;
extern int kategori, level, No, warna, shopy, belihint;

typedef struct {
    char name[50];
    int poin;
    char waktu[30];
} Pemain;

#endif