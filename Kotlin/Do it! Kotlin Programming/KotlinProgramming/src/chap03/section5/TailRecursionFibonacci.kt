package chap03.section5

import java.math.BigInteger

fun main(){
    val n = 20000
    val first = BigInteger("0")
    val second = BigInteger("1")

    println(fibonacci(n,first,second))
    println(ifNotTailRec(n,first,second))
}

tailrec fun fibonacci(n:Int, a:BigInteger, b:BigInteger):BigInteger{
    return if(n==0) b else fibonacci(n-1,b, a+b)
}

fun ifNotTailRec(n:Int, a:BigInteger, b:BigInteger):BigInteger{
    return if(n==0) b else fibonacci(n-1,b, a+b)
}