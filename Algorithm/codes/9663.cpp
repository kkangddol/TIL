#include <iostream>
#include <math.h>
using namespace std;

int chessCol[15] = { 0, };

int n, ans = 0;

bool isCool(int col, int row) {
	for (int i = 1; i <= n; i++) {
		if (col == i) continue;
		if (chessCol[i] == 0) continue;
		if (chessCol[i] == row) return false;
		if (abs(i - col) == abs(chessCol[i] - row)) return false;
	}
	return true;
}

void recur(int order) {
	if (order > n) {
		ans++;
		return;
	}

	for (int row = 1; row <= n; row++) {
		chessCol[order] = row;
		if (isCool(order, row))
			recur(order + 1);
		chessCol[order] = 0;
	}

}

int main() {
	cin >> n;
	recur(1);
	cout << ans;
}
