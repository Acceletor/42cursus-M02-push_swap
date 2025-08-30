# push_swap

A 42 project where the goal is to sort a stack of integers with the fewest operations possible, using only two stacks (`a` and `b`) and a limited set of instructions.  
This project is about learning sorting algorithms, complexity optimization, and working with stacks.

---

## Project Description
- Stack **a** starts filled with random integers.
- Stack **b** starts empty.
- You must sort all numbers in ascending order in **a**, using only the allowed operations:
  - `sa`, `sb`, `ss` (swap)
  - `pa`, `pb` (push)
  - `ra`, `rb`, `rr` (rotate)
  - `rra`, `rrb`, `rrr` (reverse rotate)

---

## My Approach
In my project, I chose to implement the **Turk algorithm**, which balances efficiency and simplicity.  
This method evaluates all possible moves and selects the **cheapest move** (the one requiring the fewest operations) to push elements between the stacks.  
By always choosing the most efficient move, the algorithm minimizes the total number of operations and improves overall performance.  

This project helped me deepen my understanding of:
- Stack data structures
- Cost-based decision making in algorithms
- Time complexity and optimization in C

---

## Installation & Usage
Build:
```bash
make
```

Run:
```bash
./push_swap 4 67 3 87 23
```

Example:
```
$ ./push_swap 2 1 3
sa
```
