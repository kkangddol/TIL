# [Algorithm]

## [2020-10-25 issue]
  > _수업노트 찾아서 다시 다 한번씩 공부하고 머릿속에 집어넣기_   

* 레드블랙트리
* AVL 트리
* 아모타이즈드 애널리시스
* B트리?
* 프림 알고리즘
* 크루스칼 알고리즘
* 다익스트라 알고리즘
* 포드풀커슨 - 네트워크플로우 - 최대이분매칭?

프로그래머스 입문테스트 했는데 쉬운데도 제대로 못하는거같아서 스트레스
알고리즘 풀 때 C++, Kotlin 둘다 도전할 수 있도록 할것


# 알고리즘
## 플로이드 와샬(Floyd Warshall)
[[출처]](https://blog.naver.com/ndb796/221234427842)

## 투포인터 부분합

## 크루스칼, 유니온파인드



------------
# C++
## C++ 빠른 입출력
아래 얘기는 cin, cout을 쓸 때의 얘기지, scanf/prinf로 입출력을 하고자 하신다면 그냥 쓰시면 됩니다. scanf/printf는 충분히 빠릅니다.   

endl은 개행문자를 출력할 뿐만 아니라 출력 버퍼를 비우는 역할까지 합니다. 그래서 출력한 뒤 화면에 바로 보이게 할 수 있는데, 그 버퍼를 비우는 작업이 매우 느립니다. 게다가 온라인 저지에서는 화면에 바로 보여지는 것은 중요하지 않고 무엇이 출력되는가가 중요하기 때문에 버퍼를 그렇게 자주 비울 필요가 없습니다. 그래서 endl을 '\n'으로 바꾸는 것만으로도 굉장한 시간 향상이 나타납니다.   

cin.tie(NULL)은 cin과 cout의 묶음을 풀어 줍니다. 기본적으로 cin으로 읽을 때 먼저 출력 버퍼를 비우는데, 마찬가지로 온라인 저지에서는 화면에 바로 보여지는 것이 중요하지 않습니다. 입력과 출력을 여러 번 번갈아서 반복해야 하는 경우 필수적입니다.   

ios_base::sync_with_stdio(false)는 C와 C++의 버퍼를 분리합니다. 이것을 사용하면 cin/cout이 더 이상 stdin/stdout과 맞춰 줄 필요가 없으므로 속도가 빨라집니다. 단, 버퍼가 분리되었으므로 cin과 scanf, gets, getchar 등을 같이 사용하면 안 되고, cout과 printf, puts, putchar 등을 같이 사용하면 안 됩니다.   

[[출처]](https://www.acmicpc.net/board/view/22716)

## 소수점 자릿수 조절
```cpp
const double dNum = 1234.56789;

// 1
cout << dNum << endl;
 
// 2
cout.precision(5);
cout << dNum << endl;
 
// 3
cout << fixed;
cout.precision(6);
cout << dNum << endl;
 
// 4
cout.unsetf(ios::fixed);
cout << dNum << endl;
 
// 5
cout.setf(ios::fixed);
cout.precision(5);
cout << dNum << endl;
```
1. 아무런 설정 없이 출력했을 때, 전체 자릿수가 6으로 고정되는 것을 알 수 있다.   
C++ 역시 출력할 때 자동으로 반올림되는 것을 알 수 있다.   

2. 자릿수를 조정하는 함수이다.   
precision(5) = 전체 자릿수를 5로 조절했기 때문에 1234.6이 출력된 것을 알 수 있다.   

3. "cout << fixed"라는 표현은 소숫점 아래 값을 고정하는 표현이다.   
즉, cout << fixed 이후에 precision(6)을 입력하면 소숫점 아래를 6으로 고정한다.   

4. / 5.   
"cout << fixed"라는 표현은 cout.setf(ios::fixed); 로 사용할 수도 있다.   
setf와 반대되는 표현이 unsetf이다. (설정 해제)   
3번에서 소수점 아래 자릿수를 6으로 고정했고   
4번에서 이 설정을 해제하고   
5번에서 소수점 아래 자릿수를 5로 고정했다.   

[[출처]](https://semaph.tistory.com/7)

## cin의 반환형
https://stackoverflow.com/questions/38978266/how-can-stdcin-return-a-bool-and-itself-at-the-same-time -> cin은 cin 객체를 반환하며, iostream 헤더파일 내에 이를 bool 또는 다른 타입으로 바꾸어 줄 수 있는 conversion operator가 정의되어 있다고 함.

```cpp
if (std::cin >> value);
```
: cin이 if나 while 안에 들어가면 예외적으로 operator에 의해 자동으로 bool로 바뀜.

```cpp
bool b = std::cin >> value;
```
: 하지만 일반적인 경우에는 형변환을 명시하지 않을 경우 operator가 실행되지 않음.

```cpp
bool b = static_cast<bool>(std::cin >> value);
```
: 이때 위와 같이 변환을 명시해주면 잘 작동함

https://stackoverflow.com/questions/36626896/how-does-cin-evaluate-to-true-when-inside-an-if-statement -> cin >> (variable) 연산 자체가 cin을 반환하므로, cin >> X >> Y >> Z 는 ((cin >> X) >> Y) >> Z 와 같으며 따라서 cin>>X, cin>>Y, cin>>Z 를 순차적으로 실행하는 것과 같음을 설명.   
cin이 if나 while 안에 들어가면 operator에 의해 bool로 바뀜.

https://stackoverflow.com/questions/46073849/error-when-assigning-the-return-of-cin-somevar-to-an-istream-variable-in-c -> cin은 input stream에 대응하는 객체이다.

```cpp
istream b = cin >> a;
```
: cin이 istream 클래스의 객체임을 감안해 이런 식으로 양변의 형이 같게 코드를 짜더라도 제대로 작동하지 않는데, 이는 '=' 연산자가 우변의 객체를 좌변의 변수에 복사할 것을 요구하고 있지만 stream 클래스가 이러한 복사 기능을 지원하지 않기 때문.

```cpp
bool b(cin >> a);
```
: 이렇게 하면 가장 간결하게 cin의 return을 boolean으로 변환한 값을 b에 저장할 수 있다. 이때 b는 cin>>a 연산의 성공 여부에 대한 True/False를 담게 된다.


https://stackoverflow.com/questions/6791520/if-cin-x-why-can-you-use-that-condition
```cpp
if (cin >> x){}
```
```cpp
cin >> x;   
if (cin){}
```
: 첫번째 코드는 조건문에 반환된 cin객체가 들어가고 두번째 코드는 cin객체를 직접 넣는 것으로 두 코드가 서로 같은 의미임   

[[출처]](https://skku.goorm.io/qna/4241)


## \<algorithm\> 헤더파일
```cpp
template <typename T>
void sort(T start, T end);
```
```cpp
template <typename T>
void sort(T start, T end, Compare comp);
```
sort 알고리즘은 \<algorithm\> 헤더파일에 속해있습니다.   
  
sort(start, end)를 이용하여 (start, end) 의 범위에 있는 인자(element)를 오름차순(default)으로 정렬해주는 함수 입니다.   
start를 포함하고 end를 포함하지 않는 구간. (iterator를 생각하면됩니다.)   

quick sort(퀵 정렬)을 기반으로 함수가 구현되어있어, 평균 시간복잡도는 n log n 입니다.   
따로 quick sort를 구현할 필요 없이 C++ STL에서 제공해주는 sort 함수를 이용하면 편리하게 정렬 할 수 있습니다.   
  
3번째 인자를 넣지 않으면 default로 오름차순으로 정렬이 됩니다.   
3번째 인자에 사용자가 정의한 함수를 기준으로 정렬을 할 수 있습니다. (이항조건자를 이용할 수도 있습니다.)   
  
* `sort(arr, arr+n);`
* `sort(v.begin(), v.end());`
* `sort(v.begin(), v.end(), compare);`\t//사용자 정의 함수 사용
* `sort(v.begin(), v.end(), greater<자료형>());`\t//내림차순 (Descending order)
* `sort(v.begin(), v.end(), less<자료형>());`\t//오름차순 (default = Ascending order)


[[출처]](https://blockdmask.tistory.com/178)

## 문자열
### 문자 비교 compare, strcmp, == 차이점

[[출처]](https://choryeonworkshop.tistory.com/119)

### \<string\> 메소드들 (find, replace 등)
* [2941](https://www.acmicpc.net/problem/2941) &nbsp; [크로아티아 알파벳] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Algorithm/codes/2941.cpp)


만약에 문자열을 찾는데 성공하였다면, 해당 문자열의 시작 위치 를 반환하고, 찾지 못한다면 npos 를 리턴한다.   
npos 는 string::npos 로 정의되는 상수 이다.   

[[find 출처]](https://modoocode.com/241)   
[[replace 출처]](https://modoocode.com/250)   

### string swap(str1,str2)


  
## 입력방법
### cin
=> \<iostream\> 에 존재   
=> 표준 입력 버퍼에서 개행 문자를 제외한 값을 가져옴   
=> 공백, 개행 무시   
=> 개행 키보드 버퍼에 남겨둠   
### cin.get()
=> \<iostream\> 에 존재   
=> 표준 입력 버퍼에서 문자를 하나만 가져옴   
=> 공백, 개행 포함   
=> 문자만 입력 받음   
### cin.getline()
=> \<iostream\> 에 존재   
=> 종결 문자를 NULL로 바꿈, 종결 문자 생략시 엔터로 간주   
=> 최대 입력 가능 문자수보다 많은 문자를 입려간 경우 n-1개 만큼 받아들이고 n번째 문자는 NULL로 바꾼다.   
=> 공백, 개행 입력 받음   
=> 문자열만 입력받음   
=> cin.getline() 과 getline()는 다른 함수이다.   
### getline()
  
[[출처]](https://luyin.tistory.com/334)

## 배열 초기화
```cpp
int arr[100] = {0,};
```
: 전부 0으로 초기화

```cpp
for(int i=0 ; i<100 ; i++)
  arr[i] = n;
```
: 0이 아닌 n으로 초기화

```cpp
fill_n(arr, 100, -1);
```
: 크기가 100인 배열 arr를 -1로 초기화

```cpp
int arr[100] = {1, };
```
: arr[0]만 1로 초기화 나머지는 0으로 초기화

## char to int
숫자 CHAR('0'~'9')는 ASCII 코드 48부터 시작하므로, 48을 빼주면 얻을 수 있음.
```cpp
char c = '5';
int n = 0;
n = c - 48;
```
하지만, 아래와 같이 하는 편이 더욱 직관적.

```cpp
char c = '5';
int n = 0;
n = c - '0';
```

## string 메소드 잘 활용하기

## transform 함수
\<algorithm\>에 정의되어있음.
```cpp
template <class InputIt, class OutputIt, class UnaryOperation>
OutputIt transform(InputIt first1, InputIt last1, OutputIt d_first,
                   UnaryOperation unary_op);  // (1)
                   
template <class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
OutputIt transform(InputIt1 first1, InputIt1 last1, InputIt2 first2,
                   OutputIt d_first, BinaryOperation binary_op);  // (2)
                   
template <class ExecutionPolicy, class ForwardIt1, class ForwardIt2,
          class ForwardIt3, class BinaryOperation>
ForwardIt3 transform(ExecutionPolicy&& policy, ForwardIt1 first1,
                     ForwardIt1 last1, ForwardIt2 first2, ForwardIt3 d_first,
                     BinaryOperation binary_op);  // (3)
```

```cpp
transform(c.begin(), c.end(), c.begin(), (int(*)(int))toupper);
```

[[출처]](https://modoocode.com/275)

## 포인터와 레퍼런스 변수의 차이
### pass by reference
* [2447](https://www.acmicpc.net/problem/2447) &nbsp; [별찍기 - 10] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Algorithm/codes/2447.cpp)

[[출처]](https://blog.naver.com/dkdlfjq31/222307500815)


## 정렬
### Counting Sort
Counting Sort 알고리즘의 시간복잡도는 O(n) 으로 Quick Sort보다 훨씬 유리해보입니다. 그러나 세상에 공짜는 없다는 말처럼 Counting Sort는 대부분의 상황에서 엄청난 메모리 낭비를 야기할 수 있습니다.

누적합 배열에 대한 접근을 O(1)에 달성하기 위해 정렬할 배열에 포함된 숫자의 최댓값 만큼의 메모리를 필요로 합니다. 아까 추가로 예시든  배열에 Counting Sort 알고리즘으로 정렬하기 위해서는 누적합 배열의 길이를 100으로 잡는 낭비를 해야합니다. 만약 배열에 최댓값으로 10억이 포함되어 있다면 엄청난 낭비가 되겠죠.

따라서 Counting Sort는 위에서든 예시처럼

정렬하는 숫자가 특정한 범위(위 예시 : 0~5) 안에 있을 때 사용하게 됩니다.
Counting Sort를 대표적으로 활용하는 사례는 26개의 알파벳으로 이루어진 문자열에서 Suffix Array를 얻는 경우인데 이때 Counting Sort를 사용하기 때문에 일반적인 Sort를 사용해서 Suffix Array를 얻때 시간복잡도 보다 빠른 에 Suffix Array를 얻는 것이 가능합니다.



출처: https://bowbowbow.tistory.com/8 [멍멍멍]
