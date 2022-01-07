#include <iostream>
using namespace std;

int memo[1000001];

int dp(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (memo[n] != 0) return memo[n];

	memo[n] = (dp(n - 1) + dp(n - 2)) % 15746;
	return memo[n];
}

int main() {
	memo[1] = 1;
	memo[2] = 2;

	int n;
	cin >> n;

	int ans = dp(n);
	cout << ans << endl;
}