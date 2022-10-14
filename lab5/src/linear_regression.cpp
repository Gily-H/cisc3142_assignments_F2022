#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

/*
 * Program to find the linear regression for a given x, y graph
 */

// helper method to calculate the mean of x-coordinate values or y-coordinate values
double find_mean_of_coords(vector<double> axis_values) {
  double mean = 0;
  // get the number of coordinate values in the given vector
  vector<double>::size_type vec_length = axis_values.size();
  // loop through the vector and sum the coord values
  for (auto iter = axis_values.begin(); iter != axis_values.end(); ++iter) {
    mean += *iter;
  }
  
  // divide the sum of coordinate values by the number of values to find the mean
  mean = mean / vec_length;
  return mean;
}

// helper method to calculate the sum of squares
// sum of squares formula --> sum of (X-coord - mean_x)^2
double find_sum_of_squares(vector<double> x_vals, double mean_x) {
  double sum_squares = 0;

  for (auto iter = x_vals.begin(); iter != x_vals.end(); ++iter) {
    // find the difference between x-coord and mean x value --> (x-coord - mean_x)^2
    double x_diff = *iter - mean_x;
    // square the difference and add it to the sum
    sum_squares += pow(x_diff, 2);
  }

  return sum_squares;
}

// helper method to calculate the numerator in the slope equation
// slope numerator --> sum of all (X - mean_x)(Y - mean_y)
// Assumptions: for every X-coord there is a corresponding Y-coord
double find_slope_numerator(vector<double> x_vals, vector<double> y_vals, double mean_x, double mean_y) {
  double numerator = 0;

  auto x_iter = x_vals.begin(); // iterator for x-coord vector
  auto y_iter = y_vals.begin(); // iterator for y-coord vector
  // loop through both vectors
  while (x_iter != x_vals.end() && y_iter != y_vals.end()) {
    // calculate (X - mean_x)(Y - mean_y) for the current (x, y) pair
    double product = (*x_iter - mean_x) * (*y_iter - mean_y);
    numerator += product; // add the product to the numerator value
    ++x_iter;
    ++y_iter;
  }

  return numerator;
}

// helper method to calculate the slope of the line formed by the x, y graph
// slope numerator --> sum of all (X - mean_x)(Y - mean_y)
// slope denominator --> sum of squares --> sum (X-coord - mean_x)^2
double find_slope(double numerator, double denominator) {
  return numerator / denominator; 
}

// helper method to find the intercept of the x, y graph
// intercept --> mean_y - (slope * mean_x)
double find_intercept(double slope, double mean_x, double mean_y) {
  double intercept = 0;
  intercept = mean_y - (slope * mean_x);
  return intercept;
}

// helper method to find the linear regression of the x, y graph
// linear regression --> intercept + (slope * X)
void linear_regression(double slope, double intercept) {
  cout << "The linear regression for the given graph ---> ^Y = " << intercept << " + " << slope << "X" << endl;
}

// helper method to print the coordinate pairs
void output_coordinates(vector<double> x_vals, vector<double> y_vals) {
  auto x_iter = x_vals.begin(); // iterator for x-coord vector
  auto y_iter = y_vals.begin(); // iterator for y-coord vector
  while (x_iter != x_vals.end() && y_iter != y_vals.end()) {
    cout << "(x: " << *x_iter << ", y: " << *y_iter << ")" << endl;
    ++x_iter;
    ++y_iter;
  }
}

int main() {
  cout << "Starting Lab 5 Practice Problem: Linear Regression\n" << endl;

  // vectors to hold the x-coords and y-coords separately
  vector<double> x_coordinates;
  vector<double> y_coordinates;

  // read graph coordinates from input file
  cout << "Reading graph data from file: linear_regression_input.txt" << endl;

  ifstream ifs; // input stream object
  ifs.open("./linear_regression_input1.txt", ifstream::in); // open the file for reading
  // loop until end of file
  while (ifs.good()) { 
    double x;
    double y;

    // read the coord pair
    ifs >> x;
    ifs >> y;
    
    // append coord to corresponding vector
    x_coordinates.push_back(x);
    y_coordinates.push_back(y);
  }

  ifs.close(); // close the stream

  // output the coordinate pairs
  output_coordinates(x_coordinates, y_coordinates);

  // calculate the mean x and mean y
  double mean_x = find_mean_of_coords(x_coordinates);
  cout << "Calculating the mean x value...  " << mean_x << endl;
  double mean_y = find_mean_of_coords(y_coordinates);
  cout << "Calculating the mean y value...  " << mean_y << endl;

  // calculate the sum of squares using x-coordinates and mean x
  double sum_squares = find_sum_of_squares(x_coordinates, mean_x);
  cout << "Calculating the sum of squares...  " << sum_squares << endl;

  // calculate the numerator used to calculate the slope of the graph
  double numerator = find_slope_numerator(x_coordinates, y_coordinates, mean_x, mean_y);

  // calculate the slope of the graph where the denominator is the sum of squares
  double slope = find_slope(numerator, sum_squares);
  cout << "Calculating the slope...  " << slope << endl;

  // // calculate the graph intercept
  double intercept = find_intercept(slope, mean_x, mean_y);
  cout << "Calculating the intercept...  " << intercept << endl;

  // output the linear regression for the given graph
  cout << endl;
  linear_regression(slope, intercept);
  cout << "---------------------------------" << endl;
  return 0;
}