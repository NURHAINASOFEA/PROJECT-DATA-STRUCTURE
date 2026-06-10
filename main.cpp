#include <iostream>
#include <cstdlib> // Required for system("cls")
#include "Book.h"

using namespace std;

int main() {
    Book catalog[MAX_CAPACITY] = {
        {101, "C++ Programming", "John Doe"},
        {102, "Data Structures", "Alice Smith"},
        {103, "Networking Basics", "Bob Wilson"},
        {104, "Operating Systems", "Charlie Brown"}
    };
    
    int currentSize = 4; 
    int choice;

    do {
        // Clear screen before showing the main menu
        system("cls"); 
        
        cout << "\n====================================" << endl;
        cout << "    CRUD BOOK CATALOG SYSTEM        " << endl;
        cout << "====================================" << endl;
        cout << "1. [Read]   Display All Books" << endl;
        cout << "2. [Create] Add New Book" << endl;
        cout << "3. [Update] Edit Book Details" << endl;
        cout << "4. [Delete] Remove a Book" << endl;
        cout << "5. [Sort]   Sort Books by Title (A-Z)" << endl;
        cout << "6. [Search] Search Book by ID" << endl;
        cout << "7. Exit" << endl;
        cout << "====================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear screen again after user types their choice so the sub-menu starts fresh
        system("cls"); 

        switch (choice) {
            case 1: displayCatalog(catalog, currentSize); break;
            case 2: addBook(catalog, currentSize); break;
            case 3: updateBook(catalog, currentSize); break;
            case 4: deleteBook(catalog, currentSize); break;
            case 5: sortByTitle(catalog, currentSize); break;
            case 6: searchByID(catalog, currentSize); break;
            case 7: cout << "\nExiting program. Goodbye!" << endl; break;
            default: 
                cout << "\nInvalid choice! Press Enter to try again.";
                cin.ignore();
                cin.get();
        }
    } while (choice != 7);

    return 0;
}