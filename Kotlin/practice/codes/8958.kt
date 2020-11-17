import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    val n = nextInt()
    var ans = 0
    var combo = 1
    var str = ""
    for(i in (1..n)){
        str = next()
        
        for(j in (0..(str.length - 1))){
            if(str[j].equals('O')){
                ans += combo++
            }else
                combo = 1
        }
        
        println(ans)
        ans = 0
        combo = 1
    }
}
