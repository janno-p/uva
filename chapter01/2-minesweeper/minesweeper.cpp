#if !defined(NOT_JUDGING) or PROBLEM == 10189

#include <iostream>
#include <limits>

using namespace std;

void increase(char* arr, int index)
{
  arr[index] = (arr[index] == '.') ? '1' : arr[index] + 1;
}

int main()
{
  int m, n, field_num = 1;
  while (cin >> n >> m)
  {
    if (m == 0 && n == 0)
      break;

    if (field_num > 1)
      cout << endl;
    cout << "Field #" << field_num++ << ":" << endl;

    int size = m * n;
    char* field = new char[size];

    for (int i = 0; i < n; i++)
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.read(&field[i * m], m);
    }

    for (int i = 0; i < size; i++)
    {
      if (field[i] != '*')
      {
        if (field[i] == '.')
          field[i] = '0';
        continue;
      }

      int j = i - m - 1;
      if ((i % m) > (j % m) && j >= 0 && field[j] != '*')
        increase(field, j);

      j = i - m;
      if (j >= 0 && field[j] != '*')
        increase(field, j);

      j = i - m + 1;
      if ((i % m) < (j % m) && j >= 0 && j < size && field[j] != '*')
        increase(field, j);

      j = i - 1;
      if ((i % m) > (j % m) && j >= 0 && field[j] != '*')
        increase(field, j);

      j = i + 1;
      if ((i % m) < (j % m) && j < size && field[j] != '*')
        increase(field, j);

      j = i + m - 1;
      if ((i % m) > (j % m) && j >= 0 && j < size && field[j] != '*')
        increase(field, j);

      j = i + m;
      if (j < size && field[j] != '*')
        increase(field, j);

      j = i + m + 1;
      if ((i % m) < (j % m) && j < size && field[j] != '*')
        increase(field, j);
    }

    for (int i = 0; i < size; i++)
    {
      if (i > 0 && i % m == 0)
        cout << endl;
      cout << field[i];
    }

    delete [] field;

    cout << endl;
  }

  return 0;
}

#endif
