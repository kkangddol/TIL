#include <iostream>
#include <algorithm>
using namespace std;

int memo[1000][3];
int colorArr[1000][3];
int n;
int ans = 2000000;

int DP(int index, int color) {
	int localMin = 2000000;
	if (index == n - 1)
		return colorArr[index][color];

	if (memo[index][color] != 0)
		return memo[index][color];

	for (int i = 0; i < 3; i++) {
		if (i == color) continue;

		int temp = DP(index + 1, i) + colorArr[index][color];

		if (temp < localMin) localMin = temp;
	}
	memo[index][color] = localMin;
	return localMin;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> colorArr[i][0] >> colorArr[i][1] >> colorArr[i][2];
	
	cout << min(min(DP(0, 0), DP(0, 1)), DP(0, 2));
	
}