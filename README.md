# Set data structure and set operations in C++

This is a generic implementation of a set for the string data type. It supports various operations on sets, such as union, intersection, difference, symmetric difference, and operations on elements like insertion, deletion, search, and sorting.

## Features

Set Operations:
-Union
-Intersection
-Difference
-Symmetric Difference

Element Operations:
-Insert elements into a set
-Search for an element in a set
-Remove elements from a set
-Display the set
-Sort the set

## Structure
```
set-data-structure/
├── include/
│   ├── Node.h
│   └── Set.h
├── src/
│   ├── Node.cpp
│   └── Set.cpp
├── build/
│   └── set_example.exe
├── .gitignore
├── main.cpp
└── README.md
```

## How to compile and run
```
g++ -o build/list_example main.cpp
./build/list_example
```

## How it works
1. The program starts by initializing two sets.
2. You can choose to perform operations either on the sets themselves or on individual elements.
3. The program provides an interactive menu system to guide you through various operations on the sets and their elements.
4. After completing the operations, you can either return to previous menus or exit the program.
