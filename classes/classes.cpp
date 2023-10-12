#include <iostream>
using namespace std;

class Cookie
{
private:
  string color;

public:
  Cookie(string color)
  {
    this->color = color;
  }

  string getColor() { return color; }

  void setColor(string newColor)
  {
    this->color = newColor;
  }
};

int main()
{
  // create Cookie instance
  Cookie *cookieOne = new Cookie("green");
  Cookie *cookieTwo = new Cookie("blue");

  cookieTwo->setColor("Yellow");

  cout << cookieOne->getColor() << endl;
  cout << cookieTwo->getColor() << endl;
}