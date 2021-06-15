class Solution {
    public long solution(int n) {
        int[] dp = new int[n+3];
        dp[0] = 1;
        for(int i = 0; i <= n; i++){
            dp[i+1] += dp[i];
            dp[i+2] += dp[i];
            dp[i+1] %= 1234567;
            dp[i+2] %= 1234567;
        }
        return dp[n];
    }
}