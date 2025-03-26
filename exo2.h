#ifndef EXO2_H
#define EXO2_H


#include "exo1.h"

typedef struct segment {
    int start;
    int size;
    struct segment *next;
} Segment;

typedef struct memoryHandler {
    void **memory;
    int total_size;
    Segment *free_list;
    HashMap *allocated;
} MemoryHandler;

// Exo 2.1
MemoryHandler *memory_init(int size);

// Exo 2.2
Segment* find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev);

// Exo 2.4
int remove_segment(MemoryHandler *handler, const char *name);

#endif