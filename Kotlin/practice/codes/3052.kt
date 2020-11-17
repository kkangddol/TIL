import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    val arr = Array(10,{0})
    for(i in (0..9)){
        arr[i] = nextInt()%42
    }
    println(arr.distinct().size)
}
