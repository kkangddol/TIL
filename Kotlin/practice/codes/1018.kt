import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    val M = nextInt()
    val arr: Array<String> = Array(N,{""})
    val arrW: Array<Array<Int>> = Array(N,{Array(M,{0})})
    val arrB: Array<Array<Int>> = Array(N,{Array(M,{0})})
    for(i in 0..N-1){
        arr[i] = next()
        for(j in 0..M-1){
            if(i%2 == 0){
                if(j%2 == 0){
                    if(arr[i][j] == 'W') arrB[i][j] = 1
                    else arrW[i][j] = 1
                }
                else{
                    if(arr[i][j] == 'B') arrB[i][j] = 1
                    else arrW[i][j] = 1
                }
            }
            else{
                if(j%2 == 0){
                    if(arr[i][j] == 'B') arrB[i][j] = 1
                    else arrW[i][j] = 1
                }
                else{
                    if(arr[i][j] == 'W') arrB[i][j] = 1
                    else arrW[i][j] = 1
                }
            }
        }
    }
    var ans = 2500
    
    
    for(i in 0..N-8){
        for(j in 0..M-8){
            var tempW = 0
            var tempB = 0
            for(k in i..i+7){
                for(l in j..j+7){
                    tempW += arrW[k][l]
                    tempB += arrB[k][l]
                }
            }
            ans = if(tempW < ans) tempW else ans
            ans = if(tempB < ans) tempB else ans
        }
    }
    println(ans)
}
