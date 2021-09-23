#include <iostream>

using namespace std;

int* merge(int* leftArr, int* rightArr, int leftIndex, int middleIndex, int rightIndex) {
	int* mergedArr = new int[rightIndex - leftIndex + 1];
	int index = 0;

	int leftCursor = 0;
	int rightCursor = 0;

	int leftSize = middleIndex - leftIndex + 1;
	int rightSize = rightIndex - middleIndex;

	while (leftCursor <= leftSize && rightCursor <= rightSize) {
		if (leftArr[leftCursor] < rightArr[rightCursor]) {
			mergedArr[index++] = leftArr[leftCursor++];
		}
		else {
			mergedArr[index++] = rightArr[rightCursor++];
		}
	}

	while (leftCursor <= leftSize) {
		mergedArr[index++] = leftArr[leftCursor++];
	}
	while (rightCursor <= rightSize) {
		mergedArr[index++] = rightArr[rightCursor++];
	}

	return mergedArr;
}

int* mergeSort(int* arr, int leftIndex, int rightIndex) {
	if (leftIndex == rightIndex)
		return &arr[leftIndex];

	int left = leftIndex;
	int middle = (rightIndex + leftIndex) / 2;
	int right = rightIndex;

	int* leftArr = mergeSort(arr, left, middle);
	int* rightArr = mergeSort(arr, middle + 1, right);

	int* answer = merge(leftArr, rightArr, left, middle, right);

	return answer;
}

int main() {
	int n;
	cin >> n;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}

	int* answer = mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << answer[i] << endl;
	}


	return 0;
}
