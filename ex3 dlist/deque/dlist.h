#ifndef deque_h
#define deque_h
template<class T> class node
{
    public:
        void setnext(node<T> *pt);
        void setprevious(node<T> *pt);
        T set();
        T get();
        node<T>* getnext();
        node<T>* getprevious();
        node()
        {
            data = 0;
            previous = next = nullptr;
        }
        node(T n){
            data = n;
            previous = next = nullptr;
        }
    private:
        T data;
        node<T> *previous;
        node<T> *next;

};
template<class T> class Deque
{
    private:
        node<T>*queue_left, *queue_right;
        int num;
    public:
        Deque()
        {
            queue_left = queue_right = nullptr;
            num = 0;
        }
        void pushback(T n);
        void pushfront(T n);
        void popback(void);
        void popfront(void);
        void print(void);
};


#endif /* deque_h */