import java.io.*
import java.util.*

fun main(args: Array<String>){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    val t = br.readLine().toInt()
    for(i in (1..t)){
        var token = StringTokenizer(br.readLine())
        var ans = token.nextToken().toInt() + token.nextToken().toInt()
        bw.write(ans.toString())
        bw.newLine()
    }
    bw.close()
    br.close()
}
