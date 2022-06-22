#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

//------------------------------------- EXCEPTION CLASSES -------------------------------------//

class InvalidPlayerName : public std::exception
{
public:
    const char *what() const noexcept
    {
        return "Player's name is not valid";
    }
};

class InvalidCardName : public std::exception
{
public:
    const char *what() const noexcept
    {
        return "Card's name is not valid";
    }
};

class DeckFileNotFound : public std::exception
{
public:
    const char *what() const noexcept
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char *what() const noexcept
    {
        return "Deck File Error: Deck size is invalid";
    }
};

class DeckFileFormatError : public std::exception
{

std::string m_str;

public:
    DeckFileFormatError(std::string& line) : m_str(("Deck File Error: File format error in line ") + line){}
    const char *what() const noexcept
    {
        return m_str.c_str();
    }
};



#endif