import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][M];
		boolean[][] chk = new boolean[N][M];
		
		int[][] moves = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
		int answer = 0;
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		Queue<Point> que = new LinkedList<>();
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(map[i][j] == 1 && !chk[i][j]) {
					que.add(new Point(i,j));
					chk[i][j] = true;
					answer++;
					while(!que.isEmpty()) {
						int cur_i = que.peek().x;
						int cur_j = que.poll().y;
						for(int k = 0; k < 8; k++) {
							int next_i = cur_i + moves[k][0];
							int next_j = cur_j + moves[k][1];
							if(next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
								if(map[next_i][next_j] == 1 && !chk[next_i][next_j]) {
									chk[next_i][next_j] = true;
									que.add(new Point(next_i, next_j));
								}
							}
						}
					}
				}
			}
		}
		System.out.println(answer);
		
	}
}
