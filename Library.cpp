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
    ifstream file(fileName);
    if(!file.is_open()) {
        throw NotFoundException("Error loading file");
    }
    string name;
    string addr;
    string office_hours;
    getline(file, name); //get name
    getline(file, addr); //get address
    getline(file, office_hours); //get office hours
    Library(name,addr,office_hours);

    string num_of_books;
    getline(file, num_of_books); //get # of books
    int numOfBooks = stoi(num_of_books);
    for(int i = 0; i < numOfBooks; i++) { //get all book data
        /* BOOK PRINT DATA GOE:
         * name, isbn, publisher
         */
        string name;
        string isbn;
        string publisher;
        getline(file, name);
        getline(file, isbn);
        getline(file, publisher);
        auto book = make_shared<Book>(name,isbn,publisher);
        this->addBook(book);
    }

    string num_of_patrons;
    getline(file,num_of_patrons);
    int numOfPatrons = stoi(num_of_patrons);
    for(int i = 1; i <= numOfPatrons; i++) { //yeet
        string name;
        string addr;
        string phoneNumber;
        getline(file, name);
        getline(file, addr);
        getline(file, phoneNumber); //assumes no books checked out
        auto patron = make_sharede<Patron>(name,addr,phoneNumber);
        this->addPatron(patron);
    }


}
//functions:
//adds book to library
bool Library::addBook(shared_ptr<Book> aBook) {
    return books.add(aBook);
}
//removes book from library
bool Library::removeBook(string bookName) {
    try{
        auto aBook = getBookByName(bookName);
        return books.remove(aBook);
    } catch(NotFoundException nf) {
        return false;
    }

}
//add patron to patron list (able to checkout books and put on hold)
bool Library::addPatron(shared_ptr<Patron> aPatron) {
    return patrons.insert(patrons.getLength() + 1, aPatron);
}
//removes patron from list
bool Library::removePatron(string patronName) {
    try {
        auto aPatron = getPatronByName(patronName);
    } catch (NotFoundException nf) {
        return false;
    }
    for(int i = 1; i <= patrons.getLength(); i++) {
        auto patron = patrons.getEntry(i);
        if(patron == aPatron) {
            patrons.remove(i);
            return true;
        }
    }
    return false;
}
//returns book to dropoff box
bool Library::dropoff(shared_ptr<Book> aBook, shared_ptr<Patron> aPatron) {
    aPatron->returnBook();
    returnedBooks.push(aBook);
}
//checks out book to patron OR adds patron to hold queue
bool Library::checkout(string patronName, string bookName) {
    try {
        auto patron = getPatronByName(patronName); //get patron
        try {
            auto book = getBookByName(bookName); //get book
            if(!book->isAvailable()) {
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
        return books.getEntry(book);
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

LinkedList<shared_ptr<Book>> Library::search(string keyword) {
    LinkedList<shared_ptr<Book>> foundBooks;
    this->books.inorderTraverse(searchHelper(foundBooks&, keyword));
}

void Library::searchHelper(LinkedList<shared_ptr<Book>>& foundBooks,string keyword, shared_ptr<Book> aBook) {
    const std::regex txt(".*" + keyword, + ".*");
    if(aBook->isAvailable()) {
        if(regex_match(txt, aBook->getTitle())) { //if regex txt keyword matches book title
            foundBooks.insert(foundBooks.getLength() + 1, aBook); //yeet
        }
    }
}


/*
 * Prints library data to ostream object
 */
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
    os << aBook << std::endl;
}

