/*
    This is a sample driver to serve as a "sanity check" for your class.
    It does not represent a thorough test effort of the class.  Be sure
    you thoroughly test your class before submission.  Do not rely on this
    driver to test your class.
*/

#include "PQueue.h"

#include <iostream>
using namespace std;

int main (int argc, char const* argv[])
{
    PQueue p;
    
    p.enqueue(5);
    p.enqueue(10);
    p.enqueue(22);
    p.enqueue(3);
    
    int x;
    
    p.dequeue(x);
    cout << x << endl;          // should be 22.
    p.dequeue(x);
    cout << x << endl;          // should be 10
    
    cout << p.isEmpty();        // should be 0
    return 0;
}
