//
// Created by Hujiarun on 2021/2/17.
//

#ifndef FIFO_DEQUE_H
#define FIFO_DEQUE_H
#include <iostream>
#include <stack>
using namespace std;
template<class T> class Queue{
public:
    void enqueue(const T& t);   //enter the queue;
    void dequeue();              //out the queue
    bool empty();               //judge whether it is empty
    void display();
private:
    stack<T> stack1;
    stack<T> stack2;
};

#endif //FIFO_DEQUE_H
