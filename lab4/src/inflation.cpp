/*
 * Program to output the cost of an item after adjusting for inflation
 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

double price_after_inflation() {
  double item_cost;
  unsigned years_till_purchase;
  double inflation_rate;

  cout << "Enter the initial cost of the item:" << endl;
  cin >> item_cost;

  cout << "Enter number of years before intended purchase date:" << endl;
  cin >> years_till_purchase;

  cout << "Enter the inflation rate percentage without the (%) symbol" << endl;
  cin >> inflation_rate;

  cout << "Initial cost: $" << item_cost << ", Years before purchase: " << years_till_purchase << " years, Inflation rate: " << inflation_rate << "%" << endl;

  // convert the inflation rate percentage to a decimal fraction
  inflation_rate = inflation_rate / 100;

  unsigned year_count = 0;
  double updated_cost = item_cost;
  // calculate the updated cost after adjusting for inflation every year
  while (year_count != years_till_purchase) {
	  // calculate the updated cost based on the previous years cost
	  updated_cost = updated_cost * (1 + inflation_rate);
	  ++year_count;
  }
    
  cout << endl;
  return updated_cost;
}

int main() {
  double updated_cost = price_after_inflation();
  cout << endl;
  cout << setprecision(2) << fixed << "Cost after inflation: $" << updated_cost << endl;
  cout << "----------------------------------" << endl;
  cout << endl;
  return 0;
}
