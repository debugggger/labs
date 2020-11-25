#include <iostream>
#include <fstream>
#include <string>
#pragma warning(disable : 4996)

int check1(int row, int column, int** arr);
int check2(int* const* arr, const int& size);
void task1();
void task2();
int setMinRow(const int size, int* const* arr, int i);
int setMaxCol(const int size, int* const* arr, int j);
int MaxMin(const int size, int* const* arr, int i, int j);

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
    bool fileOK = 1;
    freopen("input2.txt", "r", stdin); // тестовая матрица с ячейками, заполненными "5" - "input.txt"
    int size;
    if (!(std::cin >> size))
    {
        fileOK = 0;
    }
    else
        fileOK = 1;
    int** doubleArray = new int* [size];
    for (int i = 0; i < size; i++)
    {
        doubleArray[i] = new int[size];
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!(std::cin >> doubleArray[i][j]))
            {
                fileOK = 0;
            }
            else
            {
                fileOK = 1;
            }
        }
    }
    fclose(stdin);
    freopen("output.txt", "w", stdout);
    if (fileOK == 1)
    {
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
    }
    else
        std::cout << "В исходном файле содержаться не корректные значения!";
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


int maxColumn = 0;
int minRow = 0;
bool changeCol = 0;
bool changeRow = 0;
int check2(int* const* arr, const int& size)
{
    int count = 0;
    std::cout << "Позиции седловых точек: " << std::endl;
    for (int row = 0; row < size; row++)
    {
        setMinRow(size, arr, row);
        for (int col = 0; col < size; col++)
        {
            setMaxCol(size, arr, col);
            MaxMin(size, arr, row, col);
            if ((minRow == maxColumn) && (changeRow == 1) && (changeCol == 1))
            {
                count++;
                std::cout << row << ":" << col << std::endl;
            }
        }
        changeRow = 0;
        changeCol = 0;
    }
    std::cout << std::endl;
    return count;
}

int setMinRow(const int size, int* const* arr, int row)
{
    minRow = arr[row][0];
    for (int j = 0; j < size; j++)
    {
        if (arr[row][j] != arr[row][0])
        {
            changeRow = 1;
        }
        if (arr[row][j] < arr[row][0])
        {
            minRow = arr[row][j];
        }
    }
    return 0;
}

int setMaxCol(const int size, int* const* arr, int col)
{
    maxColumn = arr[0][col];
    for (int i = 0; i < size; i++)
    {
        if (arr[i][col] != arr[0][col])
        {
            changeCol = 1;
        }
        if (arr[i][col] > arr[0][col])
        {
            maxColumn = arr[i][col];
        }
    }
    return 0;
}

int MaxMin(const int size, int* const* arr, int row, int col)
{
    if (arr[row][col] < minRow)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[row][j] < arr[row][col])
            {
                minRow = arr[row][j]; // минимальный элемент в строке
            }
        }
    }
    if (arr[row][col] > maxColumn)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i][col] > arr[row][col])
            {
                maxColumn = arr[i][col]; // максимальный элемент в столбце
            }
        }
    }
    return 0;
}