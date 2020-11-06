import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {
	public static class Point{
		int x;
		int y;
		int dir;
		List<Integer> cnt;
		public Point(int x, int y, int dir, List<Integer> cnt) {
			this.x = x;
			this.y = y;
			this.dir = dir;
			this.cnt = new ArrayList<>(cnt);
		}
		
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int moves[][] = {{1,-1},{1,1},{-1,1},{-1,-1}};
		for(int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			int[][] map = new int[N][N];
			int answer = 0;
			for(int i = 0; i < N; i++) {
				String[] temp = br.readLine().split(" ");
				for(int j = 0; j < N; j++) {
					map[i][j] = Integer.parseInt(temp[j]);
				}
			}
			
			for(int i = 0; i < N-2; i++) {
				for(int j = 1; j < N-1; j++) {
					Queue<Point> que = new LinkedList<>();
					List<Integer> start = new ArrayList<>();
					start.add(map[i][j]);
					que.add(new Point(i, j, 0, start));
					while(!que.isEmpty()) {
						int cI = que.peek().x;
						int cJ = que.peek().y;
						int dir = que.peek().dir;
						List<Integer> cnt = que.poll().cnt;
						if(dir == 4) continue;
						if(cnt.size() == 1) {
							int nI = cI + moves[dir][0];
							int nJ = cJ + moves[dir][1];
							if(cnt.contains(map[nI][nJ])) continue;
							cnt.add(map[nI][nJ]);
							que.add(new Point(nI, nJ, dir, cnt));
						}
						else {
							for(int k = 0; k <= 1; k++) {
								if(dir + k >= 4) break;
								int nI = cI + moves[dir+k][0];
								int nJ = cJ + moves[dir+k][1];
								
								if(nI < 0 || nI >= N || nJ < 0 || nJ >= N) continue;
								if(cnt.size() != 1 && nI == i && nJ == j) {
									answer = Math.max(answer, cnt.size());
									System.out.println(cnt);
									continue;
								}
								if(cnt.contains(map[nI][nJ])) continue;
								cnt.add(map[nI][nJ]);
								que.add(new Point(nI, nJ, dir + k, cnt));
								cnt.remove(cnt.size()-1);
							}
						}
					}
				}
			}
			if(answer == 0)
				answer = -1;
			System.out.println("#" + tc + " " + answer);
		}
	}
}
//배고파요 보내주세요
