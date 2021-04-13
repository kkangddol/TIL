package chap11.section1

public fun customThread(start: Boolean = true, isDaemon: Boolean = false,
        contextClassLoader: ClassLoader? = null, name: String? = null,
        priority: Int = -1, block: () -> Unit): Thread {
    val valThread = object : Thread(){
        public override fun run() {
            block()
        }
    }
    if(isDaemon)
        valThread.isDaemon = true
    if(priority > 0)
        valThread.priority = priority
    if(name != null)
        valThread.name = name
    if(contextClassLoader != null)
        valThread.contextClassLoader = contextClassLoader
    if(start)
        valThread.start()
    return valThread
}

fun main(){
    customThread(start = true){
        println("Current Threads(Custom Function): ${Thread.currentThread()}")
        println("Priority: ${Thread.currentThread().priority}")
        println("Name: ${Thread.currentThread().name}")
        println("isDaemon: ${Thread.currentThread().isDaemon}")
    }
}