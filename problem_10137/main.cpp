#if !defined(NOT_JUDGING) or PROBLEM == 10137

#include <iomanip>
#include <iostream>

using namespace std;

int* read_amounts(int count)
{
  int* amounts = new int[count];
  for (int i = 0; i < count; i++)
  {
    int x, y;
    cin >> x;
    cin.ignore();
    cin >> y;
    amounts[i] = x * 100 + y;
  }
  return amounts;
}

int get_total(int* amounts, int count)
{
  int total = 0;
  for (int i = 0; i < count; i++)
    total += amounts[i];
  return total;
}

void print_sum(int sum)
{
  cout << "$" << (sum / 100) << "." << setfill('0') << setw(2) << (sum % 100) << endl;
}

int main()
{
  int count;
  while (cin >> count && count > 0)
  {
    int* amounts = read_amounts(count);

    int total = get_total(amounts, count);
    int average = total / count;

    int sum_less = 0, sum_more = 0;
    for (int i = 0; i < count; i++)
    {
      if (amounts[i] < average)
        sum_less += (average - amounts[i]);
      if (amounts[i] > average + 1)
        sum_more += (amounts[i] - average - 1);
    }

    print_sum(max(sum_less, sum_more));

    delete [] amounts;
	}

	return 0;
}

#endif
