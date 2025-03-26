#ifndef EX1_H
#define EX1_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ex 1
#define TAILLE 128
#define TOMBSTONE ((void *)-1)

typedef struct hashentry{
    char* key;
    void* value;
} HashEntry;
    
typedef struct hashmap {
    int size;
    HashEntry* table;
} HashMap;


/*1.1*/ unsigned long simple_hash(const char *str);

/*1.2*/HashMap *hashmap_create();

/*Mon propre*/HashEntry * hashentry_create(const char *key, void *value);

/*1.4*/int hashmap_insert(HashMap *map, const char *key, void *value);

/*1.5*/void *hashmap_get(HashMap *map, const char *key);

/*1.6*/int hashmap_remove(HashMap *map, const char *key);

/*1.6*/void hashmap_destroy(HashMap *map);

#endif