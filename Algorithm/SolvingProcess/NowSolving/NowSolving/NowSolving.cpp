#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int ans = 0;
	int people[1001];

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> people[i];

	sort(people, people + n);

	int rep = n;
	for (int i = 0; i < n; i++)
		ans += people[i] * rep--;

	cout << ans;
}