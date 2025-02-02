# push_swap

push_swap, a 1337 project.

Welcome to my **Push Swap** project! This project was one of the most challenging and rewarding experiences in my coding journey. It pushed me to think critically about algorithms, optimization, and problem-solving. Below, I’ll walk you through my journey, the challenges I faced, and how I overcame them.

---

## Table of Contents
1. [What is Push Swap?](#what-is-push-swap)
2. [My Journey](#my-journey)
   - [The Beginning](#the-beginning)
   - [The Challenges](#the-challenges)
   - [The Breakthrough](#the-breakthrough)
3. [How It Works](#how-it-works)
   - [Algorithm](#algorithm)
   - [Optimization](#optimization)
4. [Tester](#a push_swap tester I made)
   - [Installation]
6. [Future Improvements](#future-improvements)

---

## What is Push Swap?

**Push Swap** is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations. You’re given two stacks, **Stack A** and **Stack B**, and a set of operations like `push`, `swap`, and `rotate`. The challenge is to sort the numbers in **Stack A** in ascending order using the fewest number of operations.

---

## My Journey

### The Beginning
When I first started the Push Swap project, I was excited but also a bit overwhelmed. The idea of sorting numbers with such limited operations seemed simple at first, but I quickly realized how complex it could get, especially with larger stacks (e.g., 100 or 500 numbers).

### The Challenges
1. **Understanding the Problem**:
   - I spent a lot of time understanding the rules and constraints of the project. The limited set of operations made it tricky to implement traditional sorting algorithms.

2. **Choosing the Right Algorithm**:
   - I experimented with simple algorithms like **Bubble Sort** and **Insertion Sort**, but they were too inefficient for larger stacks.
   - I then tried **Radix Sort**, which seemed promising, but implementing it with linked lists and stack operations was a challenge.

3. **Optimizing the Number of Moves**:
   - The real challenge was optimizing the algorithm to sort 500 numbers in fewer than 5500 moves. My initial implementations were taking way too many moves, and I had to rethink my approach.

### The Breakthrough
After countless hours of debugging and testing, I finally found a solution that worked:
- I implemented a simple sorting algo using linked lists.
- I optimized the algorithm by spliting the numbers in ranges and pushed starting from the smallest ranges to the end in stack B then puashed them back to a from the biggest number to the end.
- I added checks to avoid redundant operations, and used rrr and ss as much as possible, and ensure the stack was sorted efficiently.

---
## Tester
1. **Installation**
 - You can clone the repo and use it with ```git clone https://github.com/your-username/push_swap.git``` ```chmod +x push ; push -h```
 - Or use this command ```curl -o https://raw.githubusercontent.com/zakaria-didah/push_swap/refs/heads/main/script.sh ; chmod +x push ; push -h```

## Future Improvements
 - Ading valgrind to the tester.
 - Adding a detach option to run it in the background.
 - Test for the bonus part.

