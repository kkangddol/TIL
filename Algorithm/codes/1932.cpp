#include<iostream>
#include<algorithm>
using namespace std;

int n;
int triangle[500][500];
int memo[500][500];
int ans = -1000000;

//가장 큰 합을 메모이제이션 하고 리턴
int DP(int depth, int width) {
	if (depth == n - 1) return triangle[depth][width];
	if (memo[depth][width] != -1) return memo[depth][width];

	memo[depth][width] = max(DP(depth + 1, width), DP(depth + 1, width + 1)) + triangle[depth][width];
	return memo[depth][width];
}

int main() {
	for (int i = 0; i < 500; i++)
		for (int j = 0; j < 500; j++)
			memo[i][j] = -1;

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= i; j++)
			cin >> triangle[i][j];

	cout << DP(0, 0);
}