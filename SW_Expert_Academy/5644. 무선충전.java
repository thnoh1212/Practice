package algo_1102;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	public static class Point{
		int i;
		int j;
		int range;
		public Point(int i, int j, int range) {
			super();
			this.i = i;
			this.j = j;
			this.range = range;
		}
	}
	
	public static void main(String[] args) throws Exception, IOException {
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int[][] moves = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
		for(int tc = 1; tc <= T; tc++) {
			int answer = 0;
			int[][] map = new int[10][10];
			int M, A;
			String[] temp = br.readLine().split(" ");
			M = Integer.parseInt(temp[0]);
			A = Integer.parseInt(temp[1]);
			int[] bc = new int[A];
			int[][] person = new int[2][M];
			for(int i = 0; i < 2; i++) {
				temp = br.readLine().split(" ");
				for(int j = 0; j < M; j++) {
					person[i][j] = Integer.parseInt(temp[j]);
				}
			}
			for(int i = 0; i < A; i++) {
				temp = br.readLine().split(" ");
				boolean[][] visited = new boolean[10][10];
				int startJ = Integer.parseInt(temp[0])-1;
				int startI = Integer.parseInt(temp[1])-1;
				int range = Integer.parseInt(temp[2]);
				int power = Integer.parseInt(temp[3]);
				bc[i] = power;
				Queue<Point> que = new LinkedList<>();
				que.add(new Point(startI, startJ, range));
				visited[startI][startJ] = true;
				map[startI][startJ] += (1 << i); 
				while(!que.isEmpty()) {
					int curI = que.peek().i;
					int curJ = que.peek().j;
					int leftRange = que.poll().range;
					if(leftRange == 0)
						continue;
					for(int j = 1; j <= 4; j++) {
						int nextI = curI + moves[j][0];
						int nextJ = curJ + moves[j][1];
						if(nextI < 0 || nextI >= 10 || nextJ < 0 || nextJ >= 10 || visited[nextI][nextJ]) continue;
						visited[nextI][nextJ] = true;
						map[nextI][nextJ] += 1 << i;
						que.add(new Point(nextI, nextJ, leftRange-1));
					}
				}
			}
			
			int pe1_I = 0, pe1_J = 0;
			int pe2_I = 9, pe2_J = 9;
			for(int i = 0; i <= M; i++) {
				if((map[pe1_I][pe1_J] & map[pe2_I][pe2_J]) == 0) { // 서로 독립된 구간
					int res = 0;
					for(int k = 0; k < A; k++) {
						if((map[pe1_I][pe1_J] & (int)(Math.pow(2, k))) != 0) {
							res = Math.max(res, bc[k]);
						}
					}
					answer += res;
					res = 0;
					for(int k = 0; k < A; k++) {
						if((map[pe2_I][pe2_J] & (int)(Math.pow(2, k))) != 0) {
							res = Math.max(res, bc[k]);
						}
					}
					answer += res;
				}
				else {
					int pe1_idx = 0;
					int pe2_idx = 0;
					int pe1 = 0;
					int pe2 = 0;
					for(int k = 0; k < A; k++) {
						if((map[pe1_I][pe1_J] & (int)(Math.pow(2, k))) != 0) {
							if(pe1 < bc[k]) {
								pe1 = bc[k];
								pe1_idx = k;
							}
						}
						if((map[pe2_I][pe2_J] & (int)(Math.pow(2, k))) != 0) {

							if(pe2 < bc[k]) {
								pe2 = bc[k];
								pe2_idx = k;
							}
						}	
					}
					if(pe1_idx != pe2_idx) {
						answer += pe1 + pe2;
					}
					else {
						int p1 = 0;
						int p2 = 0;
						for(int k = 0; k < A; k++) {
							if(pe1_idx == k) continue;
							if((map[pe1_I][pe1_J] & (int)(Math.pow(2, k))) != 0) {
								if(p1 < bc[k]) {
									p1 = bc[k];
								}
							}
							if((map[pe2_I][pe2_J] & (int)(Math.pow(2, k))) != 0) {
								if(p2 < bc[k]) {
									p2 = bc[k];
								}
							}	
						}
						answer += Math.max(p1 + pe2, pe1 + p2);
					}
					
				}
				if(i < M) {
					pe1_I += moves[person[0][i]][0];
					pe1_J += moves[person[0][i]][1];
					pe2_I += moves[person[1][i]][0];
					pe2_J += moves[person[1][i]][1];
				}
			}
			
			System.out.println("#" + tc + " " + answer);
		}
	}
}
