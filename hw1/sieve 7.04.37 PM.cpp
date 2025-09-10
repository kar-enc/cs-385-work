/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Karen Caguana
 * Date        : 09.10.25
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    void display_primes() const;

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    void sieve();
    static int num_digits(int num);
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    // TODO: write code to display the primes in the format specified in the
    // requirements document.
}

void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
    // All instance variables must be initialized by the end of this method.

    //setting all indeces in array to true
    for (int = 0 ; i < limit ; i++) {
        is_prime_[i] = true;
    }

    //Rough idea: 
    //  create array ; set all to true ; 
    //  change 0 and 1 to false cuz they arent prime ; 
    //  start at 2 (set variable prob) ; 
    //  if the current number is prime turn all multiples to false ; 
    //  continue from the varible and restart cycle ; 
    //  cycle stops when we get up to num < sqrt(og num) 
    //      ((b/c sqrt of the og num all the potential factors/multiples will be accounted for by 
    //      eveyrthing before the sqrt(og num)))
    //  *cycle shouls prob be a loop ; 
    //  after loop ends print out true nums as prime*

}

int PrimesSieve::num_digits(int num) {
    // TODO: write code to determine how many digits are in an integer
    // Hint: No strings are needed. Keep dividing by 10.
    int digit = 0;
    while (num != 0) {
        num = num/10;
        digit++;
    }

    return digit;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    // TODO: write code that uses your class to produce the desired output.
    return 0;
}
