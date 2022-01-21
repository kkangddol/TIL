# 중요문제!!!!!!!!!!!!!
# RGB거리
## 유형 : 동적계획법 (DP)
* [1149](https://www.acmicpc.net/problem/1149) [:page_facing_up:](https://github.com/knemo333/TIL/blob/master/Algorithm/codes/1149.cpp)


### 문제
 **규칙에 따라 집을 칠하는 비용의 최솟값을 계산하여 출력하라.**

 #### 접근방법1
> 힌트가 부분문제 정의라고 했으니...   
> 이웃한것만 다른게 나오게끔 재귀를 돌린다면? -> DFS

##### 코드1
> 46% 도전할 때 시간초과.   
> 문제점 : 쓸데없이 보는것들이 많다. 입력받고 정렬해서 최대한 작은거 부터 볼 수 있도록 시도.   


```cpp
#include <iostream>
using namespace std;

int n;
int colorArr[1000][3];
int minVal = 2000000;

void DP(int sum, int index, int preRGB) {
	if (sum > minVal)
		return;
	if (index == n) {
		if (sum < minVal) minVal = sum;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (i == preRGB) continue;
		DP(sum + colorArr[index][i], index + 1, i);
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> colorArr[i][0] >> colorArr[i][1] >> colorArr[i][2];

	DP(0, 0, -1);

	cout << minVal;
}
```

##### 코드2
> 46% 도전할 때 시간초과.   
> 정렬해도 여전히 시간초과 나옴. 결국 DFS의 한계이므로 다시 생각해야한다.

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

struct colorCost {
	string color;
	int cost;
}colorArr[1000][3];

bool colorCostComp (colorCost a, colorCost b) {
	return a.cost < b.cost;
}

int n;
int minVal = 2000000;

void DP(int sum, int index, string preRGB) {
	if (sum > minVal)
		return;
	if (index == n) {
		if (sum < minVal) minVal = sum;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (colorArr[index][i].color == preRGB) continue;
		DP(sum + colorArr[index][i].cost, index + 1, colorArr[index][i].color);
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int red, green, blue;
		cin >> red >> green >> blue;
		colorArr[i][0] = {"red" , red};
		colorArr[i][1] = { "green" , green };
		colorArr[i][2] = { "blue" , blue };
		sort(colorArr[i], colorArr[i]+3, colorCostComp);
		//cout << colorArr[i][0].color << ":" << colorArr[i][0].cost << " " << colorArr[i][1].color << ":" << colorArr[i][1].cost << " " << colorArr[i][2].color << ":" << colorArr[i][2].cost << endl;
	}

	DP(0, 0, "");

	cout << minVal;
}
```

#### 접근방법2
> DFS 말고 return 값을 활용하자. 한 단계의 DP는 해당 단계에서의 최솟값을 리턴해준다.

##### 코드3
> 통과

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int memo[1000][3];
int colorArr[1000][3];
int n;
int ans = 2000000;

int DP(int index, int color) {
	int localMin = 2000000;
	if (index == n - 1)
		return colorArr[index][color];

	if (memo[index][color] != 0)
		return memo[index][color];

	for (int i = 0; i < 3; i++) {
		if (i == color) continue;

		int temp = DP(index + 1, i) + colorArr[index][color];

		if (temp < localMin) localMin = temp;
	}
	memo[index][color] = localMin;
	return localMin;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> colorArr[i][0] >> colorArr[i][1] >> colorArr[i][2];
	
	cout << min(min(DP(0, 0), DP(0, 1)), DP(0, 2));
	
}
```

### 결론
아직 부분문제를 정의하는게 어렵다 더 많은 문제를 풀면서 어떤식으로 부분문제를 다뤄야하는지 익히자.