import java.util.Scanner
import java.io.BufferedWriter
import java.io.OutputStreamWriter
import kotlin.math.*

val bw = BufferedWriter(OutputStreamWriter(System.`out`))

fun main() = with(Scanner(System.`in`)){
    val n = nextInt() 
    
    bw.write(((2.0).pow(n)-1).toInt().toString())
    bw.newLine()
    
    hannoi(n,1,2,3)
    
    bw.flush()
    bw.close()
}

fun hannoi(n: Int, from: Int, via: Int, to: Int){
    if(n == 1){
        bw.write("${from} ${to}")
        bw.newLine()
        return
    }
    hannoi(n-1,from,to,via)
    hannoi(1,from,via,to)
    hannoi(n-1,via,from,to)
}
