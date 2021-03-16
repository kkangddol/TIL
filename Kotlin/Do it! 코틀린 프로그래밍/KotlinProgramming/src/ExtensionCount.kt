package chap09.section4

fun main(){
    val list = listOf(1,2,3,4,5,6)
    val listPair = listOf(Pair("A",300), Pair("B",200), Pair("C",100))
    val map = mapOf(11 to "Java", 22 to "Kotlin", 33 to "C++")

    println(list.fold("dd"){total,next -> total + next})
    println(list.fold(3){total,next -> total * next})
    println(list.fold(3.5){total,next -> total * next})
    println(list.fold(-0.3){total,next -> total * next})

    println(list.fold(1){a,b -> a + b})

    println(list.fold(50000){total,next -> total % next})
    println(list.foldRight(50000){total,next -> total % next})

    println(list.reduce{total,next -> total * next})
    println(list.reduce{total,next -> total + next})
    println(list.reduce{total,next -> total - next})
    println(list.reduceRight{total,next -> total - next})
}