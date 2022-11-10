#include <iostream>

using namespace std;

class Rectangle {
  /* Class to construct and modify a rectangle object */
  private:
    float length;
    float width;

  public:
    // method to set the rectangle length
    void setLength(float newLength) {
      length = newLength;
    }

    // method to set the rectangle width
    void setWidth(float newWidth) {
      width = newWidth;
    }

    // returns the perimeter value of rectangle
    float perimeter() {
      return (2 * width) + (2 * length);
    }

    // returns the area of rectangle
    float area() {
      return (length * width);
    }

    // display the length and width of the rectangle to the user
    void show() {
      cout << "Width: " << width << ", Length: " << length << endl;
    }
};

void check_if_same_area(float area1, float area2) {
  if (area1 == area2) {
    cout << "\nThe two rectangles are equal in area\n" << endl;
  } else {
    cout << "\nThe two rectangles are NOT equal in area\n" << endl;
  }
}

int main() {
  /* lab exercise 7 part 2 */

  // create two rectangle objects
  Rectangle rect1;
  Rectangle rect2;

  // set the first rectangle to have length 5 and width 2.5
  rect1.setLength(5);
  rect1.setWidth(2.5);

  // set the second rectangle to have length 5 and width 18.9
  rect2.setLength(5);
  rect2.setWidth(18.9);

  // display the dimensions, area, and perimete for both rectangles
  cout << "Rectangle 1 - Dimensions: " << endl;
  rect1.show();
  cout << "Area: " << rect1.area() << ", Perimeter: " << rect1.perimeter() << endl;
  
  cout << "\nRectangle 2 - Dimensions: " << endl;
  rect2.show();
  cout << "Area: " << rect2.area() << ", Perimeter: " << rect2.perimeter() << endl;

  /* lab exercise 7 part 3 */

  // check if the two rectangles have the same area
  check_if_same_area(rect1.area(), rect2.area());

  // reset the length and width of the first rectangle to 15 and 6.3 respectively
  rect1.setLength(15);
  rect1.setWidth(6.3);

  // display the dimesnions, area and perimeter of each rectangle again
  cout << "Rectangle 1 - Dimensions: " << endl;
  rect1.show();
  cout << "Area: " << rect1.area() << ", Perimeter: " << rect1.perimeter() << endl;
  
  cout << "\nRectangle 2 - Dimensions: " << endl;
  rect2.show();
  cout << "Area: " << rect2.area() << ", Perimeter: " << rect2.perimeter() << endl;

  // check if the two rectangles have the same area after modifying rectangle 1
  check_if_same_area(rect1.area(), rect2.area());

  return 0;
}