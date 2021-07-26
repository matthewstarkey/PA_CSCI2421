//
// Created by Kai Marshall on 7/15/21.
//

#ifndef LAB5PREP_NOTFOUNDEXCEPTION_H
#define LAB5PREP_NOTFOUNDEXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException: public logic_error {
public:
    explicit NotFoundException(const string& message = "");
};
#include "NotFoundException.cpp"
#endif //LAB5PREP_NOTFOUNDEXCEPTION_H
