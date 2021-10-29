#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, int>> coordinates;
	for (int i = 0; i < n; i++) {
		int tempX;
		int tempY;
		scanf("%d %d", &tempX, &tempY);
		coordinates.push_back(make_pair(tempX, tempY));
	}

	sort(coordinates.begin(), coordinates.end(), comp);

	vector<pair<int, int>>::iterator iter;
	for (iter = coordinates.begin(); iter != coordinates.end(); iter++) {
		printf("%d %d\n", (*iter).first, (*iter).second);
	}
}
