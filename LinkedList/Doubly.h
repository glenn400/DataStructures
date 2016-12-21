#ifndef DOUBLY_H
#define DOUBLY_H
// Glenn Norrs Jr
class Doubly{
	struct Node{
		int i;
		Node* prev;
		Node* next;
	};
	Node* p;	// Keep track of head
	Node* q;	// Keep track of rear
	public:
		Doubly()
		{
			p = 0;	// head
			q = 0;	// end
		}
		
		~Doubly()
		{
			clear();
		}
		Doubly(const Doubly &s)
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
				q = c;
				c->next = 0;
				c->prev = 0;
				return 0;
			}
			else if (x < p->i)
			{
				p->prev = c;
				c->next = p;
				p = c;
				c->prev = 0;
				return 0;
			}
			else
			{
				Node* h = p;
				Node* n = 0;
				while (h != 0 && h->i < x)
				{
					n = h;
					h = h->next;
				}
				
				n->next = c;
				c->prev = n;
				if (!h)
				{
					q = c;
					c->next = 0;
				}
				else
				{
					h->prev = c;
				}
				
				
				return 0;

			}
			
			
		}
		int remove(int x)
		{
			if (isEmpty())
			{
				return -1;
			}
			else if (p->i == x)
			{
				Node* f;
				f = p;
				p = p->next;
				p->prev = 0;
				delete f;
				return 0;
			}
			else
			{
				Node* d = p->next;
				Node* s = p;
				for (;d != 0 && d->i != x;s = s->next, d = d->next);
				
					if (d ==  0)
					{
						return -1;
					}
					else
					s->next = d->next;
					delete d;
					return 0;
			}
		}
		void print()	const
		{
			Node* h = p;
			while(h)
			{
				cout << h->i << " ";
				h = h-> next;
			}
			cout << endl;
		}
		void reverse()	const
		{
			Node* r = q;
			while(r)
			{
				cout << r->i << " ";
				r = r->prev;
			}
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
			bool check = true;
			Node* test = new Node;
			if (test)
			{
				check = false;
				
			}
			delete test;
			return check;
		;
		}
		void clear()
		{
			Node* h;
			while (p != 0)
			{
				h = p;
				p = p->next;
				delete h;
			}
			p = 0;
			q = 0;
		}
		bool find(int x)	const
		{
			if(isEmpty())
			{
				return false;
			}
			bool check;
			Node* s = p;
			while(s != 0)
			{
				if (s->i == x)
		 		{
		 			check = true;
		 			return check;
				}
				s = s->next;
			}
			check = false;
			return check;
		}
		bool operator==(const Doubly&  s)
		{
			Node* t;
			t = p;
			int x = 0;
			while(t != 0)
			{
				x++;
				t = t->next;
			}
			int y = 0;
			Node* r = s.p;
			while(r != 0)
			{
				y++;
				r = r->next;
			}
			bool check;
			if ( x == y)
			{
				check = true;
				return check;
			}
			else
			check = false;
			return check;
		}
		bool operator<(const Doubly& s)
		{
			Node* t;
			t = p;
			int x = 0;
			while(t != 0)
			{
				x++;
				t = t->next;
			}
			int y = 0;
			Node* r = s.p;
			while(r != 0)
			{
				y++;
				r = r->next;
			}
			bool check;
			if ( x < y)
			{
				check = true;
				return check;
			}
			else
			check = false;
			return check; 
		}
		const Doubly operator=(const Doubly& s)
		{
			// step 1 delete contents of of linked list
			clear();
			// repopulate linked list
			Node* a = s.p;
			a = p;
			Node* b = s.q;
			b = q;
			if (&s == this)
			{
				return *this;
			}
			int x = 0;
			while(a != 0)
			{
				a->i = x;
				insert(x);
				a = a->next;
			}
			return *this;
		}

		
		
		
};






#endif
