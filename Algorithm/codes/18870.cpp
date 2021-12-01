#include <iostream>
#include <limits>
using namespace std;

struct lowerBound {
	long long value;
	int order = 0;
	lowerBound* lastPointer = this;
} arr[1000000];

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		arr[i].value = temp;
		if (i == 0) arr[i].order = 0;

		long long maxValue = LLONG_MIN;
		long long minValue = LLONG_MAX;

		int tempIndex = -1;

		for (int j = 0; j < i; j++) {
			if (arr[j].value == temp) {
				arr[i] = arr[j];
				continue;
			}
			else if (arr[j].value < temp) {
				if (arr[j].value > maxValue) {
					maxValue = arr[j].value;
					arr[i].lastPointer = &arr[j];
				}
			}
			else {
				if (arr[j].value < minValue) {
					minValue = arr[j].value;
					tempIndex = j;
				}
			}
		}
		if (tempIndex != -1) {
			arr[tempIndex].lastPointer = &arr[i];
		}
		
	}

	for (int i = 0; i < n; i++) {
		arr[i].order = arr[i].lastPointer->order + 1;
		cout << arr[i].order << ' ';
	}
}
