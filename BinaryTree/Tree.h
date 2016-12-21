// Glenn Norris Jr
// CS 2370
// CHPT 20 HW
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <string>

using namespace std;

template <class G>
class Tree{
	private:
		struct Node{
			G item;
			Node* left;
			Node* right;
		};
		Node* nRoot;
		void insert(Node*& rootPntr,G number)
		{
			if (rootPntr == NULL)
			{
				rootPntr = new Node;
				rootPntr->item = number;
				rootPntr->left = NULL;
				rootPntr->right = NULL;
				return;
			}
			else if (number < rootPntr->item)
			{
				insert(rootPntr->left,number);
			}
			else
			{
				insert(rootPntr->right,number);
			}
		}
		void deleteIt(Node*& rt)
		{
		    Node *p = NULL;
		    if (rt == NULL)
            {
                cout << "Tree is empty and can not delete Nodes that dont exist " << endl;
            }
            else if (rt->right == NULL)
            {
                p = rt;
                rt = rt->left;
                delete p;
            }
            else if (rt->left == NULL)
            {
                p = rt;
                rt = rt->right;
                delete p;
            }
            else
            {
                p = rt->right;
                while (p->left)
                {
                    p = p->left;

                }
                p->left = rt->left;
                p = rt;
                rt = rt->right;
                delete p;
            }

		}

		void removeNode(G x, Node*& root)
		{
			if (x < root->item)
			{
				removeNode(x,root->left);
			}
			else if (x > root->item)
			{
				removeNode(x, root->right);
			}
			else
			deleteIt(root);
		}
		void PrePrint(Node*& root) const
			{

				if (root == NULL)
				{
					return;
				}
				cout << root->item <<  endl;
				PrePrint(root->left);

				PrePrint(root->right);


			}
			bool searchTree(Node*& root,G num) const
			{
				if (root == NULL)
				{
					cout << "No tree exists yet " << endl;
					return false;
				}
				if (root->item == num)
				{
					return true;
				}
				if (num < root->item)
				{
					return searchTree(root->left,num);
				}
				else
				{
					return searchTree(root->right,num);
				}
			}
			void destroyTree(Node*& root)
			{
				if (root)
				{
					if (root->left)
					{
						destroyTree(root->left);
					}
					if (root->right)
					{
						destroyTree(root->right);
					}
					delete root;
				}
			}
				int counter(Node*& nappyroot) const
				{
				    if (nappyroot == NULL)
				    {
				          return 0;
				    }
                    else
                        return 1 + counter(nappyroot->right) + counter(nappyroot->left);
				}

    public:
        Tree()
		{
			nRoot = NULL;
		}

		~Tree()
		{
		    destroyTree(nRoot);
		}
		void insertNode(G x)
		{
			insert(nRoot,x);
		}
		void remove(G x)
		{
			removeNode(x, nRoot);
		}
		void print()
		{
			PrePrint(nRoot);
		}
		void search (G x)
		{
			
			searchTree(nRoot,x);
		
		}
		void countIt()
        {
                int value;
                value = counter(nRoot);
                cout << value << endl;
        }

};
#endif
