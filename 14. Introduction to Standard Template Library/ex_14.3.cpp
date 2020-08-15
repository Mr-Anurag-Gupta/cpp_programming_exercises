/**
 * Write a program using count() algorithm to locate the position of a specified 
 * value in a sequence container.
*/

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 4, 3, 7, 8, 9, 10};

    int target1 = 4;
    int target2 = 7;
    int num_items1 = std::count(std::begin(v), std::end(v), target1);
    int num_items2 = std::count(std::begin(v), std::end(v), target2);

    std::cout << "number: " << target1 << " count: " << num_items1 << '\n';
    std::cout << "number: " << target2 << " count: " << num_items2 << '\n';

    return EXIT_SUCCESS;
}