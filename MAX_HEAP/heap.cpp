//
// Created by Hujiarun on 2021/2/18.
//

#include "heap.h"
#include <vector>
#include <iostream>

template<class T> void heap<T>::HeapAdjust(int parent, int length)
{
    //child parent records the index
    T temp = tree[parent];
    int child;
    for(child = 2*parent+1; child < length; child = child*2+1)
    {
        if(child + 1 < length && tree[child] < tree[child+1])
            child++;
        if(temp > tree[child]) break; //child smaller then parent, break to next child
        tree[parent] = tree[child];
        parent = child;
    }
    tree[parent] = temp;
}

template<class T> void heap<T>::HeapSort()
{
    int length  = tree.size();
    if(length == 0) return;
    for(int i = length/2-1; i>=0; i--) //build a heap firstly
        HeapAdjust(i, length);
    for(int i = length - 1; i > 0; i--) //exchange the top and the bottom
    {
        int temp = tree[i];
        tree[i] = tree[0];
        tree[0] = temp;
        HeapAdjust(0,i);
    }
}

template<class T> void heap<T>::print()
{
    int length = tree.size();
    for(int i = 1; i <= length; i++)
        cout<<tree[i-1]<<" ";
    cout<<endl;
}

template<class T> void heap<T>::add(T value)
{
    tree.push_back(value);
}