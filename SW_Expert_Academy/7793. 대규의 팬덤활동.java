import java.util.Scanner;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int mod = 1000000000; // 10억으로 나눈 나머지를 구해야 함
		for(int tc = 1; tc <= T; tc++) {
			int N = sc.nextInt();
			long sum = 0; // 총 합의 값 % mod
			int[][][] dp = new int[N+1][10][1024]; // 0 ~ 9 의 10자리 수 -> 0000000000 ~ 1111111111 -> 1024가지 경우의 수
			for(int i = 1; i < 10; i++) dp[1][i][1 << i] = 1; // 길이 1일때 스타트 할 숫자 설정
			for(int i = 2; i <= N; i++) { // 길이 2 ~ 길이 N
				for(int j = 0; j <= 9; j++) { // 숫자 0 ~ 숫자 9
					for(int k = 0; k < 1024; k++) { // 0000000000 ~ 1111111111
						int status = k | (1 << j); // 현재 숫자 비트에 이번에 사용할 숫자 j번쨰 비트를 1로 켜줌
						if(j != 0) // 0을 제외한 1 ~ 9 숫자를 사용한 경우 이전 자리수의 j-1값을 더해줌
							dp[i][j][status] = (dp[i][j][status] + dp[i-1][j-1][k]) % mod;
						if(j != 9) // 9를 제외한 0 ~ 8 숫자를 사용한 경우 이전 자리수의 j+1값을 더해줌
							dp[i][j][status] = (dp[i][j][status] + dp[i-1][j+1][k]) % mod;
					}
				}
			}
			
			for(int i = 0; i < 10; i++)
				sum = (sum + dp[N][i][1023]) % mod;
			
			System.out.println("#" + tc + " " + sum);
		}
		sc.close();
	}
}
