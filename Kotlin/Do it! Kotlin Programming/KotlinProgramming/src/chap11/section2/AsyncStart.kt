package chap11.section2.starttest

import kotlinx.coroutines.*
import kotlin.system.measureTimeMillis

suspend fun doWork1(): String{
    delay(1000)
    return "Work1"
}

suspend fun doWork2(): String{
    delay(3000)
    return "Work2"
}

fun main() = runBlocking {
    val timeFull = measureTimeMillis {
        delay(500)
        val time = measureTimeMillis {
            delay(500)
            val one = async(start = CoroutineStart.LAZY) { doWork1() }
            val two = async(start = CoroutineStart.LAZY) { doWork2() }
            println("AWAIT: ${one.await() + "_" + two.await()}")
        }
        println("Completed in $time ms")
    }
    println("Full Completed in $timeFull ms")

}