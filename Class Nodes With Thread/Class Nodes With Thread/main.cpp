#include "ClassNodes.h"
#include <iostream>

int main()
{
    Test test(2);

    const int NODE_SIZE = 6;
    double userValue;

    for (int i = 1; i < NODE_SIZE; i++)
    {
        std::cout << "Enter your #" << i << " value: ";
        std::cin >> userValue;
        test.insertNode(userValue);
    }

    test.showAllNodes();

}