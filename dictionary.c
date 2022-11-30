//
// Created by jplop on 30/11/2022.
//

#include "dictionary.h"

#define HASH_TABLE_SIZE 1000
typedef struct item
{
    void *key;
    void *value;
    struct item* next;
}
        Item;
struct dictionary
{
    int (*Hash)(void*);
    int (*Equal)(void*, void*);
    Item* hash_table[HASH_TABLE_SIZE];
};

Dictionary* new_dictionary(int (*hash)(void*),int (*eql)(void*, void*))
{
    Dictionary *dictionary_new = calloc(1, sizeof (Dictionary));

    dictionary_new->Hash = hash;
    dictionary_new->Equal = eql;

    return dictionary_new;
}

void* set(Dictionary* d, void* k, void* v)
{
    Item *new_item = calloc(1, sizeof (Item));
    new_item->key = k;
    new_item->value = v;
    new_item->next = NULL;

    int index = d->Hash(k);

    if(d->hash_table[index] == NULL)
    {
        d->hash_table[index] = new_item;
    } else
    {
        Item *compare = d->hash_table[index];
        if(d->Equal(compare->key, new_item->key))
        {

        }
    }
}
void* get(Dictionary* d, void* k);
int key_exists(Dictionary* d, void* k);

