#include <iostream>
using namespace std;

class Faculty{
public:
    string name;
    string id;
    string address;
    string DoB;
    string degree;
//getter and setter for salary
    double getSalary() {return salary;}
    void setSalary(double salary);
/* 1) create a getter and setter for each variable in the class*/

    static void setName(string name){};
    static void setID(string id){};
    static void setAddress(string addess){};
    static void setDoB(string DoB){};
    static void setDegree(string degree){};
    string getName(){return name;};
    string getID(){return id;};
    string getAdress(){return address;};
    string getDoB(){return DoB;};
    string getDegree(){return degree;};






private:
    double salary;
    double SSN;
};

void Faculty::setSalary(double s){
    salary=s;
}

/* 2) implement each setter and getter */

int main() {
    Faculty prof;
    Faculty prof2;


/* 3) use the implemented methods to fill prof' info and print them out */

    prof.setName("Tao");
    prof.setID("12345");
    prof.setAddress("Magnolia Hall");
    prof.setDoB("CSC");
    prof.setDegree("Bachelor");
    prof.getName();
    prof.getAdress();
    prof.getDoB();
    prof.getDegree();

    return 0;
}
