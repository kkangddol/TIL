#include<iostream>
#include<algorithm>
using namespace std;

int n;
int stair[300];
int memo[300][2]; //뒤의 인덱스는 1칸을 뛰었을때인지 2칸을 뛰었을때인지

int DP(int height, bool continuity) {
	if (height == n - 1) return stair[n-1];
	if (height > n - 1) return -3000000;

	if (continuity) {
		if (memo[height][1] != -1) return memo[height][1];

		memo[height][1] = DP(height + 2, false) + stair[height];
		return memo[height][1];
	}
	else {
		if(memo[height][0] != -1 && memo[height][1] != -1) return max(memo[height][0], memo[height][1]);

		memo[height][0] = DP(height + 1, true) + stair[height];
		memo[height][1] = DP(height + 2, false) + stair[height];
		return max(memo[height][0], memo[height][1]);
	}

}

int main() {
	for (int i = 0; i < 300; i++)
		for (int j = 0; j < 2; j++)
			memo[i][j] = -1;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];

	cout << max(DP(0, false),DP(1,false));
}