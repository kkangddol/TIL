# N-Queen
## 백트래킹
* [9663](https://www.acmicpc.net/problem/9663) [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Algorithm/codes/9663.cpp)

### 문제 : N x N 체스판에 N개의 퀸을 서로 공격하지 않게 배치하는 경우의 수를 출력.

#### 접근방법 1 : 15 x 15 체스판 배열 미리 만들고 그리디한 방식으로 접근.

##### 문제발생 1 : 중복된 답을 경우의 수에 추가함
##### 문제 1 해결방법 : 정답배열을 따로 만들어 이미 같은 답일 시 SKIP.

##### 문제발생 2 : 2차원배열을 사용하므로 N이 7만 넘어가도 답을 내놓는데 시간이 너무 오래 걸림.
