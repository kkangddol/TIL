import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    val n = nextInt()
    val str = next()
    var ans = 0
    for(i in 0..n-1){
        ans += str[i].toString().toInt()
    }
    println(ans)
}
