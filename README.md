# Data Structures

This repository contains various data structure implementations in C.

## Linked Lists

All linked list implementations are located in the [`Linked Lists/`](Linked%20Lists/) folder.

| File | Description |
|------|-------------|
| `SLLWH.c` | Singly Linked List With Header |
| `SLLWOH.c` | Singly Linked List Without Header |
| `DLLWH.c` | Doubly Linked List With Header |
| `DLLWOH.c` | Doubly Linked List Without Header |
| `CSLLWH.c` | Circular Singly Linked List With Header |
| `CSLLWOH.c` | Circular Singly Linked List Without Header |

### Features

Each implementation includes:
- Insert at Beginning
- Insert at End
- Insert at Position
- Delete from Beginning
- Delete from End
- Delete at Position
- Display List

### How to Compile and Run

```bash
cd "Linked Lists"
gcc <filename>.c -o <output_name>
./<output_name>
```

Example:
```bash
gcc SLLWOH.c -o sll
./sll
```
