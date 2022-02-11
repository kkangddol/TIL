#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int arr[1001][1001] = { 0, };

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str2[j] == str1[i]) {
				arr[i + 1][j + 1] = arr[i][j] + 1;
			}
			else {
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
			}
		}
	}

	cout << arr[str1.size()][str2.size()];
}