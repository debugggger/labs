#pragma once
#ifndef SORT_H
#define SORT_H

template <typename T> void sort(T& array, const int size)
{
	int i = 0;
	int j = 0;
	auto temp = array[0];
	for (i = 1; i < size; i++)
	{
		temp = array[i];
		j = i - 1;
		while (j > -1 && array[j] > temp)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = temp;
	}
}
#endif