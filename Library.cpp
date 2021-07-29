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
    return office_hours;
}
void Library::setOfficeHours(const string &officeHours) {
    office_hours = officeHours;
}

Library::Library(string name, string address, string office_hours) {
    this->name = name;
    this->address = address;
    this->office_hours = office_hours;
    this->books = make_shared<AVLTree<shared_ptr<Book>>>();
    this->patrons = LinkedList<shared_ptr<Patron>>();
    this->returnedBooks = LinkedStack<shared_ptr<Book>>();
}
Library::Library(string fileName) {
    /*
     * TODO: IMPLEMENT CONSTRUCTOR FROM FILE
     */
}
//functions:
//adds book to library
bool Library::addBook(shared_ptr<Book> aBook) {
    return books->add(aBook);
}
//removes book from library
bool Library::removeBook(string bookName) {
    auto aBook = getBookByName(bookName);
    books->remove(aBook);

}
//add patron to patron list (able to checkout books and put on hold)
bool Library::addPatron(shared_ptr<Patron> aPatron) {
    return patrons.insert(patrons.getLength() ,aPatron);
}
//removes patron from list
bool Library::removePatron(string patronName) {
    bool canRemove = false;
    for (int i = 0; i < patrons.getLength(); i++)
    {
        if (patronName == patrons.getEntry(i)->getName()){
            canRemove = patrons.remove(i);
        }
    }

    return canRemove;
}
//returns book to dropoff box
bool Library::dropoff(shared_ptr<Book> aBook){}
//checks out book to patron OR adds patron to hold queue TODO
bool Library::checkout(string patronName, string bookName) {
    try {
        auto patron = getPatronByName(patronName); //get patron
        try {
            auto book = getBookByName(bookName); //get book
            if(!book->getAvailability()) {
                return false;
            } else; //better run than if or else...
            patron->checkout(book);
            book->setAvailable(false);
        } catch (NotFoundException nf) { //if book isnt found
            return false;
        }
    } catch (NotFoundException nf) { //if patron isnt found
        return false;
    }
}
/*
 * Helper to get book by string name
 * returns book smart ptr
 * throws NotFoundException if book is not found
 */
shared_ptr<Book> Library::getBookByName(string bookName) {
    auto book = make_shared<Book>(bookName, "", ""); //edit if needed TODO
    try {
        return books->getEntry(book);
    } catch (NotFoundException nf) {
        throw NotFoundException("Book Doesn't Exist");
    }
}
/*
 * Helper to get patron by string name
 * returns patron smart ptr
 * throws NotFoundException if patron is not found
 */
shared_ptr<Patron> Library::getPatronByName(string patronName) {
    for(int i = 1; i <= patrons.getLength(); i++) {
        auto patron = patrons.getEntry(i);
        if(patron->getName().compare(patronName) == 0) { //if patronName == patron
            return patron;
        }
    }
    throw NotFoundException("Patron not found");
}
/*
 * Prints library data to ostream object
 */
ostream& operator<<(ostream& os, const Library& lib) {
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
    os << lib.name << std::endl;
    os << lib.address << std::endl;
    os << lib.office_hours << std::endl;
    //print books
    os << lib.books->getNumberOfNodes() << std::endl;
    //lib.books->inorderTraverse(lib.printHelper(os)); /**TODO might need to fix this printHelper
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
    aBook->setAvailable(true);
    os << aBook << std::endl;
}

