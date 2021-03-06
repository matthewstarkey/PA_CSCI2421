//
// Created by Kai Marshall on 7/29/21.
//

#include "Patron.h"
#include "Book.h"

Patron::Patron(string aName, string anAddress, string aPhone)
    : name(aName), address(anAddress), phone(aPhone), checkedOutBooks(make_unique<LinkedStack<shared_ptr<Book>>>()){}

void Patron::checkout(shared_ptr<Book> aBook) {
    if (aBook->getAvailability())
        checkedOutBooks->push(aBook);
    else {
       aBook->addHold(shared_from_this());
    }
}
void Patron::returnBook() {
    checkedOutBooks->pop();
}

string Patron::getName() {
    return name;
}
string Patron::getAddress(){
    return address;
}

string Patron::getPhone(){
    return phone;
}

void Patron::setName(string aName){
    name = aName;
}

void Patron::setAddress(string anAddress){
    address = anAddress;
}

void Patron::setPhone(string aPhone){
    phone = aPhone;
}