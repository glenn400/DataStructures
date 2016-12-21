#include <iostream>

using namespace std;
template <class G>
class Queue
{
private:
    struct Nodes
    {
        G value;
        Nodes *next;
    };
    G legnth;
    Nodes* f;
    Nodes* b;
public:
    Queue()
    {
        f = NULL;
        b = NULL;
        legnth = 0.0;
    }
    // copy constructor
    Queue(const Queue &temp)
    {
        f = NULL;
        b = NULL;
        *this = temp;


    }
    Queue& operator=(const Queue& t )
    {
        if (f && b)
        {
            delete f;
            delete b;
        }
        f = new Nodes(*t.f);
        b = new Nodes(*t.b);
        while (f.legnth == 0)
        {
            f.Eq(0);
        }
    }
    void Eq(G num)
    {
        // inqueque or add or insert
        // create a pointer and create new node
        Nodes *laker = NULL;
        laker = new Nodes;
        laker->value = num;
        laker->next = NULL;
        if (isEmpty())
        {
            // if empty place front and back pointers at new node
            f = laker;
            b = laker;
        }
        else
        {
            b->next = laker;
            b = laker;
        }
        legnth++;
    }
    void deQ(G &x)
    {
        Nodes* Warriors = NULL;
        if (isEmpty())
        {
            string exception =  " Que is empty please add to que\n ";
            throw exception;
        }
        else
            x = f->value;
            Warriors = f;
            f = f->next;
            delete Warriors;
            legnth--;
    }
    bool isEmpty() const
    {
        bool sit;
        // check to see if que is empty if so return false
        if (legnth > 0)
        {
            sit = false;
        }
        // else (meaning there are values in que and return true)
        else
            sit = true;
            return sit;
    }
    void size() const
    {
        cout << "The number of people in line is " << legnth << endl;
    }
};
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
                catch(string exception )
                {
                    cout << exception;
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
