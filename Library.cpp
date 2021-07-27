//
// Created by Matt Starkey on 7/25/21.
//

#include "Library.h"

string Library::getName() {
    return name;
}
void Library::setName(const string &aName) {
    name = aName;
}
string Library::getAddress() {
    return address;
}
void Library::setAddress(const string &anAddress) {
    address = anAddress;
}
string Library::getOfficeHours() {
    return office_hours
}
void Library::setOfficeHours(const string &officeHours) {
    office_hours = officeHours;
}

Library::Library(string name, string address, string office_hours) {
    this->name = name;
    this->address = address;
    this->office_hours = office_hours;
    AVLTree<shared_ptr<Book>> books;
    LinkedList<shared_ptr<Patron>> patrons;
    LinkedStack<shared_ptr<Book>> returnedBooks;
}
Library::Library(string fileName) {
    /*
     * TODO: IMPLEMENT CONSTRUCTOR FROM FILE
     */
}
//functions:
//adds book to library
bool Library::addBook(shared_ptr<Book> aBook) {
    return books.add(aBook);
}
//removes book from library
bool Library::removeBook(string bookName) {
    auto aBook = getBookByTitle(bookName);
    books.remove(aBook);
}
//add patron to patron list (able to checkout books and put on hold)
bool Library::addPatron(shared_ptr<Patron> aPatron) {
    return patrons.add(aPatron);
}
//removes patron from list
bool Library::removePatron(string patronName) {
    auto aPatron = getPatronByName(patronName);
    return patrons.remove(aPatron);
}
//returns book to dropoff box
bool Library::dropoff(shared_ptr<Book> aBook);
//checks out book to patron OR adds patron to hold queue
bool Library::checkout(string patronName, string bookName) {
    try {
        auto patron = getPatronByName(patronName); //get patron
        try {
            auto book = getBookByName(bookName); //get book
            if(!book->isAvailable()) {
                return false;
            } else; //better run than if or else...
            book->setAvailble(false);
            patron->checkout(book);
        } catch (NotFoundException nf) { //if book isnt found
            return false;
        }
    } catch (NotFoundException nf) { //if patron isnt found
        return false;
    }
}

shared_ptr<Book> Library::getBookByName(string bookName) {
    auto book = make_shared<Book>(bookname, "", ""); //edit if needed TODO
    try {
        return books.getEntry(book);
    } catch (NotFoundException nf) {
        throw NotFoundException("Book Doesn't Exist");
    }
}
shared_ptr<Patron> Library::getPatronByName(string patronName) {
    for(int i = 1; i <= patrons.getLength(); i++) {
        auto patron = patrons.getEntry(i);
        if(patron->getName().compare(patronName) == 0) { //if patronName == patron
            return patron;
        }
    }
    throw NotFoundException("Patron not found");
}

ostream <<operator(ostream& os, Library lib) {
    /*
     * FORMAT FOR LIBRARY FILE:
     * NAME
     * ADDRESS
     * OFFICE HOURS
     * # OF BOOKS
     * {List of books separated by \n}
     * # of patrons
     * {List of patrons}
     * (ASSUMES ALL BOOKS WILL BE AVAILABLE i.e. no patron is holding book);
     */
    //print basic library data
    os << lib.getName() << std::endl;
    os << lib.getAddress() << std::endl;
    os << lib.getOfficeHours() << std::endl;
    //print books
    os << lib.books.getNumberOfNodes() << std::endl;
    lib.books.inorderTraverse(printHelper(os)); //TODO might need to fix this printHelper
    //print patrons
    os << lib.patrons.getLength() << std::endl;
    for(int i = 1; i <= lib.patrons.getLength(); i++) {
        os << lib.patrons.getEntry(i) << std::endl;
    }
    //assumes all books are available...
    return os;
}

void printHelper(ostream& os,shared_ptr<Book> aBook) {
    //assumes all books will be available when saving library
    aBook->setAvaiable(true);
    os << aBook << std::endl;
}

