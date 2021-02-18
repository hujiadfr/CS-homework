//
// Created by Hujiarun on 2021/2/18.
//

#ifndef MAX_HEAP_HEAP_H
#define MAX_HEAP_HEAP_H
#include <vector>
using namespace std;

template<class T> class heap {
public:
    void HeapSort();
    void add(T value);
    void print();
private:
    vector<T> tree;
    void HeapAdjust(int parent, int length);
};


#endif //MAX_HEAP_HEAP_H
