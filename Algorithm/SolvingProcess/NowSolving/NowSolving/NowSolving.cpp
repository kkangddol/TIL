#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;
	vector<pair<int, int>> things; //first == wegiht , second == value
	things.push_back(make_pair(-1, -1));
	int valueMemo[101][100001] = {0,};
	
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		int tempWeight, tempValue;
		cin >> tempWeight >> tempValue;
		things.push_back(make_pair(tempWeight, tempValue));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (things[i].first > j)
				valueMemo[i][j] = valueMemo[i - 1][j];
			else {
				if (j - things[i].first > 0) {
					valueMemo[i][j] = max(things[i].second + valueMemo[i - 1][j - things[i].first], valueMemo[i - 1][j]);
				}
				else {
					valueMemo[i][j] = max(things[i].second, valueMemo[i - 1][j]);
				}
			}
		}
	}

	cout << valueMemo[n][k];

}