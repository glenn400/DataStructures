#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;

class Tree
{
	private:
		struct Node
		{
			int i;
			Node* left;
			Node* right;
		};
    private:
		int insert(Node*& r,Node* n)
		{
			if (r == 0)
			{
                r = n;
                return 0;
			}
            else if (n->i < r->i)
			{

				return insert(r->left,n);

			}
			else
				return insert(r->right,n);
		}
		void inprint(Node* n)	const
		{
		    if (n == 0)
            {
                return;
            }

				inprint(n->left);
				cout << n->i << " ";
				inprint(n->right);


		}
		bool find(Node* r, int x)   const
		{
                if(r == 0)
                {
                    return false;
                }
               if (r->i == x)
               {
                   return true;
               }
               else if (x < r->i)
               {
                   return find(r->left,x);
               }
               else
                    return find(r->right,x);
		}
		int seek(Node*& r, int x)
		{

            if (x < r->i)
            {
                return seek(r->left,x);
            }
            else if (x > r->i)
            {
                return seek(r->right,x);
            }
            else
                destroy(r);
                return 0;
		}
		void destroy(Node*& r)
		{
		    Node* t = 0;
		    if (isEmpty())
            {
                cout << "Empty tree " << endl;
            }
            else if (r->right == 0)
            {
                t = r;
                r = r->left;
                delete t;
            }
            else if (r->left == 0)
            {
                t = r;
                r = r->right;
                delete t;

            }
            else
            {
                t = r->right;
                while (t->left)
                {
                    t = t->left;
                }
                t->left = r->left;
                t = r;
                r = r->right;
                delete t;
            }
		}
		void clear(Node*& r)
		{
		   if (r != 0)
		   {
		   	clear(r->left);
		   	clear(r->right);
		   	delete r;
		   }
		}
        int counter(Node* r)   const
        {
            int x = 0;
            if (r == 0)
            {
                return x;
            }

				return counter(r->left);
				x++;
				return counter(r->right);
        }
        void copy(Node* n )
        {
        	if (root == 0)
        	{
        		n = 0;
        		return;
			}
			else
			{
				n = new Node;
				insert(n->i);
				copy(n->left);
				copy(n->right);
			}
		}
		void copyTree(Node*& r, const Node* c)
		{
			if (c == 0)
			{
				r = 0;
				return;
			}
			else
			{
				r = new Node;
				r->i = c->i;
				copyTree(r->left,c->left);
				copyTree(r->right, c->right);
			}
		}

		public:
		    Node* root;
			Tree()
			{
				root = 0;
			}
			~Tree()
			{
			    clear();
			}
			Tree(const Tree& rhs)
			{
			  copyTree(root, rhs.root);
			}
			int insert(int x)
			{
				if (isFull())
				{
					return -1;
				}
				Node* p = new Node;
				p->i = x;
				p->right = 0;
				p->left = 0;
				int y = 0;
				return insert(root,p);
			}
			void inprint()	const
			{
				inprint(root);
			}
			bool find(int x) const
			{
                bool check;
                return find(root,x);

			}
			void clear()
			{
			    if (isEmpty())
                {
                    return;
                }
                clear(root);
                root = 0;
			}
			int counter()   const
			{
			    int x = 0;
                return counter(root);
			}
			Tree& operator=(const Tree& rhs)
			{
				if (this != &rhs)
				{
					clear();
					copyTree( root, rhs.root);
				}
			}
			bool isFull()	const
			{
				Node* p = new Node;
				bool check = false;
				if (p == 0)
				{
					check = true;
					return check;
				}
				else
				return check;
			}
			bool isEmpty()	const
			{
				return root == 0;
			}
			bool operator==(const Tree& rhs)
			{
				int x = 0;
				bool check;
				x = counter(root);
				int y = 0;
				y = counter(rhs.root);
				if (x == y)
				{
					check = true;
					return check;
				}
				else
				check = false;
				return check;
			}
			bool operator<( const Tree& rhs)
			{
					int x = 0;
				bool check;
				x = counter(root);
				int y = 0;
				y = counter(rhs.root);
				if (x < y)
				{
					check = true;
					return check;
				}
				else
				check = false;
				return check;
			}


};
#endif
