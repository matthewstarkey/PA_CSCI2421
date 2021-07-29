//
// Created by Kai Marshall on 7/29/21.
//

#include "Author.h"
Author::Author(string aName) : name(aName) {}

string Author::getName() {
    return name;
}
void Author::setName(string aName){
    name = aName;
}