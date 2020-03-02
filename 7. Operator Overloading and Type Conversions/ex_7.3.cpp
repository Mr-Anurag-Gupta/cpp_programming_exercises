
#include <iostream>
#include <cassert>

class MAT
{
private:
    int rows;
    int cols;
    int **mat;

public:
    MAT() : rows(0), cols(0), mat(nullptr) {}
    MAT(int rows, int cols);
    MAT(int rows, int cols, int **arr) : rows(rows), cols(cols) { initMatrix(arr); }

    // Basic Operations.
    int getElement(int row, int col) { return mat[row][col]; }
    void putElement(int row, int col, int value) { mat[row][col] = value; }
    void initMatrix(int **);
    void display();

    // Overloaded operators.
};

void MAT::initMatrix(int **arr)
{
    // Allocate space
    mat = new int *[rows];
    if (mat == nullptr)
    {
        std::cerr << "Allocation failed." << std::endl;
        exit(0);
    }

    for (auto i = 0; i < rows; i++)
        mat[i] = new int[cols];

    for (auto i = 0; i < rows; i++)
        for (auto j = 0; j < cols; j++)
            mat[rows][cols] = *(*(arr + i) + j);
}

void MAT::display()
{
    for (auto i = 0; i < rows; i++)
    {
        for (auto j = 0; j < cols; j++)
            std::cout << mat[rows][cols] << " ";
        std::cout << std::endl;
    }
}

int main()
{
    const int rows = 2, cols = 3;
    MAT m(rows, cols);

    int arr[rows][cols] = {
        {1, 2, 3},
        {4, 5, 6}};
    m.initMatrix((int **)arr);
    m.display();

    return EXIT_SUCCESS;
}
