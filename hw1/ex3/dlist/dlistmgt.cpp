//
//  dlistmgt.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "dlist.cpp"
using std::cout;
using std::cin;

int main()
{
    int type, op;
    int pos, yes;
    int intitem, result1;
    DList<int> mylist1 = DList<int>();
    DList<double> mylist2 = DList<double>();
    double doubleitem, result2;
    bool boolresult;

    // test cases
        cout << "Test case 1: The initial array is:\n";
        mylist1.append(13);
        mylist1.append(8);
        mylist1.append(1);
        mylist1.append(0);
        mylist1.append(255);
        mylist1.append(8);
        mylist1.append(4);
        mylist1.display();
        mylist1.bubbleSort();
        cout << "After bubbleSorting:\n";
        mylist1.display();

        cout << "\n";
        
        cout << "Test case 2: The initial array is:\n";
        mylist2.append(13.6);
        mylist2.append(-2);
        mylist2.append(1.9);
        mylist2.append(0);
        mylist2.append(24.66);
        mylist2.append(8.721);
        mylist2.append(-4.0);
        mylist2.append(88);
        mylist2.append(-88);
        mylist2.append(6.7);
        mylist2.display();
        mylist2.bubbleSort();
        cout << "After bubbleSorting:\n";
        mylist2.display();

    // do
    // {
    //     cout << "Choose your element type:\n";
    //     cout << "0: int  1: double\n";
    //     cin >> type ;
    //     if ((type != 0) && (type != 1))
    //         cout << "You must choose 0 or 1\n\n";
    // }
    // while ((type != 0) && (type != 1));
    // do
    // {
    //     do
    //     {
    //         cout << "Choose an operation:\n";
    //         cout << "O: quit\n";
    //         cout << "1: append\n";
    //         cout << "2: insert\n";
    //         cout << "3: delete\n";
    //         cout << "4: set\n";
    //         cout << "5: get\n";
    //         cout << "6: in\n";
    //         cout << "7: length\n";
    //         cout << "8: concat\n";
    //         cout << "9: sublist\n";
    //         cout << "10: equal\n";
    //         cout << "11: display\n";
    //         cout << "12: bubblesort\n";
    //         cin >> op ;
    //     }
    //     while ((op < 0) && (op > 11));
    //     switch(op)
    //     {
    //         case 0: return(0);
    //         case 1:
    //         {
    //             cout << "Enter a value:\n";
    //             if (type == 0)
    //             {
    //                 cin >> intitem;
    //                 mylist1.append(intitem);
    //             }
    //             else
    //             {
    //                 cin >> doubleitem;
    //                 mylist2.append(doubleitem);
    //             }
    //             break;
    //         }
    //         case 2:
    //         {
    //             cout << "Enter a position and a value:\n";
    //             cin >> pos;
    //             if (type == 0)
    //             {
    //                 cin >> intitem;
    //                 mylist1.insert(pos, intitem);
    //             }
    //             else
    //             {
    //                 cin >> doubleitem;
    //                 mylist2.insert(pos, doubleitem);
    //             }
    //             break;
    //         }
    //         case 3:
    //         {
    //             cout << "Enter a position:\n";
    //             cin >> pos;
    //             if (type == 0)
    //                 mylist1.remove(pos);
    //             else
    //                 mylist2.remove(pos);
    //             break;
    //         }
    //         case 4:
    //         {
    //             cout << "Enter a position and a value:\n";
    //             cin >> pos;
    //             if (type == 0)
    //             {
    //                 cin >> intitem;
    //                 mylist1.setitem(pos, intitem);
    //             }
    //             else
    //             {
    //                 cin >> doubleitem;
    //                 mylist2.setitem(pos, doubleitem);
    //             }
    //             break;
    //         }
    //         case 5:
    //         {
    //             cout << "Enter a position:\n";
    //             cin >> pos;
    //             if (type == 0)
    //             {
    //                 result1 = mylist1.getitem(pos);
    //                 cout << result1 << "\n";
    //             }
    //             else
    //             {
    //                 result2 = mylist2.getitem(pos);
    //                 cout << result2 << "\n";
    //             }
    //             break;
    //         }
    //         case 6:
    //         {
    //             cout << "Enter a value:\n";
    //             if (type == 0)
    //             {
    //                 cin >> intitem;
    //                 boolresult = mylist1.member(intitem);
    //             }
    //             else
    //             {
    //                 cin >> doubleitem;
    //                 boolresult = mylist2.member(doubleitem);
    //             }
    //             cout << boolresult << "\n";
    //             break;
    //         }
    //         case 7:
    //         {
    //             if (type == 0)
    //                 result1 = mylist1.getlength();
    //             else
    //                 result1 = mylist2.getlength();
    //             cout << result1 << "\n";
    //             break;
    //         }
    //         case 8:
    //         {
    //             if (type == 0)
    //             {
    //                 DList<int> mylistnew1 = DList<int>();
    //                 do
    //                 {
    //                     cout << "Do you want to enter more list elements?\n";
    //                     cout << "1: yes  anything else: no\n";
    //                     cin >> yes;
    //                     if (yes == 1)
    //                     {
    //                         cout << "Enter a value for your new list:\n";
    //                         cin >> intitem;
    //                         mylistnew1.append(intitem);
    //                     }
    //                 }
    //                 while (yes == 1);
    //                 mylist1.concat(&mylistnew1);
    //             }
    //             else
    //             {
    //                 DList<double> mylistnew2 = DList<double>();
    //                 do
    //                 {
    //                     cout << "Do you want to enter more list elements?\n";
    //                     cout << "1: yes  anything else: no\n";
    //                     cin >> yes;
    //                     if (yes == 1)
    //                     {
    //                         cout << "Enter a value for your new list:\n";
    //                         cin >> doubleitem;
    //                         mylistnew2.append(doubleitem);
    //                     }
    //                 }
    //                 while (yes == 1);
    //                 mylist2.concat(&mylistnew2);
    //             }
    //             break;
    //         }
    //         case 9:
    //         {
    //             if (type == 0)
    //             {
    //                 DList<int> mylistnew1 = DList<int>();
    //                 do
    //                 {
    //                     cout << "Do you want to enter more list elements?\n";
    //                     cout << "1: yes  anything else: no\n";
    //                     cin >> yes;
    //                     if (yes == 1)
    //                     {
    //                         cout << "Enter a value for your new list:\n";
    //                         cin >> intitem;
    //                         mylistnew1.append(intitem);
    //                     }
    //                 }
    //                 while (yes == 1);
    //                 boolresult = mylist1.sublist(&mylistnew1);
    //             }
    //             else
    //             {
    //                 DList<double> mylistnew2 = DList<double>();
    //                 do
    //                 {
    //                     cout << "Do you want to enter more list elements?\n";
    //                     cout << "1: yes  anything else: no\n";
    //                     cin >> yes;
    //                     if (yes == 1)
    //                     {
    //                         cout << "Enter a value for your new list:\n";
    //                         cin >> doubleitem;
    //                         mylistnew2.append(doubleitem);
    //                     }
    //                 }
    //                 while (yes == 1);
    //                 boolresult = mylist2.sublist(&mylistnew2);
    //             }
    //             if (boolresult == true)
    //             {
    //                 cout << "The new list is a sublist.\n";
    //             }
    //             else
    //                 cout << "The new list is not a sublist.\n";
    //             break;
    //         }
    //         case 10:
    //         {
    //             if (type == 0)
    //             {
    //                 DList<int> mylistnew1 = DList<int>();
    //                 do
    //                 {
    //                     cout << "Do you want to enter more list elements?\n";
    //                     cout << "1: yes  anything else: no\n";
    //                     cin >> yes;
    //                     if (yes == 1)
    //                     {
    //                         cout << "Enter a value for your new list:\n";
    //                         cin >> intitem;
    //                         mylistnew1.append(intitem);
    //                     }
    //                 }
    //                 while (yes == 1);
    //                 boolresult = mylist1.equal(&mylistnew1);
    //             }
    //             else
    //             {
    //                 DList<double> mylistnew2 = DList<double>();
    //                 do
    //                 {
    //                     cout << "Do you want to enter more list elements?\n";
    //                     cout << "1: yes  anything else: no\n";
    //                     cin >> yes;
    //                     if (yes == 1)
    //                     {
    //                         cout << "Enter a value for your new list:\n";
    //                         cin >> doubleitem;
    //                         mylistnew2.append(doubleitem);
    //                     }
    //                 }
    //                 while (yes == 1);
    //                 boolresult = mylist2.equal(&mylistnew2);
    //             }
    //             if (boolresult == true)
    //             {
    //                 cout << "The new list is equal.\n";
    //             }
    //             else
    //                 cout << "The new list is not equal.\n";
    //             break;
    //         }
    //         case 11:
    //         {
    //             if (type == 0)
    //             {
    //                 int numelements = mylist1.getlength();
    //                 for (int i = 1; i <= numelements; ++i)
    //                 {
    //                     intitem = mylist1[i];
    //                     cout << "List element " << i << " is " << intitem <<".\n";
    //                 }
    //             }
    //             else
    //             {
    //                 int numelements = mylist2.getlength();
    //                 for (int i = 1; i <= numelements; ++i)
    //                 {
    //                     doubleitem = mylist2[i];
    //                     cout << "List element " << i << " is " << doubleitem <<".\n";
    //                 }
    //             }
    //             break;
    //         }
    //         case 12:
    //         {
    //             if(type == 0)
    //                 mylist1.bubbleSort();
    //             else
    //                 mylist2.bubbleSort();
    //         }
    //         break;
    //         default: return(0);
    //     }
        
    // }
    // while (op != 0);
    return(0);
}
   

