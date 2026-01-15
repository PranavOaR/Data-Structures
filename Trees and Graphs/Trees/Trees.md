# Trees Data Structure

📄 **Implementation Code:** [Trees.c](Trees.c)

<div style="background-color: #f8f9fa; padding: 20px; border-radius: 10px;">

---

## What is a Tree?

A **tree** is a non-linear hierarchical data structure that consists of nodes connected by edges. It represents data in a **parent–child relationship**.

```
            1 (Root)
           / \
          2   3
         / \   \
        4   5   6
```

---

## Tree Terminologies

| Term | Definition |
|------|------------|
| **Node** | Fundamental building block containing data and links to other nodes |
| **Edge** | The link between any two nodes |
| **Root** | The topmost node of the tree |
| **Parent** | A node that has one or more child nodes |
| **Child** | A node directly connected to another node (its parent) |
| **Siblings** | Nodes that share the same parent |
| **Leaf** | A node with no children (External Node) |
| **Internal Node** | A node with at least one child |
| **Subtree** | A tree formed by a node and its descendants |
| **Forest** | A collection of disjoint trees |

### Height, Depth & Level

| Term | Definition |
|------|------------|
| **Height of Node** | Number of edges from the node to the deepest leaf |
| **Depth of Node** | Number of edges from the root to that node |
| **Height of Tree** | Height of the root node |
| **Level** | Distance from root (Root = Level 0) |
| **Degree** | Number of children of a node |

---

## Types of Trees

### 1️⃣ General Tree

A tree where a node can have **any number of children**.

```
        A
      / | \
     B  C  D
    /|     |
   E F     G
```

**Applications:** File directory structure, Organization hierarchy

---

### 2️⃣ Binary Tree

A tree where each node has **at most two children** (left and right).

```
         10
        /  \
       5    15
      / \   / \
     3   7 12  20
```

**Applications:**
- Searching & Sorting algorithms
- Database systems
- File systems
- Compression algorithms (Huffman coding)
- Decision trees
- Game AI

---

### 3️⃣ Full Binary Tree

Each node has **either 0 or 2 children** (no node has only one child).

```
         1
        / \
       2   3
      / \
     4   5
```

> ✅ Every node has 0 or 2 children

---

### 4️⃣ Complete Binary Tree

- All levels are **completely filled** except possibly the last
- Last level nodes are filled **from left to right**

```
           1
         /   \
        2     3
       / \   /
      4   5 6
```

> ✅ Last level filled left to right

**Used in:** Heap implementation, Array representation of trees

---

### 5️⃣ Perfect Binary Tree

- All internal nodes have **exactly two children**
- All leaf nodes are at the **same level**

```
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
```

> ✅ All leaves at same level, all internal nodes have 2 children

**Property:** If height = h, total nodes = $2^{h+1} - 1$

---

### 6️⃣ Balanced Binary Tree

Height difference between left and right subtrees is **at most 1**.

**Importance:**
- ✅ Ensures efficient searching O(log n)
- ✅ Prevents tree from becoming skewed

---

### 7️⃣ Degenerate (Skewed) Tree

Each parent has **only one child** — behaves like a linked list.

```
Left Skewed:        Right Skewed:
      A                   A
     /                     \
    B                       B
   /                         \
  C                           C
 /                             \
D                               D
```

**Drawback:** Performance degrades to O(n)

---

### 8️⃣ Binary Search Tree (BST)

A binary tree where:
- **Left subtree** contains values **less than** root
- **Right subtree** contains values **greater than** root
- Both subtrees are also BSTs

```
           8
         /   \
        3     10
       / \      \
      1   6      14
         / \    /
        4   7  13
```

> ✅ Left < Root < Right (always)

**Operations:** Insertion, Searching, Deletion — all O(log n) when balanced

📄 **Code:** [Trees.c](Trees.c)

---

### 9️⃣ AVL Tree

A **self-balancing BST** where balance factor of each node is −1, 0, or +1.

```
         30 (BF=0)
        /  \
   (0) 20   40 (0)
      /  \
     10  25
```

**Balance Factor** = Height(Left Subtree) − Height(Right Subtree)

**Rotations:** LL, RR, LR, RL

---

### 🔟 Red-Black Tree

A self-balancing BST with **color properties**:
- Each node is **red** or **black**
- Root is always **black**
- No two consecutive **red** nodes
- Every path has same number of **black** nodes

```
           13(B)
          /    \
       8(R)    17(R)
       /  \      \
     1(B) 11(B)  25(B)
       \        /
       6(R)   22(R)
```

> B = Black, R = Red

---

### 1️⃣1️⃣ Heap (Binary Heap)

A **complete binary tree** satisfying heap property:

| Type | Property |
|------|----------|
| **Max Heap** | Parent ≥ Children |
| **Min Heap** | Parent ≤ Children |

```
    Max Heap:          Min Heap:
        90                 10
       /  \               /  \
      80   70            20   30
     / \                / \
    50  60             40  50
```

**Applications:** Priority queue, Heap sort

---

### 1️⃣2️⃣ Threaded Binary Tree

NULL pointers replaced by **threads** (pointers to inorder predecessor/successor).

**Purpose:**
- ✅ Faster inorder traversal
- ✅ No recursion or stack required

---

## Tree Representation

### Linked Representation (Most Common)

```c
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
```

```
     ┌──────────────────┐
     │  data  │  left  │  right  │
     └──────────────────┘
           │         │
           ▼         ▼
        [Left]    [Right]
        Child      Child
```

---

## Tree Traversals

Traversal = visiting each node **exactly once**.

### Types of Traversals

| Traversal | Order | Use Case |
|-----------|-------|----------|
| **Preorder** | Root → Left → Right | Copy tree, Prefix expression |
| **Inorder** | Left → Root → Right | BST sorted order |
| **Postorder** | Left → Right → Root | Delete tree, Postfix expression |
| **Level Order** | Level by level | BFS, Print tree |

---

### Preorder Traversal (Root → Left → Right)

```
         1  ← Visit first
        / \
       2   3
      / \
     4   5

Order: 1 → 2 → 4 → 5 → 3
```

**Steps:** Visit root, traverse left subtree, traverse right subtree

```
Visit order: Root → Left → Right
```

📄 **Code:** [Trees.c](Trees.c) - `preorder()` function

---

### Inorder Traversal (Left → Root → Right)

```
         2
        / \
       1   3  ← For BST: gives sorted order!
      
Order: 1 → 2 → 3
```

**Steps:** Traverse left subtree, visit root, traverse right subtree

```
Visit order: Left → Root → Right
```

> 💡 **For BST:** Inorder traversal gives nodes in **sorted order**

📄 **Code:** [Trees.c](Trees.c) - `inorder()` function

---

### Postorder Traversal (Left → Right → Root)

```
         3  ← Visit last
        / \
       1   2
      
Order: 1 → 2 → 3
```

**Steps:** Traverse left subtree, traverse right subtree, visit root

```
Visit order: Left → Right → Root
```

📄 **Code:** [Trees.c](Trees.c) - `postorder()` function

---

### Level Order Traversal (BFS)

```
Level 0:        1
              /   \
Level 1:     2     3
            / \   / \
Level 2:   4   5 6   7

Order: 1 → 2 → 3 → 4 → 5 → 6 → 7
```

**Steps:** Visit nodes level by level, left to right

```
Visit order: Level by level (top to bottom, left to right)
```

Uses a **Queue** for implementation.

---

## Binary Search Tree Operations

📄 **Full Implementation:** [Trees.c](Trees.c)

### Insertion

<img src="https://blog.penjee.com/wp-content/uploads/2015/11/binary-search-tree-insertion-animation.gif" alt="BST Insertion Animation" width="400">

📄 **Code:** [Trees.c](Trees.c) - `insert()` function

### Searching

<img src="https://blog.penjee.com/wp-content/uploads/2015/11/binary-search-tree-sorted-array-animation.gif" alt="BST Searching Animation" width="400">

📄 **Code:** [Trees.c](Trees.c) - `search()` function

### Deletion

<img src="https://blog.penjee.com/wp-content/uploads/2015/11/binary-search-tree-degenerating-demo-animation.gif" alt="BST Deletion Animation" width="400">

Three cases:
1. **Leaf node** → Simply remove
2. **One child** → Replace with child
3. **Two children** → Replace with inorder successor/predecessor

📄 **Code:** [Trees.c](Trees.c) - `deleteNode()` function

---

## Comparison of Tree Types

| Tree Type | Balance | Search | Insert | Delete |
|-----------|---------|--------|--------|--------|
| Binary Tree | No | O(n) | O(n) | O(n) |
| BST (balanced) | No | O(log n) | O(log n) | O(log n) |
| BST (skewed) | No | O(n) | O(n) | O(n) |
| AVL Tree | Yes | O(log n) | O(log n) | O(log n) |
| Red-Black Tree | Yes | O(log n) | O(log n) | O(log n) |
| Heap | Complete | O(n) | O(log n) | O(log n) |

---

## Applications of Trees

| Application | Tree Type |
|-------------|-----------|
| File system hierarchy | General Tree |
| Database indexing | B-Tree, B+ Tree |
| Priority queues | Heap |
| Auto-complete | Trie |
| Network routing | Spanning Tree |
| Expression parsing | Binary Tree |
| Decision making | Decision Tree |
| Compiler design | Syntax Tree |

---

## Summary

| Property | Binary Tree | BST | AVL | Heap |
|----------|-------------|-----|-----|------|
| Max children | 2 | 2 | 2 | 2 |
| Ordering | None | Left < Root < Right | Left < Root < Right | Parent ≥/≤ Children |
| Balanced | No | No | Yes | Complete |
| Use case | General | Searching | Fast search | Priority |
