package chap03.section1

fun main(){
//    println(sum(3,5))
//    println(sum(3))
//
//    normalVarargs(1,4,2,5,3,4,1)

    println(highFunc({x,y->x+y},20,10))
    println(highFunc({x,y->x-y},20,10))
    println(highFunc({x,y->x/y},20,10))
    println(highFunc({x,y->x%y},20,10))
    println(highFunc({x,y->x},20,10))
    println(highFunc({x,y->y},20,10))

    println(mul(3,4))
}

//fun sum(a: Int, b: Int = 20) = a+b

fun mul(a:Int, b:Int):Int = a*b

fun normalVarargs(vararg counts:Int) {
    for(num in counts)
        println(num)
}

fun highFunc(sum: (Int,Int)->Int, a:Int, b:Int):Int = sum(a,b)