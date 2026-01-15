# Linked List Theory

---

## 1. Singly Linked List (SLL)

### Definition

A **Singly Linked List (SLL)** is a linear data structure in which each node contains data and a pointer to the next node in the list. The last node points to `NULL`.

### Structure

<img src="https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg" alt="Singly Linked List" style="background-color: white; padding: 15px; border-radius: 8px;">

### Characteristics

- Traversal only in **one direction**
- Dynamic size
- Requires less memory than DLL

### Applications

- Implementation of stacks and queues
- Dynamic memory allocation
- Polynomial manipulation
- Symbol tables

### Advantages

- ✅ Dynamic memory usage
- ✅ Easy insertion and deletion
- ✅ No memory wastage

### Limitations

- ❌ No backward traversal
- ❌ Searching is slow (O(n))

---

## 2. Circular Singly Linked List (CSLL)

### Definition

A **Circular Singly Linked List** is a variation of SLL in which the last node points back to the first node instead of `NULL`.

### Structure

<img src="https://upload.wikimedia.org/wikipedia/commons/d/df/Circularly-linked-list.svg" alt="Circular Singly Linked List" style="background-color: white; padding: 15px; border-radius: 8px;">

### Characteristics

- No `NULL` pointer
- Traversal is **circular**
- Efficient for repeated cycles

### Applications

- Round-robin scheduling
- Multiplayer games
- Circular queues
- CPU task scheduling

### Advantages

- ✅ Any node can be treated as the first node
- ✅ Efficient looping
- ✅ No need to reset traversal pointer

### Limitations

- ❌ Infinite loops if traversal is not handled carefully
- ❌ More complex than SLL

---

## 3. Doubly Linked List (DLL)

### Definition

A **Doubly Linked List** is a linear data structure in which each node contains data, a pointer to the previous node, and a pointer to the next node.

### Structure

<img src="https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg" alt="Doubly Linked List" style="background-color: white; padding: 15px; border-radius: 8px;">

### Characteristics

- Traversal in **both directions**
- Extra memory for `prev` pointer
- Easier deletion operations

### Applications

- Navigation systems (undo/redo)
- Browser history
- Music playlist navigation
- File system navigation

### Advantages

- ✅ Bidirectional traversal
- ✅ Deletion without previous node reference
- ✅ Efficient list manipulation

### Limitations

- ❌ Extra memory usage
- ❌ More pointer updates required

---

## 4. Circular Doubly Linked List (CDLL)

### Definition

A **Circular Doubly Linked List** is a doubly linked list in which:
- The last node's `next` pointer points to the first node
- The first node's `prev` pointer points to the last node

### Structure

<img src="https://prepinsta.com/wp-content/uploads/2023/01/Circular-Doubly-Linked-List-in-C.webp" alt="Circular Doubly Linked List" style="background-color: white; padding: 15px; border-radius: 8px;">

### Characteristics

- Fully **circular**
- **Bidirectional** traversal
- No `NULL` pointers

### Applications

- Operating systems (task scheduling)
- Real-time simulations
- Memory management systems
- Multiplayer game loops

### Advantages

- ✅ Efficient traversal in both directions
- ✅ Ideal for cyclic data
- ✅ No special case for first/last node

### Limitations

- ❌ Complex pointer manipulation
- ❌ Higher memory usage
- ❌ Risk of infinite loops

---

## 5. Comparison of Linked Lists

| Feature | SLL | CSLL | DLL | CDLL |
|---------|-----|------|-----|------|
| **Pointers per node** | 1 | 1 | 2 | 2 |
| **Traversal** | One-way | One-way (circular) | Two-way | Two-way (circular) |
| **Last node points to** | `NULL` | Head | `NULL` | Head |
| **Memory usage** | Least | Low | High | Highest |
| **Complexity** | Simple | Medium | Medium | High |
| **Applications** | Basic lists | Scheduling | Navigation | OS, real-time systems |
