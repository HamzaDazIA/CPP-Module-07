#include "iter.hpp"


void addOne(int &x)
{
    x += 1;
}

void printElement(const int &x)
{
    std::cout << x << std::endl;
}
void toUpperCase(char &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - ('a' - 'A');
}

void toLowerCase(char &c)
{
    if (c >= 'A' && c <= 'Z')
        c = c + ('a' - 'A');
}

int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    const unsigned int intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original integer array:" << std::endl;
    iter(intArray, intArrayLength, printElement);

    iter(intArray, intArrayLength, addOne);

    std::cout << "Integer array after adding one to each element:" << std::endl;
    iter(intArray, intArrayLength, printElement);

    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    const unsigned int charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Original character array:" << std::endl;
    iter(charArray, charArrayLength, printElement);

    iter(charArray, charArrayLength, toUpperCase);

    std::cout << "Character array after converting to uppercase:" << std::endl;
    iter(charArray, charArrayLength, printElement);

    iter(charArray, charArrayLength, toLowerCase);

    std::cout << "Character array after converting back to lowercase:" << std::endl;
    iter(charArray, charArrayLength, printElement);

    return 0;
}