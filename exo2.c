#include <stdio.h>
#include <stdlib.h>
#include "exo2.h"

// Exo 2.1
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

// Exo 2.2
Segment* find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev){
    if (!handler) return NULL;
    prev = NULL;
    Segment *tmp = handler->free_list;
    while(tmp){
        if(tmp->start <= start && tmp->size >= start+size){
            return tmp;
        }
        (*prev) = tmp;
        tmp = tmp->next;
    }
    return NULL;
}

// Exo 2.4
int remove_segment(MemoryHandler *handler, const char *name){
    Segment *s = (Segment *)hashmap_get(handler->allocated, name);
    Segment *sf = handler->free_list;
    while (sf){
        if (s->start + s->size < sf->start){
            handler->free_list = s;
            s->next = sf;
            break;
        }

        if (s->start + s->size == sf->start){
            Segment* snv = (Segment*)malloc(sizeof(Segment));
            snv->start = s->start;
            snv->size = s->size + sf->size;
            snv->next = sf->next;
            handler->free_list = snv;
            free(sf);
            free(s);
            s = snv;
            sf = snv;
        }

        if (s->start == sf->start + sf->size){
            Segment* snv = (Segment*)malloc(sizeof(Segment));
            snv->start = sf->start;
            snv->size = s->size + sf->size;
            snv->next = sf->next;
            handler->free_list = snv;
            free(sf);
            free(s);
            s = snv;
            sf = snv;
        }

        if (s->start > sf->start + sf->size){
            Segment * s_temp = sf->next;
            sf->next = s;
            s->next = s_temp;
            sf = s;
        }
        sf = sf->next; 
    }

    return hashmap_remove(handler->allocated, name);

}


