#include <stdio.h>
#include <ctype.h>
#include <string.h>
int is_palindrome(char *s) {
    char *p = s;
    char *q = s + strlen(s) - 1;
    while (p < q) {
        while (p < q && !isalpha(*p)) p++;
        while (p < q && !isalpha(*q)) q--;
        if (tolower(*p) != tolower(*q)) return 0;
        p++;
        q--;
    }
    return 1;
}