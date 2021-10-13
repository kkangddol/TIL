#include <iostream>

using namespace std;
int counting[10001] = { 0 };

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d",&temp);
		counting[temp]++;
	}
	for (int i = 1; i <= 10000; i++) {
		while (counting[i]-- > 0) {
			printf("%d\n",i);
		}
	}
}
