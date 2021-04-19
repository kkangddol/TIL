package chap11.section3

import kotlinx.coroutines.*
import javax.xml.ws.Dispatch

fun main() = runBlocking<Unit>{
    val jobs = arrayListOf<Job>()
    jobs += launch(Dispatchers.Unconfined){
        println("Unconfined:\t\t ${Thread.currentThread().name}")
    }
    jobs += launch(coroutineContext){
        println("coroutineContext:\t ${Thread.currentThread().name}")
    }
    jobs += launch(Dispatchers.Default){
        println("Default:\t\t ${Thread.currentThread().name}")
    }
    jobs += launch(Dispatchers.IO){
        println("IO:\t\t ${Thread.currentThread().name}")
    }
    jobs += launch{
        println("main runBlocking ${Thread.currentThread().name}")
    }
    jobs += launch(newSingleThreadContext("MyThread")){
        println("MyThread:\t\t ${Thread.currentThread().name}")
    }
    jobs.forEach{it.join()}
}