#include <iostream>
using namespace std;

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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Linked w;
	int x = 0;
	x = w.enqueue(4); 
	cout << x << endl;
	int n = 0;
	n = w.enqueue(47);
	w.print();
	cout << "Did it work " << n << endl;
	int m = 0;  
	int z = w.dequeue(m);
	cout << "Did this work tho " << z << endl;
	w.print(); 
/*	int x = 0;
	x = w.push(3);
	w.push(10);
	w.push(20);
	cout<< "Did PUSH work " << x << endl; 
	w.push(7);
	w.print();
	int y = 0;
	int v = 2;
	y = w.pop(v);
	cout << "Did pop work " << y << endl;
	int b = 0;
	w.pop(v);
	w.print();
	bool t;
	t = w.isEmpty();
	cout << t << endl;
	int val = 40;
	w.enqueue(val);
/* 	w.enqueue(2);
	b = w.enqueue(9);
	cout << "Did enqueue work " << b << endl;
	w.print();
	int z = 0;
	int e = 0;
	z= w.dequeue(e);
	w.print();
	bool check;
	check = w.isFull();
	bool che;
	che = w.isEmpty();
	cout << " is it full " << check << endl;
	cout << "is it empty " << che << endl;
//	*/
	
	return 0;
}
