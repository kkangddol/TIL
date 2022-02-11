# 검색했음

# LCS
## 유형 : 
* [9251](https://www.acmicpc.net/problem/9251) [:page_facing_up:](https://github.com/knemo333/TIL/blob/master/Algorithm/codes/9251.cpp)


### 문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.   
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

#### 접근방법1
> A,B 수열이라 할 때 B 수열에 A수열의 순서를 적어주고 순서(숫자)로 LIS 돌리면 될 줄 알았는데, 중복하는 것 때문에 안된다.   
> 표를 활용하면 쉽대   
> 진짜 나는 바보인가봐

##### 코드
```cpp
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int arr[1001][1001] = { 0, };

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str2[j] == str1[i]) {
				arr[i + 1][j + 1] = arr[i][j] + 1;
			}
			else {
				arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
			}
		}
	}

	cout << arr[str1.size()][str2.size()];
}
```

### 결론
이런것도 혼자서 못풀고 짜증난다 진짜 개빡친다