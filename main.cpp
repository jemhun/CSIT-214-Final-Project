#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;


vector<string> split(string str,string sep) {
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    vector<string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != NULL) {
        arr.push_back(current);
        current = strtok(NULL, sep.c_str());
    }
    return arr;
}


class Book {
    string title, author;
    int pages, isbn;

public:
    Book(string _title, string _author, int _pages, int _isbn) {
        title = _title;
        author = _author;
        pages = _pages;
        isbn = _isbn;
    }


public:
    Book addBook(ifstream& inf) {
        string name, writer;
        int amount, bookNo;
        inf.open("C:/Users/jemhu/CLionProjects/FinalProject/inputfile");
        vector<string> arr;
        string block;

        while (getline(inf, block)) {
            arr = split(block, "/");
        }
            name = arr[0];
            writer = arr[1];
            amount = stoi(arr[2]);
            bookNo = stoi(arr[3]);

            return Book(name, writer, amount, bookNo);
    }

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




class Library {
    vector<Book> collection;

public:
    Library() = default;

public:
    Book addBook(ifstream& inf) {
        string name, writer;
        int amount, bookNo;
        inf.open("C:/Users/jemhu/CLionProjects/FinalProject/inputfile");
        vector<string> arr;
        string block;

        getline(inf, block);
        arr = split(block, "/");

        name = arr[0];
        writer = arr[1];
        amount = stoi(arr[2]);
        bookNo = stoi(arr[3]);

        return Book(name, writer, amount, bookNo);
    }
};


//public:
//void addCollection(ifstream& inf) {
//    inf.open("C:/Users/jemhu/CLionProjects/FinalProject/inputfile");
//    vector<string> arr;
//    string block;
//
//    while (getline(inf, block)) {
//        arr = split(block, "/");
//        for (size_t i = 0; i < arr.size(); i++)
//            printf("%s\n", arr[i].c_str());
//    }
//
//}
//};



int main() {
//    Book *uno = new Book("Game of Thrones", "GRR Martin", 589, 12345678);
//    cout << uno->toString();

//    ifstream lib;
//
//    Library what;
//
//    what.addCollection(lib);

ifstream lib;
vector<Book> lol;

Library conan;

for (int i=0; i<2; i++) {
    conan.addBook(lib);
}


    return 0;
}
