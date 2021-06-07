# [Algorithm]

## [2020-10-25 issue]
  > _수업노트 찾아서 다시 다 한번씩 공부하고 머릿속에 집어넣기_   
  > 바보

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

## [2021-01-31 issue]
  > 재귀에 

## C++ 빠른 입출력
아래 얘기는 cin, cout을 쓸 때의 얘기지, scanf/prinf로 입출력을 하고자 하신다면 그냥 쓰시면 됩니다. scanf/printf는 충분히 빠릅니다.   
endl은 개행문자를 출력할 뿐만 아니라 출력 버퍼를 비우는 역할까지 합니다. 그래서 출력한 뒤 화면에 바로 보이게 할 수 있는데, 그 버퍼를 비우는 작업이 매우 느립니다. 게다가 온라인 저지에서는 화면에 바로 보여지는 것은 중요하지 않고 무엇이 출력되는가가 중요하기 때문에 버퍼를 그렇게 자주 비울 필요가 없습니다. 그래서 endl을 '\n'으로 바꾸는 것만으로도 굉장한 시간 향상이 나타납니다.   
cin.tie(NULL)은 cin과 cout의 묶음을 풀어 줍니다. 기본적으로 cin으로 읽을 때 먼저 출력 버퍼를 비우는데, 마찬가지로 온라인 저지에서는 화면에 바로 보여지는 것이 중요하지 않습니다. 입력과 출력을 여러 번 번갈아서 반복해야 하는 경우 필수적입니다.   
ios_base::sync_with_stdio(false)는 C와 C++의 버퍼를 분리합니다. 이것을 사용하면 cin/cout이 더 이상 stdin/stdout과 맞춰 줄 필요가 없으므로 속도가 빨라집니다. 단, 버퍼가 분리되었으므로 cin과 scanf, gets, getchar 등을 같이 사용하면 안 되고, cout과 printf, puts, putchar 등을 같이 사용하면 안 됩니다.   
[[출처]](https://www.acmicpc.net/board/view/22716)

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
