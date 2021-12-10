# N-Queen
## 유형 : Back Tracking
* [9663](https://www.acmicpc.net/problem/9663) [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Algorithm/codes/9663.cpp)


### 문제
 **N x N 체스판에 N개의 퀸을 서로 공격하지 않게 배치하는 경우의 수를 출력.**
 
#### 접근방법 1
> 15 x 15 체스판 배열 미리 만들고 그리디한 방식으로 접근.

##### 문제발생 1
> 중복된 답을 경우의 수에 추가함.   
> **해결방법** -> 정답배열을 따로 만들어 이미 같은 답일 시 SKIP.

##### 문제발생 2
> 2차원배열을 사용하므로 N이 7만 넘어가도 답을 내놓는데 시간이 너무 오래 걸림.   
> **해결방법** -> 최적화 또는 2차원배열방법 폐기. -> 1차원 배열로 변경

##### 1차원 배열 코드 ver1
> 아직 정답은 틀림.   
> 퀸을 배치하기전에 먼저 각 행 별로 가능한 자리를 파악 -> 불필요한 탐색이라고 생각   
> 퀸을 우선 배치하고나서 아니라면 무르기로 변경?

```cpp
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int chessCol[15] = { 0, };

int n, ans = 0;

void recur(int order) {
	if (order > n) {
		ans++;
		return;
	}

	vector<int> skipCase;
	for (int i = 1; i <= n; i++)
		skipCase.push_back(i);
	
	for (int i = 1; i <= n; i++) {
		if (chessCol[i] != 0) {
			skipCase.erase(remove(skipCase.begin(), skipCase.end(), chessCol[i]), skipCase.end());
			for (int j = 1; j <= n; j++) {
				//i,chessColl[i] <> order,j
				if (abs(i - order) == abs(chessCol[i] - j))
					skipCase.erase(remove(skipCase.begin(), skipCase.end(), j), skipCase.end());
			}
		}	
	}

	vector<int>::iterator iter;
	for (iter = skipCase.begin(); iter != skipCase.end(); iter++) {
		chessCol[order] = *iter;
		recur(order + 1);
	}
}

int main() {
	cin >> n;
	recur(1);
	cout << ans;
}
```

##### 1차원 배열 코드 ver2
> 통과.   
> 현재 배치한 퀸의 조건이 맞는지 판별하는 isCool() 함수의 조건이 하나가 부족해서 전부 false를 반환하는 실수 수정.   

```
#include <iostream>
#include <math.h>
using namespace std;

int chessCol[15] = { 0, };

int n, ans = 0;

bool isCool(int col, int row) {
	for (int i = 1; i <= n; i++) {
		if (col == i) continue;
		if (chessCol[i] == 0) continue;
		if (chessCol[i] == row) return false;
		if (abs(i - col) == abs(chessCol[i] - row)) return false;
	}
	return true;
}

void recur(int order) {
	if (order > n) {
		ans++;
		return;
	}

	for (int row = 1; row <= n; row++) {
		chessCol[order] = row;
		if (isCool(order, row))
			recur(order + 1);
		chessCol[order] = 0;
	}

}

int main() {
	cin >> n;
	recur(1);
	cout << ans;
}
```


### 결론

* 아직까지는 백트래킹이라는 것이 확 와닿지 않음.
* 그냥 완전탐색 돌리는데 조건 안맞으면 걍 버려버리고 진행하는 DFS를 돌리는 느낌..?