# Data Structures in C 

A comprehensive collection of data structure implementations and theory notes in C..

---

## 📁 Repository Structure - All content details 
 
```
Data-Structures/
├── DMA-Pointers-Arrays/
│   ├── DMA.md
│   ├── Pointers.md
│   └── ADT-Array-Strcutures.md
│
├── Linked Lists/
│   ├── LLTheory.md
│   ├── SLLWH.c / SLLWOH.c
│   ├── DLLWH.c / DLLWOH.c
│   ├── CSLLWH.c / CSLLWOH.c
│   └── CDLLWH.c / CDLLWOH.c
│
├── Stacks and Queues/
│   ├── Stacks/
│   │   ├── Stack.md
│   │   ├── Static Stack.c
│   │   ├── LL Stack.c
│   │   ├── InfixToPostfix.c
│   │   └── PostfixEvaluation.c
│   │
│   └── Queues/
│       ├── Queue.md
│       ├── Static Queue.c
│       ├── LL Queue.c
│       ├── Static Circular Queue.c
│       └── LL Circular Queue.c
│
└── Trees and Graphs/
    ├── Trees/
    │   ├── Trees.md
    │   └── Trees.c
    │
    └── Graphs/
        ├── Graph.md
        └── images/
```

---

## 📚 Contents

### 1. DMA, Pointers & Arrays

Foundational concepts for understanding data structures.

| File | Topics Covered |
|------|----------------|
| [DMA.md](DMA-Pointers-Arrays/DMA.md) | malloc, calloc, realloc, free |
| [Pointers.md](DMA-Pointers-Arrays/Pointers.md) | Dangling pointers, Memory leaks |
| [ADT-Array-Strcutures.md](DMA-Pointers-Arrays/ADT-Array-Strcutures.md) | ADT, Self-referential structures, Nested structures |

---

### 2. Linked Lists - C Implementation

All linked list implementations with theory notes.

📖 **Theory:** [LLTheory.md](Linked%20Lists/LLTheory.md)

| Type | With Header | Without Header |
|------|-------------|----------------|
| **Singly Linked List** | [SLLWH.c](Linked%20Lists/SLLWH.c) | [SLLWOH.c](Linked%20Lists/SLLWOH.c) |
| **Doubly Linked List** | [DLLWH.c](Linked%20Lists/DLLWH.c) | [DLLWOH.c](Linked%20Lists/DLLWOH.c) |
| **Circular Singly LL** | [CSLLWH.c](Linked%20Lists/CSLLWH.c) | [CSLLWOH.c](Linked%20Lists/CSLLWOH.c) |
| **Circular Doubly LL** | [CDLLWH.c](Linked%20Lists/CDLLWH.c) | [CDLLWOH.c](Linked%20Lists/CDLLWOH.c) |

**Features:**
- Insert at Beginning / End / Position
- Delete from Beginning / End / Position
- Display List
- Menu-driven programs

---

### 3. Stacks

LIFO (Last In First Out) data structure implementations.

📖 **Theory:** [Stack.md](Stacks%20and%20Queues/Stacks/Stack.md)

| Implementation | File |
|----------------|------|
| Static Array Stack | [Static Stack.c](Stacks%20and%20Queues/Stacks/Static%20Stack.c) |
| Linked List Stack | [LL Stack.c](Stacks%20and%20Queues/Stacks/LL%20Stack.c) |
| Infix to Postfix | [InfixToPostfix.c](Stacks%20and%20Queues/Stacks/InfixToPostfix.c) |
| Postfix Evaluation | [PostfixEvaluation.c](Stacks%20and%20Queues/Stacks/PostfixEvaluation.c) |

**Topics Covered:**
- Stack ADT & operations
- Expression conversion (Infix → Postfix)
- Postfix evaluation
- Applications of stacks

---

### 4. Queues

FIFO (First In First Out) data structure implementations.

📖 **Theory:** [Queue.md](Stacks%20and%20Queues/Queues/Queue.md)

| Implementation | File |
|----------------|------|
| Static Array Queue | [Static Queue.c](Stacks%20and%20Queues/Queues/Static%20Queue.c) |
| Linked List Queue | [LL Queue.c](Stacks%20and%20Queues/Queues/LL%20Queue.c) |
| Static Circular Queue | [Static Circular Queue.c](Stacks%20and%20Queues/Queues/Static%20Circular%20Queue.c) |
| Linked List Circular Queue | [LL Circular Queue.c](Stacks%20and%20Queues/Queues/LL%20Circular%20Queue.c) |

**Topics Covered:**
- Queue ADT & operations
- Circular Queue
- Round Robin CPU Scheduling
- Applications of queues

---

### 5. Trees

Hierarchical data structure implementations.

📖 **Theory:** [Trees.md](Trees%20and%20Graphs/Trees/Trees.md)

| Implementation | File |
|----------------|------|
| Binary Search Tree | [Trees.c](Trees%20and%20Graphs/Trees/Trees.c) |

**Topics Covered:**
- Tree terminology & types
- Binary Trees, BST, AVL, Red-Black Trees
- Tree traversals (Inorder, Preorder, Postorder, Level Order)
- Heap data structure

---

### 6. Graphs

Non-linear data structure for representing networks.

📖 **Theory:** [Graph.md](Trees%20and%20Graphs/Graphs/Graph.md)

**Topics Covered:**
- Graph terminology & types
- Adjacency Matrix & Adjacency List
- BFS & DFS traversals
- Applications of graphs

---

## 🛠️ How to Compile and Run

```bash
# Navigate to the folder
cd "Linked Lists"

# Compile
gcc <filename>.c -o <output_name>

# Run
./<output_name>
```

### Example

```bash
gcc SLLWOH.c -o sll
./sll
```

---

## 📊 Data Structures Comparison

| Data Structure | Access | Insert | Delete | Use Case |
|----------------|--------|--------|--------|----------|
| Array | O(1) | O(n) | O(n) | Random access |
| Linked List | O(n) | O(1) | O(1) | Dynamic size |
| Stack | O(n) | O(1) | O(1) | LIFO operations |
| Queue | O(n) | O(1) | O(1) | FIFO operations |
| BST (balanced) | O(log n) | O(log n) | O(log n) | Sorted data |
| Graph | O(V+E) | O(1) | O(E) | Networks |

---

## 📝 Notes Format

All theory files (`.md`) include:
- ✅ Definitions and concepts
- ✅ Visual diagrams
- ✅ Algorithm explanations
- ✅ Code examples with links
- ✅ Comparison tables
- ✅ Applications
- ✅ Advantages & Disadvantages

---

## 🎓 Topics Covered

- [x] Dynamic Memory Allocation
- [x] Pointers & Memory Management
- [x] Abstract Data Types (ADT)
- [x] Singly Linked Lists
- [x] Doubly Linked Lists
- [x] Circular Linked Lists
- [x] Stacks (Array & Linked List)
- [x] Expression Conversion & Evaluation
- [x] Queues (Simple & Circular)
- [x] Round Robin Scheduling
- [x] Trees & Binary Search Trees
- [x] Tree Traversals
- [x] Graphs (BFS & DFS)

---

## 📄 License

This repository is for educational purposes.
