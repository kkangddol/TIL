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

* [15552](https://www.acmicpc.net/problem/15552) _빠른 A+B_ [:page_facing_up:](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/15552.kt)   
> `BufferedReader`와 `BufferedWriter`를 쓰기.   
> java에서는 저 두개 말고도 `StringBuilder`로 출력을 모아 놓았다가 그 String을 `System.out.println`하는 방법도 있음.   
> **`BufferedReader` 와 `BufferedWriter` 사용했으면 꼭 마지막에 `close()` 해줘야함**

## 20-11-16
> [while문](https://www.acmicpc.net/step/2)



