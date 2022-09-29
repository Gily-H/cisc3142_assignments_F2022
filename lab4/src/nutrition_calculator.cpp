#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void lethal_dose() {
  // lethal dose for a mouse: 5grams
  // mouse mass: 35 grams
  // 5 grams / 35 gram mouse = lethal dose (1/7th of body mass)

  // 100lb person mass: 45400 grams 
  // soda can mass: 350 grams
  // amount of sweetener in soda can: 1/10

  // desired weight after dieting
  unsigned desired_weight;
  // while (user still has input)
    cout << "Enter the desired weight after dieting:" << endl;
    cin >> desired_weight;
    
    // convert desired weight into grams
    // multiply the desired weight in grams by 1/7 to get the lethal dose
    // divide the lethal dose by mass of soda cans = number of soda cans to lethal
}

int main() {
  return 0;
}