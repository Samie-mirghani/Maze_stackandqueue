# Maze Solver: Stack vs Queue Pathfinding

## Overview

A C++ maze-solving application that demonstrates the behavioral differences between **depth-first search (DFS)** and **breadth-first search (BFS)** by solving the same maze using both a stack and a queue. The program reads a maze from a text file, computes solutions via both strategies, and visually renders each traversal path to the console — making it an effective tool for understanding how data structure choice fundamentally impacts search behavior.

## Key Features

- **Dual-Strategy Solver** — Solves any given maze using both stack-based (DFS) and queue-based (BFS) approaches in a single run.
- **File-Based Maze Input** — Reads maze dimensions and wall positions from a structured text file, supporting flexible maze configurations.
- **Step-by-Step Visualization** — Prints the maze state at each exploration step, allowing users to trace the algorithm's decision-making process.
- **Modular Object-Oriented Design** — Separates concerns across `Space` (cell representation) and `Maze` (grid logic and solvers) classes for clean, maintainable code.
- **Neighbor Discovery** — Dynamically identifies unvisited, traversable adjacent cells in all four cardinal directions.
- **Path Marking** — Distinguishes the final solution path from explored-but-discarded cells in the stack-based output.

## Tech Stack

| Component       | Technology     |
|-----------------|----------------|
| Language        | C++11          |
| Data Structures | `std::stack`, `std::queue`, `std::vector` |
| I/O             | `fstream`, `sstream` |
| Build System    | GNU Make       |

## System Architecture

```
maze.txt (input)
    │
    ▼
┌────────────────┐
│   Maze Parser   │  Reads dimensions & wall coordinates
└───────┬────────┘
        │
        ▼
┌────────────────┐
│   Grid (Space[][]) │  100×100 cell grid with type, visited, path flags
└───────┬────────┘
        │
   ┌────┴────┐
   ▼         ▼
┌───────┐ ┌───────┐
│ Stack │ │ Queue │
│ (DFS) │ │ (BFS) │
└───┬───┘ └───┬───┘
    │         │
    ▼         ▼
 Console output: explored cells & solution path
```

**Data Flow:**
1. The maze file is parsed to populate a 2D grid of `Space` objects, where walls are marked with `*` and open cells with ` `.
2. A starting position is set (default: row 1, column 0).
3. The **stack solver** explores depth-first, backtracking when no unvisited neighbors remain, then extracts the solution path.
4. The **queue solver** explores breadth-first, expanding outward layer by layer until the exit (rightmost column) is reached.
5. Both solutions are printed to the console with `P` marking visited/path cells.

## Maze File Format

The input file follows this structure:

```
<rows> <cols>
<wall_row> <wall_col>
<wall_row> <wall_col>
...
```

**Example** (`maze.txt`):
```
3 3
0 0
0 1
0 2
2 0
2 1
2 2
```

This defines a 3×3 grid where the top and bottom rows are entirely walled off, leaving only the middle row as a traversable corridor.

## Setup & Installation

### Prerequisites

- A C++11-compatible compiler (e.g., `g++` 4.8+)
- GNU Make

### Build & Run

```bash
# Clone the repository
git clone https://github.com/samie-mirghani/maze_stackandqueue.git
cd maze_stackandqueue

# Compile
make

# Run with a maze file
./a.out maze.txt
```

### Clean Build Artifacts

```bash
make clean
```

## Suggested GitHub Topics

`maze-solver` · `data-structures` · `depth-first-search` · `breadth-first-search` · `cpp` · `stack` · `queue` · `algorithms`

## Repository Description

> A C++ maze solver comparing stack-based DFS and queue-based BFS pathfinding strategies with step-by-step console visualization.

## License

This project is provided for educational purposes.
