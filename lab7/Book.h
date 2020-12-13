#pragma once
#ifndef Book_H
#define Book_H
//#include <string>
#include "MyVector.h"
#include "MyString.h"

class Book
{
private:
    String author;
    String title;
    String UDK;
    String year;
    String discipline;
    int quantity;
public:

    Book();
    Book(const String textAuthor, const String textTitle,
        const String textUDK, const String textYear, 
        const String textDiscipline, const int valueQuantity);
    Book(const Book& book);
    ~Book();

    friend Book getInfo(Book& book);
    friend String getAuthor(Book& book);
    friend String getTitle(Book& book);
    friend String getUDK(Book& book);
    friend String getYear(Book& book);
    friend String getDiscipline(Book& book);
    friend int getInfoQuantity(Book& book);
    Book operator+(const int right);
    friend Book operator-(Book& book, int right);
    bool operator>(Book& book2);
    friend bool operator<(Book& book1, Book& book2);
    friend bool operator==(Book& book1, Book& book2);
    Book& operator=(Book& book);
    Book& operator++();
    friend Book& operator++(Book& book, int);
    friend std::ostream& operator<< (std::ostream& out, Book& book);
    friend std::istream& operator>> (std::istream& in, Book& book);
};

#endif