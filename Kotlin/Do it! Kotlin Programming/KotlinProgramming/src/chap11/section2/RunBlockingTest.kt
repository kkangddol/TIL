package chap11.section2

import kotlinx.coroutines.*

fun main() = runBlocking<Unit> {    // main() 함수가 코루틴 환경에서 실행됨!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    launch {
        delay(1000L)
        println("World!")
    }
    println("Hello")
    //delay(2000L)
}