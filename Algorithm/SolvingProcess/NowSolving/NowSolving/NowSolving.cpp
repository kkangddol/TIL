#include <iostream>

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
	cin >> n;

	int arr[101];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++)
	{
		int gcd = GCD(arr[0], arr[i]);
		cout << arr[0] / gcd << "/" << arr[i] / gcd << endl;
	}

	return 0;
}