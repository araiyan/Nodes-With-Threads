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
    void insertNode(double num);
    void deleteNode(double num);
    void showNode(int index) const;
    void showAllNodes() const;

    // destructor
    ~Test();

};

#endif // !CLASS_NODES_HEADER
