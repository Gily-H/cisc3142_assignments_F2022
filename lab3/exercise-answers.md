# Exercises for Lab 3
The following are the completed exercises for lab3 of course CISC 3142

<br/>

## __Exercise 2.1__
_What are the differences between int, long, long long, and short? Between an unsigned and a signed type? Between a float and a double?_

The types int, long, long long, and short represent integers of varying sizes. The `short` type can represent small integers, while the `int` type can represent integer values that are at least as large as a short type. The `long` type can represent integers at least as large as the int type, and the `long long` type can represent integer values at least as large as the long type or greater.

A signed type can represent negative values, while an unsigned type will not represent numbers below zero.

Floats and Doubles are floating-point types that can represent precision values, or values with decimals. `float` types are single-precision and can represent six significant digits, while the double type can represent ten significant digits.

<br/>

## __Exercise 2.2__
_To calculate a mortgage payment, what types would you use for the rate, principal, and payment? Explain why you selected each type._

For the rate, principal, and payment of a mortgage, I would use the `double` floating-point type to represent all three values. Each of the values would have some amount of decimal digits and would need to be more accurate than using an `int` type that would truncate the digits after the decimal point.

<br/>

## __Exercises 2.3__
_What output will the following code produce_
```cpp
unsigned u = 10, u2 = 42;
std::cout << u2 - u << std::endl;
std::cout << u - u2 << std::endl;
int i = 10, i2 = 42;
std::cout << i2 - i << std::endl;
std::cout << i - i2 << std::endl;
std::cout << i - u << std::endl;
```
The above code will output:
```
32
4294967264 (assuming 32-bit int. The value wraps because we are calculating a negative value for an unsigned type which is not possible)
32
-32
0
```

<br/>

## __Exercise 2.10__
_What are the initial values, if any, of each of the following variables?_
```cpp
std::string global_str;
int global_int;

int main() {
	int local_int;
	std:string local_str;
}
```
The above code will have initial values of 
```
global_str: "" (empty string)
global_int: 0 (default value for built-in type outside of function)
local_int: undefined (for built-in type inside a function)
local_str: "" (empty string
```

<br/>

## __Exercise 2.12__
_Which, if any, of the following names are invalid?_
```
(a) int double = 3.14; -- invalid - double is a keyword
(b) int _; -- invalid if defined outside a function
(c) int catch-22; -- invalid, cannot have a hyphen
(d) int 1_or_2 = 1; -- invalid, must begin with either a letter or underscore
(e) double Double = 3.14; -- valid Double is not a keyword
```

<br/>

## __Exercise 2.13__
_What is the value of j in the following program?_
```cpp
int i = 42;
int main() {
	int i = 100;
	int j = i;
}
```
The value of j would be 100 since the local variable `i` inside main masks the global variable `i`

<br/>

## __Exercise 2.14__
_Is the following program legal? If so, what values are printed?_
```cpp
int i = 100, sum = 0;
for (int i = 0; i != 10; ++i)
	sum += i;
std::cout << i << " " << sum << std::endl;
```
The above program is legal and will print out `100 45`. The variable `i` in the cout statement refers to the `i` defined outside of the for-loop

<br/>

## __Exercise 2.17__
_What does the following code print?_
```cpp
int i, &ri = i;
i = 5; ri = 10;
std::cout << i << " " << ri << std::endl;
```
The above code prints `10 10` as `ri` refers to the value inside of `i`

<br/>

## __Exercise 2.27__
_Which of the following initializations are legal? Explain why_
```cpp
(a) int i = -1, &r = 0; // invalid, int literal being assigned to reference
(b) int *const p2 = &i2; // valid, pointers may be const
(c) const int i = -1, &r = 0; // valid, we can bind a literal to a const reference
(d) const int *const p3 = &i2; // valid if i2 is a const int
(e) const int *p1 = &i2; // valid if i2 is an int type
(f) const int &const r2; // invalid, const reference
(g) const int i2 = i, &r = i; // valid for either const or nonconst i variable
```

<br/>

## __Exercise 2.28__
_Explain the following definitions. Identify any that are illegal_
```cpp
// i is a plain int object, cp is a const pointer to a const int object
(a) int i, *const cp;  // illegal, cp needs to be initialized

// p1 is a pointer to an int object, p2 is a const pointer to a const int object
(b) int *p1, *const p2; // illegal, p2 needs to be initialized

// ic is a const int object, r is a reference to a const int object
(c) const int ic, &r = ic; // illegal, const ic needs to be initialized

// p3 is a const pointer that points to a const int object
(d) const int *const p3; // illegal, need to initialize const pointer

// p is a pointer to a const int object
(e) const int *p; // legal
```
