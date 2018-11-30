#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Book.h"
#include "Library.h"
using namespace std;

void inputStudent();
void searchStudent();
void editStudent();
void displayStudent();
void studentOption();
void bookOptions();
void borrow();
void deposit();
void listBooklist(vector<Book>);
vector<string> split(string str,string sep);
vector<Book> initLib(ifstream& inf);
vector<Book> collection;

int main()
{
    ifstream importBooks;
    importBooks.open("C:/Users/jemhu/CLionProjects/sutdent/inputfile.txt");
    collection = initLib(importBooks);

    cout << "What would you like to do?" << endl;
    cout << "1. Student Menu" << endl;
    cout << "2. Borrow/Return a book" << endl;
    cout << "3. Exit" << endl;

    int choose;
    cin >> choose;
    switch (choose) {
        case 1:
            studentOption();
            break;
        case 2:
            bookOptions();
        case 3:
            exit(EXIT_FAILURE);
        default:
            cout << "Enter a valid input" << endl;
    }



}

void studentOption() {
    system("cls"); //clears the screen.
    system("title Library Database");
    cout << "What would you like to do?" << endl;
    cout << "1. Input new student " << endl;
    cout << "2. Search for student " << endl;
    cout << "3. Edit existing student " << endl;
    cout << "4. Display all students " << endl;
    cout << "5. Exit " << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            inputStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            editStudent();
            break;
        case 4:
            displayStudent();
            break;
        case 5:
            exit(EXIT_FAILURE);
        default:
            cout << "Enter a valid input" << endl;

    }
    studentOption();
}


void inputStudent() //this function allows you to create a new student to add to the database. 
{
    system("cls");
    string fname; //student's first name
    string lname; //student's last name
    string fileName;
    int studentId;

    cout << "Input first name: ";
    cin >> fname;
    cout << "Input last name: ";
    cin >> lname;
    cout << "Input student ID: ";
    cin >> studentId;
    string studentId2 = to_string(studentId);
    studentId2.append(".txt");
    ofstream newStudent(studentId2);
    newStudent << fname << ' ' << lname << ' ' << studentId << ' ' << endl;
    newStudent.close();
    ofstream dir("directory.txt", ios::app); //whenever you add something new the old information will not get deleted
    dir << fname << ' ' << lname << ' ' << studentId << ' ' << endl;
    dir.close(); //every new student that is created will be stored into this directory file.
    cout << "Student has been added to the directory." << endl;
    system("pause");
    system("cls");
    studentOption();
}

void searchStudent() {
    system("cls");
    string fname;
    string lname;
    string fileName;
    int studentId;
    int blank;
    cout << "Enter student ID number: " << endl;
    cin >> studentId;
    string studentId2 = to_string(studentId);
    studentId2.append(".txt");
    ifstream student(studentId2);
    while (student >> fname >> lname >> blank) {
        int lnameLength = lname.size();
        int fnameLength = fname.size();
        int lengthTotal = fnameLength + lnameLength;
        string response;
        cout << "Is this the correct student name you are looking for? [Y/N]" << endl;
        cout << fname << ' ' << lname << endl;
        cin >> response;
        if ((response == "y") || (response == "Y")) {
            system("cls");
            cout << "Name: ";
            for (int x = 1; x < lengthTotal; x++) {
                cout << " ";
            }
            cout << "ID #:" << endl;
            for (int y = 1; y < lengthTotal + 20; y++) {
                cout << '-';
            }
            cout << ' ' << endl;
            cout << fname << ' ' << lname << ' ' << '\t' << studentId << endl;
        }
        if ((response == "n") || (response == "N")) {
            main();
        }
    }
    system("pause");
    main();
}



void editStudent() {
    system("cls");
    string fname;
    string lname;
    string newfname;
    string newlname;
    string check;
    int studentId;
    int blank;
    cout << "Enter the student ID of the student you would like to edit." << endl;
    cin >> studentId;
    string studentId2 = to_string(studentId);
    studentId2.append(".txt");
    ifstream student(studentId2);
    while (student >> fname >> lname >> blank) {
        cout << "Is this the student you wish to edit? [y/n]" << endl;
        cout << fname << ' ' << lname << endl;
        cin >> check;
        if ((check == "y") || (check == "Y")) {
            system("cls");
            cout << "Current information: " << endl;
            int lnameLength = lname.size();
            int fnameLength = fname.size();
            int lengthTotal = fnameLength + lnameLength;

            cout << "Name: ";
            for (int x = 1; x < lengthTotal; x++) {
                cout << " ";
            }
            cout << "ID #:" << endl;
            for (int y = 1; y < lengthTotal + 20; y++) {
                cout << '-';
            }
            cout << ' ' << endl;
            cout << fname << ' ' << lname << ' ' << '\t' << studentId << endl;

            cout << "Enter a new first name to assign this student" << endl;
            cin >> newfname;
            cout << "Enter a new last name to assign this student" << endl;
            cin >> newlname;
        }
        if ((check == "n") || (check == "N")) {
            main();
        }
    }
    student.close();
    ofstream student2(studentId2);
    student2 << newfname << ' ' << newlname << ' ' << studentId << endl;
    student2.close();
    system("pause");
    main();
}

void displayStudent() {
    system("cls");
    string fname;
    string lname;
    int studentId;
    cout << "Students currently in the library database: " << endl;
    cout << "----------------------------------" << endl;
    ifstream dir("directory.txt");
    while (dir >> fname >> lname >> studentId) {
        cout << fname << ' ' << lname << ' ' << studentId << endl;
    }
    system("pause");
    main();
}

//    METHOD TO LIST ALL BOOKS
void listBooklist(vector<Book> collection){
    system("cls");
    int i = 1;
    for (Book bk : collection) {
        if (bk.ifStock() == (" " + to_string(i)+ "c0")) {
            cout << bk.toString() << endl;
            i++;
        }
    }
}


//   METHOD TO SPLIT UP A STRING USING DELIMITERS
vector<string> split(string str,string sep) {
    char *cstr = const_cast<char *>(str.c_str());
    char *current;
    vector<string> arr;
    current = strtok(cstr, sep.c_str());
    while (current != nullptr) {
        arr.emplace_back(current);
        current = strtok(nullptr, sep.c_str());
    }
    return arr;
}

//  METHOD TO MAKE A LIBRARY OF BOOKS  FROM AN INPUT FILE
vector<Book> initLib(ifstream& inf) {
    string name, writer;
    int amount, bookNo, numOfLines=0;
    vector<Book> collection;
    vector<string> arr;
    string block,line, inStock;

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
        inStock = arr[4];

        collection.emplace_back(Book(name, writer, amount, bookNo, inStock));
        arr.clear();
    }
    inf.clear();
    inf.seekg(0, ios::beg);
    return collection;
}

void bookOptions() {
    system("cls");
    cout << "What would you like to do?" << endl;
    cout << "1. Borrow a book " << endl;
    cout << "2. Return a book " << endl;
    cout << "3. List current titles " << endl;
    cout << "4. Exit " << endl;

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            borrow();
            break;
        case 2:
            deposit();
            break;
        case 3:
            listBooklist(collection);
            break;
        case 4:
            main();
            break;
        default:
            cout << "Enter a valid input" << endl;

    }
    main();
}
bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void borrow() {
    system("cls");
    listBooklist(collection);
    int isbn, numOfLines=0, pointer = 0;
    string block, line, strTemp;
    vector<string> arr;
    bool found = false;
    ifstream inf;
    ofstream  opf("C:/Users/jemhu/CLionProjects/sutdent/output.txt");
//    ofstream opf("C:/Users/jemhu/CLionProjects/sutdent/output.txt",std::ofstream::app);
    inf.open("C:/Users/jemhu/CLionProjects/sutdent/inputfile.txt");
    cout << "Enter the ISBN of the book: " << endl;
    cin >> isbn;

    while(getline(inf,line))
        ++numOfLines;
    inf.clear();
    inf.seekg(0, ios::beg);

    for (int i=0; i< numOfLines; i++) {
        getline(inf, block);
        arr = split(block, "/");
        if (isbn == stoi(arr[3])) {
            found = true;
        }
        arr.clear();
        ++pointer;
        if (found) break;
    }
    inf.clear();
    inf.seekg(0, ios::beg);


    cout << pointer << endl;
    cout << (" " + to_string(pointer) + "c0") << endl;

    while (inf >> strTemp) {
        cout << strTemp <<  endl;
        if (strTemp == (to_string(pointer) + "c0"))
            strTemp = (to_string(pointer) + "c1");

        if (hasEnding(strTemp, "c0")
        || hasEnding(strTemp, "c1"))
            strTemp += "\n";

        opf << strTemp << " ";
    }

    inf.close();
//    opf.flush();
    opf.close();

    if( remove( "inputfile.txt" ) != 0 )
        perror( "Error deleting file" );
    else
        puts( "File successfully deleted" );

    rename("C:/Users/jemhu/CLionProjects/sutdent/output.txt",
           "C:/Users/jemhu/CLionProjects/sutdent/inputfile.txt");








    main();
}

void deposit() {

}


