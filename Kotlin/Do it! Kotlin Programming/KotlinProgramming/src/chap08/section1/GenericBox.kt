package chap08.section1

class Box<T>(t: T){
    var name = t
}

fun main(){
    val box1: Box<Int> = Box<Int>(1)
    val box2: Box<String> = Box<String>("babo")
    val box3 = Box(3)
    val box4 = Box(3.4)
    val box5 = Box('b')
    val box6 = Box("QEQWE")

    println(box1.name)
    println(box2.name)
    println(box3.name)
    println(box4.name)
    println(box5.name)
    println(box6.name)
    println(box1.javaClass)
}