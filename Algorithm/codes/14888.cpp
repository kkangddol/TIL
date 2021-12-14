#include <iostream>
#include <limits>
using namespace std;

int n, addition, subtraction, multiplication, division;
int arr[11];
int maxVal = -1000000000;
int minVal = 1000000000;

bool isCool(int result) {
	bool maxFlag = false;
	bool minFlag = false;

	if (result > 0) {
		if (addition == 0 && subtraction == 0 && multiplication == 0 && division == 0) return true;
		if (result < maxVal && addition == 0 && multiplication == 0) maxFlag = true;
		if (result > minVal && subtraction == 0 && division == 0) minFlag = true;
	}
	else if (result < 0) {
		if (addition == 0 && subtraction == 0 && multiplication == 0 && division == 0) return true;
		if (result < maxVal && addition == 0 && division == 0) maxFlag = true;
		if (result > minVal && subtraction == 0 && multiplication == 0) minFlag = true;
	}
	if (maxFlag && minFlag) return false;
	return true;
}

void backTracking(int result, int index) {
	int temp = result;

	if (index == n) {
		if (result > maxVal) maxVal = result;
		if (result < minVal) minVal = result;
		return;
	}

	if (addition > 0) {
		addition--;
		if (index == 1)
			temp = arr[0] + arr[1];
		else
			temp = result + arr[index];
		if (isCool(temp))
			backTracking(temp, index + 1);
		addition++;
		temp = result;
	}

	if (subtraction > 0) {
		subtraction--;
		if (index == 1)
			temp = arr[0] - arr[1];
		else
			temp = result - arr[index];
		if (isCool(temp))
			backTracking(temp, index + 1);
		subtraction++;
		temp = result;
	}

	if (multiplication > 0) {
		multiplication--;
		if (index == 1)
			temp = arr[0] * arr[1];
		else
			temp = result * arr[index];
		if (isCool(temp))
			backTracking(temp, index + 1);
		multiplication++;
		temp = result;
	}

	if (division > 0) {
		division--;
		if (index == 1)
			temp = arr[0] / arr[1];
		else
			temp = result / arr[index];
		if (isCool(temp))
			backTracking(temp, index + 1);
		division++;
		temp = result;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		arr[i] = temp;
	}
	cin >> addition >> subtraction >> multiplication >> division;

	backTracking(NULL, 1);

	cout << maxVal << endl << minVal;
}
