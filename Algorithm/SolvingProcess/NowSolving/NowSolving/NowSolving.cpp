#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int arr[100000] = { 0, };
	vector<int> memo;
	
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		if (memo.size() == 0) {
			memo.push_back(arr[i]);
			continue;
		}
		if (memo[i - 1] > 0)
			memo.push_back(memo[i - 1] + arr[i]);
		else {
			memo.push_back(arr[i]);
		}
	}
	cout << *max_element(memo.begin(), memo.end());
}