#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

//   METHOD TO SPLIT UP A STRING USING DELIMITERS
vector<string> split(string str,string sep) {
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    vector<string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL) {
        arr.emplace_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}


//  BOOK CLASS
class Book {
    string title, author;
    int pages, isbn;

//    BOOK CONSTRUCTOR
public:
    Book(string _title, string _author, int _pages, int _isbn) {
        title = _title;
        author = _author;
        pages = _pages;
        isbn = _isbn;
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



//  LIBRARY CLASS
class Library {

//    DEFAULT CONSTRUCTOR
public:
    Library() = default;

//  METHOD TO MAKE A LIBRARY OF BOOKS  FROM AN INPUT FILE
public:
    void initLib(ifstream& inf, vector<Book>& collection) {
        string name, writer;
        int amount, bookNo, numOfLines=0;
        vector<string> arr;
        string block,line;

        while(getline(inf,line))
            ++numOfLines;
        inf.clear();
        inf.seekg(0, ios::beg);


        for (int i=0; i< numOfLines; i++) {
            getline(inf, block);
            arr = split(block, "/");

            name = arr[0];
            writer = arr[1];
            amount = stoi(arr[2]);
            bookNo = stoi(arr[3]);

            collection.emplace_back(Book(name, writer, amount, bookNo));
            arr.clear();
        }

    }

//    METHOD TO LIST ALL BOOKS
public:
    void listBooklist(vector<Book> collection){
        for (Book bk : collection)
            cout << bk.toString();
    }

};


//  MAIN METHOD
int main() {

    ifstream lib;
    vector<Book> collection;
    Library contents;
    lib.open("C:/Users/jemhu/CLionProjects/FinalProject/inputfile");

   contents.initLib(lib,collection);    // INITIALIZES LIBRARY
   contents.listBooklist(collection);   // LISTS CONTENT

    return 0;
}
