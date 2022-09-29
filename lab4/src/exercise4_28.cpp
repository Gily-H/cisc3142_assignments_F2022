#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void size_of_types() {
  cout << "These are the sizes of the built-in types" << endl;
  cout << "Size of char: " << sizeof(char) << " byte" << endl;
  cout << "Size of int: " << sizeof(int) << " bytes" << endl;
  cout << "Size of float: " << sizeof(float) << " bytes" << endl;
  cout << "Size of double: " << sizeof(double) << " bytes" << endl;
}

int main() {
  size_of_types();
  return 0;
}