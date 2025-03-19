#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

MemoryHandler *memory_init(int size){
    Segment* s = (Segment*)malloc(sizeof(Segment));
    s->start = 0;
    s->size = size;
    s->next = NULL;

    MemoryHandler* mh = (MemoryHandler*)malloc(sizeof(MemoryHandler));
    mh->memory = (void**)calloc(size,sizeof(void*));
    mh->total_size = size;
    mh->free_list = s;
    mh->allocated = hashmap_create();
    return mh;
}

Segment* find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev){
    if (!handler) return NULL;
    prev = NULL;
    Segment *tmp = handler->free_list;
    while(tmp){
        if(tmp->)
    }
}