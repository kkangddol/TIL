#include <iostream>
#include <vector>
using namespace std;

int main() {
	string inputStr;

	cin >> inputStr;

	int plusNumber = 0;
	int minusNumber = 0;
	bool isMinus = false;

	int temp = 0;
	for (int i = 0; i < inputStr.length(); i++) {
		if (isMinus) {
			if (inputStr[i] >= '0' && inputStr[i] <= '9') {
				temp = temp * 10 + (inputStr[i] - '0');
			}
			else if (inputStr[i] == '+' || inputStr[i] == '-') {
				minusNumber += temp;
				temp = 0;
			}
		}
		else {
			if (inputStr[i] >= '0' && inputStr[i] <= '9') {
				temp = temp * 10 + (inputStr[i] - '0');
			}
			else if (inputStr[i] == '+') {
				plusNumber += temp;
				temp = 0;
			}
			else if (inputStr[i] == '-') {
				plusNumber += temp;
				temp = 0;
				isMinus = true;
			}
		}
	}
	if (isMinus)
		minusNumber += temp;
	else
		plusNumber += temp;

	cout << plusNumber - minusNumber;
}