#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "dlist.h"
using std::cout;
using std::cin;

template<class T> T node<T>::get()
{
    return data;
}
template<class T>node<T>* node<T>::getnext()
{
    return next;
}
template<class T>node<T>* node<T>::getprevious()
{
    return previous;
}
template<class T> void node<T>::setnext(node<T> *pt)
{
    next = pt;
    return;
}
template<class T> void node<T>::setprevious(node<T> *pt)
{
    previous = pt;
    return;
}
template<class T>void Deque<T>::print(void)
{
    if (num == 0)
	{
		cout << "deque is empty\n";
		return;
	}
	node<T>*p = queue_left;
	for (int i = 0; i < num-1; i++) {
		cout << p->get() << " ";
		p = p->getnext();
	}
	cout << p->get() << "\n";
}

template<class T>void Deque<T>::pushfront(T n)
{
    node<T>*p = new node<T>(n);
	if (num == 0)
	{
		queue_left = queue_right = p;
		queue_left->setprevious(nullptr);
        queue_left->setnext(nullptr);
		num++;
	}
	else
    {
		queue_left->setprevious(p);
		p->setnext(queue_left);
		queue_left = queue_left->getprevious();
		num++;
	}
}
template<class T>void Deque<T>::pushback(T n)
{
    node<T>*p = new node<T>(n);
	if (num == 0)
	{
		queue_left = queue_right = p;
		queue_right->setprevious(nullptr);
        queue_right->setnext(nullptr);
		num++;
	}
	else 
    {
		queue_right->setnext(p);
		p->setprevious(queue_right);
		queue_right = queue_right->getnext();
		num++;
	}
}
template<class T>void Deque<T>::popfront(void)
{
    if (num == 0) {
		cout << "deque is empty\n";
		return;
	}
	node<T>*p = queue_left->getnext();
	delete queue_left;
	queue_left = p;
	num--;
}

template<class T>void Deque<T>::popback(void)
{
    if (num == 0) {
		cout << "EMPTY\n";
		return;
	}
	node<T>*p = queue_right->getprevious();
	delete queue_right;
	queue_right = p;
	num--;
}