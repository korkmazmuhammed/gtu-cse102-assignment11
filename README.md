# GTU CSE102 Assignment 11

This repository contains the solutions for GTU CSE102 Assignment 11.  
The assignment consists of three independent C programming tasks, each demonstrating advanced use of recursion, combinations, data structures, and dynamic memory management.

---

## Table of Contents
- [Part 1: Optimal Paths to Dispatch Center](#part-1-optimal-paths-to-dispatch-center)
- [Part 2: Hospital Location Coverage Problem](#part-2-hospital-location-coverage-problem)
- [Part 3: Deck of Cards Initialization and Shuffling](#part-3-deck-of-cards-initialization-and-shuffling)
- [How to Compile & Run](#how-to-compile--run)
- [Author](#author)

---

## Part 1: Optimal Paths to Dispatch Center

**File:** `220104004043_PART1.c`

This program computes the number of *optimal paths* from a given street and avenue to a dispatch center at coordinates (1,1) on a grid (up to 5x5).  
It uses a recursive algorithm to determine how many shortest possible paths exist from a starting point to the dispatch center, only moving left or down.

**Features:**
- Takes street and avenue input from user (range 1 to 5)
- Validates input
- Recursively computes the number of optimal paths
- Prints the result

**Algorithm Overview:**
- Base case: if at dispatch center, return 0
- If either coordinate is 1 (straight line), return 1
- Else, recursively sum number of paths from (street-1, avenue) and (street, avenue-1)

**Sample Usage:**
Enter the street number
street: 3
Enter the avenue number
avenue: 3
Number of optimal path to take back home: 6


---

## Part 2: Hospital Location Coverage Problem

**File:** `220104004043_PART2.c`

This program determines the minimum set of hospital locations needed to cover all cities in a given network.  
It uses combinatorial algorithms to try every possible location combination and checks coverage, similar to the "Set Cover Problem."

**Features:**
- User enters the maximum number of hospitals
- Program computes all combinations of locations
- Each hospital can cover a subset of cities
- Checks all combinations to find at least one that covers every city
- If successful, prints hospital locations; else, prints failure message

**Main Functions:**
- `calcCombnum(n, r)`: calculates number of combinations (n choose r)
- `fillComb`, `getCombinations`: recursively generate combinations
- `findCity`, `possibleHp`: check if combination covers all cities
- `initialHp`: output chosen hospital locations

**Sample Usage:**
Enter the maximum number of hospitals that can be constructed: 2

Yes, can offer health care to all!

Hospital - 1
Hospital locations - ABC
Hospital - 2
Hospital locations - CEF


---

## Part 3: Deck of Cards Initialization and Shuffling

**File:** `220104004043_PART3.c`

This program creates, shuffles, and displays a standard 52-card deck using structures and dynamic memory allocation.  
It demonstrates advanced use of structures, pointers, and dynamic memory in C.

**Features:**
- Allocates memory for card faces and suits
- Initializes a standard deck (`Ace`, ..., `King` x `Hearts`, `Diamonds`, `Clubs`, `Spades`)
- Shuffles the deck randomly
- Prints the shuffled deck, two cards per line
- Frees all dynamically allocated memory

**Key Functions:**
- `allocation(cards deck[])`: allocates memory for face/suit
- `initialize(cards deck[])`: sets face/suit for each card
- `shuffle(cards deck[])`: randomizes the deck order
- `decks(cards deck[])`: prints the shuffled deck
- `freeAlloc(cards deck[])`: releases memory

**Sample Output:**
Hearts of Ace Diamonds of Four
Clubs of Seven Spades of King
...



---

## How to Compile & Run

Each part is standalone and can be compiled/run separately.

**For Part 1:**
```bash
gcc 220104004043_PART1.c -o optimal_paths
./optimal_paths
**For Part 2:**
```bash
gcc 220104004043_PART2.c -o hospital_cover
./hospital_cover
**For Part 3:**
```bash
gcc 220104004043_PART3.c -o deck_shuffle
./deck_shuffle

Author
Muhammed Korkmaz
Gebze Technical University
Student ID: 220104004043
