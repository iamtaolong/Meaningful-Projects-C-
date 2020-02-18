#include <iostream>
#include <vector>
#include<cassert>
using namespace std;

// print the values of two variables
void print_values(int num1, int num2) {
    cout << "Value of num1 is: " << num1 << endl;
    cout << "Value of num2 is: " << num2 << endl;
}
// swap values of two variables
void swap(int* num1, int* num2) {
    cout<<"Swap function"<<endl;
    int temp;
    temp = *num1; // save the value of num1
    *num1 = *num2; // copy over num2 to num1
    *num2 = temp; // copy the saved value of num1
}

int main() {

    int num1 = 10;
    int num2 = 20;
    //int temp=num1;
    cout << "Before Swapping: " << endl;
    print_values(num1, num2); // function call
    swap(&num1, &num2); // swap values?
    cout << "After Swapping: " << endl;
    print_values(num1, num2); // function call

}
