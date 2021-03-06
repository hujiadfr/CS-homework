/*
 * @ Author     : 
 * 
 * @ File       : 
 * 
 * @ Purpose    : 
 * 
 * @ Usage      : 
 * 
 * @ Description: 
 * 
 * @ Input      : 
 * 
 * @ Output     : 
 * 
 */
#ifndef ex1
#define ex1

#include <iostream>
#include <vector>
using namespace std;

// You may modify the decleration and definenation by yourself, add help function etc.
template <class T> class Solution {
    public:
        Solution(vector<T> input){
            data = input;
        };

        vector<T> MergeSort_k(vector<T> lst, int k);
        vector<T> Merge(vector<T> fst, vector<T> sec);
        vector<T> MergeSort_t(vector<T> lst, int t);
        vector<T> SelfSort(vector<T> lst);
        void vec_print(vector<T> vec);
        vector<T> data;
        void test(int k, int t);
    private:
        
};

// Modify the following to finish ex1.1
template <class T> vector<T> Solution<T>::MergeSort_k(vector<T> lst, int k){
    if(lst.empty()){
        return lst;
    }
    int length=lst.size();
    if(length==1){
        return lst;
    }
    vector<T> result;
    vector<T> now;
    int beg=0;
    int i,c;
    result.clear();
    int div=length/k;
    if(div<=1){
        for(c=0;c<length;c++){
            now.clear();
            now.push_back(lst[beg+c]);
            result=Merge(now,result);
        }
        return result;
    }
    else{
        for(c=1;c<k;c++){
            now.clear();
            for(i=0;i<div;i++){
                now.push_back(lst[beg+i]);
            }
            beg+=div;
            result=Merge(MergeSort_k(now,k),result);
        }
        now.clear();
        for(c=beg;c<length;c++){
            now.push_back(lst[c]);
        }
        result=Merge(MergeSort_k(now,k),result);
        return result;
    }
};


template <class T> vector<T> Solution<T>::Merge(vector<T> fst,vector<T> sec){
    vector<T> result;
    result.clear();
    int f=0;
    int s=0;
    int lf=fst.size();
    int ls=sec.size();
    while(f<lf && s<ls){
        if(fst[f]<=sec[s]){
            result.push_back(fst[f++]);
        }
        else{
            result.push_back(sec[s++]);
        }
    }
    while(f<lf){
        result.push_back(fst[f++]);
    }
    while(s<ls){
        result.push_back(sec[s++]);
    }
    return result;
};



// Modify the following to finish ex1.2
template<class T> vector<T> Solution<T>::MergeSort_t(vector<T> lst, int t){
   int i=lst.size();
   int j=i/2;
   if(i<=t){
       lst=SelfSort(lst);
   }
   else{
       vector<T> fst;
       vector<T> sec;
       fst.clear();
       sec.clear();
       for(int a=0;a<j;a++){
           fst.push_back(lst[a]);
       }
       for(int b=j;b<i;b++){
           sec.push_back(lst[b]);
       }
       lst=Merge(MergeSort_t(fst,t),MergeSort_t(sec,t));
   }
   return lst;
}

// You could implement either bubble sort, insert sort or selection sort
//bubble sort
template<class T> vector<T> Solution<T>::SelfSort(vector<T> lst){
    T i, j, temp, len;
    len=lst.size();
	for (j = 0; j < len - 1; j++)
	{
		for (i = 0; i < len - 1 - j; i++)
        {
		    if (lst[i] > lst[i + 1])
		    {
			    temp = lst[i];
			    lst[i] = lst[i + 1];
			    lst[i + 1] = temp;
		    }
        }
	}
    return lst;
}

// DO NOT modify the following
// This is to view the vector
template<class T> void Solution<T>::vec_print(vector<T> vec){
    for (T i: vec){
        cout << i << "  ";
    }
    cout << endl;
    return ;
}

// This is for testing.
template <class T> void Solution<T>::test(int k, int t){
    cout << "Self-implemented Sort:          ";
    vec_print(SelfSort(data));
    cout << "Merge Sort with K sublist:      ";
    vec_print(MergeSort_k(data, k));
    cout << "Merge Sort with Insertion Sort: ";
    vec_print(MergeSort_t(data, t));
}
#endif 

