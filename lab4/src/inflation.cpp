#include <iostream>

using std::cin;
using std::cout;
using std::endl;

double price_after_inflation() {
  double item_cost;
  unsigned years_till_purchase;
  double inflation_rate;

  cout << "Enter the initial cost of the item:" << endl;
  cin >> item_cost;

  cout << "Enter number of years before intended purchase year:" << endl;
  cin >> years_till_purchase;

  cout << "Enter the inflation rate" << endl;
  cin >> inflation_rate;

  // convert percentage to a fraction - divide by 100
  // while (years_till_purchase != 0)
    // updated cost = item_cost * (1 + inflation_rate);
    
  return item_cost;
}

int main() {
  double updated_cost = price_after_inflation();
  cout << "Cost after inflation is: " << updated_cost << endl; 
  return 0;
}