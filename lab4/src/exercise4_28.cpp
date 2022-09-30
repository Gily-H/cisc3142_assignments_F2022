/*
 * Program to print the size of each built-in type
 */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void size_of_types() {
  cout << "These are the sizes of the built-in types" << endl;
  cout << "Size of boolean: " << sizeof(bool) << " byte(s)" << endl;
  cout << "Size of char: " << sizeof(char) << " byte(s)" << endl;
  cout << "Size of unsigned char: " << sizeof(unsigned char) << " byte(s)" << endl;
  cout << "Size of signed char: " << sizeof(signed char) << " byte(s)" << endl;
  cout << "Size of short: " << sizeof(short) << " byte(s)" << endl;
  cout << "Size of unsigned: " << sizeof(unsigned) << " byte(s)" << endl;
  cout << "Size of signed: " << sizeof(signed) << " byte(s)" << endl;
  cout << "Size of int: " << sizeof(int) << " byte(s)" << endl;
  cout << "Size of float: " << sizeof(float) << " byte(s)" << endl;
  cout << "Size of double: " << sizeof(double) << " byte(s)" << endl;
  cout << "Size of long long: " << sizeof(long long) << " byte(s)" << endl;
  cout << "Size of long double: " << sizeof(long double) << " byte(s)" << endl;
}

int main() {
  size_of_types();
  return 0;
}
