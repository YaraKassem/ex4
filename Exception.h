#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

//------------------------------------- EXCEPTION CLASSES -------------------------------------//

class InvalidPlayerName: public std::exception {};

class InvalidCardName: public std::exception {};


#endif