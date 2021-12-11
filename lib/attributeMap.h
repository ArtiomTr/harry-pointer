#ifndef HARRY_POINTER_ATTRIBUTE_MAP_H
#define HARRY_POINTER_ATTRIBUTE_MAP_H

typedef struct {
    char **keys;
    char **values;
    int capacity;
    int size;
} HPAttributeMap;

HPAttributeMap hpCreateAttributeMap();
void hpSet(HPAttributeMap *map, char *key, char *value);
char *hpGetValue(HPAttributeMap *map, char *key);

#endif
