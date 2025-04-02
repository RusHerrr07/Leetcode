class Solution {
private val dp: Array<IntArray> = Array(101) { IntArray(101) { -1 } }

private fun solve(i:Int ,j:Int,n:Int,m:Int):Int{
    if(i==n-1 && j==m-1)return 1;
    if(i>=n || j>=m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    val down =solve(i+1,j,n,m);
    val right=solve(i,j+1,n,m);

     dp[i][j] = right+down;
    return dp[i][j];

}
 fun uniquePaths(m: Int, n: Int): Int {
        return solve(0,0,m,n);
        
    }
}