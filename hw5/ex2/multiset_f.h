#include "multiset.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <utility>
using namespace std;
using std::cout;
using std::cin;

/* Put your implementation here */

// MultiSet operations 
template<class T> T &MultiSet<T>::operator[](int index)
{
    return reprarray[index - 1].value;
}

template<class T> int MultiSet<T>::getlength(void)
{
    return numitems;
}



template<class T> void MultiSet<T>::allocate(void)
{
    int newsize = 2 * maxsize;
    element<T> *newarray = new element<T>[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i].value= reprarray[i].value;
        newarray[i].num= reprarray[i].num;
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void MultiSet<T>::deallocate(void)
{
    int newsize = maxsize / 2;
    element<T> *newarray = new element<T>[newsize];
    for (int i = 0; i < numitems; ++i)
    {
        newarray[i] = reprarray[i];
    }
    delete[] reprarray;
    reprarray = newarray;
    maxsize = newsize;
    return;
}

template<class T> void MultiSet<T>::insertion(T value)
{
    if (numitems == maxsize)
        allocate();
    bool find = false;
    bool success = false;
    for (int i = 0; i < numitems; i++)
    {
        if (reprarray[i].value == value)
        {
            reprarray[i].num++;
            find = true;
        }   
    } 
    if (find == false)
    {
        for (int i = 0; i < numitems; i++)
        {
            if (reprarray[i].value > value)
            {
                for (int j = numitems; j > i; j--)
                {
                    reprarray[j].value = reprarray[j-1].value;
                    reprarray[j].num = reprarray[j-1].num;   
                }
                reprarray[i].value = value;
                reprarray[i].num = 1;
                success = true;
                numitems++;
                break;
            }
        }
    }
    if (find == false && success == false)
    {
        reprarray[numitems].value = value;
        reprarray[numitems].num = 1;
        numitems++;
    }
    return;
}
template<class T> void MultiSet<T>::deletion(T value)
{
    if ((numitems == maxsize / 4) && (maxsize > minsize))
        deallocate();
    bool find = false;
    for (int i = 0; i < numitems; i++)
    {
        if (reprarray[i].value == value)
        {
            reprarray[i].num--;
            if (reprarray[i].num == 0){
                for (int j = i; j<numitems-1; j++)
                {
                    reprarray[i].value = reprarray[i+1].value;
                    reprarray[i].num = reprarray[i+1].num;
                } 
                numitems--; 
            }
            find = true;
        }   
    } 
    if (find == false)
    {
        cout << "Index error: list index out of range\n";
    }
    return;        
}

template<class T> void MultiSet<T>::retrieval(T value)
{
    
    bool find = false;
    for (int i = 0; i < numitems; i++)
    {
        if (reprarray[i].value == value)
        {
           cout << value << " is in the multiset, its multiplicity is " << reprarray[i].num << "\n";
           find = true;
        }   
    } 
    if (find == false)
    {
        cout << value << " is not in the multiset.\n";
    }
    return;  
}

template<class T> void MultiSet<T>::display(void)
{
    for (int i = 0; i < numitems; i++)
    {
        cout << reprarray[i].value << " is in the multiset, its multiplicity is " << reprarray[i].num << "\n"; 
    } 
    return;  
}

template<class T> void MultiSet<T>::display_op(void)
{
    for (int i = 0; i < numitems; i++)
    {
        cout << reprarray[i].value << " "; 
    } 
    cout << "\n"; 
    return;  
}

template<class T> MultiSet<T> MultiSet<T>::setunion(MultiSet<T> &set_1,MultiSet<T> &set_2)
{
    MultiSet<T> newset;
    for (int i=1; i<= set_1.getlength(); i++)
    {
        newset.insertion(set_1[i]);
    }
    for (int j=1; j<= set_2.getlength(); j++)
    {
        newset.insertion(set_2[j]);
    }
    return newset;
}

template<class T> MultiSet<T> MultiSet<T>::intersection(MultiSet<T> &set_1,MultiSet<T> &set_2)
{
    MultiSet<T> newset;
    int i = 1; 
    int j = 1;
    while (i <= set_1.getlength() && j <= set_2.getlength())
    {   
        if (set_1[i] == set_2[j])
        {
            newset.insertion(set_1[i]);
            i++;
            while (set_1[i]==set_1[i-1]) i++;
            j++;
            while (set_2[i]==set_2[j-1]) j++;
        }
        if (set_1[i] < set_2[j]) i++;
        if (set_2[j] < set_1[i]) j++;
    }
    return newset;
}

template<class T> MultiSet<T> MultiSet<T>::difference(MultiSet<T> &set_1,MultiSet<T> &set_2)
{
    MultiSet<T> newset;
    bool find;
    for (int i =1;i<=set_1.getlength();i++)
    {   
        find = false;
        for (int j=1; j<=set_2.getlength();j++)
        {
            if (set_1[i] == set_2[j]) find = true;
        }
        if (find == false) newset.insertion(set_1[i]);
    }
    return newset;
}


    


// MultiSet_Chaining operations 
template<class T> MultiSet_Chaining<T>::MultiSet_Chaining(int size)
{
    maxsize = size;
    if (size < 20)
        maxsize = 20; // default size is 20; no smaller hashtables are considered
    numitems = 0; // initially, the hashtable is empty
    reprarray = new DList<T>[maxsize];  // allocate space for the array of pointers
    // the for loop initialises all table entries to be undefined
    for (int i = 0; i < maxsize; i++)
    {
        DList<int> case1;
        case1.append(-1);
        reprarray[i] = case1;
    }
    T *pt0 = new T;  // This defines the fixed placeholder pointer
    *pt0 = 0;
    pt_nil = pt0;
}

// template<class T> hashset<T>::~hashset(void)
// {
//     delete[] reprarray;
// }

template<class T> T & MultiSet_Chaining<T>::operator[](int index)
{
    if (index <= 0 || index > maxsize)
    {
        cout << "Index error: index out of range\n";
        exit(EXIT_FAILURE);
    }
    if (reprarray[index - 1] != 0 && reprarray[index - 1] != pt_nil)
        return *reprarray[index - 1];
    else
    {
        cout << "Index not used in hashtable";
        return 0;
    }
}

template<class T> void MultiSet_Chaining<T>::multiunion(MultiSet_Chaining<T> *set1,MultiSet_Chaining<T> *set2){
    for(int i=0;i<(*set2).maxsize;i++){
        DList<T> *temp = &((*set2).reprarray)[i];
        //DList<T> *concated = &(set1.reprarray)[i];
        if( (*temp).getlength()!=1 || (*temp).getitem(1)!= -1){
            for(int j=0;j<(*temp).getlength();j++){
                (*set1).insertion((*temp).getitem(j+1));
                /*if((*concated).getlength()==1 && (*concated).getitem(1)==0){
                (*concated).setitem(1,(*temp).getitem(j+1));
                }
                else{
                    (*concated).append((*temp).getitem(j+1));
                }
                ++set1.numitems;*/
            }
        }
    }
    return;
}

template<class T> void MultiSet_Chaining<T>::intersect(MultiSet_Chaining<T> *set1,MultiSet_Chaining<T> *set2,MultiSet_Chaining<T> *set3){
    for(int i=0;i<(*set2).maxsize;i++){
        DList<T> *temp = &((*set2).reprarray)[i];
        if( (*temp).getlength()!=1 || (*temp).getitem(1)!= -1){
            for(int j=0;j<(*temp).getlength();j++){
                int integer = (*temp).getitem(j+1);
                if((*set1).retrieval(integer)!=false){
                    (*set3).insertion(integer);
                    (*set1).deletion(integer);
                }
            }
        }
    }
    return;
}

template<class T> void MultiSet_Chaining<T>::difference(MultiSet_Chaining<T> *set1,MultiSet_Chaining<T> *set2){
    for(int i=0;i<(*set2).maxsize;i++){
        DList<T> *temp = &((*set2).reprarray)[i];
        if( (*temp).getlength()!=1 || (*temp).getitem(1)!= -1){
            for(int j=0;j<(*temp).getlength();j++){
                //--------------------------------------------------------------------
                int integer = (*temp).getitem(j+1);
                if((*set1).retrieval(integer)){
                    (*set1).deletion(integer);
                    (*set2).deletion(integer);
                    j--;
                }
            }
        }
    }
    (*set1).multiunion(set1,set2);
    return;
}


template<class T> void MultiSet_Chaining<T>::insertion(T item)
{
    hash<T> hashfunction; // use the predefined hashfunction to get "key" values
    int index;
    index = hashfunction(item) % maxsize; // First determine the position index in the hash table, where the new value is stored, if free.
    int location = -1;  // used to distinguish between undefined entries (null pointer) and placeholders
    DList<int> *point=&reprarray[index];
    if((*point).getitem(1)==-1){
        //point.append(item);
        location=index;
        (*point).setitem(1,item);    
    }
    else{
        for(int i=1;i<(*point).getlength();i++){
            if((*point).getitem(i)==-1){
                location=index;
                (*point).setitem(i,item);
            }
        }
        if(location<0){
            (*point).append(item);
        }
    }
    // after leaving the while loop we either have location < 1, i.e. we store the item at the last examined index (which contains a null pointer),
    // otherwise, if location >= 0 holds, we found a placeholder, so the item will be stored at the location of this placeholder
    /*if (location < 0)
        location = index;
    T *pt = new T;
    *pt = item;
    reprarray[location] = pt;   // store item in the hashtable*/
    ++ numitems;
    int load = 100 * numitems / maxsize;
    if (load >= 75)             // max load factor is exceeded; double the size
    {
        int newsize = 2 * numitems;
        rehash(newsize);
    }
    return;
}

template<class T> void MultiSet_Chaining<T>::deletion(T item)
{
    hash<T> hashfunction;  // use again the predefined hashfunction
    int index;
    index = hashfunction(item) % maxsize;
    DList<int> *point=&reprarray[index];
    for(int i=0; i<(*point).getlength();i++){
        if( item == (*point).getitem(i+1)){
            (*point).remove(i+1);
            --numitems;
            int load = 100 * numitems / maxsize;
            if (load <= 25)
                // if the min load factor is undershot, we shrink the hashtable, but the size shall always be >= 20
            {
                int newsize = numitems;
                if (newsize < 20)
                    newsize = 20;
                rehash(newsize);
            }
            return;
        }
    }
 /*   while (reprarray[index] != 0)  // same as for add we search for item in the hashtable; the search starts at the designated hash value, and stops when we find a null pointer
    {
        if (reprarray[index] != pt_nil && *reprarray[index] == item)
                    // item found
        {
            int nextindex = (index + 1) % maxsize;
            // check the next entry, if it is a null pointer; if yes, we can overwrite item by a null pointer; otherwise we use a placeholder, i.e. the pointer pt_nil 
            if (reprarray[nextindex] == 0)
                reprarray[index] = 0;
            else
                reprarray[index] = pt_nil;
            --numitems;
            
        }
        index = (index + 1) % maxsize;
    }*/
    cout << item << " is not in the hashtable.\n";
    return;
}

template<class T> bool MultiSet_Chaining<T>::retrieval(T item)
{
    hash<T> hashfunction;  // use the "key" function for the type T (if defined)
    int index;
    index = hashfunction(item) % maxsize;

    DList<int> *point=&reprarray[index];
    for(int i=0; i<(*point).getlength();i++){
        if( item == (*point).getitem(i+1)){
            return true;
        }
    }
    /*
    while (reprarray[index] != 0) // again we search for item starting from the index position until we find a null pointer
    {
        if (reprarray[index] != pt_nil && *reprarray[index] == item)
            return true;  // item was found
        index = (index + 1) % maxsize;
    }*/
    return false;  // a null pointer was found, so item is not in the hashtable
}

template<class T> void MultiSet_Chaining<T>::rehash(int newsize)
{
    if (newsize < 20)
        newsize = 20;
    int newnum = 0;
    DList<T> *newarray=new DList<T>[newsize]; // allocate space for a new hashtable of the given new size
    for (int i = 0; i < newsize; i++)
    {
        DList<int> case1;
        case1.append(-1);
        newarray[i] = case1;   // initialise the new hashtable with only null pointers
    }
    for (int i = 0; i < maxsize; i++)  // we need to copy all existing entries to the new hash table
    {
        DList<int> *point=&reprarray[i];
        if( (*point).getlength()!=1 || (*point).getitem(1)!=-1){
            for(int j=0; j<(*point).getlength();j++){
                int item=(*point).getitem(j+1);
                hash<T> hashfunction;
                int index = hashfunction(item) % newsize;
                if((newarray[index]).getlength()==1 && (newarray[index]).getitem(1)==-1){
                    (newarray[index]).setitem(1,item);
                }
                else{
                    (newarray[index]).append(item);
                } 
                ++ newnum;
            }
        }
        /*if (reprarray[i] != 0 && reprarray[i] != pt_nil)
        {
            T item = *reprarray[i];
            hash<T> hashfunction;
            int index = hashfunction(item) % newsize;
                // recompute the new hash value
            while (newarray[index] != 0)  // find the first free place, where the entry can be stored in the new hashtable
            {
                index = (index + 1) % newsize;
            }
            newarray[index] = reprarray[i];  // do the actual copying
            ++ newnum;
        }*/
    }
    numitems = newnum;   // change the number of stored elements
    reprarray = newarray;   // make the new hashtable the one of the hashset object
    maxsize = newsize;   // update the size
}

template<class T> void MultiSet_Chaining<T>::display(void) // only for test purposes
{
    cout << "The size of the hashtable is: " << maxsize << "\n";
    cout << "The number of elements in the hashtable is: " << numitems << "\n";
    for (int i = 0; i < maxsize; ++i)
    {
        DList<int> current= reprarray[i]; 
        if (current.getitem(1) == -1){
            cout << "The entry " << i + 1 << " is undefined.\n";
            //cout << current.getlength();
        }    
        else{
            cout << "The entry " << i + 1 << " is ";
            current._pprint_();
            //cout << "\n";
        } 
    }
    return;
}







template<class T> node<T>::node(T item, node<T> *pt_n, node<T> *pt_p)
{
    dataitem = item;
    pt_next = pt_n;
    pt_previous = pt_p;
}

template<class T> T node<T>::getdata(void)
{
    return dataitem;
}
 
template<class T> node<T> *node<T>::getnext(void)
{
    return pt_next;
}

template<class T> node<T> *node<T>::getprevious(void)
{
    return pt_previous;
}

template<class T> void node<T>::setdata(T item)
{
    dataitem = item;
    return;
}

template<class T> void node<T>::setnext(node<T> *pt)
{
    pt_next = pt;
    return;
}

template<class T> void node<T>::setprevious(node<T> *pt)
{
    pt_previous = pt;
    return;
}

template<class T> DList<T>::DList(void)
{
    dummy = new node<T>;
    (*dummy).setnext(dummy);
    (*dummy).setprevious(dummy);
    numitems = 0;
}

//template<class T> DList<T>::~DList()
//{
//    delete[] reprarray;
//}

template<class T> T DList<T>::operator[](int index)
{
    T val = getitem(index);
    return val;
}

template<class T> int DList<T>::getlength(void)
{
    return numitems;
}

template<class T> node<T> *DList<T>::last(void)
{
    return (*dummy).getprevious();
}

template<class T> node<T> *DList<T>::first(void)
{
    return (*dummy).getnext();
}

template<class T> void DList<T>::append(T value)
{
    node<T> *lpt;
    lpt = last();
    node<T> *pt = new node<T>;
    (*pt).setdata(value);
    (*pt).setnext(dummy);
    (*pt).setprevious(lpt);
    (*dummy).setprevious(pt);
    (*lpt).setnext(pt);
    ++numitems;
    return;
}

template<class T> node<T> *DList<T>::locate(int index)
{
    if ((index <= 0) || (index > numitems))
    {
        cout << "Error: index out of range.\n";
        exit(EXIT_FAILURE);
    }
    else
    {
        node<T> *pt;
        pt = (*dummy).getnext();
        for (int i = 1; i < index; ++i)
        {
            pt = (*pt).getnext();
        }
        return pt;
    }
}

template<class T> void DList<T>::setitem(int index, T value)
{
    node<T> *pt;
    pt = locate(index);
    (*pt).setdata(value);
    return;
}

template<class T> T DList<T>::getitem(int index)
{
    node<T> *pt;
    pt = locate(index);
    return (*pt).getdata();
}

template<class T> void DList<T>::insert(int index, T value)
{
    node<T> *pt_i;
    pt_i = locate(index);
    node<T> *pt_i1;
    pt_i1 = (*pt_i).getprevious();
    node<T> *pt_new = new node<T>;
    (*pt_new).setdata(value);
    (*pt_new).setnext(pt_i);
    (*pt_new).setprevious(pt_i1);
    (*pt_i).setprevious(pt_new);
    (*pt_i1).setnext(pt_new);
    numitems += 1;
    return;
}

template<class T> void DList<T>::remove(int index)
{
    if(this->getlength()==1){
        this->setitem(1,-1);
        return;
    }
    else{
        node<T> *pt_i;
        pt_i = locate(index);
        node<T> *pt_i1;
        pt_i1 = (*pt_i).getprevious();
        node<T> *pt_i2;
        pt_i2 = (*pt_i).getnext();
        (*pt_i1).setnext(pt_i2);
        (*pt_i2).setprevious(pt_i1);
        numitems -= 1;
        return;
    }
    
}

template<class T> void DList<T>::concat(DList<T> *dlist)
{
    int num = (*dlist).getlength();
    if (num > 0)
    {
        node<T> *lpt;
        lpt = last();
        node<T> *pt0;
        pt0 = (*dlist).dummy;
        node<T> *pt1;
        pt1 = (*pt0).getnext();
        (*pt1).setprevious(lpt);
        (*lpt).setnext(pt1);
        node<T> *pt2;
        pt2 = (*pt0).getprevious();
        (*dummy).setprevious(pt2);
        (*pt2).setnext(dummy);
        numitems += num;
    }
    return;
}

template<class T> bool DList<T>::member(T value)
{
    bool result = false;
    node<T> *pt;
    pt = (*dummy).getnext();
    for (int i = 0; i < numitems; ++i)
    {
        if ((*pt).getdata() == value)
        {
            result = true;
            break;
        }
        else
        {
            pt = (*pt).getnext();
        }
    }
    return result;
}

template<class T> bool DList<T>::equal(DList<T> *dlist)
{
    bool result = true;
    if ((*dlist).getlength() != numitems)
    {
        result = false;
    }
    else
    {
        node<T> *pt;
        pt = (*dummy).getnext();
        node<T> *pt0;
        pt0 = (*dlist).dummy;
        node<T> *pt_other;
        pt_other = (*pt0).getnext();
        for (int i = 0; i < numitems; ++i)
        {
            if ((*pt).getdata() != (*pt_other).getdata())
            {
                result = false;
                break;
            }
            else
            {
                pt = (*pt).getnext();
                pt_other = (*pt_other).getnext();
            }
        }
    }
    return result;
}

template<class T> bool DList<T>::sublist(DList<T> *dlist)
{
    bool result = true;
    node<T> *pt;
    pt = (*dummy).getnext();
    node<T> *pt0;
    pt0 = (*dlist).dummy;
    node<T> *pt_other;
    pt_other = (*pt0).getnext();
    int numother = (*dlist).getlength();
    for (int i = 0, j = 0; (i < numother) && (j < numitems); ++i, ++j)
    {
        if ((*pt_other).getdata() == (*pt).getdata())
        {
            if ((j == numitems - 1) && (i < numother - 1))
            {
                result = false;
                break;
            }
            pt = (*pt).getnext();
            pt_other = (*pt_other).getnext();
        }
        else
        {
            if (j == numitems - 1)
            {
                result = false;
                break;
            }
            else
            {
                pt = (*pt).getnext();
                --i;
            }
        }
        
    }
    return result;
}

template<class T> void DList<T>::_pprint_(void){
    node<T> *pt = dummy->getnext();

    cout << "Dummy <> ";
    for (int i = 0; i < numitems; i++){
        cout << pt->getdata() << " <> ";
        pt = pt->getnext();
    }
    cout << "Dummy" << endl;

    return ;
}