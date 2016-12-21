#include <iostream>
using namespace std;

class Array{
	private:
		int* a;
		int capacity;
		int length;
		int rear;		// QUE
		int front;		// QUE
	public:
		Array(int x)
		{
			capacity = x;
			length = 0;
			a = new int[capacity];
			for (int t = 0; t > capacity; t++)
			{
				a[t] = 0;
			}
			rear = 0;
			front = 0;
		}
		~Array()
		{
			delete [] a;
			a = 0;
		}
		int push(int x)
		{
			if (isFull())
			{
				return -1;
			}
			else
			{
				length++;
				a[length-1] = x;
				return 0;	
			}
			
		}
		bool isFull()	const
		{
			bool check;
			if (length == (capacity))
			{
				check = true;
				return check;
			}
			else 
			{
				check = false;
				return check;
			}
		}
		bool isEmpty()	const
		{
			bool check;
			if (length == 0)
			{
				check = true;
				return check;
			}
			else
			{
				check = false;
				return check;
			}
		}
		int pop(int &x)
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				x = a[length-1];
				length--;
			}
		}
		int getLength()	const
		{
			return length;
		}
		void print()	const
		{
			if (isEmpty())
			{
				cout << "Stack or Que is empty " << endl;
			}
			else
			{
			for (int x = 0;x < length;x++)
			{
				cout << a[x] << " ";
			}
			cout << endl;
			}
		}
		int enqueue(int x)
		{
			if (isFull())
			{
				return -1;
			}
			else
			{
				rear = rear % capacity;
				a[rear] = x;
				length++;
				return 0;
			}
			
		}
		int dequeue(int &x)
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				front = front % capacity;
				x = a[front];
				length--;
			}
		}
		int top(int &x)
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				front = front % capacity;
			}
		}
		void clear()
		{
			int x = 0;
			for (int y = 0; y < length;y++)
			{
				x = a[length - 1];
				length--;
			}
		}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Array x(5);
	bool check, temp;
	x.enqueue(4); 
	int w = 0;
	w = x.enqueue(20);
	cout << w << endl;
	x.print();
	int y = 0;
	x.dequeue(y);
	x.print();
	
	
	return 0;
}
