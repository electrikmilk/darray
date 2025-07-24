# darray

Dynamic array implementation that can be used with any type.

They have members `items` and `size`.

- `size` is how many items are in the array.
- `items` is a pointer to the items in the array.

```c
typedef struct {
    void **items;
    long unsigned size;
} Array;
```

## Stubs

```c
// Initialize array
Array *new_array();

// Add item to array
void append_array(Array *array, void *item);

// Remove item from array
void splice_array(Array *array, int index);

// Free memory allocated for the array
void free_array(Array *array);
```

## Example usage

```c
#include <stdio.h>
#include "darray.c"

int main() {
    Array *a = new_array();

    for (int i = 1; i <= 20; i++) {
        append_array(a, &i);
    }

    splice_array(a, 1);

    for (int j = 0; j < a->size; j++) {
        printf("%d: %d\n", j, *(int *) a->items[j]);
    }

    free_array(a);

    return 0;
}
```

```console
0: 1
1: 3
2: 4
3: 5
4: 6
5: 7
6: 8
7: 9
8: 10
9: 11
10: 12
11: 13
12: 14
13: 15
14: 16
15: 17
16: 18
17: 19
```

When using an item from an array, you will need to specify the type and dereference it:

```c
*(int *) array->items[index];
```
