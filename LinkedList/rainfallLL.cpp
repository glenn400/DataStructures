/* Rainfall Statistics Modification
 Modify Programming Challenge 2 in Chapter 7 (Rainfall Statistics) to let the user
 decide how many months of data will be entered. Use a linked list instead of an array
 to hold the monthly data */
/*
Write a program that lets the user enter the total rainfall for each of 12 months into
an array of double s. The program should calculate and display the total rainfall for
the year, the average monthly rainfall, and the months with the highest and lowest
amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures. */
#include <iostream>

using namespace std;
class Rainfall{
    private:
    struct listNode{
        double value;
        struct listNode* next;
    };
    listNode* head;
    int months;
    public:
        Rainfall()
        {
            head = NULL;
            months = 0;
        }
        void append(double x)
        {
            // create two nodes
            listNode* newNode;
            listNode* nodeptr;

            newNode = new listNode;
            newNode->value = x;
            newNode->next = NULL;

            // check to see if list is empty
            if (!head)
            {
            // if it is empty set head to point at the new node
                head = newNode;
                return;
            }
            else // insert at the end
            {
                nodeptr = head;
                while (nodeptr->next)
                {
                    nodeptr = nodeptr->next;
                }
                nodeptr->next = newNode;
                return;
            }

        }
        void displayList() const
        {
            listNode* nodeptr;
            nodeptr = head;
            while (nodeptr)
            {
                cout << nodeptr->value << " " << endl;
                nodeptr = nodeptr->next;
            }
        }
        double sumRain() const
        {
            double sum = 0;
            listNode* nodeptr;
            nodeptr = head;
            while (nodeptr)
            {
                sum += nodeptr->value;
                nodeptr = nodeptr->next;
            }
            return sum;
        }
        double averageRain() const
        {
            double sum = 0;
            listNode* nodeptr;
            nodeptr = head;
            while (nodeptr)
            {
                sum += nodeptr->value;
                nodeptr = nodeptr->next;
            }
            return sum/months;
        }
        void getMonths(double x)
        {
            months = x;
        }

};

int main()
{
    int months;
    Rainfall rain;
    int x = 1;
    double amount = 0.0;
    cout << "Please enter the number of months you would like to enter rainfall amounts for " << endl;
    cin >> months;
    rain.getMonths(months);
    while (months > 0)
    {
        cout << "Please enter the amount of rainfall for month " << x << endl;
        cin >> amount;
        rain.append(amount);
        x++;
        months--;
    }
    cout << " " << endl;
    rain.displayList();
    cout <<  " " << endl;
    cout << "Total rainfall is " << rain.sumRain() << " " << endl;
    cout << "The average over is " << rain.averageRain() << endl;
    return 0;
}
