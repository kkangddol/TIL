package chap05.internal

internal class InternalClass{
    internal var i = 1
    internal fun icFunc(){
        i += 1
        println(i)
    }
    fun access(){
        icFunc()
    }
}

class Other{
    internal val ic = InternalClass()
    fun test(){
        ic.i = 10
        ic.icFunc()
    }
}

fun main(){
    val mic = InternalClass()
    mic.i = 100
    mic.icFunc()

    val ot = Other()
    ot.test()
}