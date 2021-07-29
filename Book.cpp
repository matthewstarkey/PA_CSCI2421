//
// Created by Kai Marshall on 7/29/21.
//

#include "Book.h"
Book::Book() : title(""), isbn(""), publisher(""), isAvailable(true)  {}

Book::Book(string aTitle, string aIsbn, string aPublisher)
    : title(aTitle), isbn(aIsbn), publisher(aPublisher) {
    unique_ptr<LinkedQueue<shared_ptr<Patron>>> aHoldQueue;
    unique_ptr<LinkedList<shared_ptr<Author>>> authorList;
    authors = authorList;
    holds = aHoldQueue;
    isAvailable = true;
}

bool Book::isAvailable() {
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
unique_ptr<LinkedList<shared_ptr<Author>>> Book::getAuthors() {
    return authors;
}
unique_ptr<LinkedQueue<shared_ptr<Patron>>> Book::getHoldQueue(){
    return holds;
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
void Book::setDate(Date& aDate){
    date = aDate;
}
void Book::addHold(Patron& aPatron) {
    holds->enqueue(aPatron);
    isAvailable = false;
}
void Book::addAuthor(Author& anAuthor) {
    authors.add(anAuthor);
}
void Book::setAvailable(bool avail){
    isAvailable = avail;
}