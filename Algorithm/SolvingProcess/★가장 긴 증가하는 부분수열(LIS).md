# 가장 긴 증가하는 부분수열(LIS)
## 유형 : 동적계획법 (DP)
* [11053](https://www.acmicpc.net/problem/11053) [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Algorithm/codes/11053.cpp)


### 문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

#### 접근방법1
> 현재index, 피봇index 잡고 쭉 메모이제이션 하면서 하는방법.   
> 마지막 수 처리할 때가 뭔가 이상함.   
> 구조를 다시 손봐야할듯.

##### 코드
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1000];
int memo[1000];

int DP(int currentIndex, int pivotIndex) {
	if(memo[currentIndex] != 0)

	if (arr[currentIndex] > arr[pivotIndex]) {
		memo[pivotIndex] = DP(currentIndex, currentIndex) + 1;
		return memo[pivotIndex];
	}
	else
		DP(currentIndex + 1, pivotIndex);
}

void solution() {
	for (int i = 0; i < n; i++)
		DP(i, i);
	cout << *max_element(memo, memo + n);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	solution();
}
```