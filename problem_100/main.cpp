/**
 * The 3n + 1 Problem
 */

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
		int max = 0;
		for (int i = a; i <= b; i++)
		{
			int current = cycle_length(i);
			max = std::max(current, max);
		}
		cout << a << " " << b << " " << max << endl;
	}
	
	return 0;
}
