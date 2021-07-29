//
// Created by Matt Starkey on 7/25/21.
//

#ifndef PA_CSCI2421_LIBRARY_H
#define PA_CSCI2421_LIBRARY_H
#include <iostream>
#include <fstream>
#include "string"
#include "memory"
#include "regex"
#include "Book.h"
#include "Patron.h"
#include "Author.h"
#include "Date.h"
#include "ADTs/LinkedList.h"
#include "ADTs/NotFoundException.h"
#include "ADTs/LinkedStack.h"
#include "ADTs/AVLTree.h"
class Library {
private:
    string name;
    string address;
    string office_hours;
    shared_ptr<AVLTree<shared_ptr<Book>>> books;
    LinkedStack<shared_ptr<Book>> returnedBooks;
    LinkedList<shared_ptr<Patron>> patrons;
protected:
    shared_ptr<Book> getBookByName(string bookName);
    shared_ptr<Patron> getPatronByName(string patronName);
    //helper function to print books
    void printHelper(ostream& os, shared_ptr<Book> aBook);
    //helper function to search
    void searchHelper(LinkedList<shared_ptr<Book>>& foundBooks,string keyword, shared_ptr<Book> aBook);

public:
    //getter/setters
    string getName();
    void setName(const string &aName);
    string getAddress();
    void setAddress(const string  &anAddress);
    string getOfficeHours();
    void setOfficeHours(const string &officeHours);
    //Constructors:
    Library(string name, string address, string office_hours);
    //Constructs library from saved file.
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
    bool dropoff(string bookName, string patronName);
    //checks out book to patron OR adds patron to hold queue
    bool checkout(string patronName, string bookName);
    //searches for books containing keyword, returns linkedlist of books found
    LinkedList<shared_ptr<Book>> search(string keyword);
    void emptyReturn();


    friend ostream& operator<<(ostream& os, Library& lib);
};

#include "Library.cpp"
#endif //PA_CSCI2421_LIBRARY_H
