#include <iostream>
using namespace std;

// example of O(n)
// void printItems(int n) {
//   for (int i = 0; i < n; i++) {
//     cout << i << endl;
//   }
// }

// example of Drop Constanst
// void printItems(int n) {
//   for (int i = 0; i < n; i++) {
//     cout << i << endl;
//   }

//   for (int j = 0; j < n; j++) {
//     cout << j << endl;
//   }
// }
// => this function runs O(2n) but we can drop constants => O(n)

// O(n^2)
void printItems(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << i << j << endl;
    }
  }
}

// Drop Non-Dominants
void printItems(int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << i << j << endl;
    }
  }
  // the 2 for-loops run O(n^2)

  for (int k = 0; k < n; k++)
  {
    cout << k << endl;
  }
  // this loop runs O(n)

  // now we have O(n^2) + O(n) = O(n^2 + n)
  // we drop the non-dominants, which is O(n). Then, we have the O(n^2) for this operation
}

int main()
{
  printItems(10);
}