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
> 단 한번이라도 지금 숫자가 피봇 숫자보다 큰 경우에는 memo가 정상적으로 작동한다   
> 하지만 피봇 숫자보다 큰 숫자가 단 하나라도 없을 경우에 1을 저장하고 리턴?   

##### 코드
```cpp
#include <iostream>

#include <algorithm>

using namespace std;

int n;

int arr[1000];

int memo[1000];

int DP(int currentIndex, int pivotIndex) {
	if (currentIndex > n - 1)
		return 0;

	if (memo[currentIndex] != 0)
		return memo[currentIndex];

	if (arr[currentIndex] > arr[pivotIndex])
		memo[pivotIndex] = DP(currentIndex, currentIndex) + 1;
	else if (DP(currentIndex + 1, pivotIndex) == 0)
		memo[pivotIndex] = 1;

	return memo[pivotIndex];
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

#### 접근방법2
> index 0 부터 진행하면서 큰수가 나오면 계속 카운트, 작거나 같은수가 나오면 재귀호출한 뒤 return값으로 카운트값을 비교.   
> 분기가 된 지점까지 카운트 했을때 작거나 같으면 버리고 크면 그 친구의 카운트를 가져감.

##### 코드
```cpp
```