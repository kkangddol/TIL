package chap05.section3.override

open class Bird(var name: String, var beak: String, var color: String){
    fun fly() = println("Fly!")
    open fun sing(vol:Int) = println("Sing vol : $vol")
}

class Parrot(name:String,
             beak:String,
             color:String,
             var language : String = "ENG") : Bird(name,beak,color){
    fun speak() = println("SPEAK $language")
    override fun sing(vol:Int){
        println("I'm a parrot. volume : $vol")
        speak()
    }
}

fun main() {
    val parrot = Parrot("Parrot.3","long","bluesilver","KOR")

    parrot.sing(10)
}

