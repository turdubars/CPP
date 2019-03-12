#ifndef LISTINT_H
#define LISTINT_H

#include <string>

class ListInt
{
    private:

    struct Node
    {
        int data;
        Node* prev;
        Node* next;
        
        Node(int aData, Node* aPrev, Node* aNext)
        : data(aData), prev(aPrev), next(aNext)
        {
        }
    };    
    
    Node* head;
    Node* tail;
    int length;
    
    
    void insertNode(Node* p, int x);
    
    public:
    
    ListInt();
    
    int size() const
    {
        return length;
    }
    
    std::string toStr() const;
    
    void pushBack(int x)
    {
        insertNode(tail, x);
    }
    
    
    class Iter
    {
        friend class ListInt;
        
        private:
        
        Node* p;
        
        Iter(Node* aP): p(aP) {}
        
        public:
        
        Iter& operator++()
        {
            p = p->next;
            return *this;
        }
        
        Iter& operator--()
        {
            p = p->prev;
            return *this;
        }
        
        int& operator*() const 
        {
            return p->data;
        }
        
        bool operator==(const Iter& other) const
        {
            return (*this).p == other.p;
        }
        
        bool operator!=(const Iter& other) const
        {
            return not (*this == other);
        }
    };
    
    Iter begin()
    {
        return Iter(head->next);
    }
    
    Iter end() 
    {
        return Iter(tail);
    }
};

#endif