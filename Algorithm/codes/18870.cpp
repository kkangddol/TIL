#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<pair<int, int>> v;
	int ans[1000000] = {0,};
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back({temp,i});
	}

	sort(v.begin(), v.end());

	int pivot = v[0].first;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (pivot == v[i].first) {
			ans[v[i].second] = cnt;
		}
		else {
			ans[v[i].second] = ++cnt;
			pivot = v[i].first;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}
