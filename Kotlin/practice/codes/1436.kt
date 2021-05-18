import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    var N = nextInt()
    var sum = 0
    var ans = 666
    var temp = ans
    
    while(N > 0) {
        if(sum == 3) {
            N--
            ans++
            temp = ans
            sum = 0
            continue
        }
        else if(temp == 0) {
            ans++
            temp = ans
            sum = 0
            continue
        }
        else {
            if(temp % 10 == 6) sum++
            else sum = 0
            temp /= 10
        }
    }
    println(--ans)
}
