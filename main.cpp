#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


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

public:
    Library() = default;
/*
public:
    Book addBook(ifstream& inf) {
        string name, writer;
        int amount, bookNo;
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
*/

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

public:
    void listBooklist(vector<Book> collection){
        for (Book bk : collection)
            cout << bk.toString();
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

    ifstream lib;
    vector<Book> collection;
    Library contents;
    lib.open("C:/Users/jemhu/CLionProjects/FinalProject/inputfile");

   /* while (getline(lib,line))
        ++numOfLines;

    cout << numOfLines;
    lib.clear();
    lib.seekg(0, ios::beg);


    collection.reserve(numOfLines);
    for (int i=0; i< numOfLines; i++)
        collection.emplace_back(contents.addBook(lib));


    for (Book b: collection)
        cout << b.toString() << endl;*/


   contents.initLib(lib,collection);
   contents.listBooklist(collection);



//    string str1 = "test one two three.";
//    vector<string> ary1;
//    int i = 0;
//    stringstream ssin(str1);
//    while (ssin.good() && i < 4){
//        ssin >> ary1[i];
//        ++i;
//    }
//    for(i = 0; i < 4; i++) {
//        cout << ary1[i] << endl;
//    }

    return 0;
}
