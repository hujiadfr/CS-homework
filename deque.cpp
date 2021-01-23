#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "deque.h"
using std::cout;
using std::cin;

template<class T> T &Deque<T>::operator[](int index)
{
    return reprarray[index];
}

template<class T> void Deque<T>::pushback(int value)
{
    reprarray[rear] = value;
    rear = (rear+1) % maxsize;
    numitems++;
    if (full()) {
        allocate();
        clear();
    }
}

template<class T> void Deque<T>::pushfront(int value)
{
    reprarray[head] = value;
    head = (head-1) % maxsize;
    numitems++;
    if (full()) {
        allocate();
        clear();
    }
}

template<class T> void Deque<T>::popback(void)
{
    if (empty()) {
        cout << "Error! The list is empty.";
        return;
    }
    rear = (rear-1) % maxsize;
    reprarray[rear] = 0;
    numitems--;
    if (less()) {
        deallocate();
        clear();
    }
}

template<class T> void Deque<T>::popfront(void)
{
    if (empty()) {
        cout << "Error! The list is empty.";
        return;
    }
    head = (head+1) % maxsize;
    reprarray[head] = 0;
    numitems--;
    if (less()){
        deallocate();
        clear();
    }
}

template<class T> void Deque<T>::allocate()
{
    int newsize = 2 * maxsize;
    int *newarray = new int[newsize];
    for (int i = 1; i <= numitems; ++i)
    {
        newarray[i] = reprarray[(head+i) % maxsize];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void Deque<T>::deallocate()
{
    int newsize = maxsize / 2;
    int *newarray = new int[newsize];
    for (int i = 1; i <= numitems; ++i)
    {
        newarray[i] = reprarray[(head+i) % maxsize];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return; 
}
template<class T> bool Deque<T>::full()
{
    if ((head-1) % maxsize == rear)
    {
        return true;
    }
    return false;
}

template<class T> bool Deque<T>::empty()
{
    if ((head+1) % maxsize == rear)
    {
        return true;
    }
    return false;
}

template<class T> bool Deque<T>::less(void)
{
    if((numitems+2)==maxsize/4)
    {
        return true;
    }
    return false;
}

template<class T> int Deque<T>::getlength(void)
{
    return numitems;
}

template<class T> void Deque<T>::clear(void)
{
    head = 0;
    rear = 1;
}

