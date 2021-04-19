package chap03.section3

fun main(){
    var result: Int
    val multi = {x:Int, y:Int -> x*y}
    result = multi(30,40)
    println(result)

    val multi2 : (Int,Int)->Int = {x,y ->
        print("x * y = ")
        x*y
    }
    println(multi2(3,5))

    val greet = {println("HELLO LAMBDA")}
    greet()
    val babo = greet
    babo()

    val nestedLambda: ()->()->Unit = {{println("NESTED")}}
    nestedLambda()()

    val nL : (Int)->(Int)->Int = {x->{y->
        print("$x * $y = ")
        x*y}}
    println(nL(3)(4))


}