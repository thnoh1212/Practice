import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        for(int testCase = 0; testCase < N; testCase++) {
            st = new StringTokenizer(br.readLine());
            int len = Integer.parseInt(st.nextToken());
            int[][] dp = new int[len + 1][len + 1];
            int[] arr = new int[len + 1];
            int[] sum = new int[len + 1];
            st = new StringTokenizer(br.readLine());
            for(int i = 1; i <= len; i++){
                arr[i] = Integer.parseInt(st.nextToken());
                sum[i] = sum[i-1] + arr[i];
            }

            // i ~ j 기준으로 최신화
            for(int cnt = 1; cnt <= len; cnt++){
                for(int start = 1; start + cnt <= len; start++){
                    int end = cnt + start;
                    dp[start][end] = Integer.MAX_VALUE;
                    for(int mid = start; mid < end; mid++) {
                        dp[start][end] = Math.min(dp[start][end], dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]);
                    }
                }
            }
            System.out.println(dp[1][len]);
        }
    }
}