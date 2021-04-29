#ifndef CLASS_NODES_H
#define CLASS_NODES_H

class Test
{
private:
    struct Node
    {
        double value;
        Node *nextNode = nullptr;
    };

    Node* head = nullptr;

public:
    Test(double num);
    void insertNode(double num);
    void deleteNode(double num);
    void showList(int index) const;
    void showAllNodes() const;

    // destructor
    ~Test();

};

#endif // !CLASS_NODES_HEADER
