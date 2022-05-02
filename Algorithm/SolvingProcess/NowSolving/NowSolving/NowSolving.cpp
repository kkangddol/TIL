#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int x, int y)
{
	if (x % y == 0)
	{
		return y;
	}
	else
	{
		return GCD(y, x % y);
	}
}

int main()
{
	int n;
	int inputArr[101] = { 0, };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inputArr[i];
	}
	sort(inputArr, inputArr + n);

	int gcd = inputArr[1] - inputArr[0];
	for (int i = 0; i < n - 1; i++)
	{
		gcd = GCD(inputArr[i + 1] - inputArr[i], gcd);
	}

	vector<int> gcd_vector;
	for (int i = 1; i <= gcd; i++)
	{
		if (gcd % i == 0) {
			if (i > gcd / i) break;

			gcd_vector.push_back(i);

			if (i == gcd / i) break;

			gcd_vector.push_back(gcd / i);
		}
	}

	sort(gcd_vector.begin(), gcd_vector.end());

	vector<int>::iterator iter = gcd_vector.begin();
	for (iter; iter != gcd_vector.end(); iter++)
	{
		if (*iter != 1)
		{
			cout << *iter << endl;
		}
	}

	return 0;
}