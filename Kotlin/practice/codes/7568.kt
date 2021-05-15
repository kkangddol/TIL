import java.util.Scanner

fun main() = with(Scanner(System.`in`)) {
    val N: Int = nextInt()
    val arr: Array<Array<Int>> = Array(N,{Array(2,{0})})
    val ans: Array<Int> = Array(N,{1})
    for(i in 0..N-1){
        arr[i][0] = nextInt()
        arr[i][1] = nextInt()
    }
    for(i in 0..N-1){
        for(j in 0..N-1){
            if(i == j) continue
            else if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
                ans[i]++
            }
        }
    }
    for(i in 0..N-1){
        print("${ans[i]} ")
    }    
}
