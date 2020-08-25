/*
 * 벽 부수고 이동하기4(16946)
 * 
 * 모든 벽에 대하여 BFS를 실행하면 시간초과 발생
 * 벽으로 인해 나눠진 영역들의 넓이를 미리 계산한 후
 * 각 벽에 대하여 주위 4방향을 탐색, 인접한 영역의 넓이를 모두 더해준 후 현재 위치의 벽이 부서졌으므로 +1 추가
 * 
 * 벽의 두 면이 하나의 영역과 인접해 있는 경우 4방향을 탐색하여 더해준다면 하나의 영역이 두번 더해지는 오류 발생
 * 이를 해결하기 위해 MAP배열에 각 영역을 2 이상의 숫자로 마킹하여 영역을 나타내고, 해당 영역의 넓이를 chk배열에 저장
 * 그 후 벽을 기준으로 탐색하는 과정에서 Set을 사용하여 중복값을 제거.
 */

import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main16946 {
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
