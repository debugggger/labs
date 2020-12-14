#pragma once
#ifndef STRING1_H_
#define STRING1_H_
#include <iostream>
#include <cstring>
#include <cctype>
using std::ostream;
using std::istream;

class String
{
private:
    char* str;
    int len;
    static int num_strings;
    static const int CINLIM = 255;
public:

    String(const char* s);
    String();
    String(const String&);
    ~String();
    int length() const { return len; }
    const char* getValue() { return str; }

    String& operator=(const String&);
    char& operator[](int i);
    friend bool operator==(const String& st, const String& st2);
    friend ostream& operator<<(ostream& os, const String& st2);
    friend istream& operator>>(istream& is, String& st);
    friend String operator+(const String& st1, const String& st2);

    int atoi(String _string);
    bool checkAuthor(String _string);
    bool checkTitle(String _string);
    bool checkDiscipline(String _string);
    bool checkUDK(String _string);
};
#endif