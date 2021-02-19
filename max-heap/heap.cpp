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
    int child = 2*parent + 1;
    if(child < length)
    {
        if(child + 1 < length && tree[child] < tree[child+1])
            child ++;
        if(temp >=tree[child]) //if parent is larger than child, then function end.
            return;
        tree[parent] = tree[child];
        tree[child] = temp;
        HeapAdjust(child, length);
    }
}

template<class T> void heap<T>::HeapSort()
{
    int length  = tree.size();
    if(length == 0) return;
    for(int i = length/2; i>=0; i--)
        HeapAdjust(i, length);
    for(int i = length - 1; i>0; i--) //exchange the top and the bottom
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