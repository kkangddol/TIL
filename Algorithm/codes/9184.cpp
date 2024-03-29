#include<iostream>
using namespace std;

int arr[21][21][21];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);

	if (arr[a][b][c] != NULL) return arr[a][b][c];

	if (a < b && b < c) {
		arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return arr[a][b][c];
	}

	arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return arr[a][b][c];
}

int main() {
	for (int a = 0; a < 21; a++)
		for (int b = 0; b < 21; b++)
			for (int c = 0; c < 21; c++)
				arr[a][b][c] = NULL;

	int input[3] = { 0,0,0 };
	bool isCool = true;
	while (isCool) {
		for (int i = 0; i < 3; i++)
			cin >> input[i];
		if (input[0] == -1 && input[1] == -1 && input[2] == -1) {
			isCool = false;
			return 0;
		}
		cout << "w(" << input[0] << ", " << input[1] << ", " << input[2] << ") = " << w(input[0], input[1], input[2]) << endl;
	}
}