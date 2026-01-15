# Trees Data Structure

---

## What is a Tree?

A **tree** is a non-linear hierarchical data structure that consists of nodes connected by edges. It represents data in a **parent–child relationship**.

<img src="https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_tree.svg" alt="Binary Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="400">

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

<img src="https://upload.wikimedia.org/wikipedia/commons/f/f7/Binary_tree.svg" alt="Binary Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="350">

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

<img src="https://upload.wikimedia.org/wikipedia/commons/b/b0/Full_binary.svg" alt="Full Binary Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="300">

---

### 4️⃣ Complete Binary Tree

- All levels are **completely filled** except possibly the last
- Last level nodes are filled **from left to right**

<img src="https://upload.wikimedia.org/wikipedia/commons/d/d9/Complete_binary2.svg" alt="Complete Binary Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="300">

**Used in:** Heap implementation, Array representation of trees

---

### 5️⃣ Perfect Binary Tree

- All internal nodes have **exactly two children**
- All leaf nodes are at the **same level**

<img src="https://miro.medium.com/v2/resize:fit:776/1*CMGFtehu01ZEBgzHG71sMg.png" alt="Perfect Binary Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="350">

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

<img src="https://upload.wikimedia.org/wikipedia/commons/d/da/Binary_search_tree.svg" alt="Binary Search Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="350">

**Operations:** Insertion, Searching, Deletion — all O(log n) when balanced

---

### 9️⃣ AVL Tree

A **self-balancing BST** where balance factor of each node is −1, 0, or +1.

<img src="https://upload.wikimedia.org/wikipedia/commons/f/fd/AVL_Tree_Example.gif" alt="AVL Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="350">

**Balance Factor** = Height(Left Subtree) − Height(Right Subtree)

**Rotations:** LL, RR, LR, RL

---

### 🔟 Red-Black Tree

A self-balancing BST with **color properties**:
- Each node is **red** or **black**
- Root is always **black**
- No two consecutive **red** nodes
- Every path has same number of **black** nodes

<img src="https://upload.wikimedia.org/wikipedia/commons/6/66/Red-black_tree_example.svg" alt="Red-Black Tree" style="background-color: white; padding: 15px; border-radius: 8px;" width="400">

---

### 1️⃣1️⃣ Heap (Binary Heap)

A **complete binary tree** satisfying heap property:

| Type | Property |
|------|----------|
| **Max Heap** | Parent ≥ Children |
| **Min Heap** | Parent ≤ Children |

<img src="https://upload.wikimedia.org/wikipedia/commons/3/38/Max-Heap.svg" alt="Max Heap" style="background-color: white; padding: 15px; border-radius: 8px;" width="350">

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

<img src="https://upload.wikimedia.org/wikipedia/commons/a/ac/Preorder-traversal.gif" alt="Preorder Traversal" style="background-color: white; padding: 15px; border-radius: 8px;" width="300">

```
Visit order: A → B → D → E → C → F
```

---

### Inorder Traversal (Left → Root → Right)

<img src="https://upload.wikimedia.org/wikipedia/commons/4/48/Inorder-traversal.gif" alt="Inorder Traversal" style="background-color: white; padding: 15px; border-radius: 8px;" width="300">

```
Visit order: D → B → E → A → F → C
```

> 💡 **For BST:** Inorder traversal gives nodes in **sorted order**

---

### Postorder Traversal (Left → Right → Root)

<img src="https://upload.wikimedia.org/wikipedia/commons/2/28/Postorder-traversal.gif" alt="Postorder Traversal" style="background-color: white; padding: 15px; border-radius: 8px;" width="300">

```
Visit order: D → E → B → F → C → A
```

---

### Level Order Traversal (BFS)

<img src="https://upload.wikimedia.org/wikipedia/commons/d/d1/Sorted_binary_tree_breadth-first_traversal.svg" alt="Level Order Traversal" style="background-color: white; padding: 15px; border-radius: 8px;" width="350">

```
Visit order: A → B → C → D → E → F (level by level)
```

Uses a **Queue** for implementation.

---

## Binary Search Tree Operations

### Insertion

<img src="https://blog.penjee.com/wp-content/uploads/2015/11/binary-search-tree-insertion-animation.gif" alt="BST Insertion" style="background-color: white; padding: 15px; border-radius: 8px;" width="400">

### Searching

<img src="https://blog.penjee.com/wp-content/uploads/2015/11/binary-search-tree-sorted-array-animation.gif" alt="BST Searching" style="background-color: white; padding: 15px; border-radius: 8px;" width="400">

### Deletion

Three cases:
1. **Leaf node** → Simply remove
2. **One child** → Replace with child
3. **Two children** → Replace with inorder successor/predecessor

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
