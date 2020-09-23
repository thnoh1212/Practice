package algo_0923;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main17070 {
	static class Point{
		int x;
		int y;
		int dir;
		public Point(int x, int y, int dir) {
			this.x = x;
			this.y = y;
			this.dir = dir;
		}
	}

	static int[][] moves = {{0,1},{1,0},{1,1}};
	static int[] dir0 = {0,2};
	static int[] dir1 = {1,2};
	static int[] dir2 = {0, 1, 2};
	static int [][]map;
	static int N, answer;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		answer = 0;
		for(int i = 0; i < N; i++) {
			String[] temp = br.readLine().split(" ");
			for(int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(temp[j]);
			}
		}
		dfs(0, 1, 0);
		System.out.println(answer);
	}
	public static void dfs(int i, int j, int dir) {
		if(i == N-1 && j == N-1) {
			answer += 1;
			return;
		}
		int[] arr;
		if(dir == 0)
			arr = dir0;
		else if(dir == 1)
			arr = dir1;
		else
			arr = dir2;
		
		for(int k = 0; k < arr.length; k++) {
			int nextI = i + moves[arr[k]][0];
			int nextJ = j + moves[arr[k]][1];
			if(nextI >= N || nextJ >= N || map[nextI][nextJ] == 1) continue;
			if(arr[k] == 2 && (map[i+1][j] == 1 || map[i][j+1] == 1)) continue;
			dfs(nextI, nextJ, arr[k]);
		}
	}
}
