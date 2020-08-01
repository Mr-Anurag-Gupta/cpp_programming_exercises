/**
 * Write a program that uses catch handler
*/

#include <iostream>
#include <exception>

void illustrate_mul_catch(int i)
{
    try
    {
        if (i == 1)
        {
            throw i;
        }
        else if (i == 0)
        {
            throw "i is 0.";
        }
        else
        {
            throw std::exception();
        }
    }
    catch (int)
    {
        std::cout << "Exception caught: i is 1\n";
    }
    catch (const char *error)
    {
        std::cout << "Exception caught: " << error << '\n';
    }
    catch (...)
    {
        std::cout << "Unknown exception caught\n";
    }
}

int main()
{
    illustrate_mul_catch(0);
    illustrate_mul_catch(1);
    illustrate_mul_catch(2);
    return EXIT_SUCCESS;
}