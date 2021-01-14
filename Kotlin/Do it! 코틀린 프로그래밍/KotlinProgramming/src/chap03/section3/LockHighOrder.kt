package chap03.section3

import java.util.concurrent.locks.ReentrantLock

var sharable = 1

fun main(){
    val relock = ReentrantLock()

    lock(relock,{ criticalFunc()})
    lock(relock){ criticalFunc()}
    lock(relock, ::criticalFunc)


    println(sharable)
}

fun criticalFunc(){
    sharable += 1
}

fun <T> lock(relock: ReentrantLock, body: ()->T):T{
    relock.lock()
    try {
        return body()
    }finally {
        relock.unlock()
    }
}