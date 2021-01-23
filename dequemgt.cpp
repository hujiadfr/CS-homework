
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "deque.cpp"
using std::cout;
using std::cin;

int main()
{  
    int op;
    int size = 20;
    int item;
    int intitem;
    Deque<int> mylist;
    do
    {
        do{
            cout << "Choose an operation:\n";
            cout << "0: quit\n";
            cout << "1: pushback\n";
            cout << "2: pushfront\n";
            cout << "3: popback\n";
            cout << "4: popfront\n";
            cout << "5: display\n";
            cin >> op ;
        }
        while  ((op < 0) || (op > 5));

        switch (op)
        {
            case 0: break;
            case 1:
            {
                cout << "Enter a value:\n";
                cin >> item;
                mylist.pushback(item);
                break;
            }
            case 2:
            {
                cout << "Enter a value:\n";
                cin >> item;
                mylist.pushfront(item);
                break;
            }
            case 3:
            {
                mylist.popback();
                break;
            }
            case 4:
            {
                mylist.popfront();
                break;
            }
            case 5:
            {
                int numelements = mylist.getlength();
                for (int i = 0; i <= size; ++i)
                {
                    intitem = mylist[i];
                    cout << "List element " << i << " is " << intitem <<".\n";
                }
            }
        default:
            break;
        }
    } 
    while (op != 0);
    return 0;
}