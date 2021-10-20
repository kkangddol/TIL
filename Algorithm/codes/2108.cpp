#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
vector<int> arr;
typedef pair<int, int> p;
int sum = 0;
int number[8001] = { 0, };

int mean() {
	int temp = round((float)sum / n);
	return temp;
}

int median() {
	sort(arr.begin(), arr.end());
	return arr[arr.size()/2];
}

int mode() {
	bool isfirst = true;
	int MAXCOUNT = -99999;
	int ans;

	for (int i = 0; i < 8001; i++) {
		if (number[i] == 0)
			continue;
		if (number[i] == MAXCOUNT && isfirst) {
			ans = i - 4000;
			isfirst = false;
		}
		if (number[i] > MAXCOUNT) {
			ans = i - 4000;
			MAXCOUNT = number[i];
			isfirst = true;
		}	
	}

	return ans;
}

int range() {
	sort(arr.begin(), arr.end());

	return arr.back() - arr.front();
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
		sum += temp;
		number[temp + 4000]++;
	}

	cout << mean() << endl;
	cout << median() << endl;
	cout << mode() << endl;
	cout << range() << endl;
}
