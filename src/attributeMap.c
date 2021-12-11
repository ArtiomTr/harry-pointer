#include "attributeMap.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HPAttributeMap hpCreateAttributeMap() {
    return (HPAttributeMap){
            .keys = NULL,
            .values = NULL,
            .capacity = 0,
            .size = 0,
    };
}

char **hpGet(HPAttributeMap *map, char *key) {
    for(int i = 0; i < map->size; ++i) {
        if(strcmp(map->keys[i], key) == 0) {
            return (map->values + i);
        }
    }

    return NULL;
}

void hpPush(HPAttributeMap *map, char *key, char *value) {
    if(map->capacity < map->size + 1) {
        int newCapacity = map->capacity == 0 ? 1 : map->capacity * 2;

        map->keys = realloc(map->keys, newCapacity * sizeof(char *));
        map->values = realloc(map->values, newCapacity * sizeof(char *));
        map->capacity = newCapacity;
    }

    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size += 1;
}

void hpUpdate(HPAttributeMap *map, char **oldValue, char *value) {
    int index = (int) (oldValue - map->values);

    if(index >= 0 && index < map->size) {
        map->values[index] = value;
    }
}

void hpSet(HPAttributeMap *map, char *key, char *value) {
    if(value == NULL || key == NULL) {
        return;
    }

    char **existingValue = hpGet(map, key);

    if(existingValue == NULL) {
        hpPush(map, key, value);
    } else {
        hpUpdate(map, existingValue, value);
    }
}