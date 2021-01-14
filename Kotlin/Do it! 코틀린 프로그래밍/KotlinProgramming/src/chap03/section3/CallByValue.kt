package chap03.section3

fun main(){
    println(callByValue(lambda()))
}
fun callByValue(b:Boolean) : Boolean {
    println("callByValue")
    return b
}
val lambda : ()->Boolean = {
    println("lambda")
    true
}