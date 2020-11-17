import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    val c = nextInt()
    for(i in (1..c)){
        val n = nextInt()
        var cnt = 0
        val arr = Array(n,{0})
        for(j in (0..n-1)){
            arr[j] = nextInt()
        }
        val avg = arr.average()
        for(j in (0..(n-1))){
            if(arr[j]>avg){
                cnt++
            }
        }
        print(java.lang.String.format("%.3f", (cnt.toDouble()/n*100)))
        println("%")
    }
}
