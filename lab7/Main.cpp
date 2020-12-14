#include <iostream>
#include <fstream>
#include <sstream>
#include "Book.h"
#include "MyVector.h"
#include "Sort.h"
#include "MyString.h"
#pragma warning(disable : 4996)

int maxBook(Book& array, const int i);
void books(String& PATH, MyVector<Book>& bookArray);
void getString(std::ifstream& inputFile, String& str);
void printTable(MyVector<Book>& bookArray);
int maxL(const int len, int size, int maxL);

int main()
{
    setlocale(LC_ALL, "rus");
    std::ifstream inFile;
    String text;
    MyVector <Book> bookArray;
    String PATH;
    std::cout << "Введите имя файла: ";      
    std::cin >> PATH;
    PATH = PATH + ".txt";
    books(PATH, bookArray);

    int maxI = 0;
    int tempMax = maxBook(bookArray[0], 0);

    for (int i = 1; i < bookArray.size(); i++)
    {
        maxI = maxBook(bookArray[i], i);
        if (maxI > tempMax)
        {
            tempMax = maxI;
        }
    }

    std::cout << "Информация о книгах выведена в файл output.txt" << std::endl;

    freopen("output.txt", "w", stdout);

    if (bookArray.size() == 0)
        std::cout << "Исходные данные не корректны, исправьте их и попробуйте еще раз." << std::endl;
    else
    {
        std::cout << "Книга с наибольшим количеством экземпляров: "
            << getAuthor(bookArray[maxI]) << " - " << getTitle(bookArray[maxI]) << std::endl <<
            "Подробная информация о книге: " << std::endl << "год издания: " <<
            getYear(bookArray[maxI]) << std::endl << "УДК: " <<
            getUDK(bookArray[maxI]) << std::endl << "Предмет: " <<
            getDiscipline(bookArray[maxI]) << std::endl << "Количество: "
            << getInfoQuantity(bookArray[maxI]) << std::endl;

        sort(bookArray, bookArray.size());

        printTable(bookArray);
    }
    fclose(stdout);


    return 0;
}

void books(String& PATH, MyVector<Book>& bookArray)
{
    static std::ifstream inputFile;
    String author;
    String title;
    String UDK;
    String year;
    String discipline;
    String quantity;
    inputFile.open(PATH.getValue(), std::ifstream::in);
    if (inputFile.is_open())
        std::cout << "Файл " << PATH << " открыт" << std::endl;
    else
    {
        while (!inputFile.is_open())
        {
            std::cout << "Файл " << PATH << " не был открыт! Попробуйте ввести другое имя." << std::endl;
            std::cin.clear();
            std::cin >> PATH;
            PATH = PATH + ".txt";
            inputFile.open(PATH.getValue(), std::ifstream::in);
        }
    }
    while (!inputFile.eof())
    {
        getString(inputFile, author);
        getString(inputFile, title);
        getString(inputFile, UDK);
        getString(inputFile, year);
        getString(inputFile, discipline);
        getString(inputFile, quantity);
        int quan = quantity.atoi(quantity);
        int iYear = year.atoi(year);

        try
        {
            if (author.checkAuthor(author) == false)
            {
                std::cout << "Введите ФИО автора с заглавными буквами! В выходном файле будет содержаться не вся информация!" << std::endl;
                break;
            }
        }
        catch (char a)
        {
            std::cerr << "We caught an char exception with: " << a << '\n';
        }

        try
        {
            if (title.checkTitle(title) == false)
            {
                std::cout << "Введите название книги с заглавной буквы! В выходном файле будет содержаться не вся информация!" << std::endl;
                break;
            }
        }
        catch (char a)
        {
            std::cerr << "We caught an char exception with: " << a << '\n';
        }

        try
        {
            if (discipline.checkDiscipline(discipline) == false)
            {
                std::cout << "В названии предмета недопустимые символы! В выходном файле будет содержаться не вся информация!" << std::endl;
                break;
            }
        }
        catch (char a)
        {
            std::cerr << "We caught an char exception with: " << a << '\n';
        }

        try
        {
            if (UDK.checkUDK(UDK) == false)
            {
                std::cout << "В коде УДК недопустимые символы! В выходном файле будет содержаться не вся информация!" << std::endl;
                break;
            }
        }
        catch (char a)
        {
            std::cerr << "We caught an char exception with: " << a << '\n';
        }

        try
        {
            if (quan < 0)
            {
                std::cout << "Данные о количестве книг не правильны! Исправьте данные в файле! В выходном файле будет содержаться не вся информация!" << std::endl;
                break;
            }
        }
        catch (int a)
        {
            std::cerr << "We caught an int exception with value: " << a << '\n';
        }

        try
        {
            if (iYear > 2020 || iYear < 1036)
            {
                std::cout << "Не корректный год издания книги! Исправьте данные в файле! В выходном файле будет содержаться не вся информация!" << std::endl;
                break;
            }
        }
        catch (int a)
        {
            std::cerr << "We caught an int exception with value: " << a << '\n';
        }

        bookArray.push_back(Book(author.getValue(), title.getValue(),
            UDK.getValue(), year.getValue(), discipline.getValue(), quan));
    }
    inputFile.close();
}

void getString(std::ifstream& inputFile, String& str)
{
    String text;
    inputFile >> text;
    str = text;
}

int maxBook(Book& array, const int i)
{
    static int iMax = 0;
    static int maxQuantity = 0;
    if (getInfoQuantity(array) > maxQuantity)
    {
        maxQuantity = getInfoQuantity(array);
        iMax = i;
    }
    return iMax;
}

void printTable(MyVector<Book>& bookArray)
{
    int pos = 1;
    int maxLAut = 0;
    for (int i = 0; i < bookArray.size(); i++)
    {
        maxLAut = maxL(getAuthor(bookArray[i]).length(), bookArray.size(), maxLAut);
    }
    if (maxLAut < 11)
        maxLAut = 11;
    int maxLTitle = 0;
    for (int i = 0; i < bookArray.size(); i++)
    {
        maxLTitle = maxL(getTitle(bookArray[i]).length(), bookArray.size(), maxLTitle);
    }
    if (maxLTitle < 8)
        maxLTitle = 8;
    int maxLYear = 0;
    for (int i = 0; i < bookArray.size(); i++)
    {
        maxLYear = maxL(getYear(bookArray[i]).length(), bookArray.size(), maxLYear);
    }
    if (maxLYear < 11)
        maxLYear = 11;
    int maxLUDK = 0;
    for (int i = 0; i < bookArray.size(); i++)
    {
        maxLUDK = maxL(getUDK(bookArray[i]).length(), bookArray.size(), maxLUDK);
    }
    if (maxLUDK < 3)
        maxLUDK = 3;
    int maxLDis = 0;
    for (int i = 0; i < bookArray.size(); i++)
    {
        maxLDis = maxL(getDiscipline(bookArray[i]).length(), bookArray.size(), maxLDis);
    }
    if (maxLDis < 7)
        maxLDis = 7;
    int maxLQuan = 1;
    int tempMaxQ = 1;
    for (int i = 0; i < bookArray.size(); i++)
    {
        int temp = getInfoQuantity(bookArray[i]);
        while (temp > 0)
        {
            temp = temp / 10;
            tempMaxQ++;
            if (tempMaxQ > maxLQuan)
                maxLQuan = tempMaxQ;
        }
        tempMaxQ = 0;
    }
    if (maxLQuan < 10)
        maxLQuan = 10;

    std::cout << std::endl << std::endl << "Отсортированный список книг: " << std::endl;
    for (int i = 0; i < maxLAut + maxLTitle + maxLYear + maxLUDK + maxLDis + maxLQuan + 7; i++)
        std::cout << "-";
    std::cout << std::endl;


    std::cout << "|" << "Автор книги";
    for (int i = 0; i < maxLAut - 11; i++)
        std::cout << " ";
    std::cout << "|" << "Название";
    for (int i = 0; i < maxLTitle - 8; i++)
        std::cout << " ";
    std::cout << "|" << "Год издания";
    for (int i = 0; i < maxLYear - 11; i++)
        std::cout << " ";
    std::cout << "|" << "УДК";
    for (int i = 0; i < maxLUDK - 3; i++)
        std::cout << " ";
    std::cout << "|" << "Предмет";
    for (int i = 0; i < maxLDis - 7; i++)
        std::cout << " ";
    std::cout << "|" << "Количество";
    for (int i = 0; i < maxLQuan - 11; i++)
        std::cout << " ";
    std::cout << "|" << std::endl;
    for (int i = 0; i < maxLAut + maxLTitle + maxLYear + maxLUDK + maxLDis + maxLQuan + 7; i++)
        std::cout << "-";
    std::cout << std::endl;
    for (int j = 0; j < bookArray.size(); j++)
    {
        std::cout << "|" << getAuthor(bookArray[j]);
        for (int i = 0; i < maxLAut - getAuthor(bookArray[j]).length(); i++)
            std::cout << " ";
        std::cout << "|";
        std::cout << getTitle(bookArray[j]);
        for (int i = 0; i < maxLTitle - getTitle(bookArray[j]).length(); i++)
            std::cout << " ";
        std::cout << "|";
        std::cout << getYear(bookArray[j]);
        for (int i = 0; i < maxLYear - getYear(bookArray[j]).length(); i++)
            std::cout << " ";
        std::cout << "|";
        std::cout << getUDK(bookArray[j]);
        for (int i = 0; i < maxLUDK - getUDK(bookArray[j]).length(); i++)
            std::cout << " ";
        std::cout << "|";
        std::cout << getDiscipline(bookArray[j]);
        for (int i = 0; i < maxLDis - getDiscipline(bookArray[j]).length(); i++)
            std::cout << " ";
        std::cout << "|";

        int temp = getInfoQuantity(bookArray[j]);
        int te = 0;
        int teM = 0;
        while (temp > 0)
        {
            temp = temp / 10;
            te++;
            if (te > teM)
                teM = te;
        }
        std::cout << getInfoQuantity(bookArray[j]);
        for (int i = 0; i < maxLQuan - teM; i++)
            std::cout << " ";
        std::cout << "|" << std::endl;
        for (int i = 0; i < maxLAut + maxLTitle + maxLYear + maxLUDK + maxLDis + maxLQuan + 7; i++)
            std::cout << "-";
        std::cout << std::endl; 
    }

}

int maxL(const int len, int size, int maxL)
{
    int tempPos = 0;
    if (tempPos < size)
    {
        if (len > maxL)
            maxL = len;
        tempPos++;
    }
    else
        maxL = 0;
    return maxL;
}