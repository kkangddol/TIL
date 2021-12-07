#include <iostream>
using namespace std;

int arr[9] = { 0, };
int n, m;

void output() {
	int order = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == order) {
			printf("%d ",i);
			order++;
			i = 0;
			continue;
		}
	}
	printf("\n");
}

void marking(int order) {
	if (order > m) {
		output();
		return;
	}
	
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			arr[i] = order;
			marking(order + 1);
			arr[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;
	marking(1);
}
