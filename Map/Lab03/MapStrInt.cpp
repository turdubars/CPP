#include <iostream>
#include <stack>

#include "MapStrInt.h"

using namespace std;

int& MapStrInt::operator[](const string& k)
{
    Node* pred = nullptr;
    Node* curr = root;
    bool isLeft = false;
    while (curr != nullptr)
    {
        pred = curr;
        if (k < curr->data.first)
        {
            isLeft = true;
            curr = curr->left;
        }
        else if (curr->data.first < k)
        {
            isLeft = false;
            curr = curr->right;
        }
        else
        {
            return curr->data.second;
        }
    }

    Node* t = new Node(k, 0, nullptr, nullptr);
    
    ++length;
    
    if (root == nullptr)
    {
        root = t;
    }
    else if (isLeft)
    {
        pred->left = t;
    }
    else
    {
        pred->right = t;
    }
    
    return t->data.second;
}


void MapStrInt::printInOrder() const
{
    stack<StackFrame> stk;
    
    cout << "MapStrInt: " << size() << ", { ";
    
    stk.push({root, 0});
    
    while (not stk.empty())
    {
        StackFrame& r = stk.top();
        
        if (r.node == nullptr or r.count > 2)
        {
            stk.pop();
        }
        else if (r.count == 0)
        {
            ++r.count;
            stk.push({r.node->left, 0});
        }
        else if (r.count == 1)
        {
            ++r.count;
            cout << "(" << r.node->data.first
                 << "," << r.node->data.second << ") ";
        }
        else if (r.count == 2)
        {
            ++r.count;
            stk.push({r.node->right, 0});
        }
        
    }
    
    cout << "}" << endl;
}

void MapStrInt::clear()
{
    stack<StackFrame> stk;
    
    stk.push({root, 0});
    
    while (not stk.empty())
    {
        StackFrame& r = stk.top();
        
        if (r.node == nullptr or r.count > 2)
        {
            stk.pop();
        }
        else if (r.count == 0)
        {
            ++r.count;
            stk.push({r.node->left, 0});
        }
        else if (r.count == 1)
        {
            ++r.count;
            stk.push({r.node->right, 0});
        }
        else if (r.count == 2)
        {
            ++r.count;
            // cout << "removed (" << r.node->data.first
                 // << "," << r.node->data.second << ")" << endl; 
            delete r.node;
            --length;
        }
        root = nullptr;
    }
}
