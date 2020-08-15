/**
 * Create an array with even numbers and a list with odd numbers.
 * Merge two sequences of numbers into a vector using the algorithm merge().
 * Display the vector.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <array>

template <class T>
void display(const std::vector<T> &v)
{
    for (auto it = v.begin(); it != v.end(); it++)
        std::cout << *it << " ";
    std::cout << '\n';
}

int main()
{
    // array of even numbers
    std::array<int, 5> even{0, 2, 4, 6, 8};

    // list of odd numbers
    std::list<int> odd{1, 3, 5, 7, 9};

    // merged vector
    std::vector<int> result(10);

    // merge the array and list into vector
    std::merge(even.begin(), even.end(), odd.begin(), odd.end(), result.begin());

    // output
    display(result);

    return EXIT_SUCCESS;
}