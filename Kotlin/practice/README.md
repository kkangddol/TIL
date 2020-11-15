[백준 단계별 올라가면서 코틀린 연습](https://www.acmicpc.net/step, "baekjoon link")
===================================================================================

# 20-11-13   
> [입출력](https://www.acmicpc.net/step/1, "입출력 link")   
> [if문](https://www.acmicpc.net/step/4, "if문 link")   

`with`를 이용해 scanner 객체 생성없이 더 코드를 축약할 수 있음.
```
fun main(args: Array<String>) = with(Scanner(System.`in`)){
    ...
}
```

# 20-11-15
> [for문](https://www.acmicpc.net/step/3, "for문 link")   
> [while문](https://www.acmicpc.net/step/2, "while문 link")   

### [15552 빠른 A+B](https://www.acmicpc.net/problem/15552, "15552 link")
### [소스](https://github.com/rudeore333/TIL/blob/master/Kotlin/practice/codes/15552.kt, "빠른 A+B link")
`BufferedReader`와 `BufferedWriter`를 쓰기.   
java에서는 저 두개 말고도 `StringBuilder`로 출력을 모아 놓았다가 그 String을 `System.out.println`하는 방법도 있음.
