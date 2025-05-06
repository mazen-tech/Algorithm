# SortBench: A Performance Comparator for Sorting Algorithms

## 📌 Overview

**SortBench** is a C++ benchmarking tool designed to compare the execution time of popular sorting algorithms across various input sizes. The program takes a user-defined number of elements, generates a random dataset, and sorts it using multiple algorithms. It then reports the time taken by each algorithm, helping to visualize and understand their performance in practice.

---

## ⚙️ Features

- Implements five classic sorting algorithms:
  - **Bubble Sort**
  - **Bucket Sort**
  - **Quick Sort**
  - **Merge Sort**
  - **Heap Sort**
- Accepts dynamic input size from the user
- Generates random integers for sorting
- Measures execution time using C++'s `<chrono>` high-resolution clock
- Outputs a performance report to the terminal

---

## 📈 Purpose

This project was created for educational and analytical purposes to:
- Study and compare the **time complexity** of sorting algorithms
- Understand how each algorithm behaves on small, medium, and large datasets
- Learn high-precision time measurement techniques in C++

---

## 🧪 How It Works

1. The program asks the user to enter the number of elements.
2. A random vector of integers is generated.
3. Each sorting algorithm is applied to a fresh copy of the unsorted array.
4. The time taken by each algorithm is calculated and printed to the console.

---

## 🛠️ Technologies Used

- **C++17**
- Libraries: `<vector>`, `<iostream>`, `<algorithm>`, `<random>`, and `<chrono>`
- Compiled with **g++** on **Linux** (but should work cross-platform)

---

## 📊 Sample Output

# Enter the number of elements to sort: 10000

1. Bubble Sort took: 8273900 microseconds
2. Bucket Sort took: 15100 microseconds
3. Quick Sort took: 11000 microseconds
4. Merge Sort took: 13500 microseconds
5. Heap Sort took: 14200 microseconds

---

## 🚀 Usage

### Compile
```bash
g++ -std=c++17 sort_bench.cpp -o sort_bench
