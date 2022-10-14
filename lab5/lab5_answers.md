# Textbook Exercises For Lab 5

## Exercise 4.5

```
Determine the results of the following expressions
(a) -30 * 3 + 21 / 5 - will output -86
(b) -30 + 3 * 21 / 5 - will output -18
(c) 30 / 3 * 21 % 5 - will output 0
(d) -30 / 3 * 21 % 4 - will output -2
```

```bash
# exercise 4.5 answers
(a) (-30 * 3) + (21 / 5)
    (-90) + (4)
    --> (-86)

(b) -30 + ((3 * 21) / 5)
    -30 + (63 / 5)
    -30 + (12)
    --> (-18)

(c) ((30 / 3) * 21) % 5
    (10 * 21) % 5
    210 % 5
    --> (0)

(d) ((-30 / 3) * 21) % 4
    (-10 * 21) % 4
    (-210) % 4
    --> (2)
```

## Exercise 4.17

_Explain the difference between prefix and postfix increment_

```cpp
// exercise 4.17 answer
- prefix increment will update the value before it is evaluated
- postfix increment will update the value after it is evaluated

// example
int prefix = 100;
int postfix = 100;
cout << "The prefix operator will output: " << ++prefix << endl; // this will update the prefix value and then evaluate to 101
cout << "The postfix operator will output: " << postfix++ << endl; // this will evaluate to 100 and then update the value to 101 after it has already been outputted
```

## Exercise 4.34

```
Given the variable definitions in this section, explain what conversions take place in the following expressions
(a) if (fval)
(b) dval = fval + ival;
(c) dval + ival * cval;
```

```bash
# exercise 4.34 answers

# extra information from textbook
# int ival
# double dval
# float fval
# char cval

# if fval is 0 it wil be converted to bool false, otherwise any other value of fval will be converted to bool true
if (fval)

# ival will be converted to a float and added to fval. The previous float result will be converted to double when assigned to dval
dval = fval + ival

# cval will be converted to an int and then multiplied with ival. The previous int result will then convert to a double when added to dval
dval + ival * cval
```