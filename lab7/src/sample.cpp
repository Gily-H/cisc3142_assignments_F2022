#include <iostream>
using namespace std;

class Sample {
  private:
    int x;
    double y;
  
  public:
    Sample() {
      // initialize the member variables to 0
      x = 0;
      y = 0;
    }

    Sample(int x) {
      // initialize x with the given parameter and initialize y to 0
      this->x = x;
      y = 0;
    }

    Sample(int x, int y) {
      // initialize x and y to the given params
      this->x = x;
      this->y = y;
    }
    Sample(int x, double y) {
      // initialize x to the given int param and initialize y to the given double param
      this->x = x;
      this->y = y;
    }

    void display() {
      cout << "X: " << x << ", Y: " << y << "\n" << endl;
    }
};

int main() {
  Sample sample1;
  Sample sample2(10);
  Sample sample3(20, 30);
  Sample sample4(50, 50.1);

  cout << "Constructor 1 Example: " << endl;
  sample1.display();
  cout << "Constructor 2 Example: " << endl;
  sample2.display();
  cout << "Constructor 3 Example: " << endl; 
  sample3.display();
  cout << "Constructor 4 Example: " << endl;
  sample4.display();
  return 0;
}