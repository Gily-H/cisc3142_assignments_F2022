/*
 * Exercise 1.11
 * Write a program that prompts
 * the user for two integers. Print
 * each number in the range specified
 * by those two integers - for-loop
 */

#include <iostream>

int main() {
	int num_one = 0;
	int num_two = 0;
	
	std::cout << "Please enter two numbers to see the range of numbers inbetween:" << std::endl;
	std::cin >> num_one >> num_two;

	int start = 0;
	int end = 0;

	// determine which operand is the lower limit and upper limit
	if (num_one > num_two) {
		start = num_two;
		end = num_one;
	} else if (num_one < num_two) {
		start = num_one;
		end = num_two;
	} else {
		start = num_one;
		end = start;
	}

	// print the range of numbers inclusive
	std::cout << "Here is the range of numbers" << std::endl;
	for (int i = start; i <= end; ++i) {
		std::cout << i << std::endl;
	}

	return 0;
}
