class Solution {
    public int solution(int[] money) {
        int answer = 0;
        int len = money.length;
        int[][] dp = new int[2][len];
        /*
         * 0: 첫번째 집 o
         * 1: 첫번째 집 x
         */
        dp[0][0] = dp[0][1] = money[0];
        for(int i = 2; i < len - 1; i++){
            dp[0][i] = Math.max(dp[0][i-2] + money[i], dp[0][i-1]);
        }
        dp[1][1] = money[1];
        for(int i = 2; i < len; i++){
            dp[1][i] = Math.max(dp[1][i-2] + money[i], dp[1][i-1]);
        }
        dp[0][len-1] = Math.max(dp[0][len-2], dp[0][len-3]);
        dp[1][len-1] = Math.max(dp[1][len-1], dp[1][len-2]);

        return Math.max(dp[0][len-1], dp[1][len-1]);
    }
}