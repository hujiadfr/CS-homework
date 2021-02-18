/* CS 225 group 6 assignment 1 EX2 problem 4
   Group member: Zhou Yang, Lu keyu, Hu Jiarun He Zhanhao
   Modified date: 2021.1.24 15:50
   new function:    src_length(AList<T> l)
                    src_apply(T (*function_f)(T), AList<T>& l)
                    src_condition(T (*condition)(T),AList<T>& l)
   test case: int_test_case_1(int i);
              int_test_case_2(int i);
              double_test_case_1(double i);
              double_test_case_2(double i);
*/


//
//  listmgt.cpp
//
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.cpp"
using std::cout;
using std::cin;

int int_test_case_1(int i);
int int_test_case_2(int i);
double double_test_case_1(double i);
double double_test_case_2(double i);

int main()
{
    int type, size, op;
    int pos, yes;
    int intitem, result1;
    AList<int> mylist1;
    AList<double> mylist2;
    double doubleitem, result2;
    bool boolresult;

    do
    {
        cout << "Choose your element type:\n";
        cout << "0: int  1: double 2: testcase (please press 2 and use the testcase for grading)\n";
        cin >> type ;
        if ((type != 0) && (type != 1) && (type != 2))
            cout << "You must choose 0 or 1 or testcase\n\n";
    }
    while ((type != 0) && (type != 1) && (type != 2));


    if(type == 2){
            cout << "below are the test cases for src_length, src_apply and src_condition \n\n";
            cout << "test cases used are int_test_case_1(int i); int_test_case_2(int i); double_test_case_1(double i); double_test_case_2(double i);\n";
            cout << "test_case_1 is used for testing src_apply, it mutiply the input by 5 and return the value\n";
            cout << "test_case_2 is used for testing src_condition, it sort out value bigger than 5 and return 1; otherwise return 0\n\n";
//            
            cout << "case 1 : empty array : \n\n";
            cout << "1. test for src_length is below .\n";
            cout << "int type \n mylist1 is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "output of src_length is :" << mylist1.src_length(mylist1) << "\n";
            cout << "\ndouble type \n mylist2 is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
            cout << "output of src_length is :" << mylist2.src_length(mylist2) << "\n\n";
//            
            cout << "2. test for src_apply is below .\n";
            cout << "int type \n mylist1 is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "execute src_apply(int_test_case_1,mylist1)\n";
            mylist1.src_apply(int_test_case_1,mylist1);
            cout << "mylist1 after execution is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "\ndouble type \n mylist2 is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
            cout << "execute src_apply(double_test_case_1,mylist2)\n";
            mylist2.src_apply(double_test_case_1,mylist2);
            cout << "mylist1 after execution is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
//
            cout << "\n3. test for src_condition is below .\n";
            cout << "int type \n mylist1 is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "execute src_condition(int_test_case_2,mylist1)\n";
            mylist1.src_condition(int_test_case_2,mylist1);
            cout << "mylist1 after execution is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "\ndouble type \n mylist2 is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
            cout << "execute src_condition(double_test_case_2,mylist2)\n";
            mylist2.src_condition(double_test_case_2,mylist2);
            cout << "mylist2 after execution is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }


//-----------------------------------------------------------------------            
            cout << "\ncase 2 : array with length 10 : \n\n";
            cout << "1. test for src_length is below .\n";
            AList<int> mylist1 = AList<int>(20);
            AList<double> mylist2 = AList<double>(20);
            for (int i=0; i < 10; i++){
                mylist1.append(i);
            }
            for (double j=0.1111; j < 10; j++){
                mylist2.append(j);
            }
            
            cout << "int type \n mylist1 is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "output of src_length is :" << mylist1.src_length(mylist1) << "\n";
            cout << "\ndouble type \n mylist2 is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
            cout << "output of src_length is :" << mylist2.src_length(mylist2) << "\n";

//
            cout << "\n2. test for src_apply is below .\n";
            cout << "int type \n mylist1 is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "execute src_apply(int_test_case_1,mylist1)\n";
            mylist1.src_apply(int_test_case_1,mylist1);
            cout << "mylist1 after execution is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "\ndouble type \n mylist2 is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
            cout << "execute src_apply(double_test_case_1,mylist2)\n";
            mylist2.src_apply(double_test_case_1,mylist2);
            cout << "mylist2 after execution is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
//          
            {
                double j=0.1111;
                for(int i = 0; i < 10; i++){
                    intitem=i;
                    doubleitem=j;
                    mylist1.setitem(i+1,intitem);
                    mylist2.setitem(i+1,doubleitem);
                    j++;
                }
            }
            
            cout << "\n3. test for src_condition is below .\n";
            cout << "int type \n mylist1 is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "execute src_condition(int_test_case_2,mylist1)\n";
            mylist1.src_condition(int_test_case_2,mylist1);
            cout << "mylist1 after execution is : \n";
            {
                int numelements = mylist1.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    intitem = mylist1[i];
                    cout << "List element " << i << " is " << intitem <<"\n";
                }
            }
            cout << "\ndouble type \n mylist2 is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
            cout << "execute src_condition(double_test_case_2,mylist2)";
            mylist2.src_condition(double_test_case_2,mylist2);
            cout << "mylist2 after execution is : \n";
            {
                int numelements = mylist2.getlength();
                for (int i = 1; i <= numelements; ++i)
                {
                    doubleitem = mylist2[i];
                    cout << "List element " << i << " is " << doubleitem <<"\n";
                }
            }
    }
    else{
        cout << "Enter a positive integer for the size of your list:\n";
    cin >> size;
    if (size <= 0)
        size = 20;
    switch(type)
    {
        case 0:
        {
            AList<int> mylist1 = AList<int>(size);
            break;
        }
        case 1:
        {
            AList<double> mylist2 = AList<double>(size);
            break;
        }
    }
    do
    {
        do
        {
            cout << "Choose an operation:\n";
            cout << "O: quit\n";
            cout << "1: append\n";
            cout << "2: insert\n";
            cout << "3: delete\n";
            cout << "4: set\n";
            cout << "5: get\n";
            cout << "6: in\n";
            cout << "7: length\n";
            cout << "8: concat\n";
            cout << "9: sublist\n";
            cout << "10: equal\n";
            cout << "11: display\n";
            cout << "12: src_length\n";
            cout << "13: src_apply testcase_1\n";
            cout << "14: src_condition testcase_2\n";
            cin >> op ;
        }
        while ((op < 0) && (op > 11));
        switch(op)
        {
            case 0: return(0);
            case 1:
            {
                cout << "Enter a value:\n";
                if (type == 0)
                {
                    cin >> intitem;
                    mylist1.append(intitem);
                }
                else
                {
                    cin >> doubleitem;
                    mylist2.append(doubleitem);
                }
                break;
            }
            case 2:
            {
                cout << "Enter a position and a value:\n";
                cin >> pos;
                if (type == 0)
                {
                    cin >> intitem;
                    mylist1.insert(pos, intitem);
                }
                else
                {
                    cin >> doubleitem;
                    mylist2.insert(pos, doubleitem);
                }
                break;
            }
            case 3:
            {
                cout << "Enter a position:\n";
                cin >> pos;
                if (type == 0)
                    mylist1.remove(pos);
                else
                    mylist2.remove(pos);
                break;
            }
            case 4:
            {
                cout << "Enter a position and a value:\n";
                cin >> pos;
                if (type == 0)
                {
                    cin >> intitem;
                    mylist1.setitem(pos, intitem);
                }
                else
                {
                    cin >> doubleitem;
                    mylist2.setitem(pos, doubleitem);
                }
                break;
            }
            case 5:
            {
                cout << "Enter a position:\n";
                cin >> pos;
                if (type == 0)
                {
                    result1 = mylist1.getitem(pos);
                    cout << result1 << "\n";
                }
                else
                {
                    result2 = mylist2.getitem(pos);
                    cout << result2 << "\n";
                }
                break;
            }
            case 6:
            {
                cout << "Enter a value:\n";
                if (type == 0)
                {
                    cin >> intitem;
                    boolresult = mylist1.member(intitem);
                }
                else
                {
                    cin >> doubleitem;
                    boolresult = mylist2.member(doubleitem);
                }
                cout << boolresult << "\n";
                break;
            }
            case 7:
            {
                if (type == 0)
                    result1 = mylist1.getlength();
                else
                    result1 = mylist2.getlength();
                cout << result1 << "\n";
                break;
            }
            case 8:
            {
                if (type == 0)
                {
                    AList<int> mylistnew1 = AList<int>(10);
                    do
                    {
                        cout << "Do you want to enter more list elements?\n";
                        cout << "1: yes  anything else: no\n";
                        cin >> yes;
                        if (yes == 1)
                        {
                            cout << "Enter a value for your new list:\n";
                            cin >> intitem;
                            mylistnew1.append(intitem);
                        }
                    }
                    while (yes == 1);
                    mylist1.concat(mylistnew1);
                }
                else
                {
                    AList<double> mylistnew2 = AList<double>(10);
                    do
                    {
                        cout << "Do you want to enter more list elements?\n";
                        cout << "1: yes  anything else: no\n";
                        cin >> yes;
                        if (yes == 1)
                        {
                            cout << "Enter a value for your new list:\n";
                            cin >> doubleitem;
                            mylistnew2.append(doubleitem);
                        }
                    }
                    while (yes == 1);
                    mylist2.concat(mylistnew2);
                }
                break;
            }
            case 9:
            {
                if (type == 0)
                {
                    AList<int> mylistnew1 = AList<int>(10);
                    do
                    {
                        cout << "Do you want to enter more list elements?\n";
                        cout << "1: yes  anything else: no\n";
                        cin >> yes;
                        if (yes == 1)
                        {
                            cout << "Enter a value for your new list:\n";
                            cin >> intitem;
                            mylistnew1.append(intitem);
                        }
                    }
                    while (yes == 1);
                    boolresult = mylist1.sublist(mylistnew1);
                }
                else
                {
                    AList<double> mylistnew2 = AList<double>(10);
                    do
                    {
                        cout << "Do you want to enter more list elements?\n";
                        cout << "1: yes  anything else: no\n";
                        cin >> yes;
                        if (yes == 1)
                        {
                            cout << "Enter a value for your new list:\n";
                            cin >> doubleitem;
                            mylistnew2.append(doubleitem);
                        }
                    }
                    while (yes == 1);
                    boolresult = mylist2.sublist(mylistnew2);
                }
                if (boolresult == true)
                {
                    cout << "The new list is a sublist.\n";
                }
                else
                    cout << "The new list is not a sublist.\n";
                break;
            }
            case 10:
            {
                if (type == 0)
                {
                    AList<int> mylistnew1 = AList<int>(10);
                    do
                    {
                        cout << "Do you want to enter more list elements?\n";
                        cout << "1: yes  anything else: no\n";
                        cin >> yes;
                        if (yes == 1)
                        {
                            cout << "Enter a value for your new list:\n";
                            cin >> intitem;
                            mylistnew1.append(intitem);
                        }
                    }
                    while (yes == 1);
                    boolresult = mylist1.equal(mylistnew1);
                }
                else
                {
                    AList<double> mylistnew2 = AList<double>(10);
                    do
                    {
                        cout << "Do you want to enter more list elements?\n";
                        cout << "1: yes  anything else: no\n";
                        cin >> yes;
                        if (yes == 1)
                        {
                            cout << "Enter a value for your new list:\n";
                            cin >> doubleitem;
                            mylistnew2.append(doubleitem);
                        }
                    }
                    while (yes == 1);
                    boolresult = mylist2.sublist(mylistnew2);
                }
                if (boolresult == true)
                {
                    cout << "The new list is equal.\n";
                }
                else
                    cout << "The new list is not equal.\n";
                break;
            }
            case 11:
            {
                if (type == 0)
                {
                    int numelements = mylist1.getlength();
                    for (int i = 1; i <= numelements; ++i)
                    {
                        intitem = mylist1[i];
                        cout << "List element " << i << " is " << intitem <<".\n";
                    }
                }
                else
                {
                    int numelements = mylist2.getlength();
                    for (int i = 1; i <= numelements; ++i)
                    {
                        doubleitem = mylist2[i];
                        cout << "List element " << i << " is " << doubleitem <<".\n";
                    }
                }
                break;
            }
            case 12:
            {
                if (type == 0){
                    cout << "hello" << ".\n";
                    cout << "the length of alist is " << mylist1.src_length(mylist1) << ".\n";
                }
                else{
                    cout << "hello" << ".\n";
                    cout << "the length of alist is " << mylist2.src_length(mylist2) << ".\n";
                }
                break;
            }
            case 13:
            {
                if (type == 0){
                    //cout << "hello" << ".\n";
                    mylist1.src_apply(int_test_case_1,mylist1);
                }
                else{
                    //cout << "hello" << ".\n";
                    mylist2.src_apply(double_test_case_1,mylist2);
                }
                break;
            }
            case 14:
            {
                if (type == 0){
                    //cout << "hello" << ".\n";
                    mylist1.src_condition(int_test_case_2,mylist1);
                }
                else{
                    mylist2.src_condition(double_test_case_2,mylist2);
                }
                break;
            }
            default: return(0);
        }
    }
    while (op != 0);
    return(0);
}
    }
    

int int_test_case_1(int i)
{
    return 5*i;
}

double double_test_case_1(double i)
{
    return 5*i;
}

int int_test_case_2(int i)
{
    if (i > 5){
        return 1;
    }
    return 0;
}

double double_test_case_2(double i)
{
    if (i > 5){
        return 1;
    }
    return 0;
}
