#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Circular
{
	struct Node
	{
		int i;
		Node* next;
	};
	Node* p;	// p - serves as the "head" of the circular list.
	Node* q;	// serves as the "current" pointer.  This is used  by getNext
	public:
		Circular()
		{
			p = 0;
			q = 0;
		}
		~Circular()
		{
			clear();
		}
		Circular(const Circular& s)
		{
			p = 0;
			q = 0;
			*this = s;
		}
		int insert(int x)
		{
			if (isFull())
			{
				return -1;
			}
			Node* c = new Node;
			c->i = x;
			if (p == 0)
			{
				p = c;
				c->next = c;
				return 0;
			}
			else if (x < p->i)
			{
				c->next = p;
				p->next = c;
				p = c;
				return 0;
			}
			Node* s = p;			// points to head 
			Node* h = p->next;		// points to next value of head
			//while(p->next != p)
			for( ; h != p && h->i < x; s = s->next, h = h->next );
			c->next = h;
			s->next = c;
			q = c;
			return 0;

		}
		void print()	const
		{
			if (isEmpty())
			{
				cout << "Empty" << endl;
			}
			Node* t = p;
			do
			{
				cout << t->i << " ";
				t = t->next;
			} 
			while(t != p);
			cout << endl;
		}
		bool isEmpty()	const
		{
			bool check;
			if (p == 0)
			{
				check = true;
				return check;
			}
			else
			check = false;
			return check;
		}
		bool isFull()	const
		{
			Node* t = new Node;
			bool check = true;
			if (t)
			{
				check = false;
			}
			delete t;
			return check;
		}
		int find(int x)	const
		{
			if (isEmpty())
			{
				return -1;
			}
			Node* c;
			c = p;
				do
				{
					if (p->i == x)
					{
					return 0;
					}
					c = c->next;
				}
				while (c != p);
				return -1;
			
		}
		void clear()
		{
			Node* t;
			
			while (p != p)
			{
				t = p;
				p = p->next;
				delete t;
			}
			p = 0;
		}
		int remove(int x)
		{
			if (isEmpty())
			{
				return -1;
			}
			Node* r = 0;
			if (p->i == x)
			{
				r = p;
				p = p->next;
				delete r;
				return 0;
			}
			Node *Nul= p;
			r = p;
			Node* s = p->next;
			while (s != Nul && s->i != x)
			{
				r = r->next;
				s = s->next;
				
			}
			if (s == 0)
			{
				return -1;
			}
			r->next = s->next;
			delete s;
			return 0;
			
			
			
		}
		bool operator<(const Circular& s)
		{
			Node* t = p;
			int x = 0;
			do
			{
				x++;
				t = t->next;
				
			}
			while (t != p);
			Node* r = s.p;
			int y = 0;
			do
			{
				y++;
				r = r->next;
			}
			while (r != s.p);
			bool check = false;
			if (x < y)
			{
				check = true;
				return check;
			}
			else
			return check;
		}
		bool operator==(const Circular& s)
		{
			Node* t = p;
			int x = 0;
			do
			{
				x++;
				t = t->next;
				
			}
			while (t != p);
			Node* r = s.p;
			int y = 0;
			do
			{
				y++;
				r = r->next;
			}
			while (r != s.p);
			bool check = false;
			if (x == y)
			{
				check = true;
				return check;
			}
			else
			return check;
		}
		const Circular operator=(const Circular& s)
		{
			// clear list
			clear();
			
			// repopulate list 
			Node* a = s.p;
			int x = 0;
			do
			{
				x = a->i;
				insert(x);
				a = a->next;
			}
			while (a != s.p);
			return *this;
			
		}
		int getNext(int &s)
		{
			if (isEmpty())
			{
				return -1;
			}
			Node* r = q;
			s = r->i;
			q = r->next;
			return 0;
			
		
			
		}
	
};




int main(int argc, char** argv) 
{
	Circular x;
	int q = x.insert(5);
	cout << q << endl;
	int r = x.insert(3);
	cout << r << endl;
	int s = x.insert(4);
	cout << s << endl;
	x.print(); 
	int a = x.find(3);
	cout << a << endl;
	int b = x.find(1);
	cout << b << endl;
	x.clear(); 
	int v = x.insert(4);
	cout << v << endl;
	x.insert(7);
	x.insert(12);
	x.insert(10);   
	x.print();
	return 0;
	
}
