/*
 * Exercise 1.5
 * Rewrite the program found in
 * section 1.2 of the textbook
 * to have separate statements
 * print each operand
 */

#include <iostream>

int main() {
	std::cout << "Starting Lab 2 Exercise 1.5\n" << std::endl;
	std::cout << "Enter two numbers:" << std::endl;
	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	
	/* Original program line */
	// std::cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << std::endl;
	
	/* Modified line */
	std::cout << "The first operand is " << v1 << std::endl;
	std::cout << "The second operand is " << v2 << std::endl;
	std::cout << "The sum of both operands is " << v1 + v2 << std::endl;
	std::cout << "---------------------------------" << std::endl;

	return 0;
}
