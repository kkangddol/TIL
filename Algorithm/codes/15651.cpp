#include <iostream>
using namespace std;

int n, m;

int arr[9] = { 0, };

void output() {
	for (int i = 1; i <= m; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void dfs(int order) {
	if (order > m) {
		output();
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[order] = i;
		dfs(order + 1);
		arr[order] = 0;
	}

}

int main() {
	cin >> n >> m;
	dfs(1);
}
