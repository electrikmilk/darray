# darray
Easy to use dynamic array implementation.

## Stubs

```c
// Initialize array
Array *new_array();

// Append to array
void append_array(Array *array, void *item);

// Remove item from array
void splice_array(Array *array, int index);

// Free memory allocated for array
void free_array(Array *array);
```

## Example usage

```c
#include <stdio.h>
#include "darray.c"

int main() {
    Array *a = new_array();

    for (int j = 1; j <= 20; j++) {
        append_array(a, &j);
    }

    splice_array(a, 1);

    for (int k = 0; k < a->size; k++) {
        printf("%d: %d\n", k, *(int *) a->items[k]);
    }

    free_array(a);

    return 0;
}
```
