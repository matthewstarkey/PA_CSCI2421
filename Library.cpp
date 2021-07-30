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

LinkedList<shared_ptr<Patron>> Library::getPatrons() {
    return patrons;
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
         * name, isbn, publisher, first author
         */
        string name;
        string isbn;
        string publisher;
        string author;
        getline(file, name);
        getline(file, isbn);
        getline(file, publisher);
        getline(file, author);
        auto book = make_shared<Book>(name,isbn,publisher);
        book->addAuthor(make_shared<Author>(author));
        books->add(book);
    }

    string num_of_patrons;
    getline(file,num_of_patrons);
    int numOfPatrons = stoi(num_of_patrons);
    for(int i = 0; i < numOfPatrons; i++) {
        string name;
        string addr;
        string phoneNumber;
        getline(file, name);
        getline(file, addr);
        getline(file, phoneNumber); //assumes no books checked out
        auto patron = make_shared<Patron>(name,addr,phoneNumber);
        patrons.insert(patrons.getLength() + 1, patron);
    }
    file.close();

}
//functions:
//adds book to library
bool Library::addBook(shared_ptr<Book> aBook) {
    return books->add(aBook);
}
//removes book from library
bool Library::removeBook(string bookName) {
    try{
        auto aBook = getBookByName(bookName);
        if (aBook->getAvailability())
            return books->remove(aBook);
        else
            return false;
    } catch (NotFoundException nf) {
        return false;
    }

}
//add patron to patron list (able to checkout books and put on hold)
bool Library::addPatron(shared_ptr<Patron> aPatron) {
    return patrons.insert(patrons.getLength()+1 ,aPatron);
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
bool Library::dropoff(string bookName, string patronName) {
    try{
        auto book = getBookByName(bookName);
        auto patron = getPatronByName(patronName);
        patron->returnBook();
        returnedBooks.push(book);
        return true;
    } catch (NotFoundException nf) {
        return false;
    }
}
//checks out book to patron OR adds patron to hold queue TODO
bool Library::checkout(string patronName, string bookName) {
    try {
        auto patron = getPatronByName(patronName);//get patron
        try {
            auto book = getBookByName(bookName); //get book
            if(!book->getAvailability()) {
                return false;
            } else { //better run than if or else...
                patron->checkout(book);
                book->setAvailable(false);
                return true;
            }
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
        return books->getEntryWithPointerItems(book);
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
        if(patron->getName() == patronName) { //if patronName == patron
            return patron;
        }
    }
    throw NotFoundException("Patron not found");
}
/*
 * Prints library data to ostream object
 */
ostream& operator<<(ostream& os, Library& lib) {
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
    os << lib.office_hours<< std::endl;
    //print books
    os << lib.books->getNumberOfNodes() << std::endl;
    if (!bookStackForPrinting->isEmpty()) {
        while (!bookStackForPrinting->isEmpty())
            bookStackForPrinting->pop();
    }

    lib.books->inorderTraverse(booksToPrintStack);

    while (!bookStackForPrinting->isEmpty()) {
        os << *bookStackForPrinting->peek();
        bookStackForPrinting->pop();
    }
    //print patrons
    os << lib.patrons.getLength() << std::endl;
    for(int i = 1; i <= lib.patrons.getLength(); i++) {
        os << lib.patrons.getEntry(i) << std::endl;
    }
    //assumes all books are available...
    return os;
}

void Library::emptyReturn() {
    while(!returnedBooks.isEmpty()) {
        auto book = returnedBooks.peek();
        book->setAvailable(true);
        returnedBooks.pop();
    }
}

LinkedList<shared_ptr<Book>> Library::search(string keyword) {
    keywordForSearching = keyword;
    foundBooksFromSearch->clear();
    this->books->inorderTraverse(aSearchHelper);
    return *foundBooksFromSearch;
}



LinkedList<shared_ptr<Book>> Library::getAvailable() {
    availableBooks->clear();
    this->books->inorderTraverse(booksToAvailableBooks);
    return *availableBooks;

}

LinkedList<shared_ptr<Book>> Library::getUnavailable() {
    unavailableBooks->clear();
    this->books->inorderTraverse(booksToUnavailableBooks);
    return *unavailableBooks;
}




