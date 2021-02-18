//
// Created by Hujiarun on 2021/2/17.
//
#include "deque.h"
#include <iostream>
#include <stack>
using namespace std;

template<class T> void Queue<T>::enqueue(const T &t) {
    stack1.push(t);
}

template<class T> void Queue<T>::dequeue() {
    if(stack2.size() == 0) {
        while (stack1.size() > 0) {
            //pop all the elements in stack1 and push them into stack 2
            T temp = stack1.top();
            stack1.pop();
            stack2.push(temp);
        }
    }
    if (stack2.size() > 0) {
        T temp = stack2.top();
        stack2.pop();
        cout<<temp<<endl;
    }
    else
        cout << "no elements." << endl;
}

template<class T> bool Queue<T>::empty() {
    if(!stack1.size() && !stack2.size())
        return true;
    else
        return false;
}

template<class T> void Queue<T>::display() {
    stack<T> temp_stack;
    temp_stack=stack1;
    while (!temp_stack.empty()) {
        cout<<temp_stack.top()<<" ";
        temp_stack.pop();
    }
    temp_stack=stack2;
    while (!temp_stack.empty()) {
        cout<<temp_stack.top()<<" ";
        temp_stack.pop();
    }
    cout<<endl;
}