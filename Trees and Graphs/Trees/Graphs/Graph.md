# 📊 Graph Data Structure

## 1️⃣ Definition of Graph

A **graph** is a non-linear data structure that consists of a finite set of **vertices (nodes)** and a set of **edges** connecting pairs of vertices.

![Graph Structure](https://upload.wikimedia.org/wikipedia/commons/thumb/5/5b/6n-graf.svg/350px-6n-graf.svg.png)

**Mathematical Representation:**

$$G = (V, E)$$

Where:
- **V** → Set of vertices
- **E** → Set of edges

Graphs are used to represent **networks, relationships, and connections**.

---

## 2️⃣ Basic Graph Terminology

| Term | Definition |
|------|------------|
| **Vertex (Node)** | A basic unit of a graph that represents an entity |
| **Edge** | A connection between two vertices |
| **Adjacent Vertices** | Two vertices connected by an edge |
| **Degree** | Number of edges connected to a vertex |
| **Path** | A sequence of vertices connected by edges |
| **Simple Path** | A path with no repeated vertices |
| **Cycle** | A path where the first and last vertices are the same |
| **Loop** | An edge that connects a vertex to itself |

---

## 3️⃣ Types of Graphs

### 🔹 Undirected Graph

Edges have **no direction** — connection is bidirectional.

![Undirected Graph](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bf/Undirected.svg/220px-Undirected.svg.png)

---

### 🔹 Directed Graph (Digraph)

Edges have **direction** — represented using arrows.

![Directed Graph](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a2/Directed.svg/220px-Directed.svg.png)

---

### 🔹 Weighted Graph

Each edge has a **weight or cost**. Used in shortest path problems.

![Weighted Graph](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bc/CPT-Graphs-directed-weighted-ex1.svg/300px-CPT-Graphs-directed-weighted-ex1.svg.png)

---

### 🔹 Complete Graph

Every vertex is connected to **every other vertex**.

![Complete Graph](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9e/Complete_graph_K7.svg/200px-Complete_graph_K7.svg.png)

For n vertices: $\text{Edges} = \frac{n(n-1)}{2}$

---

### 🔹 Cyclic vs Acyclic Graph

| Type | Description |
|------|-------------|
| **Cyclic** | Contains at least one cycle |
| **Acyclic** | Contains no cycles (DAG = Directed Acyclic Graph) |

![Directed Acyclic Graph](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fe/Tred-G.svg/280px-Tred-G.svg.png)

---

## 4️⃣ Degree Concepts

| Concept | Description |
|---------|-------------|
| **Degree** (Undirected) | Number of edges connected to a vertex |
| **In-Degree** (Directed) | Number of edges coming **into** a vertex |
| **Out-Degree** (Directed) | Number of edges going **out** of a vertex |

---

## 5️⃣ Graph Representation

### 🔹 Adjacency Matrix

A **2D array** of size V × V where:
- `1` → Edge exists
- `0` → No edge

![Adjacency Matrix](https://upload.wikimedia.org/wikipedia/commons/thumb/2/28/Symmetric_group_4%3B_Cayley_graph_1%2C2%2C6_%28adjacency_matrix%29.svg/300px-Symmetric_group_4%3B_Cayley_graph_1%2C2%2C6_%28adjacency_matrix%29.svg.png)

**Characteristics:**
- ✅ Fast edge lookup O(1)
- ❌ Uses more memory O(V²)
- 📌 Suitable for **dense graphs**

---

### 🔹 Adjacency List

An **array of linked lists** where each vertex stores a list of its adjacent vertices.

![Adjacency List](https://upload.wikimedia.org/wikipedia/commons/thumb/7/71/Adjacencylist_linkedlistof_doublelinkedlists_undirectedgraph.svg/400px-Adjacencylist_linkedlistof_doublelinkedlists_undirectedgraph.svg.png)

**Characteristics:**
- ✅ Uses less memory O(V + E)
- ✅ Efficient for **sparse graphs**
- ❌ Edge lookup is slower O(V)

---

## 6️⃣ Comparison: Matrix vs List

| Feature | Adjacency Matrix | Adjacency List |
|---------|------------------|----------------|
| **Memory** | O(V²) - High | O(V + E) - Low |
| **Edge Lookup** | O(1) - Fast | O(V) - Slower |
| **Best For** | Dense graphs | Sparse graphs |
| **Representation** | 2D Array | Linked Lists |

---

## 7️⃣ Graph Traversals

### 🔹 Breadth-First Search (BFS)

Explores neighbors level by level using a **Queue**.

![BFS Animation](https://upload.wikimedia.org/wikipedia/commons/4/46/Animated_BFS.gif)

**Applications:** Shortest path (unweighted), level order traversal

---

### 🔹 Depth-First Search (DFS)

Explores as deep as possible before backtracking using a **Stack**.

![DFS Animation](https://upload.wikimedia.org/wikipedia/commons/7/7f/Depth-First-Search.gif)

**Applications:** Cycle detection, topological sort, pathfinding

---

## 8️⃣ Applications of Graphs

| Application | Example |
|-------------|---------|
| 🌐 Computer Networks | Internet, LAN topology |
| 🗺️ Road Maps | GPS navigation, Google Maps |
| 👥 Social Networks | Facebook friends, LinkedIn connections |
| ⚡ Electrical Circuits | Circuit design |
| 📅 Scheduling | Task dependencies, project planning |
| 📡 Communication | Telecom networks |

---

## 📚 Code Implementation

➡️ [Graph.c](Graph.c) — Graph implementation with BFS & DFS
