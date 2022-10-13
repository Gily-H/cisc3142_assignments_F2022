#include <iostream>
using std::cout;
using std::endl;

/*
Program to determine the difference between prefix and postfix increment
*/
int main() {
  int prefix = 100;
  int postfix = 100;
  // the below statement using prefix increment will output 101
  cout << "The prefix operator will output: " << ++prefix << endl; 
  // the below statement using postfix increment will output 100 as the value is updated after it is already outputted to cout
  cout << "The postfix operator will output: " << postfix++ << endl;
  return 0;
}