#include <iostream>
#include <string>

using namespace std;

/*
 * Program to calculate the sum of the digits of a user-given number
 * Assumes input will be an unsigned whole integer value
 * Example: given input 123456789 --> output should be 45
 */

// helper method to convert char representing digit into an int value
int convert_to_num(char num_to_convert) {
  int num;
  switch (num_to_convert) {
  case '1':
    num = 1;
    break;
  case '2':
    num = 2;
    break;
  case '3':
    num = 3;
    break;
  case '4':
    num = 4;
    break;
  case '5':
    num = 5;
    break;
  case '6':
    num = 6;
    break;
  case '7':
    num = 7;
    break;
  case '8':
    num = 8;
    break;
  case '9':
    num = 9;
    break;
  default:
    num = 0;
    break;
  }

  return num;
}

int main() {
  cout << "Starting Lab 5 Practice Problem: Sum of Digits\n" << endl;
  // string variable to hold the user-inputted number
  string input;

  cout << "Please enter a whole number:" << endl;
  cin >> input;

  cout << "The following number was provided: " << input << endl;
  cout << "The sum of the following digits: ";
  int sum = 0;
  // iterate through the elements of the string and get the int conversion
  for (char elem : input) {
    int num = convert_to_num(elem); // convert the char into an integer value
    sum += num; // add the value of the digit to the sum
    cout << num << " "; // print out the digit
  }

  // output the sum of the digits
  cout << "is ---> " << sum << endl;
  cout << "---------------------------------" << endl;
  return 0;
}