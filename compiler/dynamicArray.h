#ifndef HARRY_POINTER_DYNAMICARRAY_H
#define HARRY_POINTER_DYNAMICARRAY_H

typedef struct {
    int size;
    int capacity;
    void **values;
} DynamicArray;

DynamicArray createDynamicArray();
void pushToDynamicArray(DynamicArray *array, void *value);

#endif
