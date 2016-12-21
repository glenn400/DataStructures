#ifndef LINKEDLIST_H
#define LINKEDLIST_H

// GLenn Norris Jr
// CS 3240
// HW 2 

class LinkedList
{
	struct Node
	{
		int i;
		Node* next;
	};
	private:
		Node* head;
	public:
		LinkedList()
		{
			head = 0;
		}
		~LinkedList()
		{
			clear();
		}
		void append(int x)
		{
			Node* p = new Node;			// create node
			p->i = x;					// store value in node
			p->next = 0;				// p next is null
			Node* q = head;
			if (head == 0)
			{
				head = p;
				return 0;
			}
			else						// traverse node
			{
				while (q->next)
				{
					q = q->next;
				}
				q->next = p;			// append to end of list
				return 0;
			}
			
		}
		int remove(int x)
		{
			if (head == 0)
			{
				return -1;
			}
			else if (head->i == x)
			{
					Node* p;
					p = head;
					head = head->next;
					delete p;
					return 0;
			}
			else
			{
				Node* d = head->next;
				Node* s = head;
				for (;d != 0 && d->i != x;s = s->next, d = d->next);
				{
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
		}
		void clear()
		{
			Node* p = 0;
			while (head != 0)
			{
			p = head;
			head = head->next;
			delete p;
			p = head;
			}
			return 0;
		}
		bool isEmpty()	const
		{
			if (head == 0)
			{
				return true;
			}
			else 
			return false;
		}
		int getLength()	const
		{
			int x = 0;
			Node* trav = head;
			if (head == 0)
			{
				return 0;
			}
			else
			{
			while (trav != 0)
			{
				trav = trav->next; 
				x++;
			}
			return x;
			}
		}
		bool find(int x)	const
		{
			Node* search = head;
			for (; search != 0; search = search->next)
			{
				 if (search->i == x )
				{
					return true;
				}
				
			} 
				return false;
		}
		void print()	const
		{
			Node* p;
			p = head;
			if (p == 0)
			{
				cout << "No values found " << endl;
			}
			else
			while (p != 0)
			{
				cout << p->i << " ";
				p = p->next; 
			}
			cout << endl;
			
		}
		int insert(int x)
		{
			Node* n = new Node;
    		n->i = x;
    
   			 if ( head == NULL )
    			{
		        n->next = NULL;
		        head = n;
		        return 0;
    			}
    
			else if ( x < head->i )
			    {
			        n->next = head;
			        head = n;
			        return 0;
			    }
    		else
    		{
    		Node* q = head; 
			Node* p = head->next;
		    for ( ; p != NULL && x > p->i; q = q->next, p = p->next );
				    q->next = n;
				    n->next = p;
			}
			}
		bool isFull()	const
		{
			bool check;
			Node* t = new Node;
			if (t == 0)
			{
				check = true;
				return check;	
			}
			else
			delete t;
			t = 0;
			check = false;
			return check;
			
		}	
};
#endif
