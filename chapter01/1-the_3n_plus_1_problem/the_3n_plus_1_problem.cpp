#if !defined(NOT_JUDGING) or PROBLEM == 100

#include <iostream>
#include <cmath>

using namespace std;

int cycle_length(int n)
{
  int temp = n, length = 1;
  while (temp != 1)
  {
    temp = (temp % 2 == 0) ? (temp / 2) : (3 * temp + 1);
    length++;
  }
  return length;
}

int main()
{
  int a, b;
  while (cin >> a >> b)
  {
    int first = std::min(a, b);
    int last = std::max(a, b);

    int max = 0;
    for (int i = first; i <= last; i++)
    {
      int current = cycle_length(i);
      max = std::max(current, max);
    }
    cout << a << " " << b << " " << max << endl;
  }

  return 0;
}

#endif
