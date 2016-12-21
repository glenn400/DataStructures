#ifndef MYSTACK_H
#define MYSTACK_H
#include<string>

template<class G>
class Stack
{
	private:
		struct Node
		{
			G x;				// value in node
			Node* next;			// pointer to next node
		};
		Node* Tstack;
		public:
			Stack()
			{
				Tstack = NULL;
			}
			Stack(const Stack &mem)
			{
				Tstack = NULL;
				*this = mem;
			}
			~Stack()
			{
			destroy();
					
			}
			void StackPush(G var)
			{
				// Create a new node pointer
				Node* elNode = NULL;
				// dynamically allocate a new node 
				//  and point to it 
				elNode = new Node;
				elNode->x = var;
				if (empty())
				{
					Tstack = elNode;
					elNode->next = NULL;
				}
				else
				{
					elNode->next = Tstack;
					Tstack = elNode;
					
				}
			}
			void stackPop(G &y)
			{
				Node* hello = NULL;
				if (empty())
				{
					G exception = "There is nothing in the stack lo siento.\n";
					throw  exception;
				}
				else
				{
					y = Tstack->x;
					hello = Tstack->next;
					delete Tstack;
					Tstack = hello;
					
				}
				
			}
			bool empty()
			{
				bool check;
				if (!Tstack)
				{
					check = true;
				}
				else 
					check = false;
				return check;
			}
			Stack& operator=(const Stack& s)
			{
				if (Tstack)
				{
					destroy();
					Tstack = new Node(*s.Tstack);
					for (;Tstack != NULL;Tstack = Tstack->next)
					{
						G hold;
						hold = Tstack->x;
						G y;
						y = stackPop(hold);
						StackPush(y);
						
						return *this;
					}
					
				}
			}
			void destroy()
			{
				
			    Node* search = NULL;
			    
			    while( Tstack )
			    {
			        search = Tstack;
			        Tstack = Tstack->next;
			        delete search;
			    }
			}
		
};

#endif
