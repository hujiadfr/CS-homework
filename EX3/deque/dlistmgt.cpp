#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "dlist.cpp"
using std::cout;
using std::cin;

int main()
{
    Deque<int> mylist1 = Deque<int>();
    //Deque<double> mylist2 = Deque<double>();
    mylist1.print();
    for(int i = 1; i <= 10; i++)
    {
        mylist1.pushfront(i);
        mylist1.pushback(i);
    }
    mylist1.print();
    mylist1.popback();
    mylist1.popback();
    mylist1.print();
    return 0;
}