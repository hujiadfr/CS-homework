/* Put your decleration here */
using namespace std;

template<class T> class element{
    public:
        T value;
        int num;    
    private:
};



template<class T> class MultiSet{
    public:
        MultiSet(int size = 20);
        T &operator[](int index);
        int getlength(void);
        
        /* The following is required for this assignment */
        void insertion( T value);                                      
        void deletion(T value);
        void retrieval(T value);

        void display(void);
        void display_op(void);

        MultiSet<T> setunion(MultiSet<T> &set_1,MultiSet<T> &set_2);
        MultiSet<T> intersection(MultiSet<T> &set_1,MultiSet<T> &set_2);
        MultiSet<T> difference(MultiSet<T> &set_1,MultiSet<T> &set_2);

    private:
        int maxsize, minsize;
        int numitems;
        element<T> *reprarray;
        void allocate(void);
        void deallocate(void);
};

template<class T> MultiSet<T>::MultiSet(int size)
{
    maxsize = size;
    if (size < 20)
        minsize = size;
    else
        minsize = 20;
    numitems = 0;
    reprarray = new element<T>[maxsize];
}

// The definition of hash with chaining 
#ifndef dlist_h
#define dlist_h

template<class T> class DList;

template<class T> class node
{
    friend class DList<T>;
public:
    node(T item = 0, node<T> *pt_n = 0, node<T> *pt_p = 0);
//    virtual ~node(void);
    T getdata(void);
    node<T> *getnext(void);
    node<T> *getprevious(void);
    void setdata(T item);
    void setnext(node<T> *pt);
    void setprevious(node<T> *pt);
private:
    T dataitem;
    node<T> *pt_next;
    node<T> *pt_previous;
};

template<class T> class DList
{
public:
    DList(void);
//    virtual ~DList();
    T operator[](int index);
    int getlength(void);
    void setitem(int index, T value);
    T getitem(int index);
    void append(T value);
    void insert(int index, T value);
    void remove(int index);
    void concat(DList<T> *dlist);
    bool member(T value);
    bool equal(DList<T> *dlist);
    bool sublist(DList<T> *dlist);
    void _pprint_(void);            /* Help function to display the DList */
    /****************** TODO **********************/
    /* Implement your solution in solution.h file */
    void reverse(void);

private:
    node<T> *dummy;
    int numitems;
    node<T> *locate(int index);
    node<T> *first(void);
    node<T> *last(void);
};

#endif /* dlist_h */







/* Put your decleration here */
#ifndef hashset_h
#define hashset_h

template<class T> class MultiSet_Chaining
{ 
public:
    MultiSet_Chaining(int size = 20);
//    virtual ~hashset();
    T &operator[](int index);
// The operation add inserts an element into the hashtable, remove deletes an
// element and member checks, if the element is in the hashtable
    void insertion(T item);
    void deletion(T item);
    bool retrieval(T item);
// The function display is only used for testing purposes. It shows the size of
// the hashtable, the number of elements, and displays all entries
    void display(void);
    void multiunion(MultiSet_Chaining<T> *set1,MultiSet_Chaining<T> *set2);
    void intersect(MultiSet_Chaining<T> *set1,MultiSet_Chaining<T> *set2, MultiSet_Chaining<T> *set3);
    void difference(MultiSet_Chaining<T> *set1,MultiSet_Chaining<T> *set2);

    int numitems;           // contains the number of elements in the hashtable
    DList<T> *reprarray;
/* reprarray defines a pointer to (an array of) pointers to values of type T. We will use a null pointer, if an entry is undefined, and a fixed pointer as placeholder for free entries (after remove) */
    T *pt_nil;              // used as placeholder
    int maxsize;            // defines the size of the hashtable

private:
        void rehash(int newsize);
// rehash is an internal function to enlarge or shrink the hashtable,
// if the fill factors 0.75 or 0.25 are exceeded or undershot, resp.
};

#endif /* hashset_h */
