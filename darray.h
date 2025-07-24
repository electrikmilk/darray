//
// Created by Brandon Jordan on 3/7/24.
//

#ifndef DARRAY_H
#define DARRAY_H

#include <mm_malloc.h>
#include <memory.h>

typedef struct {
    void **items;
    long unsigned size;
} Array;

Array *new_array() {
    Array *new_array;
    new_array = malloc(sizeof(Array));
    new_array->items = malloc(sizeof(void *));
    new_array->size = 0;

    return new_array;
}

void append_array(Array *array, void *item) {
    array->size++;

    unsigned long item_size = sizeof(item);
    if ((array->items = (void **) realloc(array->items, array->size * item_size)) == NULL) {
        printf("Failed to allocate memory for array item.");
        exit(1);
    }

    unsigned long new_position = array->size - 1;
    array->items[new_position] = malloc(item_size);
    memmove(array->items[new_position], item, item_size);
}

void free_array(Array *array) {
    for (unsigned long i = 0; i < array->size; i++) {
        free(array->items[i]);
        array->items[i] = NULL;
    }

    free(array->items);
    array->items = NULL;
    array->size = 0;
}

void splice_array(Array *array, int index) {
    Array *temp_array = new_array();

    array->items[index] = NULL;
    array->size--;

    unsigned long array_index = 0;
    for (unsigned long i = 0; i < array->size; i++) {
        if (array->items[i] != NULL) {
            append_array(temp_array, array->items[array_index]);
        }

        array_index++;
    }

    if ((array->items = malloc(sizeof(temp_array->items))) == NULL) {
        printf("Failed to resize array when splicing.");
        exit(1);
    }
    array->size = temp_array->size;
    array->items = temp_array->items;
}

#endif //DARRAY_H
