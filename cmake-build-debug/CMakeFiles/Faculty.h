//
// Created by Tao on 10/3/19.
//

#ifndef CLASSEXCERCISE_FACULTY_H
#define CLASSEXCERCISE_FACULTY_H

#include "Faculty.h"
Faculty::Faculty(string n, string i, double s, string a, string d, string deg, double ss) {
    salary = s;
    id = i;
    name = n;
    address = a;
    DoB = d;
    degree = deg;
    SSN = ss;
}

#endif //CLASSEXCERCISE_FACULTY_H
