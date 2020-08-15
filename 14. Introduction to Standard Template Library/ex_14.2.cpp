/**
 * Write a program using find() algorithm to locate the position of a specified 
 * value in a sequence container.
*/

#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1, 2, 3, 45, 6, 7};

    auto result = std::find(std::begin(v), std::end(v), 6);

    if (result != std::end(v))
        std::cout << "value is found: " << *result << "\n";
    else
        std::cout << "value is not found.\n";

    return EXIT_SUCCESS;
}