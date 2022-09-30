/*
 * Program to determine the number of soda cans with artificial sweetener
 * that a person can drink before dying
 */

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::setprecision;
using std::fixed;
using std::endl;

void calculate_lethal_dose() {
  cout << "Find out how much soda you would need to drink in order to perish" << endl;
  // amount of artificial sweetener needed to kill a mouse in grams
  const double mouse_sweetener = 5.0;
  // mouse mass reference in grams
  const double mouse_mass = 35.0;
  // proportion of sweetener to mass needed to be lethal
  const double mouse_lethal = mouse_sweetener / mouse_mass;
  // 100lb person mass reference in grams 
  const double person_mass = 45400.0;
  // soda-can mass in grams
  const double soda_mass = 350.0;
  // amount of sweetener in a soda can
  const double sweetener = 0.001;

  // user-inputted desired weight after dieting
  double desired_weight;
  double weight_in_grams;
  double person_lethal;
  double soda_lethal;
  int soda_cans;
  cout << "Please enter your desired weight:" << endl;
  // loop until no more input
  while (cin >> desired_weight) {
	  // convert the desired weight into grams based on hundred-pound person ratio
	  weight_in_grams = (desired_weight / 100) * person_mass;
	  // calculate lethal dose of sweetener in grams needed for person, based on mouse lethal proportion
	  person_lethal = weight_in_grams * mouse_lethal;
	  // find lethal dose in grams of soda
	  soda_lethal = person_lethal / sweetener;
	  // find lethal dose in cans of soda
	  soda_cans = soda_lethal / soda_mass;

	  cout << "Lethal dose of sweetener for " << desired_weight << "lbs person: " << person_lethal << "grams of sweetener" << endl;
	  cout << setprecision(2) << fixed << "You would need to drink about " << soda_cans << " cans or about " << soda_lethal << " grams of soda before you would die trying to diet to " << desired_weight << "lbs" << endl;

	  cout << endl;
	  cout << "Enter a new weight or exit the program using 'Ctrl+Z' or 'Ctrl+D'" << endl;
  }
}

int main() {
	calculate_lethal_dose();
  return 0;
}
