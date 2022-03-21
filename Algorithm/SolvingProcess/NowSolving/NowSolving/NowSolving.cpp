#include <iostream>

using namespace std;

int main() {
	bool isEnd = false;
	while (!isEnd) {
		int num1 = 0, num2 = 0;
		cin >> num1 >> num2;

		if (num1 == 0 && num2 == 0) {
			isEnd = true;
			break;
		}

		if (num1 == 0 || num2 == 0)
			cout << "neither";
		else if (num2 % num1 == 0)
			cout << "factor";
		else if (num1 % num2 == 0)
			cout << "multiple";
		else
			cout << "neither";
	}
}