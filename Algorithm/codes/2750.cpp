#include <iostream>
#include <limits.h>

using namespace std;

int* selectionSort(int *arr, int size) {
	int* answer = arr;

	for (int i = 0; i < size; i++) {
		int min = INT_MAX;
		int location;
		for (int j = i; j < size; j++) {
			if (answer[j] < min) {
				min = answer[j];
				location = j;
			}
		}
		swap(answer[i], answer[location]);
	}

	return answer;
}

int* bubbleSort(int* arr, int size) {
	int* answer = arr;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size-1; j++) {
			if (answer[j] > answer[j + 1])
				swap(answer[j], answer[j + 1]);
		}
	}

	return answer;
}

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];

	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		arr[i] = input;
	}
	int* answer;
	answer = selectionSort(arr,n);
	answer = bubbleSort(arr, n);

	for (int i = 0; i < n; i++) {
		cout << answer[i] << endl;
	}
}
