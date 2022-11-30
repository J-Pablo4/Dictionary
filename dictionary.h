//
// Created by jplop on 30/11/2022.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include <stdlib.h>

typedef struct dictionary Dictionary;

Dictionary* new_dictionary(
        int (*hash)(void*),
        int (*eql)(void*, void*)
);
void* set(Dictionary* d, void* k, void* v);
void* get(Dictionary* d, void* k);
int key_exists(Dictionary* d, void* k);

#endif //DICTIONARY_DICTIONARY_H
