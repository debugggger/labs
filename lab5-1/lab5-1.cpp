#include <iostream>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)

int check1(int row, int column, int** arr);
int check2(int* const* arr, const int& size);
void task1();
void task2();

int main()
{
    setlocale(LC_ALL, "ru");
    task1();
    std::cout << std::endl;
    task2();
    return 0;
}

void task1()
{
    const int row = 6;
    const int column = 6;
    int matrix[column][row]
    {
        {4,5,2,6,3,0},
        {5,2,6,2,8,12},
        {34,12,8,0,3,1},
        {4,0,23,1,6,2},
        {45,23,2,9,5,3},
        {4,7,3,9,6,24}
    };
    int* staticArrPtr[row] = { 0 };
    std::cout << "Задана матрица:" << std::endl;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        staticArrPtr[i] = matrix[i];
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << "Количество строк без 0: "
        << check1(row, column, &staticArrPtr[0]) << std::endl;
}

void task2()
{
    freopen("input2.txt", "r", stdin); // тестовая матрица сячейками, заполненными "5" - "input.txt"
    int size;
    std::cin >> size;
    int** doubleArray = new int* [size];
    for (int i = 0; i < size; i++)
    {
        doubleArray[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> doubleArray[i][j];
        }
    }
    fclose(stdin);
    freopen("output.txt", "w", stdout);
    std::cout << "Задана матрица: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << doubleArray[i][j] << "\t";
        }
        std::cout << '\n';
    }
    std::cout << std::endl;
    std::cout << "Количество седловых точек матрицы: " << check2(doubleArray, size);
    fclose(stdout);
}

int check1(int row, int column, int** arr)
{
    int count = 0;
    int nullLine = 0;
    for (int i = 0; i < column; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (arr[i][j] != 0)
                count++;
        }
        if (count == row)
        {
            nullLine++;
        }
        count = 0;
    }
    return nullLine;
}

int check2(int* const* arr, const int& size)
{
    int count = 0;
    int maxColumn = 0;
    int minRow = 0;
    bool changeCol = 0;
    bool changeRow = 0;
    std::cout << "Позиции седловых точек: " << std::endl;
    for (int i = 0; i < size; i++)
    {
        minRow = arr[i][0];
        for (int c = 0; c < size; c++)
        {
            if (arr[i][c] != arr[i][0])
            {
                changeRow = 1;
            }
            if (arr[i][c] < arr[i][0])
            {
                minRow = arr[i][c];
            }
        }
        for (int j = 0; j < size; j++)
        {
            maxColumn = arr[0][j];
            for (int r = 0; r < size; r++)
            {
                if (arr[r][j] != arr[0][j])
                {
                    changeCol = 1;
                }
                if (arr[r][j] > arr[0][j])
                {
                    maxColumn = arr[r][j];
                }
            }
            if (arr[i][j] < minRow)
            {
                for (int k = 0; k < size; k++)
                {
                    if (arr[i][k] < arr[i][j])
                    {
                        minRow = arr[i][k]; // минимальный элемент в строке
                    }
                }
            }
            if (arr[i][j] > maxColumn)
            {
                for (int k = 0; k < size; k++)
                {
                    if (arr[k][j] > arr[i][j])
                    {
                        maxColumn = arr[k][j]; // максимальный элемент в строке
                    }
                }
            }
            if ((minRow == maxColumn) && (changeRow == 1) && (changeCol == 1))
            {
                count++;
                std::cout << i << ":" << j << std::endl;
            }
        }
        changeRow = 0;
        changeCol = 0;
    }
    std::cout << std::endl;
    return count;
}