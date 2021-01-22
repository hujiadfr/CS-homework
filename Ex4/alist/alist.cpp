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
template<class T> int AList<T>::getSmallestItem(void)
{
    T minimum;
    int index;
    for(int i = 0; i < numitems; ++i)
    {
        if(minimum > reprarray[i])
            minimum = reprarray[i];
            index = i + 1;
    }
    return index;
}
template<class T> int AList<T>::getLargestItem(void)
{
    T maximum;
    int index;
    maximum = reprarray[0];
    index = 1;
    for(int i = 0; i < numitems; ++i)
    {
        if(maximum < reprarray[i])
            maximum = reprarray[i];
            index = i + 1;
    }
    return index;
}

template<class T>void AList<T>::selectionSort(void)
{
    int newsize = maxsize;
    int index;
    T *newarray = new T[newsize];
    for (int i = 0; i < numitems; ++i)
    {
    	index = getSmallest();
        newarray[i] = reprarray[index-1];
        remove(index);
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T>int AList<T>::binarySearch(int target, &T newarray)
{
	int left = 0;
	int right = numitems - 1;
	int mid;
		while(left < right)
		{
			mid = (left + right) / 2
			if(newarray[mid] == target)
				right = mid;
			else if (newaray[mid] < target)
				left = mid + 1;
			else if(newarray[mid] > target)
				right = mid;
		}
		return left;
	
}

template<class T>void AList<T>::insertionSort(void) //flag show how to sort
{
	int newsize = maxsize;
	int newitems = 0;
    int index;
    T *newarray = new T[newsize];
    newarray[0] = reprarray[0];
    for (int i = 1; i < numitems; ++i)
    {
    	index = binarySearch(reprarray[i], flag, newarray);
    	if (index < newitems)
    	{
        	for (int j = newitems - 1; j >= index; --j)
        	{
            	newarray[j+1] = newarray[j];
        	}
        		newarray[index] = reprarray[i];
        		++newitems;
   		}
    	else
    	{
        	newarray[newitems] = reprarray[i];
        	++newitems;
    	}
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T>void AList<T>::bubbleSort(void)
{
	int m,i,j;
	for(i=0;i<numitems-1;i++)
		for(j=0;j<numitems-1-i;j++)
			if(reprarray[j]>=arr[j+1])
			{
				m=reprarry[j];
				reprarry[j]=reprarry[j+1];
				reprarry[j+1]=m;
			}
}