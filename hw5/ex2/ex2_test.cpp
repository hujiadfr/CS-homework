#include "multiset_f.h"


int main(){
    /******************* Put your own test here *******************/
    /* Your are expected to give adequate test to show the correctness of your implementation */
    /* Otherwise you may be deducted points */
    
    int input1[] = {1, 1, 1, 5, 2};
    int input2[] = {0, 2, 12, 3, 3, 3, 3, 4, 5, 5, 42};

    MultiSet<int> test1, test2;
    // MultiSet_Chaining<int> test3, test4;
    // To show the rehash in part(ii), we use other test input instead.
    
    /* Add test to your container */
    for(auto i: input1){
        test1.insertion(i);
        // test3.insertion(i);
    }
    
  

    for (auto i:input2){
        test2.insertion(i);
        // test4.insertion(i); 
    }
    

    /* Test for all required operation on both inputs, missing operation would be deducted points */
    /* Test for part(i) */
    cout << "Test for part(i)\n";
    cout << "display test1.\n";
    test1.display();
    cout << "display test2.\n";
    test2.display();   
    cout << "\n";
    
    cout << "The insertion operation(1): test1.insertion(1)\n";
    test1.insertion(1);
    test1.display();
    cout << "\n";

    cout << "The deletion operation(1): test1.deletion(1)\n";
    test1.deletion(1);
    test1.display();
    cout << "\n";

    cout << "The insertion operation(1): test1.insertion(10)\n";
    test1.insertion(10);
    test1.display();
    cout << "\n";

    cout << "The deletion operation(1): test1.deletion(10)\n";
    test1.deletion(10);
    test1.display();
    cout << "\n";

    cout << "The retrieval operation(1): test1.retrieval(10)\n";
    test1.retrieval(10);
    cout << "\n";

    cout << "The retrieval operation(1): test1.retrieval(1)\n";
    test1.retrieval(1);
    cout << "\n";

    cout << "The setunion operation:";
    MultiSet<int> unionset;
    unionset = test1.setunion(test1,test2);
    unionset.display_op();
    cout << "\n";

    cout << "The intersection operation:";
    MultiSet<int> intersectionset;
    intersectionset = test1.intersection(test1,test2);
    intersectionset.display_op();
    cout << "\n";

    cout << "The difference operation test1 -> test2:";
    MultiSet<int> differenceset;
    differenceset = test1.difference(test1,test2);
    differenceset.display_op();
    cout << "\n";

    cout << "The difference operation test2 -> test1:";
    differenceset = test1.difference(test2,test1);
    differenceset.display_op();
    cout << "\n";
    /* Test for part(ii) */

    cout << "Test for part(ii)\n";

    int input3[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int input4[] = {1,1,21,21,31,31,41,41,51,51};
    MultiSet_Chaining<int> test3, test4, test5;
    cout << "\nbelow is test for MultiSet_Chaining" << endl;
    
    cout << "\n1. insertion operation with no rehashing\n" << endl;
    for (int i=0;i<6;i++){
        test3.insertion(input4[i]);
    }
    for (int i=0; i<10;i++){
        test4.insertion(input4[i]);
    }
    test3.display();

    cout << "\n2. insertion operation with rehashing\n" << endl;
    for (int i=0;i<10;i++){
        test3.insertion(input3[i]);
    }
    test3.display();
    
    cout << "\n3. deletion operation with no rehashing\n" << endl;
    test3.deletion(1);
    test3.deletion(1);
    test3.deletion(1);
    test3.display();
    
    cout << "\n4. deletion operation with rehashing\n" << endl;
    for(int i=2; i<9;i++){
        test3.deletion(i);
    }
    test3.display();

    cout << "\n5. retrieval operation\n" << endl;
    cout << "find 31 in the hashtable" << endl;
    cout << "correct answer : 31 is in hashtable" << endl;
    cout << "program answer :" ;
    if(test3.retrieval(31)){
        cout << " 31 is in hashtable" << endl;
    }
    else{
        cout << "no such number in hashtable" << endl;
    }
    cout << "\nfind 2 in the hashtable" << endl;
    cout << "correct answer : no such number in hashtable" << endl;
    cout << "program answer :" ;
    if(test3.retrieval(2)){
        cout << "2 is in hashtable" << endl;
    }
    else{
        cout << " no such number in hashtable" << endl;
    }

    cout << "\n6. multiunion operation\n" << endl;
    cout << "union test3 and test4" << endl;
    cout << "test3 is :" << endl;
    test3.display();
    cout << "test4 is :" << endl;
    test4.display();
    cout << "after union :" <<endl;
    test3.multiunion(&test3,&test4);
    test3.display();

    cout << "\n7. intersect operation\n" << endl;
    cout << "intersect test3 and test4" << endl;
    cout << "test3 is :" << endl;
    test3.display();
    cout << "test4 is :" << endl;
    test4.display();
    cout << "after intersect :" <<endl;
    test5.intersect(&test3,&test4,&test5);
    test5.display();

    cout << "\n8. difference operation\n" << endl;
    cout << "difference test3 and test4" << endl;
    cout << "test3 is :" << endl;
    test3.display();
    cout << "test4 is :" << endl;
    test4.display();
    cout << "after difference :" <<endl;
    test3.difference(&test3,&test4);
    test3.display();
    cout<<"\n";
    //test4.display();
    //test5.display();
    //test3.intersect(&test3,&test4,&test5);
    //test3.difference(&test3,&test4);
    //cout<<"\n";
    //
    


    /*for (int i=0;i<11;i++){
        test4.insertion(input2[i]);
    }
    test3.deletion(5);
    if(test3.retrieval(5)){
        cout << "item in the hash table\n"; 
    }
    else{
        cout << "item not in hash table\n";
    }*/



/*    test3.display();
    cout<<"\n";
    for(int i=12;i<19;i++){
        test3.insertion(input1[i]);
    }
    test3.display();
    for(int i=0;i<9;i++){
        test3.deletion(21);
    }
    test3.deletion(1);
    test3.deletion(1);
    test3.display();
*/




    /*test3.deletion(2);
    test3.display();
    if(test3.retrieval(2)){
        cout<<"here it is \n";
    }
    else{
        cout<<"not here \n";
    }*/

    return 0;
}