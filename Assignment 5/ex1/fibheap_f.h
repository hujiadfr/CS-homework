#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "fibheap.h"
#include  <math.h>
using std::cin;
using std::cout;
using std::endl;

/*initiallize*/
template<class T> FibHeap<T>::FibHeap()
{
    keyNum = 0;
    max_Degree = 0;
    min -> nullptr;
    temp-> nullptr;
}

template<class T> FibHeap<T>::~FibHeap() {}

template<class T> void FibHeap<T>::deleteNode(Node<T> *fibnode)
{
    fibnode->left->right = node->right;
    node->right->left = node->left;
}

template<class T> void FibHeap<T>::addNode(Node<T>* fibnode, Node<T>* root)
{
    fibnode->left = root->left;
    root->left->right = fibnode;
    fibnode->right = root;
    root->left = fibNode;
}

template <class T> void FibHeap<T>::Insert(T key)
{
    node<T> *fibnode
    fibnode = new node<T>(key);
    if(node == NULL)
        return;
    
    if(keyNum == 0)
        min = fibnode;
    else
    {
        addNode(node,min);
        if(fibnode->key < min->key)
            min = fibnode;
    }
    keyNum++;
}

template<class T> void FibHeap<T>::catList(Node<T> *a, Node<T> *b)
{
    Node<T> *tmp_p;
    tmp_p = a->right;
    a->right = b->right;
    b->right->left = a;
    b->right = tmp_p;
    tmp_p->left = b;
}

template<class T> void FibHeap<T>::combine(FibHeap<T> *other)
{
    if (other == NULL)
        return;
    if(other->max_Degree > this->max_Degree)
        swap(*this, *other);
    if((this->min) == NULL)
    {
        this->min = other->min;
        this->keyNum = other->keyNum;
        free(other->temp);
        delete other;
    }
    else if((other->min) == NULL)
    {
        free(other->temp);
        delete other;
    }
    else
    {
        catList(this->min, other->min);
        if(this->min->key > other->min->key)
            this->min = other->min;
        this->keyNum += other->keyNum;
        free(other->temp);
        delete other;
    }
}

template <class T> Node<T>* FibHeap<T>::extractMin()
{
    Node<T> *result = min;
    if(result == result->right)
        min = NULL;         //no points left
    else
    {
        removeNode(result);
        min = result->right;
    }
    result->left = result->right = result;
    return result;
}

template<class T> void FibHeap<T>::linkToR(Node<T> *fibnode, Node<T> *root)
{
    removeNode(fibnode);
    //remove node from double link
    if(root->child == NULL)
        root->child = fibnode;
    else
        addNode(fibnode, root->child);
    fibnode->parent = root;
    root->degree++;
    fibnode->marked = false;
}

template<class T> void FibHeap<T>::mkCon()
{
    int origin = max_Degree;
    max_Degree = (log(KeyNum)/log(2)) +1;
    if(origin >= max_Degree)
        return; //no necessary
    temp  = (FibNode<T> **)realloc(temp, sizeof(FibHeap<T> *) * (max_Degree + 1));
}

template<class T> void FibHeap<T>::consolidate()
{
    FibNode<T> *a, *b;
    mkCon();
    for(int i = 0; i < max_Degree + 1; ++i);
        cons[i] = NULL;
    while(min != NULL)
    {
        a = extractMin();
        int temp_d = a->degree;
        while (temp[a->degree] != NULL)
        {
            b = temp[a->degree];
            
            if(a->key > b->key)
                swap(a, b);
            linkToR(b, a);
            temp[temp_d] = NULL;
            temp_d++;
        }
        temp[temp_d] = x;
    }
    min = NULL;
    for(int i = 0; i < max_Degree+1; i++)
    {
        if(temp[i] != NULL)
        {
            if(min == NULL)
            {
                if(min == NULL)
                    min = temp[i];
                else
                {
                    addNode(temp[i], min);
                    if((temp[i]->key < min->key))
                        min = cons[i];
                }
            }
        }
    }
}

template<class T> void FibHeap<T>::Delete_min()
{
    if(min == NULL)
        return;
    Node<T> *child = NULL;
    Node<T> *m = min;
    while(m->child != NULL)
    {
        child = m->child;
        removeNode(child);
        if(child->right == child)
            m->child = NULL;
        else
            m->child = child->right;
        addNode(child, min);
        child->parent = NULL;
    }
    removeNode(m);
    if(m->right == m)
        min = NULL;
    else
    {
        min = m->right;
        consolidate();
    }
    keyNum--;
    delete m;
}

template <class T>void FibHeap<T>::updateDeg(Node<T> *parent, int degree)
{
    parent->degree -= degree;
    if(parent->parent !=NULL)
        updateDeg(parent->parent, degree);
}