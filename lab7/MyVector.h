#ifndef MyVector_H
#define MyVector_H
#pragma once

template <class T>
class MyVector
{
private:
	T* array;
	int arrayLength;
	int arraySize;
public:
	MyVector()
	{
		array = new T[1];
		arraySize = 1;
		arrayLength = 0;
	}

	~MyVector()
	{
		delete[] array;
	}

	int size()
	{
		return arrayLength;
	}

	T& operator[](int i)
	{
		return *(array + i);
	}

	void push_back(T elem)
	{
		if (arraySize > arrayLength)
		{
			array[arrayLength] = elem;
			arrayLength++;
		}
		else
		{
			T* newArray = new T[arraySize * 2];
			int i;
			for (i = 0; i < arraySize; i++)
			{
				newArray[i] = array[i];
			}
			newArray[i] = elem;
			arrayLength++;
			arraySize *= 2;
			delete[] array;
			array = newArray;
		}
	}
};
#endif