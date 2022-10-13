#include <iostream>
using std::cout;
using std::endl;

/*
Program to output the results of the following expressions 
(a) -30 * 3 + 21 / 5
(b) -30 + 3 * 21 / 5
(c) 30 / 3 * 21 % 5
(d) -30 / 3 * 21 % 4
*/
int main() {
  double a_output = -30 * 3 + 21 / 5;
  double b_output = -30 + 3 * 21 / 5;
  double c_output = 30 / 3 * 21 % 5;
  double d_output = -30 / 3 * 21 % 4;
  cout << "The output of the expressions (-30 * 3 + 21 / 5) is " << a_output << endl;
  cout << "The output of the expressions (-30 + 3 * 21 / 5) is " << b_output << endl;
  cout << "The output of the expressions (30 / 3 * 21 % 5) is " << c_output << endl;
  cout << "The output of the expressions (-30 / 3 * 21 % 4) is " << d_output << endl;
}