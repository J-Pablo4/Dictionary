#include <stdio.h>
#include "dictionary.h"
#include <string.h>

int string_equals(void *a, void *b)
{
    return strcmp(a, b) == 0;
}
// http://www.cse.yorku.ca/~oz/hash.html
int hash_string(void *s)
{
    int hash = 5381;
    char *str = s;
    char c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

int main() {
    Dictionary* d1 = new_dictionary(hash_string, string_equals);

    set(d1, "h", "hola");

    return 0;
}
