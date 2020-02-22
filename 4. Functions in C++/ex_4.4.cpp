/*
 * Problem 4.4:
 *  The effect of default argument can be achieved by overloading.
 *  Discuss with an example.
*/

#include <iostream>

void getMatrixSizes(int &, int &);
void readAMatrix(int mat[], const int, const int);
void printMatrix(int[], const int, const int);

void readAMatrix(int mat[], const int);
void printMatrix(int[], const int);
void getMatrixSizes(int &);

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

void readAMatrix(int mat[], const int m, const int n)
{
    std::cout << "Enter the matrix (use space for separation): " << std::endl;

    for (auto r = 0; r < m; r++)
        for (auto c = 0; c < n; c++)
            std::cin >> mat[r * n + c];
}

void readAMatrix(int mat[], const int n)
{
    const int m = 2;

    std::cout << "Enter the matrix (use space for separation): " << std::endl;

    for (auto r = 0; r < m; r++)
        for (auto c = 0; c < n; c++)
            std::cin >> mat[r * n + c];
}

void printMatrix(int mat[], const int m, const int n)
{
    for (auto r = 0; r < m; r++)
    {
        for (auto c = 0; c < n; c++)
        {
            std::cout << mat[r * n + c] << " ";
        }
        std::cout << std::endl;
    }
}

void printMatrix(int mat[], const int n)
{
    const int m = 2;

    for (auto r = 0; r < m; r++)
    {
        for (auto c = 0; c < n; c++)
        {
            std::cout << mat[r * n + c] << " ";
        }
        std::cout << std::endl;
    }
}