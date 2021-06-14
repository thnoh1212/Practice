package algo_0923;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



public class Main {
	public static class Point{
		long x;
		long y;
		public Point(long x, long y) {
			this.x = x;
			this.y = y;
		}
		
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		long[][] map = new long[N+1][N+1];
		long[][][] dp = new long[3][N+1][N+1];
		for(int i = 1; i <= N; i++) {
			String[] temp = br.readLine().split(" ");
			for(int j = 1; j <= N; j++) {
				map[i][j] = Integer.parseInt(temp[j-1]);
			}
		}
		dp[0][1][2] = 1;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(j+1 < N+1 && map[i][j+1] != 1)
					dp[0][i][j+1] += dp[0][i][j] + dp[2][i][j];
				if(i+1 < N+1 && map[i+1][j] != 1)
					dp[1][i+1][j] += dp[1][i][j] + dp[2][i][j];
				if(i+1 < N+1 && j+1 < N+1 && map[i+1][j] != 1 && map[i][j+1] != 1 && map[i+1][j+1] != 1)
					dp[2][i+1][j+1] += dp[0][i][j] + dp[1][i][j] + dp[2][i][j];
			}
		}
		System.out.println(dp[0][N][N] + dp[1][N][N] + dp[2][N][N]);
	
	}
}
