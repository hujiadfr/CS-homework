#include <iostream>
#include "deque.cpp"
using namespace std;
int main() {
    Queue<int> deque1;
    Queue<double> deque2;
    cout<<"Choose the type of FIFO\n";
    cout<<"0:int 1:double\n";
    int opt;
    cin>>opt;
    if(opt == 0) {
        int opt2;
        while (1) {
            cout << "0: enqueue, 1:dequeue, 2:print queue, 3:quit\n";
            cin >> opt2;
            switch (opt2) {
                case 0:
                    int value;
                    cout << "input your value\n";
                    cin >> value;
                    deque1.enqueue(value);
                    deque1.display();
                    break;
                case 1:
                    deque1.dequeue();
                    deque1.display();
                    break;
                case 2:
                    deque1.display();
                default:
                    return 0;
            }
        }
    }
    else {
        int opt2;
        while (1) {
            cout << "0: enqueue, 1:dequeue, 2:print queue, 3:quit\n";
            cin >> opt2;
            switch (opt2) {
                case 0:
                    int value;
                    cout << "input your value\n";
                    cin >> value;
                    deque2.enqueue(value);
                    deque2.display();
                    break;
                case 1:
                    deque2.dequeue();
                    deque2.display();
                    break;
                case 2:
                    deque2.display();
                default:
                    return 0;
            }
        }
    }
}
