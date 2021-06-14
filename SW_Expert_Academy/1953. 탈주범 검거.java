package algo_1103;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	public static class Point{
		int x;
		int y;
		int time;
		public Point(int x, int y, int time) {
			this.x = x;
			this.y = y;
			this.time = time;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int[][][] moves = {{{1,0},{0,1},{-1,0},{0,-1}}, // 상하좌우
							{{-1,0},{1,0},{0,0},{0,0}}, // 상 하
							{{0,-1},{0,1},{0,0},{0,0}}, // 좌 우
							{{-1,0},{0,1},{0,0},{0,0}}, // 상 우
							{{1,0},{0,1},{0,0},{0,0}},  // 하 우
							{{1,0},{0,-1},{0,0},{0,0}}, // 하 좌
							{{-1,0},{0,-1},{0,0},{0,0}} // 상 좌
							};
		for(int tc = 1; tc <= T; tc++) {
			int N, M, R, C, L;
			int answer = 0;
			String[] temp = br.readLine().split(" ");
			N = Integer.parseInt(temp[0]);
			M = Integer.parseInt(temp[1]);
			R = Integer.parseInt(temp[2]);
			C = Integer.parseInt(temp[3]);
			L = Integer.parseInt(temp[4]);
			int[][] map = new int[N][M];
			boolean[][] visited = new boolean[N][M];
			for(int i = 0; i < N; i++) {
				temp = br.readLine().split(" ");
				for(int j = 0; j < M; j++) {
					map[i][j] = Integer.parseInt(temp[j]);
				}
			}
			Queue<Point> que = new LinkedList<>();
			que.add(new Point(R, C, L));
			visited[R][C] = true;
			while(!que.isEmpty()) {
				int cI = que.peek().x;
				int cJ = que.peek().y;
				int cL = que.poll().time;
				if(cL == 1) continue;
				int dir = map[cI][cJ] - 1;
				for(int i = 0; i < 4; i++) {
					if(moves[dir][i][0] == moves[dir][i][1]) break;
					int nI = cI + moves[dir][i][0];
					int nJ = cJ + moves[dir][i][1];
					if(nI < 0 || nI >= N || nJ < 0 || nJ >= M || map[nI][nJ] == 0 || visited[nI][nJ]) continue;
					int nDir = map[nI][nJ] - 1;
					boolean flag = false;
					for(int j = 0; j < 4; j++) {
						if(moves[dir][i][0] == -1 * moves[nDir][j][0] &&
								moves[dir][i][1] == -1 * moves[nDir][j][1]) flag = true;
					}
					if(flag) {
						que.add(new Point(nI, nJ, cL - 1));
						visited[nI][nJ] = true;
					}
				}
			}
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(visited[i][j]) answer += 1;
				}
			}
			System.out.println("#" + tc + " " + answer);
		}
	}
}
