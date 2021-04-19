package chap09.section5

fun main() {
    val fibonacci = generateSequence(1 to 1) { it.second to it.first + it.second }
            .map{it.first}
    val fibonacciPair = generateSequence(Pair(1,1)) { it.second to it.first + it.second }
            .map{it.first}
    println(fibonacci.take(10).toList())
    println(fibonacci.javaClass)
    println(fibonacciPair.take(10).toList())
}