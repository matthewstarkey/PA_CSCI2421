//
// Created by Matt Starkey on 7/25/21.
//

#ifndef PA_CSCI2421_LIBRARY_H
#define PA_CSCI2421_LIBRARY_H
#include "string"
#include "memory"
//#include "LinkedList.h"
//#include "Book.h"
//#include "Patron.h"
//#include "Stack.h"
#include "AVLTree.h"
class Library {
private:
    string name;
    string address;
    string office_hours;
    shared_ptr<AVLTree<shared_ptr<Book>>> books;
    Stack<shared_ptr<Book>> returnedBooks;
    LinkedList<shared_ptr<Patron>> patrons;
    shared_ptr<Book> getBookByTitle(string bookName);

public:
    //getter/setters
    string getName();
    void setName(const string &aName);
    string getAddress();
    void setAddress(const string &anAddress);
    string getOfficeHours();
    void setOfficeHours(const string &officeHours);
    //Constructors:
    Library(string name, string address, string office_hours);
    Library(string fileName);
    //functions:
    //adds book to library
    bool addBook(shared_ptr<Book> aBook);
    //removes book from library
    bool removeBook(string bookName);
    //add patron to patron list (able to checkout books and put on hold)
    bool addPatron(shared_ptr<Patron> aPatron);
    //removes patron from list
    bool removePatron(string patronName);
    //returns book to dropoff box
    bool dropoff(shared_ptr<Book> aBook);
    //checks out book to patron OR adds patron to hold queue
    bool checkout(shared_ptr<Patron> aPatron, string bookName);
};


#endif //PA_CSCI2421_LIBRARY_H
