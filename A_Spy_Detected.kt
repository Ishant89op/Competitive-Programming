class FastScanner {
    private val br = java.io.BufferedReader(System.`in`.reader())
    private var st = java.util.StringTokenizer("")

    fun next(): String {
        while (!st.hasMoreTokens()) {
            st = java.util.StringTokenizer(br.readLine())
        }
        return st.nextToken()
    }

    fun nextInt() = next().toInt()
    fun nextLong() = next().toLong()
    fun nextDouble() = next().toDouble()
}

class Solution {
    fun solve(n: Int, arr: IntArray): Int {
        if(arr[0] != arr[1]) {
            if(arr[1] != arr[2]) {
                return 2
            } else {
                return 1
            }
        }
        for(i in 2 until n) {
            if(arr[i] != arr[i-1]) {
                return i+1
            }
        }
        return -1
    }
}

fun main() {
    val fs = FastScanner()
    val sol = Solution()
    val t = fs.nextInt()
    

    for(i in 1..t) {
        val n = fs.nextInt()
        val arr = IntArray(n) { fs.nextInt() }
        println(sol.solve(n, arr))
    }
}
