# Splay Trees and Zip Trees

This project provides implementations of Splay Trees and Zip Trees in C++. It includes multiple tests to ensure the integrity of the data structures.

## How to Run and Test
To run the code and execute tests, go to `main.cpp`. You will find comments describing different operations:

1. **Insertion:** For insertion you will find a comment describing the insertion type and uncomment the code below it and run the code, it will test insertion for both trees given the insertion type and print out the time.
2. **Search and Deletion:** For Deletion and Searching follow the same steps for insertion.

## Structural Integrity
Both `ZipTree.cpp` and `SplayTree.cpp` include an `IsValid()` function. These functions verify that the resulting trees adhere to the specific rules of their data structure:
* **Splay Trees:** Ensures binary search tree properties are maintained after splaying.
* **Zip Trees:** Validates the treap-based structure and randomized ranks.

The `IsValid()` functions are automatically called within `splayTests()` and `zipTests()` in `main.cpp` to check the integrity of the structures after operations.
