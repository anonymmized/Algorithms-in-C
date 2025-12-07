#include <ctype.h>

int atoi(char *s) {
    long long result = 0;
    int sign = 1;
    int i = 0;
    if (!s) return 0;
    while (s[i] == ' ' || s[i] == '\t') {
        i++;
    }
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    while (isdigit(s[i])) {
        result = 10 * result + (s[i] - '0');
        i++;
    }

    result *= sign;

    return (int)result;
}