# Set data structure and set operations in C++

This project implements a set data structure specifically for strings in C++. It supports various operations on sets, such as union, intersection, difference, symmetric difference, and operations on elements like insertion, deletion, search, and sorting.

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
├── main.cpp
└── README.md
```

## How to compile and run
```
g++ -o build/set_example main.cpp
./build/set_example
```

## How it works
1. The program starts by initializing two sets.
2. You can choose to perform operations either on the sets themselves or on individual elements.
3. The program provides an interactive menu system to guide you through various operations on the sets and their elements.
4. After completing the operations, you can either return to previous menus or exit the program.

## Menu options
Initial Menu:
```
[1] Set Operations: Perform operations like union, intersection, and more between sets.

[2] Element Operations: Perform actions such as adding, deleting, or searching for elements within a set.

[<] Back: Return to the previous menu.

[X] Exit: Exit the program.
```
Set Operations Menu:
```
[1] Union: Perform a union of the two sets.

[2] Intersection: Find the intersection of the two sets.

[3] Difference: Find the difference between the two sets.

[4] Symmetric Difference: Find the symmetric difference between the two sets.

[<] Back: Return to the initial menu.

[X] Exit: Exit the program.
```
Element Operations Menu:
```
[1] Insert: Insert elements into the selected set.

[2] Search: Search for an element in the selected set.

[3] Delete: Remove elements from the selected set.

[4] Display: Print the selected set.

[5] Sort: Sort the selected set.

[<] Back: Return to the initial menu.

[X] Exit: Exit the program.
```
