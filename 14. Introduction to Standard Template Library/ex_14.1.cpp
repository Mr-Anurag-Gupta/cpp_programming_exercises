/*
 * Write a code segment that does the following:
 * (a) Define a vector v with maximum size of 10.
 * (b) Sets the first element of v to 0.
 * (c) Sets the last element of v to 9.
 * (d) Sets the other elements to 1.
 * (e) Displays the content of v.
*/

#include <iostream>
#include <vector>

int main()
{
    // vector of size 10.
    std::vector<int> v(10);

    // insert 0 at front.
    v.front() = 0;

    // insert 9 at back.
    v.back() = 9;

    // initialize rests to 1;
    for (int i = 1; i < 9; i++)
        v[i] = 1;

    // display the vector elements.
    for (auto it = v.begin(); it != v.end(); ++it)
        std::cout << *it << ' ';
    std::cout << '\n';

    return EXIT_SUCCESS;
}