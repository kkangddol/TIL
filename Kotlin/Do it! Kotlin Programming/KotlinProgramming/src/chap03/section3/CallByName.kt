package chap03.section3

fun main(){
    println(callByValue(otherLambda))
}
fun callByValue(b:()->Boolean): Boolean {
    println("callByValue")
    return b()
}
val otherLambda : ()->Boolean = {
    println("otherLambda")
    true
}