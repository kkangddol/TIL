package chap10.section1

fun main(){
    data class Person(var name : String, var skills : String)
    var person = Person("길동","코틀린")
    val returnObj = person.apply {
        this.name = "신"
        this.skills = "스위프트"
        "success"
    }
    println(person)
    println("returnObj : $returnObj")

    val returnObj2 = person.run {
        this.name = "둘리"
        this.skills = "C#"
        "Success"
    }
    println(person)
    println("returnObj2 : $returnObj2")

    val returnObj3 = person.run {
        this.name = "3333"
        this.skills = "313123"
    }
    println(person)
    println("returnObj3 : $returnObj3")
}