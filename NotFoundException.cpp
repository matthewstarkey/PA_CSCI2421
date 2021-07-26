//
// Created by Kai Marshall on 7/15/21.
//
#include "NotFoundException.h"

NotFoundException::NotFoundException(const string &message)
        : logic_error("Not Found Exception: " + message){}