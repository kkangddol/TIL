import java.util.Scanner

fun main() = with(Scanner(System.`in`)){
    val N = nextInt()
    val M = nextInt()
    val arr: Array<Int> = Array(N,{item->0})
    var ans = 0
    
    for(i in 0..N-1) arr[i] = nextInt()
    //arr.sortDescending()
    
    for(i in 0..N-1){
        for(j in i+1..N-1){
            for(k in j+1..N-1){
                var temp = arr[i] + arr[j] + arr[k]
                if(temp > M){
                    continue
                }
                else if(temp == M) {
                    println(temp)
                    return
                }
                var babo = comp(temp,ans,M)
                if(babo != ans) ans = babo
            }
        }
    }
    println(ans)
}

fun comp(new: Int, old: Int, M: Int):Int {
    if(Math.abs(M-new) < Math.abs(M-old)) return new
    else return old
}
