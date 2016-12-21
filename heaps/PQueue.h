#ifndef PQUEUE_H
#define PQUEUE_H
#include <iostream>
using namespace std;

class PQueue
{
	private:
		int *queue;
		int length;
		int capacity;
		void reheapDown(int root, int bottom )
		{
			int max;
			int rc;
			int lc;
			lc = root * 2 + 1;
			rc = root * 2 + 2;
			if (lc == bottom)
			{
				max = lc;
			}
			else
			{
				if (queue[lc] <= queue[rc])
				{
					max = rc;
				}
				else
				{
					max = lc;
				}
			}
			if (queue[root] < queue[max])
			{
				Swap(queue[root],queue[max]);
				reheapDown(max,bottom);
			}		
		}
		void reheapUp(int root, int bottom)
		{
			int parent;
			if (bottom > root)
			{
				parent = (bottom - 1) / 2;
				if (queue[parent] < queue[bottom])
				{
					Swap(queue[parent],queue[bottom]);
					reheapUp(root,parent);
				}
			}
			
		}
		void Swap(int &x, int &y )
		{
			int z;
			z = x;	// set z = x 
			x = y;	// swap x with y 
			y = z;	// swap y with x(or z in this case)
		}
	public:
		PQueue()
		{
			int x = 5;
			queue = new int[x];
			capacity = x;
			length = 0;
		}
		PQueue(int x)
		{
			queue = new int[x];
			capacity = x;
			length = 0;
			
		}
		PQueue(const PQueue &rhs)
		{
			queue = 0;
			*this = rhs;
		}
		~PQueue()
		{
			delete [] queue;
			queue = 0;
			length = 0;
		}
		int enqueue(int x)
		{
			if (isFull())
			{
				return -1;
			}
			else
			{
				length++;
				queue[length - 1] = x;
				reheapUp(0,length -1);
				return 0;
			}
			
		}
		int dequeue(int& x)
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				x = queue[0];
				queue[0] = queue[length - 1];
				length--;
				reheapDown(0,length - 1);
				return 0;
			}
		}
		void clear()
		{
			length = 0;
		}
		bool isEmpty()	const
		{
			return length == 0;
		}
		bool isFull()	const
		{
			return length == capacity;
		}
		PQueue& operator=(const PQueue& rhs)
		{
			if (this == &rhs)
			{
				return *this;
			}
			else
			{
				delete [] queue;
				length = rhs.length;
				capacity = rhs.capacity;
				queue = new int[capacity];
				for (int i = 0; i < capacity; i++)
				{
					queue[i] = rhs.queue[i];
				}
				return *this;
			}
		}
		bool operator<(const PQueue& rhs)
		{
			bool check = false;
			if (length < rhs.length)
			{
				check = true;
				return check;
			}
			else
			return check; 
		}
		bool operator==(const PQueue& rhs)
		{
			bool check = false;
			if (length == rhs.length)
			{
				check = true;
				return check;
			}
			else
			return check;
		}
	
	
	
};


#endif

