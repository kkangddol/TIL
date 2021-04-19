package chap02.section3

fun main() {
    var str : String? = "Kotlin"
    str = null


    //println("${str?.length}")
    //println("${str!!.length}")

//    val len = if(str != null) str.length else -1
//    println("str1 : &str1 length : $len")

    println("str1 : &str1 length : ${str?.length ?: -1}")
}