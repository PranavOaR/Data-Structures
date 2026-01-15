# Stack Data Structure

---

## What is an Expression?

| Type | Example | Evaluation |
|------|---------|------------|
| **Infix** | `A + B` | Needs precedence rules |
| **Postfix** | `A B +` | No precedence needed |
| **Prefix** | `+ A B` | Operator first |

> 💡 Stacks are mainly used to convert **infix → postfix**

---

## Why Convert Infix to Postfix?

- ❌ Infix needs precedence & parentheses handling
- ✅ Postfix can be evaluated directly using stack
- ✅ Used by compilers & interpreters

---

## Operator Precedence

| Operator | Priority |
|----------|----------|
| `^` | Highest |
| `*` `/` | Medium |
| `+` `-` | Lowest |

---

## Algorithm: Infix → Postfix

1. Scan expression **left to right**
2. If **operand** → add to postfix output
3. If `(` → push to stack
4. If **operator**:
   - Pop operators from stack with **higher or equal precedence**
   - Then push current operator
5. If `)` → Pop until `(` is found
6. After scanning → Pop remaining operators from stack

### Example

```
Infix:   A + B * C
Postfix: A B C * +
```

### 📄 Code: [InfixToPostfix.c](InfixToPostfix.c)

---

## Postfix Expression Evaluation

### Algorithm

1. Scan expression **left to right**
2. If **operand** → push onto stack
3. If **operator**:
   - Pop `operand2`
   - Pop `operand1`
   - Apply operator: `operand1 op operand2`
   - Push result back
4. Final stack top is the **result**

### Example

```
Postfix: 2 3 * 5 4 * +

Step 1: 2 3 * → 6
Step 2: 5 4 * → 20
Step 3: 6 + 20 → 26

Result: 26
```

### 📄 Code: [PostfixEvaluation.c](PostfixEvaluation.c)

---

## Stack Implementation

### Stack ADT

**LIFO** – Last In First Out

| Operation | Description |
|-----------|-------------|
| `push()` | Add element to top |
| `pop()` | Remove element from top |
| `peek()` | View top element |
| `display()` | Show all elements |

### Structure

```
    ┌───────┐
    │   3   │  ← top
    ├───────┤
    │   2   │
    ├───────┤
    │   1   │
    └───────┘
```

---

## Stack Using Static Array

### 📄 Code: [Static Stack.c](Static%20Stack.c)

**Key Points:**
- Fixed size array
- `top` variable tracks the top element
- Check for **overflow** before push
- Check for **underflow** before pop

---

## Stack Using Linked List

### 📄 Code: [LL Stack.c](LL%20Stack.c)

**Key Points:**
- Dynamic size (no overflow)
- Each node contains `data` and `next` pointer
- `top` is a pointer to the first node
- New elements added at the head

---

## Applications of Stack

| Application | Description |
|-------------|-------------|
| **Expression Evaluation** | Postfix/Prefix evaluation |
| **Function Calls** | Call stack in recursion |
| **Undo/Redo** | Text editors, browsers |
| **Backtracking** | Maze solving, puzzles |
| **Parenthesis Checking** | Balanced brackets |
| **Browser History** | Back button navigation |

---

## Advantages & Disadvantages

### ✅ Advantages

- Simple to implement
- Fast operations – **O(1)** for push/pop
- Memory efficient (linked list version)

### ❌ Disadvantages

- Limited access (only top element)
- Overflow possible (array version)
- Underflow if empty

---

## Quick Reference

| Implementation | Overflow | Underflow | Size |
|----------------|----------|-----------|------|
| **Static Array** | Yes | Yes | Fixed |
| **Linked List** | No | Yes | Dynamic |

