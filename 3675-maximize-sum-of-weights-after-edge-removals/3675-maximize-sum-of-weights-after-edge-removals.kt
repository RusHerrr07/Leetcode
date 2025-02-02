import java.util.*

class Solution {
    private lateinit var graph: Array<MutableList<Pair<Int, Int>>>
    private lateinit var dp: Array<Pair<Long, Long>>

    fun maximizeSumOfWeights(edges: Array<IntArray>, maxD: Int): Long {
        val edgeList = edges.map { it.toList() } // Convert Array<IntArray> to List<List<Int>>
        val n = edgeList.size + 1
        graph = Array(n) { mutableListOf() }
        buildGraph(edgeList)
        dp = Array(n) { Pair(0L, 0L) }
        dfs(0, -1, maxD)
        return dp[0].first
    }

    private fun buildGraph(edges: List<List<Int>>) {
        for (edge in edges) {
            val u = edge[0]
            val v = edge[1]
            val w = edge[2]
            graph[u].add(Pair(v, w))
            graph[v].add(Pair(u, w))
        }
    }

    private fun dfs(u: Int, parent: Int, maxD: Int) {
        val gains = mutableListOf<Long>()
        var sum = 0L
        for ((v, w) in graph[u]) {
            if (v == parent) continue
            dfs(v, u, maxD)
            sum += dp[v].first
            val g = w.toLong() + dp[v].second - dp[v].first
            gains.add(g)
        }
        processGains(gains, sum, u, maxD)
    }

    private fun processGains(gains: MutableList<Long>, sum: Long, u: Int, maxD: Int) {
        gains.sortDescending()
        var total = sum
        for (i in 0 until minOf(gains.size, maxD)) {
            if (gains[i] > 0) total += gains[i]
        }
        dp[u] = Pair(total, dp[u].second)

        if (maxD > 0) {
            total = sum
            for (i in 0 until minOf(gains.size, maxD - 1)) {
                if (gains[i] > 0) total += gains[i]
            }
            dp[u] = Pair(dp[u].first, total)
        } else {
            dp[u] = Pair(dp[u].first, sum)
        }
    }
}
