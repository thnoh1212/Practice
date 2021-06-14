import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Solution {
	static int answer;
	static int N;
	static int M;
	static int C;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			answer = 0;
			String[] temp = br.readLine().split(" ");
			N = Integer.parseInt(temp[0]);
			M = Integer.parseInt(temp[1]);
			C = Integer.parseInt(temp[2]);
			int[][] honey = new int[N][N];
			boolean[][] chk = new boolean[N][N];
			for(int i = 0; i < N; i++) {
				temp = br.readLine().split(" ");
				for(int j = 0; j < N; j++) {
					honey[i][j] = Integer.parseInt(temp[j]);
				}
			}
			for(int i = 0; i < N; i++) {
				for(int k = 0; k < M; k++)
					chk[i][k] = true;
				for(int j = 0; j < N - M + 1; j++) {
					chk[i][j + M - 1] = true;
					selectHoney(honey, chk, i, j);
				}
			}
			System.out.println("#" + tc + " " + answer);
		}
	}
	
	public static void selectHoney(int[][] honey, boolean[][] chk, int fI, int fJ) {
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N - M + 1; j++) {
				if(chk[i][j]) continue;
				else {
					calcValue(honey, fI, fJ, i, j);
				}
			}
		}
	}
	public static void calcValue(int[][] honey, int fI, int fJ, int i, int j) {
		int[] honey1 = new int[M];
		int[] honey2 = new int[M];
		boolean[] chk = new boolean[M];
		for(int k = 0; k < M; k++){
			honey1[k] = honey[fI][fJ + k];
			honey2[k] = honey[i][j + k];
		}
		Arrays.sort(honey1);
		Arrays.sort(honey2);
		int h1 = dfs(honey1, chk, 0);
		int h2 = dfs(honey2, chk, 0);
		answer = Math.max(h1+h2, answer);
	}
	public static int dfs(int[] honey, boolean[] chk, int idx) {
		int max = 0;
		if(idx == M) {
			int sum = 0;
			int honeySum = 0;
			for(int i = 0; i < M; i++) {
				if(chk[i]) {
					sum += honey[i];
					honeySum += (int)Math.pow(honey[i],2);
					if(sum > C) return 0;
				}
			}
			return honeySum;
		}
		chk[idx] = true;
		max = Math.max(max, dfs(honey, chk, idx+1));
		chk[idx] = false;
		max = Math.max(max,dfs(honey, chk, idx+1));
		return max;
	}
}
