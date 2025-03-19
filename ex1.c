#include "ex1.h"

// Exo 1.1
unsigned long simple_hash(const char *str){
    unsigned long s = 0;
    for(int i = 0; i < strlen(str) || str[i]!='\0'; i++){
        s += ((unsigned long)str[i] + i + 1);
    }

    return s % 128;
}

// Exo 1.2
HashEntry * hashentry_create(const char *key, void *value){
    HashEntry *he = (HashEntry *)malloc(sizeof(HashEntry));
    he->key = (char *)key;
    he->value = value;
    return he;
}

HashMap *hashmap_create(){
    HashMap *hm = (HashMap *)malloc(sizeof(HashMap));
    hm->size = TAILLE;
    hm->table = (HashEntry *)malloc(TAILLE * sizeof(HashMap));

    for (int i = 0; i < TAILLE; i++){
        hm->table[i] = *hashentry_create("", TOMBSTONE);
    }
    return hm;
}

// Exo 1.3
int hashmap_insert(HashMap *map, const char *key, void *value){
    unsigned long indice = simple_hash(key);

    if (map->table[indice].value == TOMBSTONE){
        map->table[indice].key = (char *)key;
        map->table[indice].value = value;
        return indice;
    } else {
        for(int i = indice+1; i != indice; i++){
            if (map->table[i].value == TOMBSTONE){
                map->table[i].key = (char *)key;
                map->table[i].value = value;
                return i;
            }
        }
    }
    exit(-1);
}

// Exo 1.4
void * hashmap_get(HashMap *map, const char *key){
    unsigned long indice = simple_hash(key);
    return map->table[indice].value;
}

// Exo 1.5
int hashmap_remove(HashMap *map, const char *key){
    unsigned long indice = simple_hash(key);
    map->table[indice].key = (char *)key;
    map->table[indice].value = TOMBSTONE;
    return indice;
}

// Exo 1.6
void hashmap_destroy(HashMap *map){
    free(map->table);
    free(map);
}






