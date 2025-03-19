#include "ex1.h"

int main(){

    printf("%lu\n", simple_hash("youg"));

    HashMap *map = hashmap_create();

    hashmap_insert(map, "you", (void *)14);

    int val = (int)hashmap_get(map, "you");

    printf("%d\n", val);

    hashmap_remove(map, "you");

    val = (int)hashmap_get(map, "you");

    printf("%d\n", val);

    hashmap_destroy(map);
    return 0;
}