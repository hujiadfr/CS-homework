#include <iostream>
#include "heap.cpp"
int main() {
    heap<double> heap1;
    for(int i=5; i >= 1; i--)
    {

        heap1.add(i);
    }
    heap1.HeapSort();
    heap1.print();

}
