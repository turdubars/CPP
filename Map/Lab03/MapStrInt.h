#ifndef MAPSTRINT_H
#define MAPSTRINT_H

#include <string>
#include <utility>

class MapStrInt
{
    public:
    
    MapStrInt()
    : root(nullptr), length(0)
    {
    }
    
    ~MapStrInt()
    {
        clear();
    }
    
    int& operator[](const std::string& k);
    
    void printInOrder() const;
    
    void clear();
    
    int size() const
    {
        return length;
    }
    
    private:
    
    struct Node
    {
        std::pair<std::string, int> data;
        Node* left;
        Node* right;
        
        Node(const std::string& k, int v, Node* aLeft, Node* aRight)
        : data(k, v), left(aLeft), right(aRight)
        {
        }
    };
    
    struct StackFrame
    {
        const Node* node;
        int count;
        StackFrame(Node* aNode, int aCount)
        : node(aNode), count(aCount)
        {
        }
    };

    Node* root;
    int length;
};

#endif