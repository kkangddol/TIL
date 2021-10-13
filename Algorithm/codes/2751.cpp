#include<iostream>

using namespace std;



int arr[1000001];
int ans[1000001];

void merge(int left, int right) {
	int mid = (left + right) / 2;
	int index = left;
	int L_index = left;
	int R_index = mid + 1;
	while (L_index <= mid && R_index <= right) {
		int temp;
		if (ans[L_index] < ans[R_index])
			temp = ans[L_index++];
		else
			temp = ans[R_index++];

		arr[index++] = temp;
	}
	while (L_index <= mid) {
		arr[index++] = ans[L_index++];
	}
	while (R_index <= right) {
		arr[index++] = ans[R_index++];
	}
	for (int i = left; i <= right; i++)
		ans[i] = arr[i];
}

void mergesort(int left, int right) {
	if (left == right) {
		ans[left] = arr[left];
		return;
	}
	mergesort(left, (left + right) / 2);
	mergesort((left + right) / 2 + 1, right);
	merge(left, right);
}

int main() {

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr[i] = temp;
	}
	mergesort(0, n - 1);

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

}
