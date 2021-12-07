#include "Util.h"

/* Made by Hunter */
/* Returns the length of the string (including null char) */
int StringLength (const char *s) {
    int n = 0;
    while (s[n++] != '\0');
    return n;
}