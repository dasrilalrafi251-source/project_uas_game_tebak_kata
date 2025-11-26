#include <ctype.h>
#include <string.h>
#include "utilsh.h"

void str_to_upper(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}
//Menghilangkan seluruh jenis spasi 
void remove_all_whitespace(char *str) {
    char *src = str, *dst = str;
    while (*src != '\0') {
        if (!isspace((unsigned char)*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

void hilanginNewLine(char *s) {
    size_t len = strlen(s);
    if (len == 0) return;
    if (s[len-1] == '\n') s[len-1] = '\0';
}