[백준 단계별 올라가면서 코틀린 연습](https://www.acmicpc.net/step, "baekjoon link")
===================================================================================

## 20-11-13   
> [입출력](https://www.acmicpc.net/step/1)   
> [if문](https://www.acmicpc.net/step/4)   

`with`를 이용해 scanner 객체 생성없이 더 코드를 축약할 수 있음.
```
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    ...
}
```

## 20-11-15
> [for문](https://www.acmicpc.net/step/3)    

* [15552](https://www.acmicpc.net/problem/15552) &nbsp; [빠른 A+B] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/15552.kt)   
    > `BufferedReader`와 `BufferedWriter`를 쓰기 (BufferedWriter 형식은 무조건 String!).   
    > java에서는 저 두개 말고도 `StringBuilder`로 출력을 모아 놓았다가 그 String을 `System.out.println`하는 방법도 있음.   
    > **`BufferedReader` 와 `BufferedWriter` 사용했으면 꼭 마지막에 `close()` 해줘야함**

## 20-11-17
> [while문](https://www.acmicpc.net/step/2)   
> [1차원 배열](https://www.acmicpc.net/step/6)   
> * [배열 생성법](https://brunch.co.kr/@mystoryg/27)   
> * [배열 생성법](https://brunch.co.kr/@mystoryg/47)   

* [10951](https://www.acmicpc.net/problem/10951) &nbsp; [A+B - 4] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/10951.kt)
    > 테스트 케이스의 개수가 주어지지 않았을 때에는 `Scanner`의 `hasNextInt()`와 같은 메소드를 활용해라.

* [10818](https://www.acmicpc.net/problem/10818) &nbsp; [최소,최대] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/10818.kt)
    > 최대 최소 구할때는 배열과 sort를 활용하라.

* [3052](https://www.acmicpc.net/problem/3052) &nbsp; [나머지] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/3052.kt)
    > 배열에서 겹치지 않는 값을 list로 반환해주는 `distinct()` 메소드

* [8958](https://www.acmicpc.net/problem/8958) &nbsp; [OX퀴즈] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/8958.kt)
    > 입력받을 때 `next()`와 `nextLine()` 잘 사용해야한다. 공백과 엔터차이 주의.

* [4344](https://www.acmicpc.net/problem/4344) &nbsp; [평균은 넘겠지] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/4344.kt)
    > 소수점 자리 출력할 때 `String.format()` 이용하기 `java.lang.String.format("%.3f", 값)`

배열의 평균은 `average()` 메소드   
배열복사할 때 `val arr = 복사할배열.copyOf()`   
`Math.메소드`들의 매개변수는 대부분 Double타입   
문제 꼼꼼히 읽어   

## 20-11-18
> [함수](https://www.acmicpc.net/step/5)

* [4673](https://www.acmicpc.net/problem/4673) &nbsp; [셀프 넘버] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/4673.kt)
    > **그냥 풀이가 마음에 안듦 다시 풀것**
    
## 20-11-27 ~ 20-12-02
> [문자열](https://www.acmicpc.net/step/7)

* [11720](https://www.acmicpc.net/problem/11720) &nbsp; [숫자의 합] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/11720.kt)
    > Char to Int : char.toString().toInt()   
    > Character.getNumericValue(str) || Character::getNumericValue는 무슨뜻이지?
    > [스택오버플로우질문글](https://stackoverflow.com/questions/47592167/how-do-i-convert-a-char-to-int)

* [1157](https://www.acmicpc.net/problem/11720) &nbsp; [단어 공부] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/1157.kt)
    > `Array.indexOfFirst` 사용할때 `Array.indexOfFirst{it > 3}` 이런식으로 사용할것. 람다식인가? 그 묵시함수? 뭐였지? 그런건가?   
    > 이거 풀때 `Array.count{it == Array.max()}` 의 개수가 2 이상이면 ? 출력하게 해도 되겠네
    

`java.util.StringTokenizer` 잊지말것   
**아스키코드 잊지말것**   
`String.reversed()` 는 문자열의 순서를 뒤집은 문자열을 반환   


## 20-12-28
> [수학1](https://www.acmicpc.net/step/8)

* [2869](https://www.acmicpc.net/problem/2869) &nbsp; [달팽이는 올라가고 싶다] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/2869.kt)
    > 막힘. for문을 줄일 수 있는 방법을 찾아야 함.   
    > 처음에는 v/a부터 v/(a-b) 까지 순차적으로 v를 넘는지 체크했더니 금방 시간초과가 나옴.   
    > 따라서 v/(a-b)부터 v/a까지 역으로 v를 못넘는지 체크했더니 시간초과는 해결했으나 답을 틀림.   
    > 해결했음 조금 더 경우의 수를 자세하게 파악해볼것!
    

* [10757](https://www.acmicpc.net/problem/10757) &nbsp; [큰 수 A+B] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/10757.kt)
    > BigInteger 사용하는 문제.   
    > BigInteger가 없는 경우 String으로 바꿔서 한자리 한자리 더해주고 올림발생하면 다음자릿수에 +1 해주면서 처리.
    

* [1011](https://www.acmicpc.net/problem/10757) &nbsp; [Fly me to the Alpha Centauri] &nbsp;&nbsp; [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/1011.kt)
    > 재귀로 접근. 하지만 DFS방식으로 진행되었고 또 제대로 가지치기랑 종료가 되지않아서 타임오버.   
    > ~최소이려면 어차피 공차가 1인 등차수열이 2개인거니까~   
    > 1은 1 2는 11 3은 111 4는 121 5는 1211,1121 6은 1221 7은 12211 11221 ...   
    > 21/01/09 해결 : 모르겠을때는 쭉 적어보면서 규칙 찾기. 오버플로우 조심할 것.
    
    
문제의 출력 조건 조심! **한줄**

## 21-01-09
> [수학2](https://www.acmicpc.net/step/10)


소수 관련문제에서 1 실수하지 말것



