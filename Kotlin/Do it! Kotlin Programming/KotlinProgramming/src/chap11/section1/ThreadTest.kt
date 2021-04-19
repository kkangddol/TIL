package chap11.section1

class SimpleThread: Thread(){
    override fun run(){
        println("Current Threads: ${Thread.currentThread()}")
    }
}

class SimpleRunnalbe: Runnable{
    override fun run() {
        println("Current Threads: ${Thread.currentThread()}")
    }
}

fun main(){
    val thread = SimpleThread()
    thread.start()

    val runnalbe = SimpleRunnalbe()
    val thread1 = Thread(runnalbe)
    thread1.start()

    object : Thread(){
        override fun run(){
            println("Current Threads(object): ${Thread.currentThread()}")
        }
    }.start()

    Thread({
        println("Current Threads(lambda): ${Thread.currentThread()}")
    }).start()

    Thread{
        println("Current Threads(labda2): ${Thread.currentThread()}")
    }.start()
}