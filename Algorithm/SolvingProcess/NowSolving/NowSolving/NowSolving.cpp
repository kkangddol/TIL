#include <iostream>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int a, b;
		vector<int> primes;

		cin >> a >> b;

		int prime = 2;
		while (1) {
			if (prime > a || prime > b)
				break;

			if (a % prime == 0 && b % prime == 0) {
				a /= prime;
				b /= prime;
				primes.push_back(prime);
				prime = 2;
			}
			else
				prime++;
		}
		int LCM = a * b;

		vector<int>::iterator iter;
		for (iter = primes.begin(); iter != primes.end(); iter++)
			LCM *= (*iter);

		cout << LCM << endl;
	}
}