/*
 * Problem 4.1:
 *  Write a function to read a matrix m x n from
 *  the keyboard.
*/

#include <iostream>

void getMatrixSizes(int &m, int &n);
void readAMatrix(int mat[], const int, const int);

int main()
{
    int m, n;
    getMatrixSizes(m, n);

    int *mat = new int[m * n];
    readAMatrix(mat, m, n);

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

void readAMatrix(int mat[], const int m, const int n)
{
    std::cout << "Enter the matrix (use space for separation): " << std::endl;

    for (auto r = 0; r < m; r++)
        for (auto c = 0; c < n; c++)
            std::cin >> mat[c + r * m];
}