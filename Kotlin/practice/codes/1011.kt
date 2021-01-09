import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    val t = nextInt()
    for(i in 1..t){
        val x = nextInt()
        val y = nextInt()
        val temp = y-x
        var sqrt_temp: Long = Math.sqrt(temp.toDouble()).toLong()
        var a: Long = (sqrt_temp-1) * sqrt_temp
        var b: Long = sqrt_temp * (sqrt_temp+1)
        if(!(a < temp && temp <= b)){
            sqrt_temp++
            a = b
            b = sqrt_temp * (sqrt_temp+1)
        }
        if(temp <= (a+b)/2){
            println(sqrt_temp*2 - 1)
        }else{
            println(sqrt_temp*2)
        }
    }
}
