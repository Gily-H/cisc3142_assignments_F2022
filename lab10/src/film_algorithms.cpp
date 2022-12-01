#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

struct Film {
  // key = category, value = category_value
  map<string, string> data;
  int year;
  int length;
  int popularity;
  bool awards;
};

// helper method to convert a given word to lower case
string lower_case(string word) {
  for (auto it = word.begin(); it != word.end(); ++it) {
    if (isalpha(*it)) {
      *it = tolower(*it);
    }
  }

  return word;
}

// method to create and return a Film object with given film data
Film parse_film_data(vector<string> categories, vector<string> film_data) {
  Film film;
  for (int i = 0; i < categories.size(); ++i) {
    // loop through all film categories and store the k,v pairs
    string category = categories[i]; // map key
    string category_value = film_data[i]; // map value
    film.data[category] = category_value;
  }

  // store these category values for convenience and type conversion
  film.year = stoi(film.data["year"]);
  film.length = stoi(film.data["length"]);
  film.popularity = stoi(film.data["popularity"]);
  film.awards = film.data["awards"] == "Yes" ? true : false;

  cout << "Title: " << film.data["title"] << ", Rating: " << film.popularity << endl;

  return film;
}

// helper function to be used inside an accumulate() call
// first param is the initial accumulating value, second param comes from the iterator
int accumulator_helper(int accum, Film film) {
  return accum + film.length;
}

// method to find the total duration of all films in the given list
int find_total_duration(vector<Film> films) {
  int sum = accumulate(films.begin(), films.end(), 0, accumulator_helper);
  return sum;
}

// helper function to be used in sort() call
// returns a boolean result from the comparison between the two params
bool sort_helper(Film one, Film two) {
  return one.popularity > two.popularity;
}

// method to sort the list of films by their popularity rating - highest --> lowest
// pass by reference the list of films
void sort_by_popularity(vector<Film> &films) {
  sort(films.begin(), films.end(), sort_helper);
}

// method to find the first occurrence of a given value in the given film category
Film find_first_occurrence(vector<Film> films, string category, string value) {
  vector<string> values;
  // loop through films and collect all values from the given category
  for (Film &film : films) {
    values.push_back(film.data[category]);
  }

  // find the desired value in the collected list of values
  auto it = find(values.begin(), values.end(), value);
  if (it == values.end()) {
    // return empty Film object if no match found for desired value
    Film empty_film = Film{};
    return empty_film;
  }

  // find the index of the film with the associated found value
  auto film_index = it - values.begin();
  Film film = films[film_index];
  return film;
}

// helper function to be used in unique() call
// returns boolean result when comparing if two param values are equal 
bool unique_helper(Film one, Film two) {
  return one.year == two.year;
}

// method to compare the unique release dates between action and comedy films
bool compare_unique_release_dates(vector<Film> films) {
  vector<Film> comedies;
  vector<Film> actions;

  // filter the films by actions and comedies
  for (Film &film: films) {
    string subject = film.data["subject"];
    if (subject == "Comedy") {
      comedies.push_back(film);
    } else if (subject == "Action") {
      actions.push_back(film);
    }
  }

  // sort the comedies and actions before finding unique values
  sort(comedies.begin(), comedies.end(), [](Film one, Film two) {
    return one.year > two.year;
  });
  sort(actions.begin(), actions.end(), [](Film one, Film two) {
    return one.year > two.year;
  });

  // find unique release years for comedies and erase any duplicate years
  auto com_it = unique(comedies.begin(), comedies.end(), unique_helper);
  comedies.erase(com_it, comedies.end());

  // find unique release years for actions and erase any duplicate years
  auto act_it = unique(actions.begin(), actions.end(), unique_helper);
  actions.erase(act_it, actions.end());

  // compare the unique lists of years to see if they are equal
  // equal() assumes the second list is as large as the first list
  bool is_equal;
  if (comedies.size() >= actions.size()) {
    is_equal = equal(comedies.begin(), comedies.end(), actions.begin(), unique_helper);
  } else {
    is_equal = equal(actions.begin(), actions.end(), comedies.begin(), unique_helper);
  }

  return is_equal;
}

int main() {
  vector<Film> films;
  vector<string> categories;
  ifstream ifs;
  ifs.open("./input/test.csv"); // open the input file for reading

  // go through the first two lines of the file containing column headers
  if (ifs.good()) {
    string header;

    // loop through and store the film category headers (in lower case form)
    for (int i = 0; i < 9; ++i) {
      getline(ifs, header, ';');
      categories.push_back(lower_case(header)); 
    }

    getline(ifs, header, '\n'); // end of first line of file
    categories.push_back(header); // get the last category of the line
    getline(ifs, header); // retrieve the second line of the file -- not needed
  }

  cout << "\n===============================================\n" << endl;
  cout << "Reading film data...\n" << endl;

  // loop through rest of the lines of film data in file
  while (ifs.good()) {
    vector<string> film_data;
    string data;

    // store each category value for the current line of film data
    for (int i = 0; i < 9; ++i) {
      getline(ifs, data, ';'); // will split the values by the delimiter
      film_data.push_back(data);
    }

    getline(ifs, data, '\n'); // end of line
    film_data.push_back(data); // get the last category value -- image file

    // create a film object with the data
    Film film = parse_film_data(categories, film_data); 
    films.push_back(film);
  }

  ifs.close(); // close the file stream when done reading from file

  cout << "\n===============================================\n" << endl;

  // summation of film lengths
  int total_duration = find_total_duration(films);
  cout << "The total duration of all movies: " << total_duration << " minutes" << endl;

  cout << "\n===============================================\n" << endl;

  // sort the films from highest popularity rating to lowest
  cout << "Sorting the list of films by popularity..." << endl;
  cout << "------------------------------------------" << endl;
  sort_by_popularity(films);
  Film most_popular_film = films[0];
  Film least_popular_film = films[films.size() - 1];
  pair<string, int> most_popular(most_popular_film.data["title"], most_popular_film.popularity);
  pair<string, int> least_popular(least_popular_film.data["title"], least_popular_film.popularity);
  cout << "Most popular film: " << most_popular.first << ", Rating: " << most_popular.second << endl << "Least popular film: " << least_popular.first << ", Rating: " << least_popular.second << endl;

  cout << "\n===============================================\n" << endl;

  // search in film data
  string film_category;
  string value_to_search;
  Film found_film;
  
  do {
    // prompt user for a film category to search the value
    cout << "Enter a film category to search in:" << endl;
    getline(cin, film_category);

    // prompt user for a value to search
    cout << "\nEnter a value to search:" << endl;
    getline(cin, value_to_search);

    found_film = find_first_occurrence(films, lower_case(film_category), value_to_search);
    if (found_film.data.empty()) {
      cout << "\n**Unable to find desired search value. Please try again.**\n" << endl;
    }

  } while (found_film.data.empty()); // repeat until match found for desired search value

  cout << "\nFound value: " << value_to_search << ", in category: " << film_category << ", for film: " << endl;
  cout << "------------------------------------------" << endl;
  cout << found_film.data["title"] << " (" << found_film.year << ") " << found_film.length << " mins" << endl
       << "Directed by " << found_film.data["director"] << endl
       << "Starring" << endl
       << found_film.data["actor"] << " and " << found_film.data["actress"] << endl
       << "Rating: " << found_film.popularity << endl;
  cout << "\n===============================================\n" << endl;
  
  // compare unqiue release years between action films and comedy films
  bool identical_releases;
  identical_releases = compare_unique_release_dates(films);
  if (identical_releases) {
    cout << "Action and Comedy films have identical release years";
  }
  
  cout << "Action and Comedy films do not have identical release years" << endl;
  cout << "\n===============================================\n" << endl;

  return 0;
}