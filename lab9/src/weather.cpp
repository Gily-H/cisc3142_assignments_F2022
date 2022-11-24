#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


const int column_width = 20;
const double period = 2; // actual period is += 1; accounts for 0-indexed vectors
struct Weather {
  // structure to hold temperature data for a specific month
  string month;
  double temp;
};

string find_next_month(int num)
{
  // helper method to determine the month based on the given num
  int remainder = num % 12;
  string month;
  switch (remainder)
  {
  case 1:
    month = "Jan";
    break;
  case 2:
    month = "Feb";
    break;
  case 3:
    month = "Mar";
    break;
  case 4:
    month = "Apr";
    break;
  case 5:
    month = "May";
    break;
  case 6:
    month = "Jun";
    break;
  case 7:
    month = "Jul";
    break;
  case 8:
    month = "Aug";
    break;
  case 9:
    month = "Sep";
    break;
  case 10:
    month = "Oct";
    break;
  case 11:
    month = "Nov";
    break;
  case 0:
    month = "Dec";
    break;
  default:
    month = "Err";
    break;
  }

  return month;
}

void find_simple_average(vector<Weather> records) {
  // calculate the average temp using all months
  double sum = 0;
  for (Weather &record : records) {
    sum += record.temp;
  }

  double simple_average = sum / records.size();
  cout << "The simple average: " << simple_average << "\n" << endl;
}

void find_moving_average(vector<Weather> records) {
  // using a 3-month period, calculate the moving average for the third month of the group
  // ex: Jan - Mar --> moving average for March
  cout << setw(column_width) << left << "Months" << setw(column_width) << right << "Moving Average" << endl;

  for (auto curr_month = period; curr_month < records.size(); ++curr_month) {
    double moving_sum = 0; 

    // get the records for the past 3 months
    Weather curr = records[curr_month];
    Weather prev = records[curr_month - 1];
    Weather prevprev = records[curr_month - 2];

    // sum the temperatures for the past three months
    moving_sum += curr.temp;
    moving_sum += prev.temp;
    moving_sum += prevprev.temp;

    // calculate the average for the three months
    double moving_average = moving_sum / period;

    cout << prevprev.month << " " << prev.month << " " << curr.month << setw(column_width) << " " << fixed << setprecision(2) << moving_average << endl;
  }

  cout << "\n" << endl;
}

void find_weighted_moving_average(vector<Weather> records) {
  // using a 3-month period, calculate the weighted average for the next sequential month
  // ex: Jan - Mar --> weighted moving average for April
  cout << setw(column_width) << left << "Months" << setw(column_width) << right << "Weighted Moving Average" << endl;

  for (auto curr_month = period; curr_month < records.size(); ++curr_month) {
    double weighted_sum = 0;

    Weather curr = records[curr_month];
    Weather prev = records[curr_month - 1];
    Weather prevprev = records[curr_month - 2];

    // sum the temperatures for the past three months
    weighted_sum += curr.temp * 3;
    weighted_sum += prev.temp * 2;
    weighted_sum += prevprev.temp * 1;

    // calculate the average for the three months
    int weight = 3 + 2 + 1;
    double current_weighted_average = weighted_sum / (weight);

    int next_month = curr_month + 2; // add 2 instead of 1 - 0-indexed vector
    cout << prevprev.month << " " << prev.month << " " << curr.month << " " << find_next_month(next_month) << setw(column_width) << " " << current_weighted_average << endl;
  }

  cout << "\n" << endl;
}


int main() {
  // create an input file stream to read a csv file containing monthly temperature data
  vector<Weather> weather_records;

  ifstream ifs; 
  ifs.open("lab9/src/input/weather.csv");
  // read one line to move past the column headings
  if (ifs.good()) {
    string line;
    ifs >> line; 
  }

  cout << "Reading in monthly weather temperatures" << endl;
  while (ifs.good()) {
    Weather weather;
    string data;

    // read a line of data from the csv file -> format: "Month,Temp"
    ifs >> data;

    // find the comma in the line of data
    int delimiter = data.find(",");
    // retrieve the month without the comma
    weather.month = data.substr(0, delimiter);
    // retrieve the temp and convert it to an int type
    string temp = data.substr(delimiter + 1, data.length());
    weather.temp = stod(temp);

    // store the weather record
    weather_records.push_back(weather);
    cout << weather.month << ": " << weather.temp << endl;
  }

  ifs.close(); // close the ifstream
  cout << "Finished reading input file\n" << endl;

  // calculate the simple, moving, and weighted moving averages using the given data
  find_simple_average(weather_records);
  find_moving_average(weather_records);
  find_weighted_moving_average(weather_records);

  return 0;
}