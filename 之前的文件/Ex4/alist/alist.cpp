//
//  alist.cpp
//  
//
//  Created by KD on 14.01.21.
//

#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "alist.h"
using std::cout;
using std::cin;

template<class T> T &AList<T>::operator[](int index)
{
    return reprarray[index - 1];
}

template<class T> int AList<T>::getlength(void)
{
    return numitems;
}

template<class T> void AList<T>::setitem(int index, T value)
{
    if ((index > 0) && (index <= numitems))
    {
        reprarray[index - 1] = value;
        return;
    }
    else
        cout << "Index error: index out or range\n";
}

template<class T> T AList<T>::getitem(int index)
{
    if ((index > 0) && (index <= numitems))
    {
        return reprarray[index - 1];
    }
    else
    {
        cout << "Index error: index out or range\n";
        exit(EXIT_FAILURE);
    }
}

template<class T> void AList<T>::append(T value)
{
    if (numitems == maxsize)
        allocate();
    reprarray[numitems] = value;
    ++numitems;
    return;
}

template<class T> void AList<T>::insert(int index, T value)
{
    if (numitems == maxsize)
        allocate();
    if (index < numitems)
    {
        for (int j = numitems - 1; j >= index; --j)
        {
            reprarray[j+1] = reprarray[j];
        }
        reprarray[index] = value;
        ++numitems;
        return;
    }
    else
    {
        append(value);
        return;
    }
}

template<class T> void AList<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::remove(int index)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    if (index < numitems)
    {
        for (int j = index; j < numitems; ++j)
        {
            reprarray[j-1] = reprarray[j];
        }
        --numitems;
        return;
    }
    else
        cout << "Index error: list index out of range\n";
}

template<class T> void AList<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void AList<T>::concat(AList<T> &list)
{
    int length = list.getlength();
    for (int i = 1; i <= length; ++i)
    {
        append(list[i]);
    }
    return;
}

template<class T> bool AList<T>::member(T value)
{
    bool result = false;
    for (int i = 0; i < numitems; ++i)
    {
        if (reprarray[i] == value)
        {
            result = true;
            break;
        }
    }
    return result;
}

template<class T> bool AList<T>::equal(AList<T> &list)
{
    bool result = true;
    if (numitems == list.getlength())
    {
        for (int i = 0; i < numitems; ++i)
        {
            if (reprarray[i] == list[i + 1])
                continue;
            else
            {
                result = false;
                break;
            }
        }
    }
    else
        result = false;
    return result;
}

template<class T> bool AList<T>::sublist(AList<T> &list)
{
    int length = list.getlength();
    bool result = true;
    for (int i = 1, j = 0; (i <= length) && (j < numitems); ++i, ++j)
    {
        if (list[i] == reprarray[j])
        {
            if ((j == numitems - 1) && (i < length))
            {
                result = false;
                break;
            }
        }
        else
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
                --i;
    }
    return result;
}
template<class T>void AList<T>::selectionSort(void)
{
    int i,j;
    int mid;
    for (i = 0 ; i < numitems - 2 ; i++) 
    {
                int min = i;
                for (j = i + 1; j < numitems - 1; j++)
                        if (reprarray[j] < reprarray[min])
                                min = j;
                mid = reprarray[min];
                reprarray[min] = reprarray[i];
                reprarray[i] = mid;
        }
}

template<class T>int AList<T>::binarySearch(int target, int left, int right)
{
	int mid = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (target < reprarray[mid])
            right = mid - 1;
        else if (target > reprarray[mid])
            left = mid + 1;
        else
            return mid;
    }
    return left;
}

template<class T>void AList<T>::insertionSort(void) //flag show how to sort
{
    int temp, index;
    int j, i;
    for (i = 1; i < numitems; i++)
    {
        temp = reprarray[i];
        index = binarySearch(temp, 0, i - 1);
        for(j = i - 1; j >= index; j--)
            reprarray[j + 1] = reprarray[j];
        reprarray[j + 1] = temp;
    }
}


template<class T>void AList<T>::bubbleSort(void)
{
	int m,i,j;
	for(i=0;i<numitems-1;i++)
		for(j=0;j<numitems-1-i;j++)
			if(reprarray[j]>=reprarray[j+1])
			{
				m=reprarray[j];
				reprarray[j]=reprarray[j+1];
				reprarray[j+1]=m;
			}
}