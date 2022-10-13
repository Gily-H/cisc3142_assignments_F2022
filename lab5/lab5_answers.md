# Textbook Exercises

## Exercise 4.5
*Determine the result of the following expressions*
```
(a) -30 * 3 + 21 / 5 - will output -86
(b) -30 + 3 * 21 / 5 - will output -18
(c) 30 / 3 * 21 % 5 - will output 0
(d) -30 / 3 * 21 % 4 - will output -2
```

```cpp
#include <iostream>
using std::cout;
using std::endl;

int main() {
  double a_output = -30 * 3 + 21 / 5;
  double b_output = -30 + 3 * 21 / 5;
  double c_output 30 / 3 * 21 % 5;
  double d_output = -30 / 3 * 21 % 4;
  cout << "The output for exercise 4.5: (a) " << a_output << " (b) " << b_output << " (c) " << c_output << " (d) " << d_output << endl;
  return 0;
}
```

## Exercise 4.17
*Explain the difference between prefix and postfix increment*

```cpp
#include <iostream>
using std::cout;
using std::endl;

// prefix increment will change the value before it is evaluated
// postfix increment will update the value after it is evaluated
int main() {
  int prefix = 100;
  int postfix = 100;
  cout << "The prefix operator will output: " << ++prefix << endl; // this will output 101
  cout << "The postfix operator will output: " << postfix++ << endl; // this will output 100
  return 0;
}
```

## Exercise 4.34
*Given the variable definitions in this section, explain what conversions take place in the following expressions*
```
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval; 
```

```cpp
// extra information from textbook
// int ival
// double dval
// float fval
// char cval

int main() {
  // using some arbitrary values to initialize the variables
  int ival = 10;
  double dval = 3.14;
  float fval = 4.29;
  char cval = 'a';
  // if (fval) // if fval is 0 it wil be converted to bool false, otherwise any other value of fval will be converted to bool true

  // dval = fval + ival // ival will be converted to a float and added to fval. The previous float result will be converted to double when assigned to dval

  // dval + ival * cval // cval will be converted to an int and then multiplied with ival. The previous int result will then convert to a double when added to dval

  return 0;
}
```

# Practice Problems
## Sum of Digits
Calculate the sum of digits of a number. The program prompts the user to enter the number. For example: Enter number: 7865 The output should be 7+ 8 + 6 + 5 = 26

Sample output of the program is shown below:
Enter a positive number: 7865
Sum of digits of the number 7865 is: 26

```cpp
#include <iostream>
#include <string>
using namespace std;
// calculate sum of digits of user-given input
int main() {

  string input;
  // get the user-inputted number as a string
  cout << "Enter a whole number" << endl;
  cin >> input;

  cout << "The following number was given: " + input << endl;
  cout << "The sum of the following digits ";
  int sum = 0;
  // iterate through the elements of the string and get the int conversion
  for (char elem : input) {
    int elem_as_num = elem; // get the char and save it into a new int variable
    sum += elem_as_num; // add the digit to the sum
    cout << elem << " ";
  }

  cout << "is " + sum << endl;
  return 0;
}
```

## Prime Numbers
Write a program that finds and prints all the prime numbers between 3 and 100. A prime number is a number such that 1 and itself are the only numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17, ...).

```cpp
#include <iostream>
#include <cmath> // to be able to use the sqrt function
using namespace std;
// find all prime numbers between 3 and 100 inclusive
int main() {
  cout << "These are all the prime numbers between 3 and 100 inclusive" << endl;
  for (int i = 3; i <= 100; ++i) {
    if (check_if_prime(i)) { // check if the current number is prime
      cout << i << " "; // output the prime number
    }
  }

  cout << endl;
}

// helper method to check if a number is prime
bool check_if_prime(int val){
  for (int i = 2; i < val; ++i) { // loop through all posible factors of param val
    if (val % i == 0) { // values with 0 remainder are not prime
      return false;
    }
  }

  return true;
}
```

## Linear Regression
Write a program that reads a file containing a pair of numbers in each line (representing x y coordinates); at the end of reading this file compute the linear regression for this set of numbers.

Please use to the linear regression formulas mentioned in class (if you missed class, find a classmate to get notes).

```cpp
#include <fstream>
#include <vector>
int main() {

  vector<int> x_values;
  vector<int> y_values;
  // read input from file
  return 0;
}

// helper method to get the average of x values
double find_x_average(vector<int> x_vals) {
  double x_average;
  // get the number of elements in the given vector 
  vector<int>::size_type vec_length = x_vals.size(); 
  // loop through vector and average
  return x_average;
}

// helper method to get the average of y values
double find_y_average(vector<int> y_vals) {
  double y_average;
  // loop through the vector and average the y values
  return y_average;
}

// helper method to find the mean x
double mean_x(vector<int> x_vals) {
  double mean;
  // find the average for x values
  find_x_average(x_vals);
  // find the mean

  return mean;
}

double numerator() {
  double x;
  double y
  // calculate (X - Xbar) * (Y - Ybar)
  // return result of above
}

// helper method to find the slope
double slope(double numerator, double denominator) {
  return numerator / denominator;
}

double find_intercept(double slope, double mean_x, double mean_y) {
  double intercept;
  // mean of y-values - slope * mean of x-values
  intercept = mean_y - (slope * mean_x);
  return intercept;
}

double linear_regression(double slope, double intercept) {
  cout << "The linear regression for the given values is Y^=" << intercept << " + " << slope << "x" << endl;
}