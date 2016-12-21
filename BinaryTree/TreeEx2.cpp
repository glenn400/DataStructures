#include <iostream>
using namespace stdd;


class Tree
{
private:
    struct Node
    {
        int i;
        Node* right;
        Node* left;
    };
    Node* root;
    int insert(Node*& r, Node* n)
    {
        if (r == 0)
        {
            r = n;
        }
        else if (n->i < r->i)
        {
            return insert(r->left,n);
        }
        else
            return insert(r->right,n);
    }
public:
    Tree()
    {
        root = 0;
    }
    int insert(int x)
    {
        if (isEmpty())
        {
            return -1;
        }
        Node *n = new Node;
        n->i = x;
        n->left = 0;
        n->right = 0;
        insert(root,n);
    }
    bool isFull()   const
    {
        Node* p = new Node;
        if  (p)
        {
            delete p;
            return false;
        }
        return true;
    }
    bool isEmpty()
    {
        return root == 0;
    }



};

int main()
{
    Tree x;
    x.insert(4);
    x.insert(3);

    return 0'
}
