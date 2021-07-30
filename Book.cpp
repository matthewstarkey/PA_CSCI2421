//
// Created by Kai Marshall on 7/29/21.
//

#include "Book.h"
#include "Patron.h"

Book::Book() : title(""), isbn(""), publisher(""), isAvailable(true)
        , authors(make_unique<LinkedList<shared_ptr<Author>>>())
        , holds(make_unique<LinkedQueue<shared_ptr<Patron>>>()){}

Book::Book(string aTitle, string aIsbn, string aPublisher)
    : title(aTitle), isbn(aIsbn), publisher(aPublisher), isAvailable(true)
    , authors(make_unique<LinkedList<shared_ptr<Author>>>())
    , holds(make_unique<LinkedQueue<shared_ptr<Patron>>>()) {}

bool Book::getAvailability() {
    return isAvailable;
}

string Book::getTitle() {
    return title;
}
string Book::getIsbn() {
    return isbn;
}
string Book::getPublisher() {
    return publisher;
}
shared_ptr<Date> Book::getDate() {
    return date;
}

shared_ptr<Patron> Book::getNextHold() {
    return holds->peekFront();
}

void Book::setTitle(string aTitle){
    title = aTitle;
}
void Book::setIsbn(string aIsbn){
    isbn = aIsbn;
}
void Book::setDate(shared_ptr<Date> aDate){
    date = aDate;
}
void Book::addHold(shared_ptr<Patron> aPatron) {
    holds->enqueue(aPatron);
    isAvailable = false;
}
void Book::addAuthor(shared_ptr<Author> anAuthor) {
    authors->insert(authors->getLength()+1, anAuthor);
}
void Book::setAvailable(bool avail){
    isAvailable = avail;
}

ostream &operator<<(ostream &os, const Book &book) {
    os << book.title << " by "<< book.authors->getEntry(1)->getName() ;
    return os;
}

bool operator==(Book &rhs, Book& lhs) {
    return rhs.getTitle() == lhs.getTitle();
}

bool operator>(Book &lhs, Book &rhs) {
    return lhs.getTitle() > rhs.getTitle();
}
