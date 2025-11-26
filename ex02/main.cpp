#include <iostream>
#include "Array.hpp"

int main()
{
    std::cout << "=== Test 1: Default Constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    std::cout << "\n=== Test 2: Parametric Constructor ===" << std::endl;
    Array<int> arr(5);
    std::cout << "Array size: " << arr.size() << std::endl;

    std::cout << "\n=== Test 3: Operator[] (set values) ===" << std::endl;
    for (unsigned int i = 0; i < arr.size(); i++)
    {
        arr[i] = i * 10;
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    std::cout << "\n=== Test 4: Copy Constructor ===" << std::endl;
    Array<int> copy(arr);
    std::cout << "Copy size: " << copy.size() << std::endl;
    std::cout << "Copy values: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 5: Assignment Operator ===" << std::endl;
    Array<int> assigned;
    assigned = arr;
    std::cout << "Assigned size: " << assigned.size() << std::endl;
    std::cout << "Assigned values: ";
    for (unsigned int i = 0; i < assigned.size(); i++)
        std::cout << assigned[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 6: Deep Copy Verification ===" << std::endl;
    arr[0] = 999;
    std::cout << "Original arr[0]: " << arr[0] << std::endl;
    std::cout << "Copy arr[0]: " << copy[0] << std::endl;
    std::cout << "Assigned arr[0]: " << assigned[0] << std::endl;

    std::cout << "\n=== Test 7: Out of Bounds Exception ===" << std::endl;
    try
    {
        std::cout << "Accessing arr[10]..." << std::endl;
        arr[10] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Accessing arr[-1]..." << std::endl;
        arr[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Different Types ===" << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "!";
    std::cout << "String array: ";
    for (unsigned int i = 0; i < strArr.size(); i++)
        std::cout << strArr[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}