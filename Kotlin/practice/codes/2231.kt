import java.util.Scanner
import kotlin.math.pow

fun main() = with(Scanner(System.`in`)) {
    val N: Int = nextInt()
    var stdN: Int = N
    var ans: Int = 0
    while(stdN > 0){
        val temp = divideSum(stdN)
        if(temp == N) ans = stdN
        stdN--
    }
    println(ans)
}

fun divideSum(num: Int): Int {
    val len = (Math.log10(num.toDouble())+1).toInt()
    var rtn: Int = num
    for(i in 1..len){
        var t = ((10.0).pow(i)).toInt()
        rtn += num%t/(t/10)
    }
    return rtn
}
