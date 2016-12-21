#ifndef HASH_H
#define HASH_H
#include "LinkedList.h"
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Hash
{
	private:
		LinkedList* table;
		int len;
		int capacity;
		int hash(string s)
		{
			
			int sum = 0;
			for (int x = 0; s[x] != 0;x++)
			{
				sum = sum + int(s[x]);
			}
			return sum % capacity;
		}
	public:
		Hash(int x)
		{
			table = new LinkedList[x];
			capacity = x;
			len = 0;
		}
		Hash( const Hash& rhs )
		{
			table = 0;
			*this = rhs;
		}
		~Hash()
		{
			clear();
			delete [] table;
			table = 0;
			len = 0;
			
		}
		Hash& operator=( const Hash& rhs )
		{
			if (this == &rhs)
			{
				return *this;
			}
			clear();
			len = rhs.len;
			capacity = rhs.capacity;
			table = new LinkedList[capacity];
			for (int x = 0; x < capacity;x++)
			{
				table[x] = rhs.table[x];	
			}
			return *this;
		}
		bool operator==( const Hash& rhs )
		{
			return len == rhs.len;
		}
		bool operator<( const Hash& rhs )
		{
			return len < rhs.len;
		}
		int insert(string s)
		{
			int sub;
			sub = hash(s);
			if (sub <= capacity - 1)
			{
				table[sub].append(s);
				len++;
				return 0;
			}
			return -1;
		
		}
		int remove(string s)
		{
			if (isEmpty())
			{
				return -1;
			}
			int y;
			for (int x = 0; x < capacity-1;x++)
			{
				y = table[x].remove(s);
			}
			return y;
		}
		bool find(string s)	const
		{
			if (isEmpty())
			{
				return -1;
			}
			bool y;
			for (int x = 0; x < capacity; x++)
			{
				y = table[x].find(s);
			}
			return y;
		}
		void clear()
		{
			for (int x = 0; x < capacity; x++)
			{
				table[x].clear();
			}
		}
		int size()	const
		{
			return len;
		}
		void print()	const
		{
			for (int x = 0; x < capacity; x++)
			{
				table[x].print();
			}
		}
		bool isFull()	const
		{
			return table[0].isFull();
		}
		bool isEmpty()	const
		{
			return len == 0;
		}
		
	
};
#endif
