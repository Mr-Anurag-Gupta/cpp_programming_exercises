/*
 * Refer Program 5.1 and write a function that receives two matrix objects
 * as arguments and returns a new matrix object containing their multiplication
 * result.
*/

#include <iostream>
#include <iomanip>

class Matrix
{
private:
    int **m;
    int rows, cols;

public:
    Matrix()
    {
        rows = 0;
        cols = 0;
    };
    Matrix(int, int);
    void allocateMemory();
    void read(int *);
    void display();
    friend Matrix addMatrices(Matrix &, Matrix &);
};

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    allocateMemory();
}

void Matrix::allocateMemory()
{
    try
    {
        m = new int *[rows];
        for (auto i = 0; i < rows; i++)
            m[i] = new int[cols];
    }
    catch (std::bad_alloc &ex)
    {
        std::cerr << "\nbad_alloc caught: " << ex.what() << std::endl;
    }
}

void Matrix::display()
{
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
            std::cout << std::setw(5) << m[i][j];
        std::cout << '\n';
    }
}

void Matrix::read(int *array)
{
    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            m[i][j] = *(array + i * cols + j);
}

Matrix addMatrices(Matrix &m1, Matrix &m2)
{
    Matrix m3 = Matrix(m1.rows, m2.cols);

    for (auto i = 0; i < m1.rows; i++)
        for (auto j = 0; j < m2.cols; j++)
            for (auto k = 0; k < m2.rows; k++)
                m3.m[i][j] += m1.m[i][k] * m2.m[k][j];

    return m3;
}

int main()
{
    int A[2][2] = {
        {2, 1},
        {1, 2}};

    int B[3][1] = {
        {2},
        {0}};

    Matrix m1(2, 2);
    Matrix m2(2, 1);

    m1.read((int *)A);
    m2.read((int *)B);

    std::cout << "m1\n";
    m1.display();
    std::cout << "m2\n";
    m2.display();

    Matrix m3 = addMatrices(m1, m2);
    std::cout << "m3\n";
    m3.display();

    return EXIT_SUCCESS;
}