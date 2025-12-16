#include <string.h>

char* str_trim(char *s) {
    if (s == NULL) return NULL;

    int len = strlen(s);
    if (len == 0) return s;
    int start = 0;

    while (start < len && (s[start] == ' ' || s[start] == '\t')) {
        start += 1;
    }

    if (start >= len) {
        s[0] = '\0';
        return s;
    }

    int end = len - 1;
    while (end >= start && (s[end] == ' ' || s[end] == '\t')) {
        end -= 1;
    }

    int i = 0;
    for (int k = start; k <= end; k++) {
        s[i++] = s[k];
    }
    s[i] = '\0';
    return s;
}