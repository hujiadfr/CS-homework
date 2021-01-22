

#include <stdio.h>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::cin;


template<class T> class DList;

template<class T> class node
{
    friend class DList<T>;
public:
    node(T item = 0, node<T> *pt_n = 0, node<T> *pt_p = 0);
//    virtual ~node(void);
    T getdata(void);
    node<T> *getnext(void);
    node<T> *getprevious(void);
    void setdata(T item);
    void setnext(node<T> *pt);
    void setprevious(node<T> *pt);
private:
    T dataitem;
    node<T> *pt_next;
    node<T> *pt_previous;
};

template<class T> class DList
{
public:
    DList(void);
//    virtual ~DList();
    T operator[](int index);
    int getlength(void);
    void setitem(int index, T value);
    T getitem(int index);
    void append(T value);
    void insert(int index, T value);
    void remove(int index);
    void concat(DList<T> *dlist);
    bool member(T value);
    bool equal(DList<T> *dlist);
    bool sublist(DList<T> *dlist);
    //this is my new code
    void delete_last(DList<T> *dlist, int k);
private:
    node<T> *dummy;
    int numitems;
    node<T> *locate(int index);
    node<T> *first(void);
    node<T> *last(void);
};


//
//  dlist.cpp
//  
//
//  Created by KD on 16.01.21.
//


template<class T> node<T>::node(T item, node<T> *pt_n, node<T> *pt_p)
{
    dataitem = item;
    pt_next = pt_n;
    pt_previous = pt_p;
}

template<class T> T node<T>::getdata(void)
{
    return dataitem;
}

template<class T> node<T> *node<T>::getnext(void)
{
    return pt_next;
}

template<class T> node<T> *node<T>::getprevious(void)
{
    return pt_previous;
}

template<class T> void node<T>::setdata(T item)
{
    dataitem = item;
    return;
}

template<class T> void node<T>::setnext(node<T> *pt)
{
    pt_next = pt;
    return;
}

template<class T> void node<T>::setprevious(node<T> *pt)
{
    pt_previous = pt;
    return;
}

template<class T> DList<T>::DList(void)
{
    dummy = new node<T>;
    (*dummy).setnext(dummy);
    (*dummy).setprevious(dummy);
    numitems = 0;
}

//template<class T> DList<T>::~DList()
//{
//    delete[] reprarray;
//}

template<class T> T DList<T>::operator[](int index)
{
    T val = getitem(index);
    return val;
}

template<class T> int DList<T>::getlength(void)
{
    return numitems;
}

template<class T> node<T> *DList<T>::last(void)
{
    return (*dummy).getprevious();
}

template<class T> node<T> *DList<T>::first(void)
{
    return (*dummy).getnext();
}

template<class T> void DList<T>::append(T value)
{
    node<T> *lpt;
    lpt = last();
    node<T> *pt = new node<T>;
    (*pt).setdata(value);
    (*pt).setnext(dummy);
    (*pt).setprevious(lpt);
    (*dummy).setprevious(pt);
    (*lpt).setnext(pt);
    ++numitems;
    return;
}

template<class T> node<T> *DList<T>::locate(int index)
{
    if ((index <= 0) || (index > numitems))
    {
        cout << "Error: index out of range.\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        node<T> *pt;
        pt = (*dummy).getnext();
        for (int i = 1; i < index; ++i)
        {
            pt = (*pt).getnext();
        }
        return pt;
    }
}

template<class T> void DList<T>::setitem(int index, T value)
{
    node<T> *pt;
    pt = locate(index);
    (*pt).setdata(value);
    return;
}

template<class T> T DList<T>::getitem(int index)
{
    node<T> *pt;
    pt = locate(index);
    return (*pt).getdata();
}

template<class T> void DList<T>::insert(int index, T value)
{
    node<T> *pt_i;
    pt_i = locate(index);
    node<T> *pt_i1;
    pt_i1 = (*pt_i).getprevious();
    node<T> *pt_new = new node<T>;
    (*pt_new).setdata(value);
    (*pt_new).setnext(pt_i);
    (*pt_new).setprevious(pt_i1);
    (*pt_i).setprevious(pt_new);
    (*pt_i1).setnext(pt_new);
    numitems += 1;
    return;
}

template<class T> void DList<T>::remove(int index)
{
    node<T> *pt_i;
    pt_i = locate(index);
    node<T> *pt_i1;
    pt_i1 = (*pt_i).getprevious();
    node<T> *pt_i2;
    pt_i2 = (*pt_i).getnext();
    (*pt_i1).setnext(pt_i2);
    (*pt_i2).setprevious(pt_i1);
    numitems -= 1;
    return;
}

template<class T> void DList<T>::concat(DList<T> *dlist)
{
    int num = (*dlist).getlength();
    if (num > 0)
    {
        node<T> *lpt;
        lpt = last();
        node<T> *pt0;
        pt0 = (*dlist).dummy;
        node<T> *pt1;
        pt1 = (*pt0).getnext();
        (*pt1).setprevious(lpt);
        (*lpt).setnext(pt1);
        node<T> *pt2;
        pt2 = (*pt0).getprevious();
        (*dummy).setprevious(pt2);
        (*pt2).setnext(dummy);
        numitems += num;
    }
    return;
}

template<class T> bool DList<T>::member(T value)
{
    bool result = false;
    node<T> *pt;
    pt = (*dummy).getnext();
    for (int i = 0; i < numitems; ++i)
    {
        if ((*pt).getdata() == value)
        {
            result = true;
            break;
        }
        else
        {
            pt = (*pt).getnext();
        }
    }
    return result;
}

template<class T> bool DList<T>::equal(DList<T> *dlist)
{
    bool result = true;
    if ((*dlist).getlength() != numitems)
    {
        result = false;
    }
    else
    {
        node<T> *pt;
        pt = (*dummy).getnext();
        node<T> *pt0;
        pt0 = (*dlist).dummy;
        node<T> *pt_other;
        pt_other = (*pt0).getnext();
        for (int i = 0; i < numitems; ++i)
        {
            if ((*pt).getdata() != (*pt_other).getdata())
            {
                result = false;
                break;
            }
            else
            {
                pt = (*pt).getnext();
                pt_other = (*pt_other).getnext();
            }
        }
    }
    return result;
}

template<class T> bool DList<T>::sublist(DList<T> *dlist)
{
    bool result = true;
    node<T> *pt;
    pt = (*dummy).getnext();
    node<T> *pt0;
    pt0 = (*dlist).dummy;
    node<T> *pt_other;
    pt_other = (*pt0).getnext();
    int numother = (*dlist).getlength();
    for (int i = 0, j = 0; (i < numother) && (j < numitems); ++i, ++j)
    {
        if ((*pt_other).getdata() == (*pt).getdata())
        {
            if ((j == numitems - 1) && (i < numother - 1))
            {
                result = false;
                break;
            }
            pt = (*pt).getnext();
            pt_other = (*pt_other).getnext();
        }
        else
        {
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
            {
                pt = (*pt).getnext();
                --i;
            }
        }
        
    }
    return result;
}

template<class T> void DList<T>::delete_last(DList<T> *dlist, int k)
{
    for(;k > 0; k--)
    {
        node<T> *pt_i;
        pt_i = locate(numitems);
        node<T> *pt_i1;
        pt_i1 = (*pt_i).getprevious();
        node<T> *pt_i2;
        pt_i2 = (*pt_i).getnext();
        (*pt_i1).setnext(pt_i2);
        (*pt_i2).setprevious(pt_i1);
        numitems -= 1;
    }
    return;
}

int main()
{
    int type, op;
    int pos, yes;
    int intitem, result1;
    DList<int> mylist1 = DList<int>();
    DList<double> mylist2 = DList<double>();
    double doubleitem, result2;
    bool boolresult;
    do
    {
        cout << "Choose your element type:\n";
        cout << "0: int  1: double\n";
        cin >> type ;
        if ((type != 0) && (type != 1))
            cout << "You must choose 0 or 1\n\n";
    }
    while ((type != 0) && (type != 1));
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
            cout << "12: delete_last\n";
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
                    DList<int> mylistnew1 = DList<int>();
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
                    mylist1.concat(&mylistnew1);
                }
                else
                {
                    DList<double> mylistnew2 = DList<double>();
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
                    mylist2.concat(&mylistnew2);
                }
                break;
            }
            case 9:
            {
                if (type == 0)
                {
                    DList<int> mylistnew1 = DList<int>();
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
                    boolresult = mylist1.sublist(&mylistnew1);
                }
                else
                {
                    DList<double> mylistnew2 = DList<double>();
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
                    boolresult = mylist2.sublist(&mylistnew2);
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
                    DList<int> mylistnew1 = DList<int>();
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
                    boolresult = mylist1.equal(&mylistnew1);
                }
                else
                {
                    DList<double> mylistnew2 = DList<double>();
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
                    boolresult = mylist2.equal(&mylistnew2);
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
                if(type == 0)
                {
                    int k;
                    int numelements = mylist1.getlength();
                    cout << "Enter how many elements do you want to delete:\n";
                    cin >> k;
                    while (k > numelements)
                    {
                        cout << " a wrong number please enter again!\n";
                        cin >> k;
                    }
                    mylist1.delete_last(&mylist1, k);
                }
                else
                {
                    int k;
                    int numelements = mylist2.getlength();
                    cout << "Enter how many elements do you want to delete:\n";
                    cin >> k;
                    while (k > numelements)
                    {
                        cout << " a wrong number please enter again!\n";
                        cin >> k;
                    }
                    mylist2.delete_last(&mylist2, k);
                }
                break;
            }
            default: return(0);
        }
        
    }
    while (op != 0);
    return(0);
}
