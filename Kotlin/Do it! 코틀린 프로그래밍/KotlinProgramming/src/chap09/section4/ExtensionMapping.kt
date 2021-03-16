package chap09.section4

fun main(){
    val list = listOf(1,2,3,4,5,6)
    val listWithNull = listOf(1,null,3,null,5,6)
    val mapTest = mapOf(1 to listOf("a,b"), 2 to listOf("c","d"))

    println(mapTest)

    println(list.flatMap {listOf(it,'A')})
    val result = listOf("abc", "12").flatMap { it.toList() }
    println(result)
}