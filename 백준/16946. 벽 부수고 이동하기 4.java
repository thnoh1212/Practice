import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][M];
		int[][] answer = new int[N][M];
		int[][] moves = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };

		for (int i = 0; i < N; i++) {
			String temp = br.readLine();
			for (int j = 0; j < M; j++) {
				map[i][j] = temp.charAt(j) - '0';
				answer[i][j] = 0;
			}
		}
		int cnt = 2;
		int[] chk = new int[1000002];
		
		Queue<Point> que = new LinkedList<>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					map[i][j] = cnt;
					int num = 1;
					que.add(new Point(i, j));
					while(!que.isEmpty()) {
						int cur_i = que.peek().x;
						int cur_j = que.poll().y;
						for(int k = 0; k < 4; k++) {
							int next_i = cur_i + moves[k][0];
							int next_j = cur_j + moves[k][1];
							if(next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
								if(map[next_i][next_j] == 0) {
									map[next_i][next_j] = cnt;
									num++;
									que.add(new Point(next_i, next_j));
								}
							}
						}
					}
					chk[cnt++] = num%10;
				}
			}
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(map[i][j] == 1) {
					Set<Integer> temp = new HashSet<>();
					int sum = 1;
					for(int k = 0; k < 4; k++) {
						int next_i = i + moves[k][0];
						int next_j = j + moves[k][1];
						if(next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
							if(!temp.contains(map[next_i][next_j]) && map[next_i][next_j] != 1) {
								temp.add(map[next_i][next_j]);
							}
						}
					}
					for(int t : temp){
						sum += chk[t];
					}
					answer[i][j] = sum%10;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				System.out.print(answer[i][j]);
			}
			System.out.println();
		}

	}
}
