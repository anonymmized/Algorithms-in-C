#include <string.h>

void reverse_string(char *s) {
    if (s == NULL) return;
    char *p = s;
    char *q = s + strlen(s) - 1;
    while (p < q) {
        char temp;
        temp = *p;
        *p = *q;
        *q = temp;
        p++;
        q--;
    }
}