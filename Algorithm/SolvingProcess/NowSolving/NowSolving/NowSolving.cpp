#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	int cnt = 0;
	int beginPivot = 0, endPivot = 0;
	cin >> n;

	vector<pair<int, int>> meetings; //first == beginTime, second == endTime;
	for (int i = 0; i < n; i++) {
		int beginTemp, endTemp;
		cin >> beginTemp >> endTemp;
		meetings.push_back(make_pair(beginTemp, endTemp));
	}

	bool isFinished = false;
	while (!isFinished) {
		vector<pair<int, int>>::iterator iter;

		isFinished = true;
		for (iter = meetings.begin(); iter != meetings.end(); iter++) {
			if ((*iter).second == endPivot && (*iter).first >= beginPivot) {
				cnt++;
				beginPivot = endPivot;
			}
			if ((*iter).second > endPivot)
				isFinished = false;
		}
		endPivot++;
	}


	cout << cnt;

}