#include <iostream>
#include "Tree.h"
#include <string>
using namespace std;

int main(int argc, char** argv)
{
	string input;
	Tree<char> t;

	do
	{
		cout << "I for Insert" << endl;
		cout << "R for Remove " << endl;
		cout << "S for Search " << endl;
		cout << "C for count " << endl;
		cout << "P for Print " << endl;
		cout << "Q for Quit " << endl;

		getline(cin,input);
		switch(input[0])
		{
			case 'i':
			case 'I':
				cout << "You have selected insert " << endl;
				cout << "Please enter a value " << endl;
				char value;
				cin >> value;
				t.insertNode(value);
				break;
			case 'r':
			case 'R':
				cout << "You have selected remove " << endl;
				cout << "Enter value you want removed" << endl;
				char number;
				cin >> number;
				t.remove(number);
				break;
			case 'c':
			case 'C':
				cout <<  "You have selected count " << endl;
				t.countIt();
				break;
			case 'p':
			case 'P':
				cout << "You have selected print " << endl;
				t.print();
				break;
			case 'q':
			case 'Q':
				cout << "You have selected to Quit " << endl;
				break;
            case 's':
            case 'S':
                cout << "You have selected Search" << endl;
                cout << "Enter value you want to search for " << endl;
                char v;
                cin >> v;
                t.search(v);
			default:
				cout << "Invalid Selection " << endl;
		}
	} while (input[0] != 'Q');




	return 0;
}

