# ADT, Arrays & Structures in C

---

## 1. Abstract Data Type (ADT)

### Definition

An **Abstract Data Type (ADT)** is a data type that defines *what* operations are performed on data but does not specify *how* they are implemented.

### Key Points

- Focuses on **logical behavior**
- Implementation is **hidden**
- Improves **modularity** and **security**

### Example: Stack ADT

| Operations | Description |
|------------|-------------|
| `push()` | Add element to top |
| `pop()` | Remove element from top |
| `peek()` | View top element |

> 💡 Can be implemented using array or linked list

### Difference: Data Type vs ADT

| Data Type | ADT |
|-----------|-----|
| Defines storage | Defines behavior |
| Concrete implementation | Abstract specification |

---

## 2. Self-Referential Structure

### Definition

A **self-referential structure** is a structure that contains a pointer to another structure of the same type.

### Syntax Example

```c
struct node {
    int data;
    struct node *next;
};
```

### Usage

- Used in **linked lists**
- Enables **dynamic data structures**

> 💡 **Why pointer?** A structure cannot contain itself directly, only its address.

---

## 3. Nested Structure

### Definition

A **nested structure** is a structure that contains another structure as one of its members.

### Example

```c
struct date {
    int day, month, year;
};

struct student {
    int id;
    char name[20];
    struct date dob;  // Nested structure
};
```

### Applications

- Employee records
- Student information systems

---

## 4. Structure of Arrays

### Definition

A **structure of arrays** is a structure where each member is an array.

### Example

```c
struct student {
    int roll[50];
    float marks[50];
};
```

### Usage

- Storing similar data for multiple records
- Efficient batch processing

---

## 5. Passing Structures and Arrays to Functions

### Passing Structure (Call by Value)

```c
void display(struct student s) {
    printf("%d", s.id);
}
```

### Passing Structure (Call by Reference)

```c
void display(struct student *s) {
    printf("%d", s->id);
}
```

### Passing Array to Function

```c
void print(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
```

### Key Difference

| Type | Behavior |
|------|----------|
| Structures | Copied when passed by value |
| Arrays | Passed as address automatically |

---

## 6. Static Structure vs Dynamic Structure

| Feature | Static Structure | Dynamic Structure |
|---------|------------------|-------------------|
| Memory | Compile-time | Runtime |
| Size | Fixed | Variable |
| Allocation | Stack | Heap |
| Example | Array of structures | Linked list |

### Example

```c
struct student s[10];    // Static - fixed size
struct student *s;       // Dynamic - can grow/shrink
```

---

## 7. Classification of Data Types

```
Data Types
├── 1. Primitive
│   ├── int
│   ├── float
│   ├── char
│   └── double
│
└── 2. Non-Primitive
    ├── a) Derived
    │   ├── Array
    │   ├── Pointer
    │   ├── Structure
    │   └── Union
    │
    ├── b) User-Defined
    │   ├── typedef
    │   ├── enum
    │   ├── structure
    │   └── union
    │
    └── c) Abstract (ADT)
        ├── Stack
        ├── Queue
        ├── List
        └── Tree
```
