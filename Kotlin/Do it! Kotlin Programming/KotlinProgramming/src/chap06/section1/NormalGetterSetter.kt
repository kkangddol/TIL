package chap06.section1

class User(_id: Int, _name: String, _age: Int){
    val id: Int = _id
        get() = field

    var name: String = _name
        get() = field+" 추가당"
        set(value){
            println("대문자당!")
            field = value.toUpperCase()
        }

    var age: Int = _age
        get() = field
        private set
}

fun main(){
    val u = User(1,"temp",3)
    println(u.age)
    println(u.name)
    u.name = "small"
    //u.age = 4
    println(u.name)
}