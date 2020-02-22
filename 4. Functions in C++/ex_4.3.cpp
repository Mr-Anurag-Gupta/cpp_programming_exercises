/*
 * Problem 4.3:
 *  Rewrite the program of Exercise 4.2 to make the row
 *  parameter of the matrix as a default.
*/

#include <iostream>

void getMatrixSizes(int &, int &);
void getMatrixSizes(int &n);
void readAMatrix(int mat[], const int, const int = 2);
void printMatrix(int[], const int, const int = 2);

int main()
{
    int m = 2, n;
    getMatrixSizes(n);

    int *mat = new int[m * n];
    readAMatrix(mat, n);

    printMatrix(mat, n);

    delete[] mat;
    return EXIT_SUCCESS;
}

void getMatrixSizes(int &m, int &n)
{
    std::cout << "Please enter following details:" << std::endl;
    std::cout << "No. of rows (m): ";
    std::cin >> m;
    std::cout << "No. of columns (n): ";
    std::cin >> n;
}

void getMatrixSizes(int &n)
{
    std::cout << "Please enter following details:" << std::endl;
    std::cout << "No. of columns (n): ";
    std::cin >> n;
}

void readAMatrix(int mat[], const int col, const int row)
{
    std::cout << "Enter the matrix (use space for separation): " << std::endl;

    for (auto r = 0; r < row; r++)
        for (auto c = 0; c < col; c++)
            std::cin >> mat[r * col + c];
}

void printMatrix(int mat[], const int col, const int row)
{
    for (auto r = 0; r < row; r++)
    {
        for (auto c = 0; c < col; c++)
        {
            std::cout << mat[r * col + c] << " ";
        }
        std::cout << std::endl;
    }
}