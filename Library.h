//
// Created by jemhu on 11/28/2018.
//

#ifndef SUTDENT_LIBRARY_H
#define SUTDENT_LIBRARY_H


//  LIBRARY CLASS
class Library {

//    DEFAULT CONSTRUCTOR
public:
    Library() = default;

//    METHOD TO BORROW BOOKS
/*public:
    void borrow(ifstream& inf) {
        int selected;
        unique_ptr<Book> chosen;

        listBooklist(initLib(inf));
        inf.clear();
        inf.seekg(0, ios::beg);
        cout << "Select a book by typing its ISBN" << endl;
        cin >> selected;
        for (Book k: initLib(inf))
            if (k.getISBN() == selected) {
                chosen = new Book();
                chosen->toString();
            }
            else
                cout << "wrong";
    }*/
};


#endif //SUTDENT_LIBRARY_H
