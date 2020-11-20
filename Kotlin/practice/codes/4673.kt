import java.io.BufferedWriter
import java.io.OutputStreamWriter

data class CheckData(var n:Int = 1, var ret:Int = 0)

fun main(){
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    
    val ans = Array(10001,{0})
    val cd = CheckData()
    while(isSelf(cd) <= 10000){
        ans[cd.ret] = 1
        cd.n++
    }
    for(i in (1..10000)){
        if(ans[i] == 0){
            bw.write(i.toString())
            if(i < 10000){
                bw.newLine()
            }
        }
    }
    bw.flush()
    bw.close()
}

fun isSelf(cd : CheckData) : Int{
    val k = (Math.log10((cd.n).toDouble())+1).toInt()
    var ret = cd.n
    for(i in (1..k)){
        ret += ((cd.n)/Math.pow(10.toDouble(),(i-1).toDouble())%10).toInt()
    }
    if(ret > 10000 && cd.n < 10000){
        cd.ret = 0
        return 0
    }
    cd.ret = ret
    return ret
}
