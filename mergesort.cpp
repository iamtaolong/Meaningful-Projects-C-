#include <iostream>
#include <vector>
using namespace std;

//Learning Objectives:
//●	Write C++ programs in a modern software development using the CLion IDE and version control with Github repositories,
//●	Write modular code in a single file organized into functions,
//●	Apply recursion to sort a vector of integers,
//●	Implement and manipulate the contents of vectors.

//author：Tao Long
//studentID: 06558480
//project: CSC112-Project2
//instructor： Dr.Alqahtani


// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);


int main() {

    // print greeting message
    cout << "Welcome to the MergeSort!" << endl;
    cout << endl;

    // get input: first is random seed, second is vector length
    int seed;
    cout << "Please Enter Seed: ";
    cin >> seed ;

    // get input: first is random seed, second is vector length
    int length;
    cout << "Please Enter Length: ";
    cin >> length;

    // srand() function
    srand(seed);

    //define the length of the two vectors we use during the sorting process
    // vector to be sorted
    vector<int> v(length);
    // temporary workspace
    vector<int> t(length);

    // unit test for merge
    // print out messages for the comparsion between
    // the original unit test vector's expected sorted vector and the actual one
    cout << "Unit Test will be conducted first~" << endl;

    //declare variables for the unit test
    vector<int> unittestVector = {1, 2, 98, 99, 3, 4, 97};
    vector<int> unitestTmp (7);
    vector<int> unittestExpectedOutput = {1, 2, 3, 4, 97, 98, 99};

    cout << "Expect vector {1, 2, 98, 99, 3, 4, 97} to get {1, 2, 3, 4, 97, 98, 99}" << endl;
    cout << "                               - Actually get {";

    // call the mergeSort method for sorting
    // mergeSortedLists(unittestVector, unitestTmp, 0, (0+size)/2, size-1);
    mergeSortedLists(unittestVector, unitestTmp, 0, 3, 6);
    // print the sorted vector by using a for loop
    for(int unittest = 0; unittest < 7; unittest++) {
        if (unittest != 6){
            cout << unittestVector.at(unittest) << ", ";
        }
        else{
            cout << unittestVector.at(unittest) << "}" << endl;
        }
    }
    // use assert to double check the unit test
    for(int i = 0; i < unittestExpectedOutput.size(); i++) {
        assert(unittestVector.at(i) == unittestExpectedOutput.at(i));
    }

    cout << "Here comes your own vectors: ";
    // initialize and print input
    // use random()%100 to create random numbers from 0-99
    // store the random number to the vector one by one and they print them out with a for-loop
    cout << endl << "Original Vector: ";
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    // call the mergeSort method
    mergeSort(v,t,0,v.size() - 1);

    // print output with a for-loop
    cout << "Sorteded Vector: ";
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    // use assert to test if the sorted vector follow the rule former < following
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }
    return 0;
}


// mergeSortedLists method
// sort the list
void mergeSortedLists( vector<int>& a, vector<int>& tmp, int left, int middle, int right){

    // declare variables
    int signal = 0;
    int start = left;
    int end = middle + 1;

    // resize the tmp for storing values
    tmp.resize(right - left + 1);

    // to create a whileloop
    // if the start and end are following the imported left-end and right-end
    while ((start <= middle) && (end <= right)){
        if(a.at(start) < a.at(end)){
            tmp.at(signal) = a.at(start);
            signal = signal + 1;
            start++;
        }
        else{
            tmp.at(signal) = a.at(end);
            signal = signal + 1;
            end++;
        }
    }
    //when left side is used up for the sorting
    //the left half is completed
    while (start <= middle){
        tmp.at(signal) = a.at(start);
        signal++;
        start++;
    }
    // when right side is used up
    while (end <= right){
        tmp.at(signal) = a.at(end);
        signal++;
        end++;
    }
    //transfer the value from the tmp vector to the a
    for(int savework = left, loadwork= 0; savework <= right; savework++, loadwork++){
        a.at(savework) = tmp.at(loadwork);
    }
}


// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){

    // use recursion for mergeSort
    // first the left half
    // then mergeSort the right half
    if(left < right) {
        int mid = (left + right) / 2;
        mergeSort(a, tmp, left, mid);
        mergeSort(a, tmp, mid + 1, right);
        mergeSortedLists(a, tmp, left, mid, right);
    }
}