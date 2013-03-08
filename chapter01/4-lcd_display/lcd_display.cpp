#if !defined(NOT_JUDGING) or PROBLEM == 706

#include <iostream>

using namespace std;

void print_digit(int section, int size, int digit)
{
  bool print_pipe = (section == 1 && !((digit > 0 && digit < 4) || digit == 7))
    || (section == 3 && (digit == 0 || digit == 2 || digit == 6 || digit == 8));
  cout << (print_pipe ? "|" : " ");
  
  bool print_dash = (section == 0 && !(digit == 1 || digit == 4))
    || (section == 2 && !(digit == 0 || digit == 1 || digit == 7))
    || (section == 4 && !(digit == 1 || digit == 4 || digit == 7));
  for (int i = 0; i < size; i++)
    cout << (print_dash ? "-" : " ");
  
  print_pipe = (section == 1 && !(digit == 5 || digit == 6))
    || (section == 3 && digit != 2);
  cout << (print_pipe ? "|" : " ");
}

void print_number(int size, int number)
{
  int count = 0;
  int number_array[8];
  for (int i = 0; i < 8 && number > 0; i++)
  {
    number_array[i] = number % 10;
    number /= 10;
    count = i + 1;
  }
  
  if (count == 0)
  {
    number_array[0] = 0;
    count = 1;
  }
  
  for (int section = 0; section < 5; section++)
  {
    int iterations = (section == 1 || section == 3 ? size : 1);
    for (int i = 0; i < iterations; i++)
      for (int digit_index = count - 1; digit_index >= 0; digit_index--)
      {
        print_digit(section, size, number_array[digit_index]);
        if (digit_index == 0)
          cout << endl;
        else
          cout << " ";
      }
  }
}

int main()
{
  int size, number;
  while (cin >> size >> number && !(size == 0 && number == 0))
  {
    print_number(size, number);
    cout << endl;
  }
  
  return 0;
}

#endif
