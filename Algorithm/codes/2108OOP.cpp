#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
	vector<int> mInputArr;
	int mCountingArr[8001] = {0,};
	int mMean;
	int mMedian;
	int mMode;
	int mRange;

public:
	Solution(vector<int> inputArr) {
		this->mInputArr = inputArr;
		mMean = CalculateMean();
		mMedian = CalMedian();
		mMode = CalMode();
		mRange = CalRange();
	}

	int CalculateMean() {
		int sum = 0;
		vector<int>::iterator iter;
		for (iter = mInputArr.begin(); iter != mInputArr.end(); iter++) {
			sum += *iter;
		}
		return round((float)sum / mInputArr.size());
	}

	int CalMedian() {
		sort(mInputArr.begin(), mInputArr.end());
		return mInputArr[mInputArr.size() / 2];
	}

	int CalMode() {
		int maxCount = -1;
		int mode;
		bool bIsFirst = true;
		vector<int>::iterator iter;
		for (iter = mInputArr.begin(); iter != mInputArr.end(); iter++) {
			mCountingArr[*iter + 4000]++;
		}
		
		for (int i = 0; i < 8001; i++) {
			if (mCountingArr[i] == 0)
				continue;

			if (mCountingArr[i] > maxCount) {
				maxCount = mCountingArr[i];
				mode = i - 4000;
				bIsFirst = true;
			}
			else if (mCountingArr[i] == maxCount && bIsFirst) {
				mode = i - 4000;
				bIsFirst = false;
			}
		}

		return mode;
	}

	int CalRange() {
		return mInputArr.back() - mInputArr.front();
	}

	int GetMean() {
		return mMean;
	}
	int GetMedian() {
		return mMedian;
	}
	int GetMode() {
		return mMode;
	}
	int GetRange() {
		return mRange;
	}

};

int main() {
	int n;
	vector<int> inputArr;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		inputArr.push_back(temp);
	}

	Solution s = Solution(inputArr);

	cout << s.GetMean() << endl;
	cout << s.GetMedian() << endl;
	cout << s.GetMode() << endl;
	cout << s.GetRange();
}
