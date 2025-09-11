/*******************************************************************************
 * Name        : sqrt.cpp
 * Author      : Karen Caguana
 * Date        : 09.10.25
 * Description : Square root of a double using Newton's method
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/

#include <iostream>
#include <cmath>
#include <limits>
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

    while (fabs(prev - next) > epsilon) {
        prev = next;
        next = (prev + num/prev) / 2.0;
    }

    return next;
 }

 int main(int argc, char *argv[]) {
    //needs 1 or 2 arugements max
    if (argc < 2 || argc > 3) {
        cout << "Usage: ./sqrt <value> [epsilon]" <<endl;
        return 1;
    }
    
    double num;
    double epsilon = 1e-7;

    //testing if the value actually the correct type
    try {
        num = stod(argv[1]);
    } catch (...) {
        cout << "Error: Value argument must be a double." << endl;
        return 1;
    } 

    //error for epsilon ; if theres one is it positive and double
    if (argc == 3) {
        try {
            epsilon = atof(argv[2]);
        } catch (...) {
            cout << "Error: Epsilon argument must be a positive double." << endl;
            return 1;
        }
        if (epsilon <= 0) {
            cout << "Error: Epsilon argument must be a positive double." << endl;
            return 1;
        }
    }

    double ans = sqrt(num, epsilon);
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
 }