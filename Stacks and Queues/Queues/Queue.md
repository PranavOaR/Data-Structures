# Queue Data Structure

---

## What is a Queue?

A **Queue** is a linear data structure that follows the **FIFO** (First In First Out) principle – the element inserted first is removed first.

### Structure

```
  front                                rear
    ↓                                   ↓
┌───────┬───────┬───────┬───────┬───────┐
│   1   │   2   │   3   │   4   │   5   │
└───────┴───────┴───────┴───────┴───────┘
    ↑                               ↑
  dequeue                        enqueue
  (remove)                        (add)
```

---

## Queue ADT

| Operation | Description |
|-----------|-------------|
| `enqueue()` | Insert element at rear |
| `dequeue()` | Remove element from front |
| `peek()` / `front()` | View front element |
| `isEmpty()` | Check if queue is empty |
| `isFull()` | Check if queue is full (array) |

---

## Types of Queues

| Type | Description |
|------|-------------|
| **Simple Queue** | Basic FIFO queue |
| **Circular Queue** | Rear connects back to front |
| **Priority Queue** | Elements have priority |
| **Double-Ended Queue (Deque)** | Insert/delete at both ends |

---

## 1. Simple Queue Using Static Array

### Theory

- Uses a **fixed-size array**
- `front` points to the first element
- `rear` points to the last element
- Initially both `front = -1` and `rear = -1`
- **Limitation**: Space is wasted after dequeue operations (front moves forward but space is not reused)

### Operations

| Operation | Time Complexity |
|-----------|-----------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |

### 📄 Code: [Static Queue.c](Static%20Queue.c)

---

## 2. Simple Queue Using Linked List

### Theory

- Uses **dynamic memory allocation**
- Each node contains `data` and `next` pointer
- `front` pointer points to the first node
- `rear` pointer points to the last node
- **No overflow** (limited only by available memory)
- **No space wastage** like static array

### Advantages over Static Array

| Feature | Static Array | Linked List |
|---------|--------------|-------------|
| Size | Fixed | Dynamic |
| Memory | May waste | Efficient |
| Overflow | Possible | Not possible |
| Implementation | Simple | Slightly complex |

### 📄 Code: [LL Queue.c](LL%20Queue.c)

---

## 3. Circular Queue Using Static Array

### Theory

A **Circular Queue** connects the rear back to the front, forming a circle. This solves the **space wastage problem** of simple queues.

### How it Works

```
        ┌───┬───┬───┬───┬───┐
        │ 4 │ 5 │   │ 1 │ 2 │
        └───┴───┴───┴───┴───┘
          ↑       ↑
        rear    front

After rear reaches end, it wraps to index 0
```

### Key Formulas

```c
// Next position (circular)
rear = (rear + 1) % MAX;
front = (front + 1) % MAX;

// Check if full
(rear + 1) % MAX == front

// Check if empty
front == -1
```

### Advantages

- ✅ **No space wastage** – reuses empty positions
- ✅ Efficient memory utilization
- ✅ Used in **CPU scheduling** and **buffering**

### 📄 Code: [Static Circular Queue.c](Static%20Circular%20Queue.c)

---

## 4. Circular Queue Using Linked List

### Theory

Combines the benefits of:
- **Circular structure** – last node points to first
- **Linked list** – dynamic size

### Structure

```
┌───────────┐     ┌───────────┐     ┌───────────┐
│ data │ ●─┼────▶│ data │ ●─┼────▶│ data │ ●─┼──┐
└───────────┘     └───────────┘     └───────────┘  │
      ↑                                            │
      └────────────────────────────────────────────┘
    front                                        rear
```

### Advantages

- ✅ No fixed size limit
- ✅ No overflow condition
- ✅ Efficient for continuous operations

### 📄 Code: [LL Circular Queue.c](LL%20Circular%20Queue.c)

---

## Round Robin CPU Scheduling

### Definition

**Round Robin** is a preemptive CPU scheduling algorithm where each process gets a fixed **time quantum** (time slice). It uses a **circular queue** to manage processes.

### Algorithm

1. Insert all processes into a **circular queue**
2. Execute current process for **quantum time**
3. If remaining burst time > 0 → **reinsert** at rear
4. Move to next process
5. Repeat until all processes complete

### Example

| Process | Burst Time |
|---------|------------|
| P1 | 4 |
| P2 | 3 |
| P3 | 5 |

**Time Quantum = 2**

#### Execution (Gantt Chart)

```
│ P1 │ P2 │ P3 │ P1 │ P2 │ P3 │ P3 │
0    2    4    6    8    9   11   12
```

#### Step-by-Step

| Time | Process | Remaining BT | Action |
|------|---------|--------------|--------|
| 0-2 | P1 | 4→2 | Reinsert |
| 2-4 | P2 | 3→1 | Reinsert |
| 4-6 | P3 | 5→3 | Reinsert |
| 6-8 | P1 | 2→0 | Complete ✓ |
| 8-9 | P2 | 1→0 | Complete ✓ |
| 9-11 | P3 | 3→1 | Reinsert |
| 11-12 | P3 | 1→0 | Complete ✓ |

### Why Circular Queue?

- ✅ Processes **rotate** automatically
- ✅ **Fair** CPU allocation to all processes
- ✅ No starvation – every process gets a turn
- ✅ Easy to implement with circular structure

---

## Applications of Queue

| Application | Queue Type |
|-------------|------------|
| **CPU Scheduling** | Circular Queue |
| **Printer Spooling** | Simple Queue |
| **Call Center Systems** | Priority Queue |
| **Network Buffering** | Circular Queue |
| **Keyboard Buffer** | Circular Queue |
| **BFS Graph Traversal** | Simple Queue |
| **Disk Scheduling** | Multiple Queues |

---

## Comparison: Stack vs Queue

| Feature | Stack | Queue |
|---------|-------|-------|
| Principle | LIFO | FIFO |
| Insert | push (top) | enqueue (rear) |
| Delete | pop (top) | dequeue (front) |
| Pointers | 1 (top) | 2 (front, rear) |
| Example | Undo operation | Print jobs |

---

## Advantages & Disadvantages

### ✅ Advantages

- Maintains order of elements
- Efficient O(1) operations
- Fair processing (FIFO)
- Natural fit for scheduling problems

### ❌ Disadvantages

- **Simple Queue**: Space wastage after dequeue
- **Static Array**: Fixed size, overflow possible
- No random access to elements
- Search operation is O(n)

---

## Quick Reference

| Implementation | Overflow | Space Wastage | Size |
|----------------|----------|---------------|------|
| **Static Simple** | Yes | Yes | Fixed |
| **LL Simple** | No | No | Dynamic |
| **Static Circular** | Yes | No | Fixed |
| **LL Circular** | No | No | Dynamic |

