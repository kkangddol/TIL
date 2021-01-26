package chap05.section3.openclass

open class Bird(var name: String, var beak: String, var color: String){
    fun fly() = println("Fly!")
    fun sing(vol:Int) = println("Sing vol : $vol")
}

class Lark(name: String, beak: String, color: String) : Bird(name,beak,color){
    fun singHighTone() = println("Sing HIGH")
}

class Parrot : Bird {
    val language:String

    constructor(
        name: String,
        beak: String,
        color: String,
        language : String
    ) : super(name,beak,color){
        this.language = language
    }

    fun speak() = println("speak $language")
}

fun main() {
    val coco = Bird("mk.1","short","silver")
    val lark = Lark("lark.2","middle","redgold")
    val parrot = Parrot("Parrot.3","long","bluesilver","eng")

    coco.fly()
    coco.sing(3)

    lark.fly()
    lark.sing(5)
    lark.singHighTone()

    parrot.fly()
    parrot.sing(9)
    parrot.speak()

}

