package chap05.section4.personthis

open class Person{
    constructor(firstName: String){
        println("[Person] firstName : $firstName")
    }
    constructor(firstName: String, age:Int){
        println("[Person] firstName : $firstName, age : $age")
    }
}

class Developer : Person{
    constructor(firstName: String) : this(firstName,10){
        println("[DEV] $firstName")
    }
    constructor(firstName: String, age: Int) : super(firstName, age){
        println("[DEV] $firstName , $age")
    }
}

fun main(){
    val babo = Developer("babo")
}