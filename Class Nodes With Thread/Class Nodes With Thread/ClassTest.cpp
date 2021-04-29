#include "ClassNodes.h"
#include <iostream>

//
// Test constructor
//
Test::Test(double num)
{
    Node* node = new Node;
    
    node->nextNode = nullptr;
    node->value = num;

    head = node;
}

//
// Inserts a node on a list depending on the value passed into the function
//
void Test::insertNode(double num)
{
    Node* newNode = new Node;
    Node* nodePtr;
    Node* previousNodePtr = nullptr;

    nodePtr = head;

    while (nodePtr && nodePtr->value < num)
    {
        previousNodePtr = nodePtr;
        nodePtr = nodePtr->nextNode;
    }

    if (previousNodePtr)
    {
        newNode->value = num;
        newNode->nextNode = nodePtr;
        previousNodePtr->nextNode = newNode;
    }
    else
    {
        newNode->value = num;
        newNode->nextNode = head;
        head = newNode;
    }
}

//
// Deletes a node containing a numbers
//
void Test::deleteNode(double num)
{
    Node* nodePtr = head;
    Node* previousNodePtr = nullptr;

    while (nodePtr)
    {
        if (nodePtr->value == num)
        {
            if (previousNodePtr)
            {
                previousNodePtr->nextNode = nodePtr->nextNode;
            }
            else
            {
                head = nodePtr->nextNode;

            }
            delete nodePtr;
            break;
        }
        else
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->nextNode;
        }
    }
    
}

//
// Shows all the nodes and their values
//
void Test::showAllNodes() const
{
    Node* nodePtr = head;

    while (nodePtr)
    {
        std::cout << nodePtr->value << ", ";
        nodePtr = nodePtr->nextNode;
    }
}

//
// Deletes all the nodes
// 
Test::~Test()
{
    Node* nextNodePtr = head->nextNode;
    while (nextNodePtr)
    {
        delete head;
        head = nextNodePtr;
        nextNodePtr = nextNodePtr->nextNode;
    }
    delete nextNodePtr;
}