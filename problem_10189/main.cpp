#include <iostream>

using namespace std;

int main()
{
  int m, n, field_num = 1;
  while (cin >> n >> m)
  {
    if (m == 0 && n == 0)
      break;
    
    cout << "Field #" << field_num++ << ":" << endl;
    
    // Read the array replacing all dots with zero-s on the way
    
    // Go through all the elements of the array and increase neighbouring cells
    // of "*" by one.
    
    // Print the result
    
    cout << endl;
  }
  
  return 0;
}