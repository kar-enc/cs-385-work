/*******************************************************************************
 * Name        : sqrt.cpp
 * Author      : Karen Caguana
 * Date        : 09.10.25
 * Description : Square root of a double using Newton's method
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <sstream>
#include <iostream>
#include <cmath>
#include <iomanip>


using namespace std;

 double sqrt(double num, double epsilon) {
    if (num < 0) {
        return numeric_limits<double>::quiet_NaN();
    } if (num == 0 || num == 1) {
        return num;
    }

    double prev = num;
    double next = (prev + num/prev) / 2.0;

    while (abs(prev - next) <= epsilon) {
        prev = next;
        next = (prev + num/prev) / 2.0;
    }

    return next;
 }

 int main(int argc, char *argv[]))

