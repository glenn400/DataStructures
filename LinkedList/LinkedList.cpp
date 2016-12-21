#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class LinkedList
{
	private:
		struct Node
		{
		char h;			// value
		Node *next;  	// Node pointer
		};
		Node *head;		// Node that points to head of linked list
		int reverse(Node *r) const
		{
			if (r == NULL)
			{
				return 0;
			}
			return 1 + reverse(head->next);
			cout << head->h << endl;
		} 
	public:
		LinkedList()
		{
			head = NULL;
		}
		~LinkedList()
		{
			
			// destroy();
			
		}
	void insert(char v)
	{
	Node* point;		// Go through list
	Node* go = NULL;	// point to previous Node
	//Create a new node.
	Node* newKid;
	newKid = new Node;
	newKid->h = v;
	// Test to see if it is empty list
	if (head == NULL)
	{
		head = newKid;
		newKid->next= NULL;
	}
	else		// else put new node in sorted position
	{
		point = head;
		// traverse nodes to check values 
		while(point != NULL && point->h < v)
		{
			go = point;
			point = point->next;
		}
		// if new node is to be first in the list
		if (go == NULL)
		{
			head = newKid;
			newKid->next = point;
		}
		else
		{
			go->next = newKid;
			newKid->next = point;
		}
	}
	}
	void remove(char v)
	{
		// First determine whether list is empty
		if (head == NULL)
		{
			return;
		}
		// remove node right after first element
		if (head->h == v)
		{
			// point pointer to what the head pointer is pointing to
			Node*pointer = head;
			// Move head pointer to next node 
			head = head->next;
			// then delete pointer which removes node from list
			delete pointer;
			return;
		}
		// remove node that is n positions after head
		// create two nodes one to search nodes other to destroy desired
		// node
		Node* point = head->next;
		Node* point2 = head;
		for ( ;(point != NULL && point->h != v);point2 = point2->next,point = point->next)
		{
			if (point == NULL)
			{
				return;
			}
			else
				point2->next = point2->next->next;
				delete point;
		}
	}
	void print() const
	{
		Node* movPntr;
		movPntr = head;
		// traverse list
		while (movPntr)
		{
			if (movPntr == NULL)
			{
				cout << "List is empty " << endl;
			}
			else
			cout << movPntr->h << endl;
			movPntr = movPntr->next;
		}
	}
	int size() const
	{
		int x = 0;
		Node* move;
		move = head;
		// traverse list
		while (move)
		{
			cout << x << endl;
			move = move->next;
			x =  x++;
		}
		return x;
	}
	bool search(char v) const
	{
		
		Node* movPntr;
		movPntr = head;
		// traverse list
		while (movPntr)
		{
			if (movPntr->h != v )
			{
			movPntr = movPntr->next;
			}
			else
				cout << "Value found " << endl;
				return true;
		
		}
	}
	bool write()
	{
		Node* pntr;
		pntr = head;
		fstream file;
		file.open("list.dat",ios::out);
		if (!file)
		{
			cout << "Error opening file " << endl;
			return -1;
		}
		while (pntr)
		{	// where i transerve nodes and copy value into file 
			// after each iteraation
			file << pntr->h;
			// move to next node and loop 
			pntr = pntr->next;
		}
		file.close();
		return true;
	}
	bool read()
	{
		fstream file;
		file.open("List.dat",ios::in);
		if (!file)
		{
			cout << "File did not open successfully" << endl;
			return -1;
		}
		else
		{
			int size = 10;
			int x;
			x = 0;
			char word[size];
			file >> word;
			x = strlen(word);
			file.close();
			return true;
		}
		
	}
	void destroy()
	{
		Node* point = NULL;
		while (head != NULL)
		{
			point = head;
			head = head->next;
			delete point;
			point = head;
		}
		cout << "Node List has been destroyed .. Good Bye" << endl;
	}
	void callRev() const
	{
		Node* Use;
		Use = head;
		reverse(Use);
	}
	
	void menu()
	{
	cout << "Enter C for Clear " << endl;
	cout << "Enter D for Delete " << endl;
	cout << "Enter G for Get" << endl;
	cout << "Enter I for Insert " << endl;
	cout << "Enter L for Legnth " << endl;
	cout << "Enter M for Menu" << endl;
	cout << "Enter P for Print " << endl;
	cout << "Enter Q for Quit " << endl;
	cout << "Enter S for Search " << endl;
	}
	void switchit(char v)
	{
	switch(v)
	{
		case 'c':
		case 'C': cout << "You have entered C"<< endl;
					destroy();
				//	looping = true;
				break;
		case 'd':
		case 'D': cout << "You have entered D " << endl;
					cout << "Enter character you want to delete" << endl;
					char character;
					cin >> character;
					remove(character);
				//	looping = false;
				break;
		case 'g':
		case 'G': cout << "You have entered G " << endl;
					write();
					destroy();
					read();
					
				break;
		case 'i':
		case 'I':   char val;
					cout << "You have entered I" << endl;
					cout << "Please enter the character you want to store" << endl;
					cin >> val;
					insert(val);
				//	looping = false;
				break;
		case 'l':
		case 'L':cout << "You have entered L " << endl;
				cout << "The legnth is  " << size() << endl;
			//	looping = false;
				break;
		case 'm':
		case 'M':cout << "You have entered M " << endl;cout << "Enter C for Clear " << endl;
				menu();
			//	looping = false;
				break;
		case 'p':
		case 'P':cout << "You have entered P " << endl;
				print();
				break;
		case 'q':
		case 'Q': cout << "You have entered Q " << endl;
				cout << " Good Bye  " << endl;
				// looping = true;
				break;
		case 's':
		case 'S': char v;
					cout << "You have entered S " << endl;
					cout << "Enter value you'd like to search for" << endl;
					search(v);
			//	looping = false;
				break;
	default: cout << "You did not enter one of the choices " << endl;
	}
}
	
	
};


int main(int argc, char** argv) 
{
	LinkedList Vile;
	char selection;
	char value;
	Vile.menu();
	bool repeat;
	cin >> selection;
	do 
	{
		repeat = true;
	Vile.switchit(selection);
	cout << "Would you like to repeat " << endl;
	cin >> value;
	if (value == 'N' || value == 'n')
	{
		char loco;
		Vile.menu();
		Vile.switchit(loco); 
		
	}
	else (selection);
	{
		
	}
		
		repeat = false;

	 } while (repeat);

 

	cin.get();
	
	
	return 0;
}
