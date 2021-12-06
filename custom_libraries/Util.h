#ifndef UTIL_H
#define UTIL_H

// Utility functions, since we don't have a standard library on the proteus as far as I'm aware

#define ARRAY_SIZE(n) ((sizeof(n))/(sizeof((n)[0])))

// Returns String length (including null character)
int StringLength(const char *);

#endif