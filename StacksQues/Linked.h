#ifndef LINKED_H
#define LINKED_H

class Linked{
	struct Node
	{
		int i;
		Node* next;	
	};
	Node* head;
	Node* rear;			// QUE
	public:
		Linked()
		{
			head = 0;
			rear = 0;
		}
		~Linked()
		{
			clear();	
		}
		int pop(int &x)		// LIFO
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				Node* p = 0;
				x = head->i;
				p = head->next;
				delete head;
				head = p;
				return 0;
			}
		}
		int push(int x)		// LIFO
		{
			Node* p = new Node;
			p->i = x;
			if (isEmpty())
			{
				head = p;
				p->next = 0;
				return 0;
			}
			else
			{
				p->next = head;
				head = p;
				return 0;
			}
			return -1;	
		}
		void clear()
		{
			Node* p;
			Node* t;
			p = head;
			while (p != 0)
			{
				t = p->next;
				delete p;
				p = t;
			}	
		}
		bool isEmpty()	const
		{
			bool check;
			if (head == 0)
			{
				check = true;
			}
			else
			{
				check = false;
			}
			return check;
		}
		void print()	const
		{
			Node* p;
			p = head;
			if (isEmpty())
			{
				cout << "Stack or Que is empty" << endl;
			}
			else
			while(p)
			{
				cout << p->i << " ";
				p = p->next;	
			}
			cout << endl;
		
					
		}
		int enqueue(int x)	// FIFO
		{
			Node* p = 0;
			p = new Node;
			p->i = x;
			p->next = 0;
			if (isEmpty())
			{
				head = p;
				rear = p;
				return 0;
			}
			else 
			{
				Node* q = head;
				while (q->next)
				{
					q = q->next;
				}
				rear = q;
				rear->next = p;
				rear = p;
				return 0;
			}
			// return -1;
		
		}
		int dequeue(int &x)	// FIFO
		{
			Node* p;
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				x = head->i;
				p = head;
				head = head->next;
				delete p;
				return 0;
			}
		}
		int top(int &x)	const
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				x = head->i;
				return 0;
			}
		}
		bool isFull()	const
		{
			Node* p;
			p = new Node;
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
	   
};

#endif
