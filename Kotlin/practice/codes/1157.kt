import java.io.BufferedReader
import java.io.InputStreamReader

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val str = br.readLine()
    val arr = Array(26, {0})
    val smallAscii = 'a'.toInt()
    val bigAscii = 'A'.toInt()
    for(i in 0..str.length-1){
        if(str[i].toInt() >= smallAscii)
            arr[str[i].toInt() - smallAscii]++
        else
            arr[str[i].toInt() - bigAscii]++
    }
    if(arr.indexOfFirst{it == arr.max()} != arr.indexOfLast{it == arr.max()})
        println("?")
    else
        println((bigAscii+arr.indexOf(arr.max())).toChar())
    
}
