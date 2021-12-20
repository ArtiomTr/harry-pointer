#include "dynamicArray.h"

#include <stdlib.h>

DynamicArray createDynamicArray() {
    return (DynamicArray){
            .capacity = 0,
            .size = 0,
            .values = NULL,
    };
}

void pushToDynamicArray(DynamicArray *array, void *value) {
    if(array->size >= array->capacity) {
        int newCapacity = array->capacity == 0 ? 1 : array->capacity * 2;
        array->values = realloc(array->values, newCapacity * sizeof(void*));
    }

    array->values[array->size] = value;
    array->size += 1;
}
