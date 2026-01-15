# Dynamic Memory Allocation in C

## Introduction

Dynamic Memory Allocation (DMA) in C allows a program to allocate and deallocate memory at runtime from the **heap** instead of fixed memory at compile time. It is useful when the size of data structures is not known in advance.

### General Workflow:
1. Allocate memory
2. Use allocated memory
3. Deallocate memory when no longer needed

---

## Dynamic Memory Allocation Functions

### 1. `malloc()`

- Allocates a **single block** of memory
- Memory is **uninitialized** (contains garbage values)
- Returns `NULL` on failure

**Syntax:**
```c
ptr = (datatype*)malloc(size);
```

**Example:**
```c
int *p = (int*)malloc(sizeof(int));
*p = 10;
printf("%d", *p);
free(p);
```

---

### 2. `calloc()`

- Allocates memory for **multiple elements**
- Initializes memory to **zero**
- Returns `NULL` on failure

**Syntax:**
```c
ptr = (datatype*)calloc(n, size);
```

**Example:**
```c
int *p = (int*)calloc(5, sizeof(int));
// Allocates memory for 5 integers, all initialized to 0
```

---

### 3. `realloc()`

- **Resizes** previously allocated memory
- Preserves existing data
- Returns `NULL` on failure (original memory remains unchanged)

**Syntax:**
```c
ptr = realloc(ptr, new_size);
```

**Example:**
```c
int *p = (int*)malloc(5 * sizeof(int));
p = (int*)realloc(p, 10 * sizeof(int));  // Resize to hold 10 integers
```

---

### 4. `free()`

- **Deallocates** allocated memory
- Prevents memory leaks
- Always free memory when no longer needed

**Syntax:**
```c
free(ptr);
```

---

## Comparison Table

| Function | Initialization | Use Case |
|----------|----------------|----------|
| `malloc()` | No (garbage values) | Single block allocation |
| `calloc()` | Yes (zero) | Multiple elements allocation |
| `realloc()` | Preserves old data | Resize existing allocation |
| `free()` | N/A | Deallocate memory |

---

## Best Practices

1. **Always check for NULL** after allocation
2. **Always free memory** when done to prevent memory leaks
3. **Set pointer to NULL** after freeing to avoid dangling pointers
4. **Don't free the same memory twice** (double free error)
