#include <ctime> /* For performance comparasion */
#include "hashset_f.h"
#include "hash_extend_f.h"

int main()
{
    /******************* Put your own test here *******************/
    /* Your are expected to give adequate test to show the correctness of your implementation */
    /* Otherwise you may be deducted points */

    /**************************************************************/
    /* Check Point 1: Correctness */
    int input1[] = {1, 1, 1, 5, 2};
    int input2[] = {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42};

    HashSet_LCFS<int> test1, test2;
    HashSet_RH<int> test3, test4;

    /* Add test to your container */
    for (auto i : input1)
    {
        test1.add(i);
        test3.add(i);
    }

    for (auto i : input2)
    {
        test2.add(i);
        test4.add(i);
    }

    /* Test on both inputs, missing operation would be deducted points */
    /* Test for LCFS Hash */
    cout << "test for LCFS Hash"
         << "\n";
    cout << "test1 with input {1, 1, 1, 5, 2}"
         << "\n";
    cout << "the initial hash table is\n";
    test1.display();
    cout << "add 21,it will occur 1's place.\nthe current hashset is\n";
    test1.add(21);
    test1.display();
    cout << "remove 21,as the lode is <=25,it will rehash.\nthe current hashset is\n";
    test1.remove(21);
    test1.display();
    cout << "add 10-21 to test rehash to bigger\nthe current hashset is\n";
    for(int i=10;i<=21;i++){
        test1.add(i);
    }
    test1.display();
    cout << "For member function, its correctness won't be affected by add and rehash function. It doesn't need testing\n\n";
    
    
    cout<<"test2 with input {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42}\n";
    cout<<"the initial hash table is\n";
    test2.display();
    cout << "add 23,it will occur 3's place.\nthe current hashset is\n";
    test2.add(23);
    test2.display();
    cout << "remove 23,as the lode is >25, it will be free\nthe current hashset is\n";
    test2.remove(23);
    test2.display();
    cout << "add 15-29 to test rehash to bigger\nthe current hashset is\n";
    for(int i=15;i<=29;i++){
        test2.add(i);
    }
    test2.display();
    cout << "For member function, its correctness won't be affected by add and rehash function. It doesn't need testing\n\n";
    
    
    
    /* Test for RH Hash */
    cout << "test for RH Hash"
         << "\n";
    cout << "test3 with input {1, 1, 1, 5, 2}"
         << "\n";
    cout << "the initial hash table is\n";
    test3.display();
    cout << "add 21,it will be same place with 1 and then compete. as their cost are both 0, 21 compete with 2. then cost(21)=1>cost(2)=0,occurs 2's place and 2 goes next entry\nthe current hashset is\n";
    test3.add(21);
    test3.display();
    cout << "remove 21,as the lode is <=25,it will rehash.\nthe current hashset is\n";
    test3.remove(21);
    test3.display();
    cout << "add 10-21 to test rehash to bigger\nthe current hashset is\n";
    for(int i=10;i<=21;i++){
        test3.add(i);
    }
    test3.display();
    cout << "For member function, its correctness won't be affected by add and rehash function. It doesn't need testing\n\n";


    cout << "\n\ntest4 with input {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42}\n";
    cout << "the initial hash table is\n";
    test4.display();
    cout << "add 23,theoretically,it will compete with 42 first.23's cost less then 42,then compete with 3,still less, compete with 4,win.then 4 compete with 5,win,5 to entry 8.\nthe current hashset is\n";
    test4.add(23);
    test4.display();
    cout << "remove 23,as the lode is >25, it will be free\nthe current hashset is\n";
    test4.remove(23);
    test4.display();
    cout << "add 15-29 to test rehash to bigger\nthe current hashset is\n";
    for(int i=15;i<=29;i++){
        test4.add(i);
    }
    test4.display();
    cout << "For member function, its correctness won't be affected by add and rehash function. It doesn't need testing\n\n";

    /**************************************************************/
    /* Check Point 2: Compare the performance with initial hashset as baseline */
    /* ctime is included for you to help */
    cout<< "add 100000 items (odd number from 1 - 200000) to a new hashtable\nfind 1-200000 in the hashset\n";
    hashset<int> test5;
    clock_t start,end;
    start=clock();
    for(int i=1;i<200001;i=i+2){
        test5.add(i);
    }
    end=clock();
    cout<<"adding time for hashset is "<< end-start<<"\n";
    start=clock();
    for(int i=1;i<200001;i=i+2){
        test5.member(i);
    }
    end=clock();
    cout<<"the finding time for hashset is "<<end-start<<"\n";
    
    HashSet_LCFS<int> test6;

    start=clock();
    for(int i=1;i<200001;i=i+2){
        test6.add(i);
    }
    end=clock();

    cout<<"adding time for hashset_lcfs is "<< end-start<<"\n";
    start=clock();
    for(int i=1;i<200001;i=i+2){
        test6.member(i);
    }
    end=clock();
    cout<<"the finding time for hashset_lcfs is "<<end-start<<"\n";

    HashSet_RH<int> test7;

    start=clock();
    for(int i=1;i<200001;i=i+2){
        test7.add(i);
    }
    end=clock();
    cout<<"adding time for hashset_rh is "<< end-start<<"\n";
    start=clock();
    for(int i=1;i<200001;i=i+2){
        test7.member(i);
    }
    end=clock();
    cout<<"the finding time for hashset_rh is "<<end-start<<"\n";
    cout<<"in conclusion, for finding function, hashset_rh and hashset_lcfs is better, for adding function, hashset performs a little better but mostly same\n";
    return 0;
}