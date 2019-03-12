#include <sstream>
#include "ListInt.h"

using namespace std;

ListInt::ListInt()
: head(new Node(0, nullptr, nullptr)), 
  tail(new Node(0, nullptr, nullptr)),
  length(0)
{
    head->next = tail;
    tail->prev = head;
}

string ListInt::toStr() const
{
    ostringstream sout;
    
    bool first = true;
    
    sout << "{";
    for (Node* p = head->next; p != tail; p = p->next)
    {
        if (not first)
        {
            sout << ", ";
        }
        sout << p->data;
        first = false;
    }
    sout << "}";
    
    return sout.str(); 
}

void ListInt::insertNode(Node* p, int x)
{
    Node* t = new Node(x, p->prev, p);
    t->next->prev = t;
    t->prev->next = t;
    
    ++length;
}