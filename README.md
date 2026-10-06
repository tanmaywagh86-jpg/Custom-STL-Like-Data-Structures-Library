# Custom STL-Like Data Structures Library

A C++ implementation of commonly used STL-like data structures built from scratch using **templates, OOP, pointers, and dynamic memory allocation**.

The project focuses on understanding how fundamental containers work internally rather than directly relying on the C++ Standard Template Library.

## 🚀 Features

The library currently implements:

- **Vector** — Dynamic array with automatic capacity expansion
- **LinkedList** — Singly linked list with head and tail pointers
- **Stack** — LIFO data structure built using the custom Vector
- **Queue** — FIFO data structure built using the custom LinkedList
- **Performance Benchmarking** — Compares custom implementations with STL containers using `std::chrono`
- **Time Complexity Analysis** — Documents the complexity of major operations

---

## 📂 Data Structures

### 1. Custom Vector

`MyVector<T>` implements a dynamic array similar to `std::vector`.

#### Operations

- `push_back()`
- `pop_back()`
- `operator[]`
- `getSize()`
- `empty()`

#### Complexity

| Operation     | Complexity     |
| ------------- | -------------- |
| `push_back()` | O(1) amortized |
| `pop_back()`  | O(1)           |
| Access        | O(1)           |

The vector automatically increases its capacity when the current storage becomes full.

---

### 2. Custom LinkedList

`MyLinkedList<T>` implements a singly linked list using dynamically allocated nodes.

The implementation maintains both `head` and `tail` pointers.

#### Operations

- `push_front()`
- `push_back()`
- `pop_front()`
- `front()`
- `back()`
- `getSize()`
- `empty()`

#### Complexity

| Operation      | Complexity |
| -------------- | ---------- |
| `push_front()` | O(1)       |
| `push_back()`  | O(1)       |
| `pop_front()`  | O(1)       |
| Search         | O(n)       |

Maintaining a `tail` pointer allows insertion at the end in constant time.

---

### 3. Custom Stack

`MyStack<T>` provides a LIFO (Last In, First Out) interface and is implemented using the custom `MyVector<T>`.

#### Operations

- `push()`
- `pop()`
- `top()`
- `size()`
- `empty()`

#### Complexity

| Operation | Complexity     |
| --------- | -------------- |
| `push()`  | O(1) amortized |
| `pop()`   | O(1) amortized |
| `top()`   | O(1)           |

---

### 4. Custom Queue

`MyQueue<T>` provides a FIFO (First In, First Out) interface and is implemented using the custom `MyLinkedList<T>`.

#### Operations

- `push()`
- `pop()`
- `front()`
- `size()`
- `empty()`

#### Complexity

| Operation | Complexity |
| --------- | ---------- |
| `push()`  | O(1)       |
| `pop()`   | O(1)       |
| `front()` | O(1)       |

---

## 🧩 Templates

The containers use C++ templates so that the same data structure can work with different data types.

```cpp
MyVector<int> numbers;
MyVector<double> values;
MyVector<string> names;
```

This avoids writing separate implementations for every data type.

---

## 💻 Basic Usage

Example:

```cpp
MyVector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);

cout << v[1] << endl;
```

Output:

```text
20
```

Stack example:

```cpp
MyStack<int> st;

st.push(10);
st.push(20);
st.push(30);

cout << st.top() << endl;
```

Output:

```text
30
```

Queue example:

```cpp
MyQueue<int> q;

q.push(100);
q.push(200);
q.push(300);

cout << q.front() << endl;
```

Output:

```text
100
```

---

## ⚡ Performance Benchmark

The project compares the custom implementations with their STL counterparts using:

```cpp
std::chrono::high_resolution_clock
```

The benchmark performs a large number of insertion operations and measures the execution time in milliseconds.

### Comparisons

| Custom         | STL           |
| -------------- | ------------- |
| `MyVector`     | `std::vector` |
| `MyLinkedList` | `std::list`   |
| `MyStack`      | `std::stack`  |
| `MyQueue`      | `std::queue`  |

---

## 📊 Sample Output

The following is an example of an actual benchmark run:

```text
========================================
       BASIC USAGE OF CUSTOM DS
========================================

Vector: 10 20 30
LinkedList front: Tanmay
Stack top: 30
Queue front: 100

========================================
       CUSTOM vs STL PERFORMANCE
========================================

===== VECTOR COMPARISON =====
Custom Vector push_back : 3.4894 ms
STL Vector push_back    : 4.61478 ms

===== LINKED LIST COMPARISON =====
Custom LinkedList push_back : 27.6669 ms
STL List push_back          : 28.4852 ms

===== STACK COMPARISON =====
Custom Stack push : 3.76064 ms
STL Stack push    : 2.86744 ms

===== QUEUE COMPARISON =====
Custom Queue push : 28.0072 ms
STL Queue push    : 3.15986 ms

========================================
          TIME COMPLEXITY
========================================

Vector:
  push_back : O(1) amortized
  pop_back  : O(1)
  access    : O(1)

LinkedList:
  push_front : O(1)
  push_back  : O(1)
  pop_front  : O(1)
  search     : O(n)

Stack:
  push : O(1) amortized
  pop  : O(1) amortized
  top  : O(1)

Queue:
  push  : O(1)
  pop   : O(1)
  front : O(1)
```

> **Note:** Benchmark results depend on hardware, compiler, optimization settings, operating system, and system load. These measurements are intended as an experimental comparison rather than a rigorous microbenchmark.

---

## 🔍 Understanding the Benchmark

The results demonstrate an important concept:

> **Same Big-O complexity does not necessarily mean the same practical performance.**

For example, both the custom queue and STL queue provide constant-time insertion:

```text
Custom Queue → O(1)
STL Queue    → O(1)
```

However, their measured latencies are different.

The custom queue uses a linked list and dynamically allocates a new node for each element. The standard `std::queue` normally uses `std::deque` as its underlying container, which uses block-based storage.

This difference in memory allocation, cache locality, and implementation overhead can produce significantly different execution times even though both operations are **O(1)**.

Similarly, the benchmark shows that the custom Vector can sometimes be faster than the STL Vector in a particular run. This does **not** mean the custom implementation is generally faster than STL; benchmark results vary between runs and environments.

---

## 🧠 Time Complexity Summary

| Data Structure | Operation      |     Complexity |
| -------------- | -------------- | -------------: |
| Vector         | `push_back()`  | O(1) amortized |
| Vector         | `pop_back()`   |           O(1) |
| Vector         | Access         |           O(1) |
| LinkedList     | `push_front()` |           O(1) |
| LinkedList     | `push_back()`  |           O(1) |
| LinkedList     | `pop_front()`  |           O(1) |
| LinkedList     | Search         |           O(n) |
| Stack          | `push()`       | O(1) amortized |
| Stack          | `pop()`        | O(1) amortized |
| Stack          | `top()`        |           O(1) |
| Queue          | `push()`       |           O(1) |
| Queue          | `pop()`        |           O(1) |
| Queue          | `front()`      |           O(1) |

---

## 🛠️ Technologies & Concepts

### Language

- C++

### Core Concepts

- Data Structures
- Object-Oriented Programming
- C++ Templates
- Generic Programming
- Pointers
- Dynamic Memory Allocation
- Operator Overloading
- Time Complexity
- Performance Benchmarking

### Standard Libraries Used for Comparison

- `<vector>`
- `<list>`
- `<stack>`
- `<queue>`
- `<chrono>`
- `<iostream>`

---

## 📁 Project Structure

```text
Custom-STL-Like-Data-Structures/
│
├── main.cpp
├── README.md
└── .gitignore
```

The current implementation is kept in a single source file for simplicity.

A future modular structure could be:

```text
Custom-STL-Like-Data-Structures/
│
├── include/
│   ├── MyVector.h
│   ├── MyLinkedList.h
│   ├── MyStack.h
│   └── MyQueue.h
│
├── src/
│   └── main.cpp
│
├── README.md
└── .gitignore
```

---

## 🎯 Learning Objectives

The main goal of the project is to understand how commonly used containers work internally rather than treating STL containers as black boxes.

The project demonstrates:

1. How dynamic arrays grow and manage capacity.
2. How linked-list nodes are connected using pointers.
3. How stacks can be built on top of another container.
4. How queues can be built using linked lists.
5. How templates enable generic data structures.
6. How to analyze data-structure operations using Big-O notation.
7. How implementation details affect real-world performance.
8. How custom implementations compare with optimized STL implementations.

---

## 🔮 Future Improvements

Possible extensions include:

- Custom `HashMap`
- Custom iterators
- Better `const` correctness
- Copy and move semantics
- Unit testing
- Multiple benchmark trials
- More rigorous benchmarking
- Separate header/source files
- More STL-compatible APIs
- Benchmarking different underlying containers

---

## 👨‍💻 Author

**Tanmay Wagh**

B.Tech — Artificial Intelligence & Machine Learning
Walchand College of Engineering, Sangli

---

## ⭐ Project Highlights

**C++ → Templates → OOP → Data Structures → Pointers → Complexity → Benchmarking**

This project focuses on implementing fundamental data structures from scratch and experimentally comparing their behavior with standard STL containers.
