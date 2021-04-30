#include "ClassNodes.h"
#include <iostream>
#include <thread>
#include <fstream>
#include <Windows.h>
#include <vector>

int main()
{
    Test test;

    std::thread th;
    std::vector<std::thread> threads;
    std::ifstream inputFile;

    inputFile.open("numbers.txt");

    if (!inputFile)
    {
        std::cout << "No input file";
        for (int i = 0; i < 3; i++)
        {
            Sleep(200);
            std::cout << ".";
        }
        Sleep(300);
        std::cout << " getting input from the user" << std::endl << std::endl;
        Sleep(200);

        const int NODE_SIZE = 6;
        double userValue;

        for (int i = 1; i < NODE_SIZE; i++)
        {
            std::cout << "Enter your #" << i << " value: ";
            std::cin >> userValue;
            threads.push_back(std::thread(&Test::insertNode, std::ref(test), userValue));
        }
    }
    else
    {
        double fileValue;
        while (!inputFile.eof())
        {
            inputFile >> fileValue;
            threads.push_back(std::thread(&Test::insertNode, std::ref(test), fileValue));
        }
    }

    for (std::thread& thread : threads)
        thread.join();

    test.showAllNodes();
}