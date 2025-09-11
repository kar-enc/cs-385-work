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

    //need to include:
    //  total num of prime nums found ; found through counter
    //  "prime up to 'limit_" ; 
    //  right aligned
    cout << "Number of primes found: " << num_primes_ << endl;
    cout << "Primes up to " << limit_ << " : " << endl; 


    const int max_prime_width = num_digits(max_prime_width);
    const int primes_per_row = 80 / (max_prime_width + 1);

    int counter = 0;

    if (num_primes_ <= primes_per_row) {
        //fits all in one row case ; !!remember start with 2 cuz 0 and 1 arent prime!
        for (int i =2 ; i <= limit_ ; i++) {
            if (is_prime_[i] == true) {
                cout << i;
                counter++;
                if (counter < num_primes_) {
                    cout << ' ';
                } if (counter / primes_per_row != 0) {
                    cout << endl;
                }

            }
        }
        cout << endl;
        
    } else {
        //multiple line case need to be right algined 
        for (int i = 2 ; i <= limit_ ; i++) {
            if (is_prime_ == true) {
                cout << setw(max_prime_width) << i;
                counter++;
                if (counter / primes_per_row == 0 ) {
                    cout << endl;
                } if (counted < num_primes_) {
                    cout << ' ';
                }
            }
        }
    }

}

void PrimesSieve::sieve() {
    // TODO: write sieve algorithm
    // All instance variables must be initialized by the end of this method.

    // Setting all indeces in array to true
    for (int i = 0 ; i <= limit_ ; i++) {
        is_prime_[i] = true;
    }

    // 0 and 1 set as false
    is_prime_[0] = false;
    is_prime_[1] = false;

    int counter = 0;

    // Starting at 2 until its reach sqrt limit
    for (int = 2 ; i < sqrt(limit) ; i++) {
        //only looking at true indeces since after loops runs once some might be false so theres no point in looking in them
        if (is_prime_[i] == true) {
        //setting multiples as false
        //i*i is used because the first num is 2 and its multiples will elimanate a lot of nums that might potentially be touched in when checking
            for (int j = i*i ; j <= limit_ ; j += i) {
            //if inside this loop then its a multiple of i and needs to be false
                is_prime_[j] = false;
                counter--;
            }
        }
    }

    for (int i = 0 ; i <= limit_ ; i++) {
        if (is_prime_[i] != '\0' && is_prime_[i] == true) {
            num_primes_++;
        }
    }


    for (int i = limit_ ; i > 0 ; i--) {
        if (is_prime_[i] == true) {
            max_prime_ = i;
            break;
        }
    }
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
