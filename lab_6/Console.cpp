#include <iostream>
#include <fstream>
#include <string>

bool isExpression(char**);
bool isTerm(char**);
bool isMultiplier(char**);
bool isNumber(char**);
bool isDigit(char**);
bool isLetter(char**);
bool isIdent(char**);
bool isEmpty(std::ifstream& pFile);

int main()
{
	setlocale(LC_ALL, "rus");
	int count = 1;
	std::string numberLine;
	try {
		std::ifstream file("input.txt");
		if (!file)
		{
			throw std::exception("Ошибка чтения файла!");
			return 1;
		}
		if (isEmpty(file))
		{
			throw std::exception("Файл пуст!");
			return 1;
		}
		std::getline(file, numberLine);
		int size = atoi(numberLine.c_str());
		while (!file.eof())
		{
			char* symbol = new char[size + 1];
			file.getline(symbol, size);
			char* tempSymbol = symbol;
			std::cout << count << ". " << (isExpression(&symbol) && *symbol == '\0' ? "Да" : "Нет") << "\n";
			symbol = tempSymbol;
			count++;
			delete[] symbol;
		}
		file.close();
	}
	catch (const std::exception& error)
	{
		std::cerr << error.what() << std::endl;
		return 1;
	}
	return 0;
}

bool isLetter(char** symbol)
{
	if ((**symbol >= 'a') && (**symbol <= 'e'))
	{
		*symbol = *symbol + 1;
		return true;
	}
	return false;
}

bool isDigit(char** symbol)
{
	if (**symbol >= '0' && **symbol <= '9')
	{
		*symbol = *symbol + 1;
		return true;
	}
	return false;
}

bool isNumber(char** symbol)
{
	if (isDigit(symbol))
	{
		isNumber(symbol);
		return true;
	}
	return false;
}

bool isMultiplier(char** symbol)
{
	if (isIdent(symbol))
		return true;
	else if (isNumber(symbol))
		return true;
	return false;
}

bool isTerm(char** symbol)
{
	if (isMultiplier(symbol))
	{
		if (**symbol == '*')
		{
			*symbol = *symbol + 1;
			return isTerm(symbol);
		}
		return true;
	}
	return false;
}

bool isIdent(char** symbol)
{
	if (isLetter(symbol))
		return true;
	return false;
}

bool isExpression(char** symbol)
{
	if (isTerm(symbol))
	{
		if (**symbol == '+' || **symbol == '-')
		{
			*symbol = *symbol + 1;
			return isExpression(symbol);
		}
		return true;
	}
	return false;
}

bool isEmpty(std::ifstream& pFile)
{
	return pFile.peek() == std::ifstream::traits_type::eof();
}