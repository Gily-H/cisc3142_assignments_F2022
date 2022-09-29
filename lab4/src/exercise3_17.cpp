/*
 * Read a sequence of words from cin and store the values in a vector.
 * Process each word to uppercase and print eight words per line
 */

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/*
 * assumes user inputs words one at a time
 */
void to_uppercase_words() {
  // declare an empty string vector
  vector<string> sequence;
  // declare a string type to hold the input
  string word;

  cout << "Enter a sequence of words, one word at a time" << endl;
  // while (there is input to read)
  while (cin >> word) {
    // append word to end of vector
    sequence.push_back(word);
  }

  cout << "Modifying the words to uppercase" << endl;
  // for each string in the vector
  for (auto it = sequence.begin(); it != sequence.end(); ++it)
    // for each char in the string
    for (auto str_it = (*it).begin(); str_it != (*it).end(); ++str_it)
      // uppercase the char
      *str_it = toupper(*str_it);

  cout << "Here are the uppercased words" << endl;
  // counter to determine when to add a new line
  int word_count = 0;
  // for each string in the vector
  for (auto it = sequence.begin(); it != sequence.end(); ++it) {
    ++word_count;

    // print the modified word
    cout << *it << " ";

    // append a new line when current line contains eight words
    if (word_count % 8 == 0) {
      cout << endl;
    }
  }

  cout << endl;
}

int main() {
  to_uppercase_words();
  return 0;
}
