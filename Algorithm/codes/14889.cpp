#include <iostream>
#include <math.h>
using namespace std;

int n;
int stats[20][20];
bool team[20];
int minVal = 1000000000;

void backTracking(int cnt, int index) {
	if (cnt == n / 2) {
		int teamAStats = 0, teamBStats = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				if (team[i] == true && team[j] == true)
					teamAStats += stats[i][j];
				else if (team[i] == false && team[j] == false)
					teamBStats += stats[i][j];
			}
		int temp = abs(teamAStats - teamBStats);
		if (temp < minVal) minVal = temp;
		return;
	}
	for (int i = index; i < n; i++) {
		team[i] = true;
		backTracking(cnt + 1, i + 1); ////////////////////////////////// 여기 ㅡㅡ
		team[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> stats[i][j];
	team[0] = true;
	backTracking(1, 1);
	cout << minVal;
}