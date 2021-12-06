#include "Util.h"

int StringLength (const char *s) {
    int n = 0;
    while (s[n++] != '\0');
    return n;
}