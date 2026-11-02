# Data Structures & Algorithms in C 🚀

A comprehensive, curated repository of fundamental Data Structures and Algorithms implemented in C. This collection covers theoretical concepts, lab exercises, and assignment solutions developed throughout the university coursework.

All source implementations preserve original in-line commentary, step-by-step notes, edge-case checks, and problem analyses.

---

## 📂 Repository Structure

The implementations are structured by domain into 7 core modules, accompanied by the master assignment log in the root directory:

```
├── dsa_assignments.c                  # Master assignment syllabus, prompts, and timeline log
├── 01-linked-lists/                   # Singly, Doubly, Circular Linked Lists, and Applications
├── 02-stacks-and-expressions/         # Stack implementations, Infix/Postfix/Prefix, and Parsing
├── 03-queues/                         # Linear, Circular, Linked-list, and Priority Queues
├── 04-trees-and-binary-search-trees/  # BSTs, Threaded Binary Trees, Expression Trees, and Traversals
├── 05-heaps-and-priority-queues/      # Min/Max Heaps, Heap Sorts (Ascending/Descending), and PQ
├── 06-hashing-and-tries/              # Linear/Quadratic Probing, Chaining, Rehashing, and Trie
└── 07-graphs/                         # Graph Representations (Matrix/List) with BFS and DFS
```

---

## 📚 Curriculum Breakdown & File Index

### 01. Linked Lists (`01-linked-lists/`)
* **`dsa_singlelinkedlist.c`**: Singly Linked List operations (front/rear insert, delete, display).
* **`dsa_doublelinkedlist.c`**: Doubly Linked List bidirectional traversals and node manipulation.
* **`circularsinglylinkedlist.c`**: Circular Singly Linked List (ordered insert, positional insert/delete).
* **`circulardoublylinkedlist.c`**: Circular Doubly Linked List with bidirectional wrapping.
* **`posins_posdel_doublylinkedlist.c`**: Positional insertion and deletion in a doubly linked list.
* **`predecessor_node_ins_del.c`**: Insertion and deletion relative to predecessor nodes.
* **`search_and_del_singlylinkedlist.c`**: Key searching and target node deletion in singly linked lists.
* **`search_and_del_doublylinkedlist.c`**: Key searching and target node deletion in doubly linked lists.
* **`sum_of_list_singlylinkedlist.c`**: Aggregation algorithms (sum of all nodes, sum at even vs. odd indices).
* **`josephus.c`**: Classic Josephus Problem simulation using circular linked structures.

### 02. Stacks & Expression Parsing (`02-stacks-and-expressions/`)
* **`stackusingarray.c`**: Fixed-size stack implementation with bounds checking (`push`, `pop`, `peek`).
* **`stackusinglinkedlist.c`**: Dynamic stack implementation using singly linked list headers.
* **`isstackfull_isstackempty.c`**: State evaluation functions for bounded stacks.
* **`parenthesis_matching.c`**: Balanced parenthesis verification using stack discipline.
* **`infixtopostfix_full_parenthesised.c`**: Fully parenthesized infix-to-postfix expression converter.
* **`infixtopostfix_partial_parenthesised.c`**: Operator precedence and associativity-driven infix-to-postfix converter.
* **`infixtopostfix_conversion_evaluation.c`**: Combined pipeline converting infix to postfix and evaluating numeric operands.
* **`infixtoprefix_conversion.c`**: Infix-to-prefix conversion utilizing reversed traversal and operator switching.
* **`postfix_evaluation.c`**: Postfix (Reverse Polish Notation) arithmetic evaluator.

### 03. Queues (`03-queues/`)
* **`Queueusingarray.c`**: Array-backed FIFO queue with front and rear pointers.
* **`queueusinglinkedlist.c`**: Dynamic FIFO queue backed by linked list nodes.
* **`circular_queue.c`**: Modular arithmetic circular queue eliminating false overflow conditions.
* **`priorityqueue.c`**: Priority-based queue ordering elements by defined significance.

### 04. Trees & Binary Search Trees (`04-trees-and-binary-search-trees/`)
* **`binarysearchtree_usingarray.c`**: Sequential index-mapped representation of a binary search tree.
* **`binarysearchtree_usinglinkedlist.c`**: Dynamic pointer-based Binary Search Tree with search, insertion, and recursive traversals.
* **`binarysearchtree_usinglinkedlist_no_duplicates.c`**: Strict BST implementation rejecting duplicate keys.
* **`Expression tree.c`**: Expression tree construction from postfix expressions and tree-based evaluation.
* **`iterative_inorder_tree_traversal.c`**: Non-recursive Inorder traversal (LNR) utilizing an explicit stack.
* **`iterative_preorder_tree_traversal.c`**: Non-recursive Preorder traversal (NLR) utilizing an explicit stack.
* **`iterative_postorder_tree_traversal.c`**: Non-recursive Postorder traversal (LRN) using dual-stack / state-tracking algorithms.
* **`inthreaded binary tree.c`**: In-order Threaded Binary Tree making efficient use of null pointers.
* **`leftthreaded_bst.c`**: Left-threaded BST where left null pointers link to in-order predecessors.
* **`rightthreaded_bst.c`**: Right-threaded BST where right null pointers link to in-order successors.

### 05. Heaps & Priority Queues (`05-heaps-and-priority-queues/`)
* **`maxheapascending.c`**: Max-Heap construction and Heap Sort arranging elements in ascending order.
* **`maxheapdescending.c`**: Max-Heap implementation sorting elements in descending order.
* **`minheapascending.c`**: Min-Heap construction and sorting in ascending order.
* **`minheapdescending.c`**: Min-Heap implementation sorting elements in descending order.
* **`priorityqueueusingheap.c`**: Priority Queue built on binary heap abstractions for $O(\log n)$ operations.

### 06. Hashing & Prefix Trees (`06-hashing-and-tries/`)
* **`hashlp.c`**: Open Addressing hash table using Linear Probing for collision resolution.
* **`hashqp.c`**: Open Addressing hash table using Quadratic Probing to reduce primary clustering.
* **`Seperate_Chining_Hash.c`**: Closed Addressing (Separate Chaining) hash table utilizing linked bucket chains.
* **`rehash.c`**: Dynamic table resizing and rehashing based on load factor thresholds.
* **`trie.c`**: 26-way prefix tree (Trie) for efficient dictionary storage, prefix lookup, and word search.

### 07. Graphs (`07-graphs/`)
* **`adjacency matrix bfs.c`**: Breadth-First Search (BFS) graph traversal using an Adjacency Matrix and queue.
* **`adjacency matrix graphs dfs.c`**: Depth-First Search (DFS) graph traversal using an Adjacency Matrix.
* **`adjacency list bfs.c`**: Breadth-First Search on an Adjacency List representation.
* **`adjacency list dfs.c`**: Depth-First Search on an Adjacency List representation.

---

## 🛠️ Compilation & Execution

All source files are standalone, self-contained C programs that can be compiled with standard C compilers (`gcc` or `clang`).

### Compile any file:
```bash
gcc 01-linked-lists/dsa_singlelinkedlist.c -o single_linked_list
./single_linked_list
```

### Windows (MinGW / GCC):
```cmd
gcc "04-trees-and-binary-search-trees\binarysearchtree_usinglinkedlist.c" -o bst.exe
bst.exe
```

---

## 🍽️ Capstone Coursework Project: DineTrack
The major course project applying these data structures is hosted in its dedicated repository:
* [DineTrack Restaurant Management System](https://github.com/Tanmayi-n14/dinetrack-restaurant-management-DSA) — Modular C implementation integrating Queues for orders, Stacks for billing actions, Linked Lists for dynamic menus, and Hash tables for fast item lookup.

---

## 📝 Coursework Notes & Diary
The root file [`dsa_assignments.c`](dsa_assignments.c) contains the original chronological assignment log, submission checkpoints, and topic instructions recorded throughout the semester.
