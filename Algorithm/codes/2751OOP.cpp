#include <iostream>
#include <vector>

using namespace std;

class mergesort {
private:
	int n;
	vector<int> arr;
	vector<int> ans;

public:
	mergesort(int n, vector<int> arr) {
		this->n = n;
		this->arr = arr;
		ans = devide(0,n-1);
	}

	vector<int> devide(int left, int right) {
		if (left == right) {
			vector<int> temp;
			temp.push_back(arr[left]);
			return temp;
		}
		
		int mid = (left + right) / 2;

		return merge(devide(left, mid), devide(mid + 1, right));
	}

	vector<int> merge(vector<int> left, vector<int> right) {
		vector<int> tempv;
		vector<int>::iterator left_iter = left.begin();
		vector<int>::iterator right_iter = right.begin();
		while (left_iter != left.end() && right_iter != right.end()) {
			int temp;
			if (*left_iter < *right_iter) {
				temp = *left_iter;
				left_iter++;
			}
			else {
				temp = *right_iter;
				right_iter++;
			}
			tempv.push_back(temp);
		}
		while (left_iter != left.end()) {
			tempv.push_back(*left_iter);
			left_iter++;
		}
		while (right_iter != right.end()) {
			tempv.push_back(*right_iter);
			right_iter++;
		}

		return tempv;
	}

	void printAns() {
		for (int i = 0; i < n; i++)
			printf("%d\n", ans[i]);
	}
};

int main() {
	int n;
	vector<int> arr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		arr.push_back(temp);
	}
	mergesort ms = mergesort(n, arr);
	ms.printAns();
}
