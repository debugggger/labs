#include "Book.h"

Book::Book(const String textAuthor, const String textTitle,
    const String textUDK, const String textYear,
    const String textDiscipline, const int valueQuantity)
{
	this->author = textAuthor;
	this->title = textTitle;
	this->UDK = textUDK;
	this->year = textYear;
	this->discipline = textDiscipline;
	this->quantity = valueQuantity;
}

Book::Book(const Book& book)
{
    this->author = book.author;
	this->title = book.title;
	this->UDK = book.UDK;
	this->year = book.year;
	this->discipline = book.discipline;
	this->quantity = book.quantity;
}

Book::Book()
{
	quantity = 0;
}

Book::~Book()
{

}

Book Book::operator+(const int right)
{
	quantity += right;
	return *this;
}

Book operator-(Book& book, int right)
{
	book.quantity -= right;
	return book;
}

bool Book::operator>(Book& book2)
{
		return this->quantity > book2.quantity; 

}

bool operator<(Book& book1, Book& book2)
{
		return book1.quantity < book2.quantity; 
}

bool operator==(Book& book1, Book& book2)
{
	if (book1.quantity == book2.quantity)
		return book1.quantity;
	else
		return book1.quantity == book2.quantity;
}

Book& Book::operator=(Book& book)
{
	author = book.author;
	title = book.title;
	UDK = book.UDK;
	year = book.year;
	discipline = book.discipline;
	quantity = book.quantity;
	return *this;
}

Book& Book::operator++()
{
	quantity++;
	return *this;
}

Book& operator++(Book& book, int)
{
	static Book& temp(book);
	book.quantity++;
	return temp;
}

std::ostream& operator << (std::ostream& out, Book& book)
{
	out << book.author;
	out << book.title;
	out << book.UDK;
	out << book.year;
	out << book.discipline;
	out << book.quantity;
	out << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Book& book)
{
	String temp;
	in >> book.author;
	in >> book.title;
	in >> book.UDK;
	in >> book.year;
	in >> book.discipline;
	in >> book.quantity;
	return in;
}

String getAuthor(Book& book)
{
	String temp = book.author;
	return temp;
}

String getTitle(Book& book)
{
	String temp = book.title;
	return temp;
}

String getUDK(Book& book)
{
	String temp = book.UDK;
	return temp;
}

String getYear(Book& book)
{
	String temp = book.year;
	return temp;
}

String getDiscipline(Book& book)
{
	String temp = book.discipline;
	return temp;
}

int getInfoQuantity(Book& book)
{
	int temp = book.quantity;
	return temp;
}