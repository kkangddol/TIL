#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int num = 10 - (2 * (n + 1) * (n + 1) - 1) % 10;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			cout << ' ';
		}
		for (int k = i; k < 2 * n - i +1; k++) {
			cout << 9 - (num % 10);
			num++;
		}
		cout << '\n';
	}

	for (int i = 0; i < n; i++) {
		cout << ' ';
	}
	cout << 9 - (num % 10) << endl;
	num++;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n-i; j++) {
			cout << ' ';
		}
		for (int k = 0; k < 2 * i + 1; k++) {
			cout << 9 - (num % 10);
			num++;
		}
		cout << '\n';
	}

		
}
