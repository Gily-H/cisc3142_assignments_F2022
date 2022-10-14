#include <iostream>

using namespace std;

/* 
 * Program to list out all the prime numbers between 3 and 100 inclusive
 */

// helper method to check if a number is prime
bool check_if_prime(int val) {
  // loop through all factors of the given integer param from 2 (inclusive) to the param value (not inclusive)
  for (int i = 2; i < val; ++i) {
    // a value with 0 remainder is not prime
    if (val % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  cout << "Starting Lab 5 Practice Problem: Prime Numbers\n" << endl;
  cout << "These are all the prime numbers between 3 and 100 inclusive" << endl;
  for (int i = 3; i <= 100; ++i) {
    // check if the current number is prime
    if (check_if_prime(i)) {
      cout << i << " "; // if prime, output the number
    }
  }

  cout << "\n---------------------------------" << endl;
}
