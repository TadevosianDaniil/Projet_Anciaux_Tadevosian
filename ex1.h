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


// Ex 2

typedef struct segment {
    int start; // Position de debut (adresse) du segment dans la memoire
    int size; // Taille du segment en unites de memoire
    struct Segment *next; // Pointeur vers le segment suivant dans la liste chainee
} Segment;

typedef struct memoryHandler {
    void ** memory; // Tableau de pointeurs vers la memoire allouee
    int total_size; // Taille totale de la memoire geree
    Segment *free_list; // Liste chainee des segments de memoire libres
    HashMap *allocated; // Table de hachage (nom, segment) 
} MemoryHandler;

/*2.1*/MemoryHandler *memory_init(int size);

/*2.2*/Segment *find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev);

/*2.3*/int create_segment(MemoryHandler *handler, const char *name, int start, int size); 

/*2.4*/

#endif