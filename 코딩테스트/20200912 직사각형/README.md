    class Solution {
    fun solution(v: Array<IntArray>): IntArray {
        
        var x = v[0][0] xor v[1][0] xor v[2][0]
        var y = v[0][1] xor v[1][1] xor v[2][1]
        
        var answer = intArrayOf(x,y)

        return answer
        }
    }
