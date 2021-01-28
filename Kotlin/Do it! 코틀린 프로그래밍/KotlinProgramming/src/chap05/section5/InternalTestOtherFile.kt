package chap05.section5.internal

import chap05.internal.InternalClass

fun main(){
    val babo = InternalClass()

    println(babo.i)
    babo.icFunc()
}