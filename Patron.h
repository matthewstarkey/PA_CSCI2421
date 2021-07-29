//
// Created by Kai Marshall on 7/29/21.
//

#ifndef PA_CSCI2421_PATRON_H
#define PA_CSCI2421_PATRON_H
#include <string>
#include "ADTs/LinkedStack.h"

class Book;

class Patron : std::enable_shared_from_this<Patron> {
private:
    string name;
    string address;
    string phone;
    unique_ptr<LinkedStack<shared_ptr<Book>>> checkedOutBooks;

public:
    Patron(string aName, string anAddress, string aPhone);
    void checkout(shared_ptr<Book> aBook);
    void returnBook();

    string getName();
    string getAddress();
    string getPhone();

    void setName(string aName);
    void setAddress(string anAddress);
    void setPhone(string aPhone);

};

#include "Patron.cpp"
#endif //PA_CSCI2421_PATRON_H
