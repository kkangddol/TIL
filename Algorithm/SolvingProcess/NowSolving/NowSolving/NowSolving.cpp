#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}

int main() {
	int n;
	int cnt = 0;
	int pivot = 0;
	cin >> n;

	vector<pair<int, int>> meetings; //first == beginTime, second == endTime;
	for (int i = 0; i < n; i++) {
		int beginTemp, endTemp;
		cin >> beginTemp >> endTemp;
		meetings.push_back(make_pair(beginTemp, endTemp));
	}

	sort(meetings.begin(), meetings.end(), compare);

	vector<pair<int, int>>::iterator iter;
	for (iter = meetings.begin(); iter != meetings.end(); iter++) {
		if ((*iter).first >= pivot) {
			cnt++;
			pivot = (*iter).second;
		}
	}

	cout << cnt;
}	