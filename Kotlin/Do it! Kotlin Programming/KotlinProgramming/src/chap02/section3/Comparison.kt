package chap02.section3

fun main() {
    val a: Int = 128
    val b = a
    println(a === b)

    val c: Int? = a
    val d: Int? = a
    val e: Int? = c
    println(c == d)
    println(c === d)
    println(c === e)

    //-128 ~ 127 범위는 캐시에 저장되므로 같다고 나옴
    val aB: Int = 127
    val bB = aB
    println(aB === bB)

    val cB: Int? = aB
    val dB: Int? = aB
    val eB: Int? = cB
    println(cB == dB)
    println(cB === dB)
    println(cB === eB)
}