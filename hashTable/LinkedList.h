#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
using namespace std;

class LinkedList
{
    private:
    
    struct Node
    {
        string i;
        Node* next;
    };
    
    Node* head;
    
    public:
    LinkedList()
	{
   		 head = NULL;
	}
	LinkedList( const LinkedList& rhs )
	{
    head = NULL;
    
    *this = rhs;
	}
    ~LinkedList()
    {
    	clear();
	}
	LinkedList& operator=( const LinkedList& rhs )
	{
    if ( this == & rhs )
        {
		return *this;
		}
    
    clear();
   
    Node* p = rhs.head;
    while( p )
    {
        insert( p->i );
        p = p->next;
    }
    
    return *this;
	}
	bool operator==( const LinkedList& rhs )
		{
	    int rhscount = 0, count = 0;
	    
	    Node* rhs_p = rhs.head, *p = head;
	    
	    while( rhs_p )
	    {
	        rhscount++;
	        rhs_p = rhs_p->next;
	    }
	    
	    while( p )
	    {
	        count++;
	        p = p->next;
	    }
	    
	    return count == rhscount;
	}
	bool operator<( const LinkedList& rhs )
	{
    int rhs_count = 0, count = 0;
    
    Node* rhs_p = rhs.head, *p = head;
    
    while( rhs_p )
    {
        rhs_count++;
        rhs_p = rhs_p->next;
    }
    
    while( p )
    {
        count++;
        p = p->next;
    }
    
    return count < rhs_count;
	}

    void clear()
    {
    	Node* p = NULL;
    
    	while( head )
   		{
        p = head;
        head = head->next;
        delete p;
    	}
	}
    int insert( string x )
    {
    	if ( isFull() )
       	{
		 return -1;
		}
    	Node* n = new Node;
    	n->i = x;
	    if ( isEmpty() )
	    {
	        head = n;
	        n->next = NULL;
	        return 0;        
	    }
	    if ( x < head->i )
	    {
	        n->next = head;
	        head = n;
	        return 0;
	    }
	    Node* q = head, *p = head->next;
	    for( ; p != NULL && p->i < x; q = q->next, p = p->next );
	    
	    // one the pointers stop moving...
	    // set the new node's next to the lead pointer
	    // set the trailer node's next to the new node and return
	    n->next = p;
	    q->next = n;
	    return 0;
	}
    int append( string x )
    {
	    
	    if ( isFull() )
	        {
				return -1;
			}
	    Node* n = new Node;
	    n->i = x;
	    n->next = NULL;
	    
	    if ( isEmpty() )
	    {
	        head = n;
	        return 0;
	    }
	    Node* p = head;
	    while( p->next )
	    {
	        p = p->next;
	    }
	    p->next = n;
	    
	    return 0;
	}
    int remove( string x )
	{
	
	    if ( isEmpty() )
	        return -1;
	    
	    // check if value is in first node    
	    Node* p = NULL;
	    
	    if ( head->i == x )
	    {
	        p = head;
	        head = head->next;
	        delete p;
	        return 0;
		}
		Node* q = head;
	    p = head->next;
	
	    for( ; p != NULL && p->i != x; q = q->next, p = p->next );
	    if ( p == NULL )
	        return -1;
	    
	    q->next = p->next;
	    
	    delete p;
	    
	    return 0;
    }
    bool isFull() const
    {
	    bool state = true;
	    
	    Node* n = new Node;
	 
	    if ( n )
	        state = false;
	        
	    delete n;
	    
	    return state;
	}
    bool isEmpty() const
    {
    	 return head == NULL;
	}
    int getLength() const
    {
    	 int count = 0;
	    
	    Node* p = head;
	    
	    while( p )
	    {
	        count++;
	        p = p->next;
	    }
    
    	return count;
	}
    bool find( string x ) const
    {
    	for ( Node* p = head; p != NULL; p = p->next )
        if ( p->i == x )
            return true;
            
    return false;
	}
    void print() const
	    {
	    	  // set a temp pointer to head
	    Node* p = head;
	    
	    // use it to traverse the list, printing as we go
	    while( p )
	    {
	        cout << p->i << " ";
	        p = p->next;
	    }
	    
	    cout << endl;
		}
};

#endif
