
#include <iostream>
#include <cassert>
#include <exception>

class MAT
{
private:
    int rows;
    int cols;
    int **mat;
    void allocateSpace();

public:
    MAT() : rows(0), cols(0), mat(nullptr){};
    MAT(int rows, int cols) : rows(rows), cols(cols){};
    MAT(int rows, int cols, int *arr);

    // Basic Operations.
    int getElement(int row, int col) { return mat[row][col]; }
    void putElement(int row, int col, int value) { mat[row][col] = value; }
    void initMatrix(int *);
    void display();

    // Overloaded operators. (<object> <(+|-|*|/|)> <value>)
    void operator*(int);
    void operator+(int);
    void operator/(int);
    void operator-(int);

    // Returns the resultant matrix after the operation is performed.
    MAT operator+(const MAT &);
    MAT operator*(const MAT &);
    MAT operator/(const MAT &);
    MAT operator-(const MAT &);

    friend void operator*(int, MAT &);
    friend void operator+(int, MAT &);
    friend void operator/(int, MAT &);
    friend void operator-(int, MAT &);
};

MAT::MAT(int rows, int cols, int *arr)
{
    this->rows = rows;
    this->cols = cols;
    allocateSpace();
    initMatrix(arr);
}

void MAT::allocateSpace()
{
    // Allocate space
    try
    {
        mat = new int *[rows];
        for (auto i = 0; i < rows; i++)
            mat[i] = new int[cols];
    }
    catch (std::bad_alloc ex)
    {
        std::cerr << "bad_alloc: " << ex.what() << std::endl;
    }
}

void MAT::initMatrix(int *arr)
{
    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            mat[i][j] = *(arr + i * cols + j);
}

void MAT::display()
{
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
            std::cout << mat[i][j] << " ";
        std::cout << std::endl;
    }
}

void MAT::operator*(int value)
{
    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            mat[i][j] *= value;
}

void MAT::operator+(int value)
{
    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            mat[i][j] += value;
}

void MAT::operator/(int value)
{
    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            mat[i][j] /= value;
}

void MAT::operator-(int value)
{
    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            mat[i][j] -= value;
}

void operator*(int value, MAT &m)
{
    for (auto i = 0; i < m.rows; i++)
        for (auto j = 0; j < m.cols; j++)
            m.mat[i][j] *= value;
}

void operator+(int value, MAT &m)
{
    for (auto i = 0; i < m.rows; i++)
        for (auto j = 0; j < m.cols; j++)
            m.mat[i][j] += value;
}

void operator/(int value, MAT &m)
{
    for (auto i = 0; i < m.rows; i++)
        for (auto j = 0; j < m.cols; j++)
            m.mat[i][j] /= value;
}

void operator-(int value, MAT &m)
{
    for (auto i = 0; i < m.rows; i++)
        for (auto j = 0; j < m.cols; j++)
            m.mat[i][j] -= value;
}

MAT MAT::operator+(const MAT &m1)
{
    assert(rows == m1.rows);
    assert(cols == m1.cols);

    MAT m3(rows, cols);
    m3.allocateSpace();

    for (auto i = 0; i < m3.rows; i++)
        for (auto j = 0; j < m3.cols; j++)
            m3.mat[i][j] = mat[i][j] + m1.mat[i][j];

    return m3;
}

MAT MAT::operator-(const MAT &m1)
{
    assert(rows == m1.rows);
    assert(cols == m1.cols);

    MAT m3(rows, cols);
    m3.allocateSpace();

    for (auto i = 0; i < m3.rows; i++)
        for (auto j = 0; j < m3.cols; j++)
            m3.mat[i][i] = mat[i][j] - m1.mat[i][j];

    return m3;
}

MAT MAT::operator/(const MAT &m1)
{
    assert(rows == m1.rows);
    assert(cols == m1.cols);

    MAT m3(rows, cols);
    m3.allocateSpace();

    for (auto i = 0; i < m3.rows; i++)
        for (auto j = 0; j < m3.cols; j++)
            m3.mat[i][i] = mat[i][j] / m1.mat[i][j];

    return m3;
}

MAT MAT::operator*(const MAT &m1)
{
    // For matrix multiplications, (col of one matrix)
    // should be == (row of other matrix).
    assert(cols == m1.rows);

    MAT m3(rows, m1.cols);
    m3.allocateSpace();

    int sum;
    for (auto i = 0; i < rows; i++)
    {
        sum = 0;
        for (auto j = 0; j < m1.cols; j++)
        {
            for (auto k = 0; k < m1.rows; k++)
                sum += mat[i][k] * m1.mat[k][j];
            m3.mat[i][j] = sum;
        }
    }

    return m3;
}

int main()
{
    const int rows = 2, cols = 3;
    int m1_arr[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6}};
    int m2_arr[cols][rows] = {
        {1, 2},
        {3, 4},
        {5, 6}};

    MAT m1(rows, cols, (int *)m1_arr);
    MAT m2(cols, rows, (int *)m2_arr);
    MAT m3;
    MAT m4(rows, cols, (int *)m1_arr);

    std::cout << "\nm1:" << std::endl;
    m1.display();

    std::cout << "\nm2:" << std::endl;
    m2.display();

    std::cout << "\nm4:" << std::endl;
    m4.display();

    // Test cases.
    std::cout << "\n(*):" << std::endl;
    m1 * 2;
    m1.display();

    std::cout << "\n(/):" << std::endl;
    m1 / 2;
    m1.display();

    std::cout << "\n(-):" << std::endl;
    m1 - 1;
    m1.display();

    std::cout << "\n(+):" << std::endl;
    m1 + 1;
    m1.display();

    std::cout << "\n(m1 * m2):" << std::endl;
    m3 = m1 * m2;
    m3.display();

    std::cout << "\n(m1 + m4):" << std::endl;
    m3 = m1 + m4;
    m3.display();

    std::cout << "\n(m1 - m4):" << std::endl;
    m3 = m1 - m4;
    m3.display();

    std::cout << "\n(m1 / m4):" << std::endl;
    m3 = m1 / m4;
    m3.display();

    return EXIT_SUCCESS;
}
