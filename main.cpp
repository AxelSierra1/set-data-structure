#include <iostream>
#include <limits>
#include <cmath>
#include <conio.h>
#include "src/Set.cpp"

using namespace std;

void initialization();                      // (First menu)
void initial_menu(Set*, Set*);              // (resulting from initialization)
void set_operations_menu(Set*, Set*);       // (resulting from initial_menu)
void final_set_menu(Set*, Set*);            // (resulting from set_operations_menu)
void element_operations_menu(Set*, Set*);   // (resulting from initial_menu)
void element_operations_menu_1(Set*, Set*); // (resulting from element_operations_menu)
void element_operations_menu_2(Set*, Set*); // (resulting from element_operations_menu)
void final_element_menu_1(Set*, Set*);      // (resulting from element_operations_menu_1)
void final_element_menu_2(Set*, Set*);      // (resulting from element_operations_menu_2)

void add_element(Set* set) {
    string element;
    cin >> element;
    set->insert(element);
}

void remove_element(Set* set) {
    string element;
    cin >> element;
    set->remove(element);
}

void initialization() {
    double card1;  // cardinality of the first set
    double card2;  // cardinality of the second set
    Set* set1 = new Set();
    Set* set2 = new Set();

    cout << "======================================================================================\n";
    cout << "                                    Initialization\n";
    cout << "======================================================================================\n";
    while (cout << "Enter the cardinality (size) of the first set:\n" && (!(cin >> card1) || card1 < 0 || fmod(card1, 1) != 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid value (you must enter a positive integer)\n\n";
        cout << "\nPress any key to continue...\n";
        getch();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (card1 == 0) {
        for (int i = 0; i < card1; i++) {
            add_element(set1);
        }
    } else {
        cout << "\nEnter the elements of the first set:\n";
        cout << "(The elements must be words)\n";
        for (int i = 0; i < card1; i++) {
            add_element(set1);
        }
    }

    cout << "\nFirst set entered: ";
    set1->print();
    cout << "\n";
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

    while (cout << "Enter the cardinality (size) of the second set:\n" && (!(cin >> card2) || card2 < 0 || fmod(card2, 1) != 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid value (you must enter a positive integer)\n\n";
        cout << "\nPress any key to continue...\n";
        getch();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (card2 == 0) {
        for (int i = 0; i < card2; i++) {
            add_element(set2);
        }
    } else {
        cout << "\nEnter the elements of the second set:\n";
        cout << "(The elements must be words)\n";
        for (int i = 0; i < card2; i++) {
            add_element(set2);
        }
    }

    cout << "\nSecond set entered: ";
    set2->print();
    cout << "\n";
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";

    initial_menu(set1, set2);
}

void initial_menu(Set* set1, Set* set2) {
    char menu;
    cout << "\n\n\n\n\n......................................................................................\n";
    cout << " Initialization -> Types of operations\n";
    cout << "......................................................................................\n";
    cout << "======================================================================================\n";
    cout << "                           Select the type of operation\n";
    cout << "======================================================================================\n";
    cout << "[1] Set operations:\n";
    cout << "[2] Element operations:\n";
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
    case '1':
        set_operations_menu(set1, set2);
        break;
    case '2':
        element_operations_menu(set1, set2);
        break;
    case 'X':
        break;
    case '<':
        cout << "\nYou are going back to the set creation menu...\n\n";
        cout << "\nPress any key to continue...\n";
        getch();
        initialization();
        break;
    default:
        cout << "\nPlease enter a valid value...\n";
        cout << "\nPress any key to continue...\n";
        getch();
        initial_menu(set1, set2);
        break;
    }
}

void set_operations_menu(Set* set1, Set* set2) {
    char menu;
    cout << "\n\n\n\n\n\n\n......................................................................................\n";
    cout << " Initialization -> Types of operations -> Operation selection\n";
    cout << "......................................................................................\n";
    cout << "======================================================================================\n";
    cout << "                Enter the corresponding key for the appropriate option\n";
    cout << "======================================================================================\n";
    cout << "[1] Union\n";
    cout << "[2] Intersection\n";
    cout << "[3] Difference\n";
    cout << "[4] Symmetric difference\n";
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
    case '1':
        cout << "\nThe union between the sets is:\n";
        set1->union_(set2)->print();
        cout << "\n\n";
        final_set_menu(set1, set2);
        break;
    case '2':
        cout << "\nThe intersection between the sets is:\n";
        set1->intersection(set2)->print();
        cout << "\n\n";
        final_set_menu(set1, set2);
        break;
    case '3':
        cout << "\nThe difference between the sets is:\n";
        set1->difference(set2)->print();
        cout << "\n\n";
        final_set_menu(set1, set2);
        break;                                            
    case '4':
        cout << "\nThe symmetric difference between the sets is:\n";
        set1->symmetric_difference(set2)->print();
        cout << "\n\n";
        final_set_menu(set1, set2);
        break;
    case 'X':
        break;
    case '<':
        initial_menu(set1, set2);
        break;
    default:
        cout << "\nPlease enter a valid value...\n";
        cout << "\nPress any key to continue...\n";
        getch();
        set_operations_menu(set1, set2);
        break;
    }
}

void final_set_menu(Set* set1, Set* set2) {
    char menu;
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
        case 'X':
            break;
        case '<':
            set_operations_menu(set1, set2);
            break;
        default:
            cout << "\nPlease enter a valid value...\n";
            final_set_menu(set1, set2);
            break;
    }
}

void element_operations_menu(Set* set1, Set* set2) {
    char menu;
    char set_selection;

    cout << "\n\n\n\n\n\n\n......................................................................................\n";
    cout << " Initialization -> Types of operations -> Set selection\n";
    cout << "......................................................................................\n";
    cout << "======================================================================================\n";
    cout << "                     Select the set to operate on";
    cout << "\n First set: ";
    set1->print();
    cout << "\n Second set: ";
    set2->print();
    cout << "\n";
    cout << "======================================================================================\n";
    cout << "[1] First set\n";
    cout << "[2] Second set\n";
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> set_selection;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (set_selection) {
    case '1':
        element_operations_menu_1(set1, set2);
        break;
    case '2':
        element_operations_menu_2(set1, set2);
        break;
    case 'X':
        break;
    case '<':
        initial_menu(set1, set2);
        break;
    default:
        cout << "\nPlease enter a valid value...\n";
        cout << "\nPress any key to continue...\n";
        getch();
        element_operations_menu(set1, set2);
        break;
    }
}

void element_operations_menu_1(Set* set1, Set* set2) {
    char menu;
    double quantity;
    string element;

    cout << "\n\n\n\n\n\n\n......................................................................................\n";
    cout << " Initialization -> Types of operations -> Set selection -> Operation selection\n";
    cout << "......................................................................................\n";
    cout << "======================================================================================\n";
    cout << "                               Select an operation\n";
    cout << "======================================================================================\n";
    cout << "[1] Insert\n";
    cout << "[2] Search\n";
    cout << "[3] Delete\n";
    cout << "[4] Display set (print)\n";
    cout << "[5] Sort\n";
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
    case '1':
        cout << "\nEnter the number of elements to insert into the set:\n";
        cout << "(Set 1 = ";
        set1->print();
        cout << ")";

        while (cout << "\n" && (!(cin >> quantity) || quantity < 0 || fmod(quantity, 1) != 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value. Please try again (enter a positive integer)\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (quantity == 0) {
            cout << "\nNo elements were added\n\n";
        } else {
            cout << "Enter the elements:\n";
            for (int i = 0; i < quantity; i++) {
                add_element(set1);
            }
            cout << "\nElements added successfully\n\n";
        }
        final_element_menu_1(set1, set2);
        break;
    case '2':
        cout << "\nEnter the element to search for:\n";
        cin >> element;
        if (set1->search(element) == NULL) {
            cout << "\nThe element is not part of the set\n\n";
        } else {
            cout << "\nThe element is part of the set\n\n";
        }
        final_element_menu_1(set1, set2);
        break;
    case '3':
        cout << "\nEnter the number of elements to delete from the set:\n";
        cout << "(Set 1 = ";
        set1->print();
        cout << ")";

        while (cout << "\n" && (!(cin >> quantity) || quantity < 0 || fmod(quantity, 1) != 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value. Please try again (enter a positive integer)\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (quantity == 0) {
            cout << "\nNo elements were deleted\n\n";
        } else {
            cout << "Enter the elements:\n";
            for (int i = 0; i < quantity; i++) {
                remove_element(set1);
            }
            cout << "\nElements deleted successfully\n\n";
        }
        final_element_menu_1(set1, set2);
        break;
    case '4':
        cout << "\nSet 1: ";
        set1->print();
        cout << "\n";
        final_element_menu_1(set1, set2);
        break;
    case '5':
        cout << "\nSorted set: ";
        set1->sort();
        set1->print();
        cout << "\n";
        final_element_menu_1(set1, set2);
        break;
    case 'X':
        break;
    case '<':
        element_operations_menu(set1, set2);
        break;
    default:
        cout << "\nPlease enter a valid value...\n";
        cout << "\nPress any key to continue...\n";
        getch();
        element_operations_menu_1(set1, set2);
        break;
    }
}
void element_operations_menu_2(Set* set1, Set* set2) {
    char menu;
    double quantity;
    string element;

    cout << "\n\n\n\n\n\n\n......................................................................................\n";
    cout << " Initialization -> Types of operations -> Set selection -> Operation selection\n";
    cout << "......................................................................................\n";
    cout << "======================================================================================\n";
    cout << "                               Select an operation\n";
    cout << "======================================================================================\n";
    cout << "[1] Insert\n";
    cout << "[2] Search\n";
    cout << "[3] Delete\n";
    cout << "[4] Display set (print)\n";
    cout << "[5] Sort\n";
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
    case '1':
        cout << "\nEnter the number of elements to insert into the set:\n";
        cout << "(Set 2 = ";
        set2->print();
        cout << ")";

        while (cout << "\n" && (!(cin >> quantity) || quantity < 0 || fmod(quantity, 1) != 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value. Please try again (enter a positive integer)\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (quantity == 0) {
            cout << "\nNo elements were added\n\n";
        } else {
            cout << "Enter the elements:\n";
            for (int i = 0; i < quantity; i++) {
                add_element(set2);
            }
            cout << "\nElements added successfully\n\n";
        }
        final_element_menu_2(set1, set2);
        break;
    case '2':
        cout << "\nEnter the element to search for:\n";
        cin >> element;
        if (set2->search(element) == NULL) {
            cout << "\nThe element is not part of the set\n\n";
        } else {
            cout << "\nThe element is part of the set\n\n";
        }
        final_element_menu_2(set1, set2);
        break;
    case '3':
        cout << "\nEnter the number of elements to delete from the set:\n";
        cout << "(Set 2 = ";
        set2->print();
        cout << ")";

        while (cout << "\n" && (!(cin >> quantity) || quantity < 0 || fmod(quantity, 1) != 0)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid value. Please try again (enter a positive integer)\n";
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (quantity == 0) {
            cout << "\nNo elements were deleted\n\n";
        } else {
            cout << "Enter the elements:\n";
            for (int i = 0; i < quantity; i++) {
                remove_element(set2);
            }
            cout << "\nElements deleted successfully\n\n";
        }
        final_element_menu_2(set1, set2);
        break;
    case '4':
        cout << "\nSet 2: ";
        set2->print();
        cout << "\n\n";
        final_element_menu_2(set1, set2);
        break;
    case '5':
        cout << "\nSorted set: ";
        set2->sort();
        set2->print();
        cout << "\n\n";
        final_element_menu_2(set1, set2);
        break;
    case 'X':
        break;
    case '<':
        element_operations_menu(set1, set2);
        break;
    default:
        cout << "\nPlease enter a valid value...\n";
        cout << "\nPress any key to continue...\n";
        getch();
        element_operations_menu_2(set1, set2);
        break;
    }
}

void final_element_menu_1(Set* set1, Set* set2) {
    char menu;
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
        case 'X':
            break;
        case '<':
            element_operations_menu_1(set1, set2);
            break;
        default:
            cout << "\nPlease enter a valid value...\n";
            final_element_menu_1(set1, set2);
            break;
    }
}

void final_element_menu_2(Set* set1, Set* set2) {
    char menu;
    cout << "[<] Go back\n";
    cout << "[X] Exit\n";
    cin >> menu;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (menu) {
        case 'X':
            break;
        case '<':
            element_operations_menu_2(set1, set2);
            break;
        default:
            cout << "\nPlease enter a valid value...\n";
            final_element_menu_2(set1, set2);
            break;
    }
}

int main() {
    initialization();
    cout << "\nProgram successfully completed.\n\n";
    return 0;
}