import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.BufferedWriter
import java.io.OutputStreamWriter
import java.util.StringTokenizer

fun main(){
    var br = BufferedReader(InputStreamReader(System.`in`))
    var bw = BufferedWriter(OutputStreamWriter(System.`out`))
    var token = StringTokenizer(br.readLine())
    var a = token.nextToken().toInt()
    var b = token.nextToken().toInt()
    var v = token.nextToken().toInt()
    br.close()
    
    var temp1: Int = v/a
    var temp2: Int = v/(a-b)
    if(v%(a-b) != 0)
        temp2++
    
    for(i in temp2 downTo temp1){
        if(a*i - b*(i-1) < v){
            bw.write((i+1).toString())
            break
        }else if(a*i - b*(i-1) == v){
            bw.write(i.toString())
            break
        }
    }
    bw.close()
}
