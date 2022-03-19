#include <iostream>

using namespace std;

int main() {
	int n;
	int distances[1000] = {0,};
	int gasPrice[1000] = {0,};

	cin >> n;
	for (int i = 0; i < n-1; i++)
		cin >> distances[i];
	for (int i = 0; i < n; i++)
		cin >> gasPrice[i];

	int ans = 0;
	int distance = 0;
	int minPrice = 1000000001;

	for (int i = 0; i < n - 1; i++) {
		if (minPrice <= gasPrice[i]) {
			distance += distances[i];
		}
		else {
			ans += minPrice * distance;
			minPrice = gasPrice[i];
			distance = distances[i];
		}
	}
	ans += minPrice * distance;

	cout << ans;
}