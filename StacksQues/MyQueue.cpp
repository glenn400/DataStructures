#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;


int main()
{
    int value = 1;
    int customer = 1;
    Queue<int> PutIt;

    string letter;
    do
    {
        cout << "E for Enqueue" << endl;
        cout << "D for Dequeue " << endl;
        cout << "Q for Quit " << endl;
        getline(cin,letter);
        switch (letter[0])
        {
            case 'E':
                cout << "Please enter a value " << endl;
                PutIt.Eq(value);
                cout << "Customer number " << customer++ << " is now in line " << endl;
                PutIt.size();
            break;
            case 'D':
                try
                {
                PutIt.deQ(value);
                cout << "Now serving customer " << customer << endl;
                PutIt.size();
                }
                catch(string &word)
                {
                    cout << word;
                }
            break;
            case 'Q':
                cout << "Good Bye " << endl;
                cout << endl;
            break;
            default:
                cout << "You did not enter a valid response " << endl;
        }
    } while( letter[0] != 'Q');

    return 0;
}

