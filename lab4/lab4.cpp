#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)

int count = 0;

char* functionC(char* destination, const char* text, const int number)
{
	int temp = 0;
	for (int i = 0; i < number; i++)
	{
		if ((text[i] == ' ') && (i == 0))
		{
			while (temp != 0)
			{
				i++;
				temp++;
			}
		}
		if ((text[i] == ' ') && (i != 0))
		{
			if (text[i + 1] == ' ')
				while (text[i] != ' ')
				{
					i++;
					temp++;
				}

			if (text[i + 1] != ' ')
			{
				destination[temp] = text[i];
				temp++;
				count++;
			}
		}
		else
		{
			destination[temp] = text[i];
			temp++;
			count++;
		}
	}
	return destination;
}

std::string functionString(const std::string& text)
{
	std::string ans;
	for (int i = 0; i < text.size(); i++)
	{
		ans += text[i];
	}
	return ans;
}

int main()
{
	{
		freopen("input.txt", "r", stdin);
		int number;
		std::cin >> number;
		number++;
		char* text = new char[number];
		getc(stdin);
		gets_s(text, number);
		char* result = new char[number];
		result = functionC(result, text, number);
		fclose(stdin);

		std::cout << result;

		freopen("output.txt", "w", stdout);
		for (int i = 0; i < count; i++)
		{
			if (result[i] != '\0')
			{
				std::cout << result[i];
			}
		}
		fclose(stdout);
	}

	// вывод через string

	{
		std::ifstream inFile;
		std::string word;
		std::vector <std::string> array;
		std::string text, ans;
		std::string fileT = "input2.txt";
		inFile.open(fileT);
		while (!(inFile.eof()))
		{
			std::getline(inFile, text);
			std::stringstream ss(text);
			while (ss >> word)
			{
				array.push_back(word);
			}
			freopen("output2.txt", "w", stdout);
			for (int i = 0; i < array.size(); i++)
			{
				ans = functionString(array[i]);
				if (i < array.size() - 1)
					std::cout << ans << " ";
				if (i == array.size() - 1)
					std::cout << ans << std::endl;
			}
		}
		inFile.close();
		fclose(stdout);
	}
	return 0;
}