#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

void multiply_by_two() {
  // initialize an int vector that can hold 10 ints, default value 0
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // get the starting iterator and the end iterator of the nums vector
  auto iter1 = nums.begin();
  auto iter2 = nums.end();

  // for (while iter1 != iter2; ++iter1)
    // dereference iter1 = *iter1 * 2

  // for (int in nums)
    // print the updated value
}

int main() {
  multiply_by_two();
  return 0;
}