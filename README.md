# Push Swap

A fast sorting algorithm implementation using two stacks with a limited set of operations.

## Overview

**Push Swap** is a sorting algorithm project that sorts a random list of integers using two stacks (A and B) and a restricted set of operations. The goal is to sort all integers in ascending order using the least number of operations possible.

This is a comprehensive implementation featuring:
- **Case-by-case sorting** for 0-3 elements with optimal patterns
- **Smart sort algorithm** for 4+ elements
- **Bonus checker** program to verify sorting solutions
- **Optimized operations** with minimal move count

## Problem Statement

Given a list of random integers, you must sort them using:
- **Stack A**: Contains the integers to sort
- **Stack B**: Helper stack (initially empty)
- **Limited operations**: Only `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`

The challenge is to sort stack A in ascending order while minimizing the total number of operations.

## Project Structure

```
push_swap/
├── INSTRUCTIONS/        # Core stack operations
│   ├── swap.c          # Swap elements (sa, sb, ss)
│   ├── push.c          # Push operations (pa, pb)
│   ├── rotate.c        # Rotate operations (ra, rb, rr)
│   └── reverse.c       # Reverse rotate operations (rra, rrb, rrr)
├── SOLVE/              # Main sorting algorithms
│   ├── push_swap.c     # Entry point and main logic
│   ├── radix.c         # Radix sort implementation
│   ├── smart_sort.c    # Optimized sort for small lists
│   └── utils_solve*.c  # Helper functions
├── UTILS/              # Utility functions
│   ├── parsing.c       # Input parsing and validation
│   ├── split.c         # String splitting utility
│   ├── sort_index.c    # Index sorting helper
│   └── utils*.c        # General utilities
├── BONUS/              # Bonus checker program
│   ├── checker.c       # Verifies sorting solution
│   └── get_next_line.c # Line reading utility
├── INCLUDES/           # Header files
│   └── push_swap.h     # Main header
├── Makefile            # Build configuration
└── README.md           # This file
```

## Features

### Core Algorithms
- **Case-by-Case Sorting (0-3 elements)**: Optimal patterns with minimal operations
- **Smart Sort (4+ elements)**: Intelligent sorting algorithm with adaptive strategies
- **Efficient Operation Handling**: Minimizes stack operations for faster execution

### Available Operations
| Operation | Effect |
|-----------|--------|
| `sa` | Swap first two elements of stack A |
| `sb` | Swap first two elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push top element from stack B to stack A |
| `pb` | Push top element from stack A to stack B |
| `ra` | Rotate stack A (first → last) |
| `rb` | Rotate stack B (first → last) |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last → first) |
| `rrb` | Reverse rotate stack B (last → first) |
| `rrr` | Execute `rra` and `rrb` simultaneously |

### Bonus Features
- **Checker Program**: Validates if a sequence of operations correctly sorts the input
- **Error Handling**: Robust input validation and error reporting

## Compilation

### Requirements
- `gcc` (GCC compiler)
- `make` (Build automation tool)
- POSIX-compliant system (macOS, Linux)

### Build Commands

**Compile the main program:**
```bash
make
```

**Compile with bonus (checker program):**
```bash
make bonus
```

**Clean object files:**
```bash
make clean
```

**Remove all build artifacts:**
```bash
make fclean
```

**Rebuild from scratch:**
```bash
make re
```

## Usage

### Push Swap Program

Sort a list of integers:
```bash
./push_swap 3 1 4 1 5 9 2 6
```

The program outputs a sequence of operations (one per line) to sort the stack.

**Input:**
- Space-separated integers
- Duplicates allowed
- Negative numbers supported

**Output:**
- One operation per line
- Empty output if input is already sorted

### Checker Program (Bonus)

Verify if a sequence of operations correctly sorts the input:
```bash
./push_swap 3 1 4 1 5 9 2 6 | ./checker 3 1 4 1 5 9 2 6
```

**Output:**
- `OK` if operations correctly sort the stack
- `KO` if operations fail to sort the stack
- Error message if invalid input or operations

## Algorithm Details

### Case-by-Case Strategy (0-3 elements)
For very small datasets, each case is handled individually:
- **0 elements**: Already sorted
- **1 element**: Already sorted
- **2 elements**: Single swap if needed (`sa`)
- **3 elements**: Optimized patterns with 0-2 operations

This approach guarantees the minimum number of operations for small lists.

### Smart Sort Strategy (4+ elements)
An intelligent sorting algorithm that:
- Analyzes the input data structure
- Chooses optimal movement patterns
- Minimizes total operations through strategic stack manipulation
- Adapts to different input distributions

**Time Complexity**: Optimized for typical cases
**Space Complexity**: O(n)

## Examples

### Example 1: Sort 3 elements
```bash
$ ./push_swap 3 1 2
sa
```

### Example 2: Sort 5 elements
```bash
$ ./push_swap 2 1 3 5 4
pb
ra
pb
ra
pa
pa
```

### Example 3: Verify with checker
```bash
$ ./push_swap 5 1 3 2 4 | ./checker 5 1 3 2 4
OK
```

## Performance Considerations

- **0-3 elements**: Case-by-case optimization with minimal operations
- **4+ elements**: Smart sort algorithm for efficient handling
- **Small to medium lists**: Optimized performance

Typical operation counts:
- 3 elements: 0-2 operations
- 5 elements: ~3-5 operations
- Large lists: Efficient smart sort handling
