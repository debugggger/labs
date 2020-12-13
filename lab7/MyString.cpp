#include "MyString.h" 
#pragma warning(disable : 4996)

using std::cin;
using std::cout;


int String::num_strings = 0;


String::String(const char* s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 1;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String& st)
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
}

String::~String()
{
    --num_strings;
    delete[] str;
}

String& String::operator=(const String& st)
{
    if (this == &st)
        return *this;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
    
}

char& String::operator[](int i)
{
    return str[i];
}

bool operator==(const String& st1, const String& st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream& os, const String& st)
{
    os << st.str;
    return os;
}

String operator+(const String& st1, const String& st2)
{
    String _temp;                 
    delete[] _temp.str;               
    _temp.len = st1.len + st2.len;      
    _temp.str = new char[_temp.len + 1]; 

    std::strcpy(_temp.str, std::strcat(st1.str, st2.str));
    return _temp;
}

istream& operator>>(istream& is, String& st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n' && is.get() != '\0')
        continue;
    return is;
}

int String::atoi(String _string)
{
    char* str = _string.str;
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        res = res * 10 + str[i] - 48;
    }
    return res;
}