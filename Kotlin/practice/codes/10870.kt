import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    println(fibonacci(nextInt()))
}

tailrec fun fibonacci(n:Int, prev:Int=0, now:Int=1):Int{
    return if(n==0) prev else fibonacci(n-1,now,prev+now)
}
