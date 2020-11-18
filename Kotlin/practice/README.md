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
    > `BufferedReader`와 `BufferedWriter`를 쓰기.   
    > java에서는 저 두개 말고도 `StringBuilder`로 출력을 모아 놓았다가 그 String을 `System.out.println`하는 방법도 있음.   
    > **`BufferedReader` 와 `BufferedWriter` 사용했으면 꼭 마지막에 `close()` 해줘야함**

## 20-11-17
> [while문](https://www.acmicpc.net/step/2)   
> [1차원 배열](https://www.acmicpc.net/step/6)

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



