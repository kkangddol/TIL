package chap02.section2

fun main() {
    var num = 0.1
    val babo : Int
    var abc : Int

    println(65.toChar())

    val a = "equals"
    val b = a
    val c = "equals"

    println(a==b)
    println(a==c)
    println(a===b)
    println(a===c)

    for(i in 0..999){
        num += 0.1
    }
    println(num)    //부동소수점 오차
}