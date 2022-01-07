#include<iostream>
using namespace std;

int memo[41];

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (memo[n] != 0) return memo[n];

    int temp = fibonacci(n - 1) + fibonacci(n - 2);
    memo[n] = temp;
    return temp;
}

int main() {
	int t;
	cin >> t;
    memo[0] = 0;
    memo[1] = 1;
	for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        if (n == 0)
            cout << "1 0" << endl;
        else {
            fibonacci(n);
            cout << memo[n - 1] << " " << memo[n] << endl;
        }
	}
}