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

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class booking{
    public:
        booking(int a, int d){
            arrival = a;
            departure = d;
        };
        int arrival; 
        int departure; 
};


class Bookings{
    public:
        Bookings(vector<booking> bookings, int K){
            bks = bookings;
            k = K;
        };
        vector <booking> bks;
        int k;
        void bookings_print();
        void test();
        void display(int* array, int size);
        int getStandard(int array[], int i, int j);
        void QuickSort(int array[], int low, int high);
        // Modify the following to solve the exercise
        // You may also add your own help function
        bool checkdemands();


    private:

};



// You should right the following to finish the exercise
// You may also add your own help function
bool Bookings::checkdemands(){
    int room = this->k;
    int i = 0;
    int k = 0;
    for(booking j : this->bks){
        i++;
    }
    i=i*2;
    int ar[i];
    for(booking j : this->bks){
        ar[k++]=j.arrival;
        ar[k++]=-j.departure;
    }
    QuickSort(ar,0,i-1);
    //display(ar,i);
    for(k=0;k<i;k++){
        if(room<0){
            return 0;
        }
        if(ar[k]>0){
            room--;
        }
        else{
            room++;
        }
    }


    return 1;
};

void Bookings :: display(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int Bookings :: getStandard(int array[], int i, int j) {
    int key = array[i];
    while (i < j) {
        while (i < j && abs(array[j]) >= abs(key)) {
            j--;
        }
        if (i < j) {
            array[i] = array[j];
        }
        while (i < j && abs(array[i]) <= abs(key)) {
            i++;
        }
        if (i < j) {
            array[j] = array[i];
        }
    }
    array[i] = key;
    return i;
}

void Bookings :: QuickSort(int array[], int low, int high) {
    if (low < high) {
        int standard = getStandard(array, low, high);
        QuickSort(array, low, standard - 1);
        QuickSort(array, standard + 1, high);
    }
}


// DO NOT modify the following 
void Bookings::bookings_print(){
    cout << "Bookings as follow:" << endl;
    for(booking i: this->bks){
        cout << "A: " << i.arrival << "  | D: " << i.departure << endl;
    }
    cout << "Max available room:" << this->k << endl;
    return ;
}

void Bookings::test(){
    bookings_print();
    cout << "Check whether satisfy the demands: " << (checkdemands()? "Success":"Fail") << endl;
}