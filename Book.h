#ifndef BOOK_H
#define BOOK_H

#include <string>

struct Book {
    int id;
    std::string title;
    std::string author;
};

const int MAX_CAPACITY = 20;

void displayCatalog(Book arr[], int size);
void addBook(Book arr[], int &size); // Logic will change inside Book.cpp
void updateBook(Book arr[], int size);
void deleteBook(Book arr[], int &size);
void sortByTitle(Book arr[], int size);
void searchByID(Book arr[], int size);

#endif