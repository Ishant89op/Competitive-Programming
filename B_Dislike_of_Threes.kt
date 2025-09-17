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

fun main() {
    val dp: IntArray = IntArray(1001)
    val fs = FastScanner()
    val t = fs.nextInt()
    var num = 1
    var idx = 0
    while (idx < 1000) {
        val numStr = num.toString()
        if (num % 3 != 0 && numStr.last() != '3') {
            dp[idx] = num
            idx++
        }
        num++
    } 
    

    for(i in 1..t) {
        val k = fs.nextInt()
        println(dp[k-1])
    }
}