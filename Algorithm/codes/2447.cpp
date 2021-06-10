#include <iostream>
#include <vector>

using namespace std;

void star(vector<vector<char>> &arr, int x, int y, int size) {
	int cnt = 0;
	if (size == 1)
		arr[x][y] = '*';
	else {
		for (int i = x; i < x + size; i += size/3) {
			for (int j = y; j < y + size; j += size / 3) {
				cnt++;
				if (cnt != 5) star(arr, i, j, size / 3);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<char>> arr(n, vector<char>(n, ' '));
	star(arr, 0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}
