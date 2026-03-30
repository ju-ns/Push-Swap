*This project has been created as part of the 42 curriculum by jnogueir*

# Description

Push_swap "Because Swap_push doesn’t feel as natural" 

push_swap is an algorithm-focused project that presents a conceptually simple yet highly structured challenge: sorting a set of integers using only two stacks and a limited set of allowed operations to manipulate them.

The main objective of the project is to design an algorithm capable of sorting the input values using the smallest possible number of operations, exploring efficient strategies for partitioning, movement, and reinsertion between stacks.

# Project Modules
 
## 📥 `parse`
 
Responsible for processing user input.
 
**Includes:**
- Command-line argument parsing
- Value validation
- Duplicate detection
- Safe integer conversion (using the custom `atoi_safe` function added to `libft`)
- Preparing data for stack initialization
 
---
 
## 🛠 `utils`
 
Contains helper functions primarily used by the parsing module.
 
**Includes:**
- Token validation
- Conversion utilities
- Generic helper functions
 
---
 
## 🧱 `stack`
 
Implementation of the `t_stack` Abstract Data Type (ADT), the core data structure used in the project.
 
**Includes:**
- Classic insertion and removal operations
- Helper functions for structure manipulation
 
> This module encapsulates all stack-related logic used by the sorting algorithm.
 
---
 
## 🔄 `operations`
 
Responsible for implementing the operations allowed by the project:
 
| Operation | Commands |
|-----------|----------|
| `push_op` | `pa`, `pb` |
| `reverse_rotate_op` | `rra`, `rrb`, `rrr` |
| `rotate_op` | `ra`, `rb`, `rr` |
| `swap_op` | `sa`, `sb`, `ss` |
 
> These operations represent the fundamental interface used by the sorting algorithm implemented in this project.
 
---
 
## 🧠 `sort`
 
Responsible for implementing the stack sorting logic.
 
**Includes:**
- Handling different sorting scenarios (`small sort` / `big sort`)
- Operation count optimization strategies
- Coordination between stacks `a` and `b`
 
> This module contains the core algorithmic logic of the project.


## Technical Choices
This section describes the main architectural and algorithmic decisions adopted during the development of this project.
 
---
 
## 🎯 Sorting Strategy: Turk Algorithm + Quick Select
 
The main sorting logic is based on the **Turk Algorithm**, enhanced with optimizations using **median-based partitioning** and **cost-based reinsertion**.
 
Instead of pushing elements from stack `a` to stack `b` sequentially, the algorithm uses the median as a pivot, allowing a more balanced distribution of elements between stacks and reducing the total number of operations required.
 
During the first phase of the sorting process, elements from stack `a` are moved to stack `b` according to the median value:
 
- Elements **less than or equal** to the median are pushed to `b`
- Elements **greater than** the median remain in `a`
- The process continues until only **three elements** remain in `a`
 
---
 
## ⚡ Efficient Median Selection with Quick Select
 
The median is computed using a **Quick Select-based** approach, allowing pivot selection without fully sorting the dataset.
 
This reduces the average complexity of median computation from:
 
```
O(n log n)
```
 
to:
 
```
O(n)
```
 
For larger inputs, this optimization contributes directly to reducing the overall cost of the sorting process.
 
---
 
## 🔺 Base-case Optimization (`sort_three`)
 
After the partitioning phase, only three elements remain in stack `a`.
 
These elements are sorted using a dedicated minimal-cost routine:
 
```
sort_three(a)
```
 
ensuring the smallest possible number of operations for this base case.
 
---
 
## 🎯 Cost-based Reinsertion Strategy
 
After sorting the remaining elements in stack `a`, values stored in stack `b` are reinserted using a **cost-based movement strategy**.
 
For each candidate element in `b`, the algorithm computes:
 
- Number of rotations required in stack `a`
- Number of rotations required in stack `b`
- Possibility of simultaneous rotations (`rr`, `rrr`)
- Total movement cost
 
The element with the **lowest total cost** is selected for reinsertion, reducing the global number of operations executed by the algorithm.
 
---
 
## 🧱 Data Structure Choice: Doubly Linked List
 
The `t_stack` ADT was implemented using a **doubly linked list**.
 
Reasons for this choice include:
 
- Allows rotations (`ra`, `rb`) in `O(1)` time
- Enables efficient reverse rotations (`rra`, `rrb`)
- Simplifies insertion and removal operations at the top of the stack
- Reduces traversal cost during position calculations
 
> In this project, operational efficiency was prioritized over minimal memory usage.
 
---
 
## 🧩 Stack Abstraction (`t_stack`)
 
The stack was implemented as an **Abstract Data Type (ADT)** in order to encapsulate and separate:
 
- Internal structure representation
- Basic stack manipulation operations
 
This design improves:
 
- Low coupling between modules
- Maintainability and extensibility of the codebase
- Code readability
- Reusability of the data structure
 
> Additionally, the operations `push`, `swap`, and `rotate` were intentionally kept independent from the sorting logic, improving modularity and separation of concerns within the implementation.

# Instructions

---

## 📦 Compilation

Compile the project using:

```bash
make
```

This will generate the executable:

```
push_swap
```

---

## ▶️ Execution

Run the program by providing a sequence of integers as arguments:

```bash
./push_swap 4 2 3 1
```

Expected output:

```
pb
ra
sa
pa
```

Each line represents an operation performed to sort the stack.

---

## 📥 Supported Input Formats

The program accepts multiple arguments separated by spaces:

```bash
./push_swap 5 1 4 3 2
```

or as a quoted string:

```bash
./push_swap "5 1 4 2 3"
```

---

## 🧪 Testing with the `checker`

It is possible to validate the result using the project's `checker`:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker $ARG
```

Expected output:

```
OK
```

---

## 🎲 Testing with Random Input

You can generate random input values using:

```bash
ARG=$(shuf -i 1-100 -n 10)
./push_swap $ARG
```

To validate automatically:

```bash
ARG=$(shuf -i 1-100 -n 10)
./push_swap $ARG | ./checker $ARG
```

# Resources

During the development of this project, several study materials were used to support the understanding of sorting algorithms, partitioning strategies, and stack-based movement optimization techniques.

- Turk Algorithm article — https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0
- push_swap article - https://42-cursus.gitbook.io/guide/2-rank-02/push_swap
- tad article - http://www.decom.ufop.br/anascimento/site_media/uploads/bcc202/aula_03_-_tipo_abstrato_de_dados.pdf

Generative AI tools were used **exclusively as a research support resource**, particularly for consulting conceptual topics such as:
 
- Sorting algorithms
- Partitioning strategies







