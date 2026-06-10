#include <iostream>
#include <iomanip>
#include <cstdlib> // Required for system("cls")
#include "Book.h"

using namespace std;

// helper function to handle the "Press 0 to go back" loop prompt
void waitForBackSignal() {
    int backChoice;
    do {
        cout << "\n------------------------------------" << endl;
        cout << "Enter 0 to go back to Main Menu: ";
        cin >> backChoice;
    } while (backChoice != 0);
}

// 1. READ
void displayCatalog(Book arr[], int size) {
    if (size == 0) {
        cout << "\n[Notification] Catalog is completely empty." << endl;
    } else {
        cout << "\n--- Current Book Catalog ---" << endl;
        cout << left << setw(10) << "Book ID" << setw(25) << "Book Title" << "Author" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (int i = 0; i < size; i++) {
            cout << left << setw(10) << arr[i].id 
                 << setw(25) << arr[i].title 
                 << arr[i].author << endl;
        }
    }
    waitForBackSignal(); // Hold screen until user presses 0
}

// 2. CREATE
void addBook(Book arr[], int &size) {
    if (size >= MAX_CAPACITY) {
        cout << "\n[Error] Catalog is full! Cannot add more books." << endl;
        waitForBackSignal();
        return;
    }

    Book newBook;
    int highestID = 100; 
    for (int i = 0; i < size; i++) {
        if (arr[i].id > highestID) highestID = arr[i].id;
    }
    newBook.id = highestID + 1; 

    cin.ignore(); 
    cout << "\n--- ADD NEW BOOK ---" << endl;
    cout << "[System] Generated Book ID: " << newBook.id << endl;
    cout << "Enter Book Title: ";
    getline(cin, newBook.title);
    cout << "Enter Author Name: ";
    getline(cin, newBook.author);

    arr[size] = newBook; 
    size++;              
    cout << "\n[Success] Book \"" << newBook.title << "\" added successfully!" << endl;
    
    waitForBackSignal();
}

// 3. UPDATE
void updateBook(Book arr[], int size) {
    while (true) {
        system("cls"); // Keep view clean if they make multiple updates
        if (size == 0) {
            cout << "\n[Error] No books available to update." << endl;
            waitForBackSignal();
            return;
        }

        // Display current catalog snippet cleanly
        cout << "\n--- Current Book Catalog ---" << endl;
        cout << left << setw(10) << "Book ID" << setw(25) << "Book Title" << "Author" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (int i = 0; i < size; i++) {
            cout << left << setw(10) << arr[i].id << setw(25) << arr[i].title << arr[i].author << endl;
        }

        int targetID;
        cout << "\nEnter the Book ID to update (or enter 0 to go back): ";
        cin >> targetID;

        if (targetID == 0) return; // Instantly breaks out back to main menu

        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].id == targetID) {
                cout << "\n[Book Found] Current details: \"" << arr[i].title << "\" by " << arr[i].author << endl;
                cin.ignore();
                cout << "Enter New Title: ";
                getline(cin, arr[i].title);
                cout << "Enter New Author: ";
                getline(cin, arr[i].author);
                cout << "\n[Success] Details updated successfully!" << endl;
                found = true;
                waitForBackSignal();
                return; 
            }
        }
        if (!found) {
            cout << "\n[Error] Book ID " << targetID << " not found. Press Enter to retry.";
            cin.ignore(); cin.get();
        }
    }
}

// 4. DELETE
void deleteBook(Book arr[], int &size) {
    while (true) {
        system("cls");
        if (size == 0) {
            cout << "\n[Error] No books available to delete." << endl;
            waitForBackSignal();
            return;
        }

        cout << "\n--- Current Book Catalog ---" << endl;
        cout << left << setw(10) << "Book ID" << setw(25) << "Book Title" << "Author" << endl;
        cout << "--------------------------------------------------------" << endl;
        for (int i = 0; i < size; i++) {
            cout << left << setw(10) << arr[i].id << setw(25) << arr[i].title << arr[i].author << endl;
        }

        int targetID;
        cout << "\nEnter the Book ID to delete (or enter 0 to go back): ";
        cin >> targetID;

        if (targetID == 0) return;

        bool found = false;
        for (int i = 0; i < size; i++) {
            if (arr[i].id == targetID) {
                for (int j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                size--; 
                cout << "\n[Success] Book deleted successfully!" << endl;
                found = true;
                waitForBackSignal();
                return;
            }
        }
        if (!found) {
            cout << "\n[Error] Book ID " << targetID << " not found. Press Enter to retry.";
            cin.ignore(); cin.get();
        }
    }
}

// 5. SORT
void sortByTitle(Book arr[], int size) {
    if (size <= 1) return;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].title > arr[j + 1].title) {
                Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "\n[Success] Catalog sorted alphabetically by Title!" << endl;
    waitForBackSignal();
}

// 6. SEARCH
void searchByID(Book arr[], int size) {
    if (size == 0) {
        cout << "\n[Error] No books in the catalog to search." << endl;
        waitForBackSignal();
        return;
    }

    int targetID;
    cout << "\nEnter Book ID to search (or enter 0 to go back): ";
    cin >> targetID;

    if (targetID == 0) return;

    bool found = false;
    for (int i = 0; i < size; i++) {
        if (arr[i].id == targetID) {
            cout << "\n[Book Found!]" << endl;
            cout << "ID: " << arr[i].id << endl;
            cout << "Title: " << arr[i].title << endl;
            cout << "Author: " << arr[i].author << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\n[Notification] Book ID " << targetID << " could not be found." << endl;
    }
    waitForBackSignal();
}