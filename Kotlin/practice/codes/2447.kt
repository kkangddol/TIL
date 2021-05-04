import java.util.Scanner
import java.io.BufferedWriter
import java.io.OutputStreamWriter

var arr = Array(1,{CharArray(1)})

fun main() = with(Scanner(System.`in`)){
    val bw = BufferedWriter(OutputStreamWriter(System.`out`))
    
    val N = nextInt()
    arr = Array(N,{CharArray(N)})
    star(0,0,N,false)
    for(i in 0..N-1){
        for(j in 0..N-1){
            bw.write(arr[i][j].toString())
        }
        bw.newLine()
    }
    bw.flush()
    bw.close()
}

fun star(x: Int, y: Int, N: Int, blank: Boolean){
    if(blank){
    	for(i in x..x+N-1){
            for(j in y..y+N-1){
                arr[i][j] = ' '
            }
        }
        return
    }
    
    if(N == 1){
        arr[x][y] = '*'
        return
    }
    else{
        var size = N/3
        var count = 0
        
        for(i in x..x+N-1 step size){
            for(j in y..y+N-1 step size){
                count++
                if(count == 5){
                    star(i,j,size,true)
                }
                else{
                    star(i,j,size,false)
                }
            }
        }
    }
}
