/* Put your decleration here */
template<class T> class Node {
    public:
        T key;
        int degree;
        Node<T> *left;
        Node<T> *right;
        Node<T> *child;
        Node<T> *parent;
        bool marked;
        Node(T value)
        {
            key    = value;
            degree = 0;
            marked = false;
            left = this;
            right = this
            parent = NULL;
            child =NULL;
        }
};

template<class T> class FibHeap{
    public:
        FibHeap();
        ~FibHeap();
        /* You should add other functions to make the structure as Fibonacci heap  */
        /* It is part of computing assignment, so we would not provide the basic implementation for you */
        void Insert(T key);
        void Delete_min();
        void Print(Node<T> *node, Node<T> *prev, int direction);
        void combine(FibHeap<T> *other)
        int minimum(T **minikey);
        
        /* The following is required for this assignment */
        /* It is not complete, you should design the API by yourself */
        void Change_Key(T oldkey, T newKey);
        void Destroy();
    private:
        int keyNum;
        int max_Degree;
        Node<T> *min;
        Node<T> *temp; //temp area for consolidate operation
        void deleteNode(Node<T> *fibnode);        //remove node from double link list
        void addNode(Node<T>* fibnode, Node<T>* root);   //add node in to the list of root
        void catList(Node<T> *first, Node<T> *right);    //combine two lists
        Node<T> *extractMin();      //remove minimal node from root list
        void linkToR(Node<T> *fibnode, Node<T> *root);     //link a node to root node
        void mkCon();   //make space for consolidate operation
        void consolidate(); //consolidate
        void updateDeg(Node<T> *parent, int degree);    //update degree for parent Node
        void updateKey(Node<T> *node, T key); 
        void cut(Node<T> *child, Node<T> *parent);  //cut a node from its  parent, add it to root
        void cascadedCut(Node<T> *fibnode);
        Node<T>* extractMin();
        Node<T>* find(T key);
        Node<T>* find(Node<T> *root, T key) // find node in min_heap

};

