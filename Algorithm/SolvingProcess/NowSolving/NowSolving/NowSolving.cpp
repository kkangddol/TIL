#include <iostream>
#include <vector>
using namespace std;

int main() {
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
	int GCD = 1;
	int LCM = 1;

	vector<int>::iterator iter;
	for (iter = primes.begin(); iter != primes.end(); iter++)
		GCD *= (*iter);

	LCM = GCD * a * b;

	cout << GCD << endl << LCM;
}