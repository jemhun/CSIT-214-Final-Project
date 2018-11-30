//
// Created by jemhu on 11/28/2018.
//

#ifndef SUTDENT_BOOK_H
#define SUTDENT_BOOK_H
#include <string>
using namespace std;

class Book {
    string title, author, inStock;
    int pages, isbn;

//    BOOK CONSTRUCTOR
public:
    Book(string _title, string _author, int _pages, int _isbn, string _inStock) {
        title = _title;
        author = _author;
        pages = _pages;
        isbn = _isbn;
        inStock = _inStock;
    }

public:
    int getISBN() {
        return isbn;
    }

public:
    string ifStock() {
        return inStock;
    }

//    TOSTRING METHOD
public:
    string toString() {
        string description;
        description += "Title: " + title + "\n";
        description += "Author: " + author + "\n";
        description += "No. of Pages: " + to_string(pages) + "\n";
        description += "ISBN: " + to_string(isbn) + "\n";

        return description;
    }
};


#endif //SUTDENT_BOOK_H
