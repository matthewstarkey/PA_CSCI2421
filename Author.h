//
// Created by Kai Marshall on 7/29/21.
//

#ifndef PA_CSCI2421_AUTHOR_H
#define PA_CSCI2421_AUTHOR_H
#include <string>
using namespace std;

class Author {
private:
    string name;
public:
    Author(string aName);
    string getName();
    void setName(string aName);

};

#include "Author.cpp"
#endif //PA_CSCI2421_AUTHOR_H
