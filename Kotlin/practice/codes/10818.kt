import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val token = StringTokenizer(br.readLine())
    val arr = Array(n,{0})
    for(i in (0..n-1))
        arr[i] = token.nextToken().toInt()
    arr.sort()
    println("${arr[0]} ${arr[n-1]}")
}
