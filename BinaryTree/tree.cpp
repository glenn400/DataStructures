#include <iostream>
#include <string>
using namespace std;

class Tree{
	private:
		struct Node{
			int item;
			Node* left;
			Node* right;
		};
		Node* nRoot;
		void insert(Node*& rootPntr,int number)
		{
			if (rootPntr == NULL)
			{
				rootPntr = new Node;
				rootPntr->item = number;
				rootPntr->left = NULL;
				rootPntr->right = NULL;
				return;
			}
			if (number < rootPntr->item)
			{
				insert(rootPntr->right,number);
			}
			else
			{
				insert(rootPntr->left,number);
			}
		}
		void deleteIt(Node*& root)
		{
			Node* p = NULL;
			if (root == NULL)
			{
				cout << "Error empty Tree can not delete " << endl;
				return;
			}
			// if there is only one node and each child is NULL 
			if (root->left == NULL && root->right == NULL)
			{
				delete root;
				root = NULL;
				return;
			}
			// left child only
			if (root->left!= NULL && root->right == NULL)
			{
				p = root;
				root = root->left;
				delete p;
			}
			// right child only
			if (root->right != NULL && root->left == NULL)
			{
				p = root;
				root = root->right;
				delete  p;
			}
			// two children
			else
			{
				p = root->right;
				// find left most leaf
				while (p->left != NULL)
				{
					p = p->left;
				}
				p->left = root->left;
				p = root;
				root = root->right;
				delete p;
			}
		}
		void removeNode(Node*& root,int x)
		{
			if (x < root->item)
			{
				removeNode(root->left,x);
			}
			else if (x > root->item)
			{
				removeNode(root->right,x);
			}
			else
			deleteIt(root);
		}
		
		bool searchTree(Node*& root,int num)
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
			void PrePrint(Node*& root) 
			{
				if (root = NULL)
				{
					cout << "Tree is empty" << endl;
					return;
				}
				cout << root->item << endl;
				PrePrint(root->left);
				PrePrint(root->right);
				
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
	
	public:
		Tree()
		{
			nRoot = NULL;
		}
		~Tree()
		{
			destroyTree(nRoot);
		}
		void insertNode(int x)
		{
			insert(nRoot,x);
		}
		void remove(int x)
		{
			removeNode(nRoot,x);
		}
		bool search (int x)
		{
			searchTree(nRoot,x);
		}
		void print() 
		{
			PrePrint(nRoot);
		}
		int count() const;
};


int main(int argc, char** argv) 
{
	string input;
	Tree t;
	
	do
	{
		cout << "I for Insert" << endl;
		cout << "R for Remove " << endl;
		cout << "S for Search " << endl;
		cout << "C for count " << endl;
		cout << "P for Print " << endl;
		cout << "Q for Quit " << endl;
		
		getline(cin,input);
		switch(input[0])
		{
			case 'i':
			case 'I':
				cout << "You have selected insert " << endl;
				cout << "Please enter a value " << endl;
				int value;
				cin >> value;
				t.insertNode(value);
				break;
			case 'r':
			case 'R':
				cout << "You have selected remove " << endl;
				cout << "Enter value you want removed" << endl;
				int number;
				cin >> number;
				t.remove(number);
				break;
			case 'c':
			case 'C':
				cout <<  "You have selected count " << endl;
				break;
			case 'p':
			case 'P':
				cout << "You have selected print " << endl;
				break; 
			case 'q':
			case 'Q':
				cout << "You have selected to Quit " << endl;
				break;
			default:
				cout << "Invalid Selection " << endl;
		}	
	} while (input[0] != 'Q');
	
	
	
	
	return 0;
}
