package algo_1102;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
	
	public static class Point{
		int i;
		int j;
		int num;
		public Point(int i, int j, int num) {
			super();
			this.i = i;
			this.j = j;
			this.num = num;
		}
	}
	static int answer;
	static int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
	public static void main(String[] args) throws Exception {
		 BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		 int T = Integer.parseInt(br.readLine());
		 for(int tc = 1; tc <= T; tc++) {
			 answer = 180;
			 String[] temp = br.readLine().split(" ");
			 int N = Integer.parseInt(temp[0]);
			 int W = Integer.parseInt(temp[1]);
			 int H = Integer.parseInt(temp[2]);
			 int[][] board = new int[H][W];
			 
			 for(int i = 0; i < H; i++) {
				 temp = br.readLine().split(" ");
				 for(int j = 0; j < W; j++) {
					 board[i][j] = Integer.parseInt(temp[j]);
				 }
			 }
			 
			 dfs(N, W, H, board);
			 System.out.println("#" + tc + " " + answer);
		 }
	}
	
	static void dfs(int N, int W, int H, int[][] board) {
		if(N == 0) { // 공을 다 쓴 경우
			int cnt = 0;
			for(int i = 0; i < H; i++) {
				for(int j = 0; j < W; j++) {
					if(board[i][j] != 0)
						cnt++;
				}
			}
			answer = Math.min(answer, cnt);
			return;
		}
		for(int i = 0; i < W; i++) {
			int idx = -1; 
			for(int j = 0; j < H; j++) { // 보드판 확인
				if(board[j][i] != 0) {
					idx = j;
					break;
				}
			}
			if(idx == -1) continue;
			
			int[][] t_board = new int[H][W];
			for(int j = 0; j < H; j++) { // 보드 복사
				for(int k = 0; k < W; k++)
					t_board[j][k] = board[j][k];
			}
			
			Queue<Point> que = new LinkedList<>();
			que.add(new Point(idx, i, t_board[idx][i]));
			t_board[idx][i] = 0;
			while(!que.isEmpty()) {
				int cI = que.peek().i;
				int cJ = que.peek().j;
				int range = que.poll().num;
				for(int j = 0; j < 4; j++) {
					int nI = cI;
					int nJ = cJ;
					for(int k = 1; k < range; k++) {
						nI += moves[j][0];
						nJ += moves[j][1];
						if(nI < 0 || nI >= H || nJ < 0 || nJ >= W) break;
						if(t_board[nI][nJ] == 1) {
							t_board[nI][nJ] = 0;
							continue;
						}
						else if(t_board[nI][nJ] > 1) {
							que.add(new Point(nI, nJ, t_board[nI][nJ]));
							t_board[nI][nJ] = 0;
						}
					}
				}
			}
			boolean flag = true;
			for(int j = 0; j < W; j++) {
				List<Integer> list = new ArrayList<>();
				for(int k = H-1; k >= 0; k--) {
					if(t_board[k][j] != 0) {
						list.add(t_board[k][j]);
						flag = false;
					}
				}
				int limit = 0;
				for(int k = H-1; k >= 0; k--) {
					if(limit < list.size())
						t_board[k][j] = list.get(limit++);
					else
						t_board[k][j] = 0;
				}
			}
			if(flag)
				N = 1;
			dfs(N-1, W, H, t_board);
		}
	}
}
