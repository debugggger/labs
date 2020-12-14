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

bool String::checkAuthor(String _string)
{
    char* str = _string.str;
    for (int i = 0; i < _string.length(); i++)
    {
        if (i == 0 && str[i] > 64 && str[i] < 90)
            return true;
        else
            return false;
        if (i == _string.length() - 1 && str[i] > 64 && str[i] < 90)
            return true;
        else
            return false;
        if(i == _string.length() - 3 && str[i] > 64 && str[i] < 90)
            return true;
        else
            return false;
    }
}

bool String::checkTitle(String _string)
{
    char* str = _string.str;
    for (int i = 0; i < _string.length(); i++)
    {
        if (i == 0 && str[i] > 64 && str[i] < 90)
            return true;
        else
            return false;
    }
}

bool String::checkDiscipline(String _string)
{
    char* str = _string.str;
    bool tr = 0;
    for (int i = 0; i < _string.length(); i++)
    {
        if ((str[i] > 64 && str[i] < 90) || (str[i] > 96 && str[i] < 123))
            tr = 1;
        else
            tr = 0;
    }
    if (tr == 1)
        return true;
    else
        return false;
}

bool String::checkUDK(String _string)
{
    char* str = _string.str;
    bool tr = 0;
    for (int i = 0; i < _string.length(); i++)
    {
        if ((str[i] > 47 && str[i] < 58) || (str[i] == 46))
            tr = 1;
        else
            tr = 0;
    }
    if (tr == 1)
        return true;
    else
        return false;
}

int String::atoi(String _string)
{
    char* str = _string.str;
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] > 47 && str[i] < 58)
            res = res * 10 + str[i] - 48;
        else
        {
            std::cout << "Числовые данные не корректны!" << std::endl;
            return -1;
            break;
        }
    }
    return res;
}