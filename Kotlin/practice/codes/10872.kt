import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    println(factorial(nextInt()))
}

tailrec fun factorial(n: Int, run: Int = 1):Int{
    return if(n==0) 1 else if(n==1) run else factorial(n-1, run*n)
}
