#include "ex1.h"

// Exo 2.1

MemoryHandler *memory_init(int size){
    MemoryHandler * mh = (MemoryHandler *)malloc(sizeof(MemoryHandler));
    mh->memory = NULL;
    mh->total_size = size;
    mh->free_list = NULL;
    mh->allocated = NULL;
}

// Exo 2.2

/*Segment * find_free_segment(MemoryHandler* handler, int start, int size, Segment** prev){
        while(handler->free_list){
            if()
            handler->free_list = handler->free_list->next;
        }
        return new_seg;
    } else {

    } */

// Exo 2.3

/*int create_segment(MemoryHandler *handler, const char *name, int start, int size){
    Segment * seg = (Segment *)malloc()sizeof(Segment);
    seg->
}*/