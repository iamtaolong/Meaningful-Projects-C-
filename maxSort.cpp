#include <iostream>
#include <vector>
using namespace std;

// function declarations
void maxSort(vector<int>& list);
void swap(int& a, int& b);
void print(const vector<int>& list);



int main() {

    vector<int> v(5);  // vector to be sorted

    // initialize v
    v = {6, 1, 3, 2, 1};

    // print the unsorted v
    cout << "v = {6, 1, 3, 2, 1}";

    // sort v
    maxSort(v);

    // print the sorted v
    print(v);


    return 0;
}

/* the function definitions */

//Max sort function



void maxSort(vector<int>& list) {

    for (int i = list.size() - 1; i >= 0; i--) {
        int currentPostion = 0; //find the current position
        int currentMax = 0;
        for (int j = 0; j <= i; j++) {
            if (list[j] > currentMax) {
                currentMax = list[j];
                currentPostion = j;
                //find the great value in this loop and record the position and value of it
            }
        }
        swap(list[currentPostion], list[i]);
        //swap
    }
}

// swap function
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
        //make the use of the temp value to exchange values of a and b
    }

// print function
    void print(const vector<int> &list) {
    cout << endl;
    cout << "new v = {";
    for (int k = 0; k < 5; k++){
        if (k < 4) {
            cout << list[k] << ", ";
        }
        else{
        cout << list[k];}
    }
    cout << "}";
}

