import java.util.Scanner
import java.math.BigInteger

fun main() = with(Scanner(System.`in`)){
    var a:BigInteger = nextBigInteger()
    var b:BigInteger = nextBigInteger()
    println(a.add(b))
}
