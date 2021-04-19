package chap11.section2

import kotlinx.coroutines.*

fun main(){
    GlobalScope.launch {
        doSomething()
        delay(1000L)
        println("World!")
    }
    println("Hello, ")
    Thread.sleep(2000L)
}

suspend fun doSomething(){
    println("Do Something!")
}