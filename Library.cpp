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

Library::Library(string name, string address, string office_hours {
    this->name = name;
    this->address = address;
    this->office_hours = office_hours;
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
            }
            book->setAvailble(false);
            patron->checkout(book);
        } catch (NotFoundException nf) { //if book isnt found
            return false;
        }
    } catch (NotFoundException nf) { //if patron isnt found
        return false;
    }
}

ostream <<operator(ostream& os, Library lib) {

    return os;
}

