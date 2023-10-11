#include <iostream>
using namespace std;

int main() {
  int num1 = 11;
  int num2 = 22;

  num2 = num1;

  int* num3 = new int(22);
  int* num4 = num3;

  int* num5 = new int(44);
  num4 = num5;

  cout << "num1: " << num1 << endl;
  cout << "num2: " << num2 << endl;
  cout << "address num3: " << num3 << endl;
  cout << "address num4: " << num4 << endl;
  cout << "actual num3: " << *num3 << endl;
  cout << "actual num4: " << *num4 << endl;
}