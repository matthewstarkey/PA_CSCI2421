//
// Created by Kai Marshall on 7/29/21.
//

#ifndef PA_CSCI2421_BOOK_H
#define PA_CSCI2421_BOOK_H
#include "Author.h"
#include "Date.h"
#include "Patron.h"
#include <string>
#include <memory>
#include "ADTs/LinkedQueue.h"
#include "ADTs/LinkedList.h"

class Book {
private:
    string title;
    string isbn;
    string publisher;
    shared_ptr<Date> date;
    bool isAvailable;
    unique_ptr<LinkedQueue<shared_ptr<Patron>>> holds;
    unique_ptr<LinkedList<shared_ptr<Author>>> authors;

public:
    Book();
    Book(string aTitle, string aIsbn, string aPublisher);
    bool isAvailable();
    string getTitle();
    string getIsbn();
    string getPublisher();
    shared_ptr<Date> getDate();
    unique_ptr<LinkedList<shared_ptr<Author>>> getAuthors();
    unique_ptr<LinkedQueue<shared_ptr<Patron>>> getHoldQueue();
    shared_ptr<Patron> getNextHold();

    void setTitle(string aTitle);
    void setIsbn(string aIsbn);
    void setDate(Date& aDate);
    void addHold(Patron& aPatron);
    void addAuthor(Author& anAuthor);
    void setAvailable(bool avail);

};

#include "Book.cpp"
#endif //PA_CSCI2421_BOOK_H
