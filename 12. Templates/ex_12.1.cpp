/**
 * Write a function template for finding the minimum value contained in an array.
*/
#include <iostream>

template <class T>
T min(T a[], int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (a[i] < min)
            min = a[i];
    }

    return min;
}

int main()
{
    constexpr int size = 5;
    int arr[size] = {3, 4, 5, 2, -1};
    std::cout << "min: " << min<int>(arr, size) << '\n';
    return EXIT_SUCCESS;
}