#ifndef BSTREEINT_H
#define BSTREEINT_H

#include <string>

class BSTreeInt
{
    private:

    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int aData, Node* aLeft, Node* aRight)
        : data(aData), left(aLeft), right(aRight)
        {
        }
    };

    Node* root;
    int counter;

    void eraseLeaf(Node* curr, Node* prev, bool isLeft);
    void eraseNodeWithOneChild(Node* curr, Node* prev, bool isLeft);
    void eraseNodeWithTwoChildren(Node* curr);

    public:

    #ifdef AUCA_DEBUG
    std::string path;
    #endif

    BSTreeInt()
    : root(nullptr), counter(0)
    {
    }

    int size() const
    {
        return counter;
    }

    bool insert(int k);
    bool find(int k);
    bool erase(int k);
};

#endif
