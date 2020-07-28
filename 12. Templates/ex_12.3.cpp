/*
 * Write a function template to perform a linear search in an array.
*/
#include <iostream>

template <class T>
void linear_search(T arr[], int size, T search_val)
{
    bool is_found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search_val)
            is_found = true;
    }
    if (is_found)
        std::cout << search_val << " is present in the array.\n";
    else
        std::cout << search_val << " is not present in the array.\n";
}

int main(void)
{
    constexpr int size = 3;

    // integer array.
    int arr_int[size] = {10, 20, 30};

    // found case.
    linear_search<int>(arr_int, size, 10);

    // not found case.
    linear_search<int>(arr_int, size, 40);

    // character array.
    char arr_char[size] = {'a', 'b', 'c'};

    // found case.
    linear_search<char>(arr_char, size, 'a');

    // not found case.
    linear_search<char>(arr_char, size, 'd');

    return EXIT_SUCCESS;
}