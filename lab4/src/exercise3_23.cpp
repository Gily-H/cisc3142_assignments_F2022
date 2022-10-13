/*
 * Program to create a vector of ten ints
 * Double the values in the int vector
 */

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void multiply_by_two() {
  // initialize an int vector that can hold ten ints
  vector<int> nums = {12, 27, 3, 74, 25, 16, 7, 88, 89, 11};

  cout << "These are the current values in the vector" << endl;
  // for (while iter1 != iter2; ++iter1)
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    // print the current value in vector
    cout << *it << " ";
    // double the value
    *it = *it * 2;
  }
  cout << endl;

  cout << "These are the values in the vector doubled" << endl;
  // print out the modified values in the vector
  for (auto it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
  }

  cout << endl;
  cout << "----------------------------------" << endl;
  cout << endl;
}

int main() {
  multiply_by_two();
  return 0;
}
