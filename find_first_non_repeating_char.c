#include <stdio.h>
char find_first(char *s) {
    char rep = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        rep = s[i];
        for (int j = i + 1; s[j] != '\0'; j++) {
            if (s[i] == s[j]) {
                rep = 0;
            }
        }
        if (rep != 0) {
            return rep;
        }
    }
}
