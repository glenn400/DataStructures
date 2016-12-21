#ifndef ARRAYLIST_H
#define ARRAYLIST_H

// Glenn Norris Jr
// CS 3240 HW #2

class ArrayList
{
	private:
		int* a;
		int capacity;
		int length;
	public:
		ArrayList(int x)
		{
			capacity = x;
			length = 0;
			a = new int[capacity];
			for (int y = 0;y < capacity;y++)
			{
				a[y] = 1;
			}
			
		}
		~ArrayList()
		{
			delete [] a;
			a = 0;
		}
		bool ifFull() const
		{
			bool x;
			if (length == capacity - 1)
			{
				x = true;
				return x;
			}
			else 
			x = false;
			return x;
		}
		bool isEmpty()	const
		{
			bool x;
			if (length == 0)
			{
				x = true;
				return x;
			}
			else
			x = false;
			return x;
		}
		int append(int x)
		{
			if (ifFull())
			{
				return -1;
			}
			else
			{
				if (length == 0)
				{
					a[0] = x;
					length++;
					return 0;
				}
				else
				{
					a[length+1] = x;
					length++;
					return 0;
				}
			}
		}
		int remove(int x)
		{
			if (isEmpty())
			{
				return -1;
			}
			else
			{
				for (int z = 0;z < length && x != a[z];z++)
				{
					for (int p = length;p > z;p--)
					{
						a[p] = a[p-1];
					}
					length--;
					return 0;
					
				}
				return -1;	// if not found
			
			
			}
		}
		int insert(int x)
		{
			if (ifFull())
			{
				return -1;
			}
			else
			{
				if (length == 0)
				{
					a[0] = x;
					length++;
					return 0;
				}
				else if (length != 0)
				{
				for (int z = 0;z < length && x > a[z];z++)
				{
					for (int k = length; k > z; k--)
					{
						a[k] = a[k-1];
					}
					a[z] = x;
					
				}
				length++;
				return 0;
				}
				else
				return -1;
			}
		}
		int getLength()	const
		{
			return length;
		}
		void print()	const
		{
			for (int x = 0; x < length;x++)
			{
				cout << a[x] << " ";
			}
			cout << endl;
		}
		bool find(int x)	const
		{
			bool check;
			if (isEmpty())
			{
				check = true;
				return check;
			}
			else
			{
				for (int y = 0; y < length && x != a[y]; y++)
				{
					if (x == a[y])
					{
						check = true;
						return check;
					}
					else 
					{
						check = false;
						return false;
					}
				}
			}
		}
		void clear()
		{
			delete [] a;
			a = 0;	
		}	
};


#endif
