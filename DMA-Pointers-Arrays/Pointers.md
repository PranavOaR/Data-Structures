# Pointers - Common Issues and Best Practices

---

## Dangling Pointer

### Definition

A **dangling pointer** is a pointer that points to memory that has already been freed or deallocated.

### How it Occurs

```c
int *p = (int*)malloc(sizeof(int));
free(p);
*p = 5;   // ⚠️ Dangling pointer - accessing freed memory!
```

### Implications

- ❌ Undefined behavior
- ❌ Program crash
- ❌ Security vulnerabilities

### Good Practices

- ✅ Set pointer to `NULL` after `free()`
- ✅ Avoid multiple pointers referencing same memory
- ✅ Free memory exactly once

---

## Memory Leak

### Definition

A **memory leak** occurs when memory is allocated but never freed, causing the program to consume more and more memory over time.

### Example

```c
int *p = malloc(10 * sizeof(int));
// ⚠️ No free(p); - memory is leaked!
```

### Good Practices to Avoid Memory Leaks

- ✅ Always free allocated memory
- ✅ Avoid overwriting pointers without freeing first
- ✅ Use one pointer per allocation

---

## Practice Question

**Problem:** Allocate memory for 4 integers → resize to 7 → print all values

### Solution

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory for 4 integers
    int *arr = (int*)malloc(4 * sizeof(int));

    // Initialize first 4 elements
    for (int i = 0; i < 4; i++)
        arr[i] = i + 1;

    // Resize to hold 7 integers
    arr = (int*)realloc(arr, 7 * sizeof(int));

    // Initialize new elements
    for (int i = 4; i < 7; i++)
        arr[i] = i + 1;

    // Print all elements
    for (int i = 0; i < 7; i++)
        printf("%d ", arr[i]);

    // Free allocated memory
    free(arr);
    return 0;
}
```

**Output:** `1 2 3 4 5 6 7`
