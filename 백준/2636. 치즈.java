import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}}; // 4방향 탐색용 배열
		String[] temp = br.readLine().split(" ");
		int N = Integer.parseInt(temp[0]);
		int M = Integer.parseInt(temp[1]);
		int total = 0; // 총 치즈 개수를 저장할 변수
		int answer = 0; // 지난 시간을 저장할 변수
		int cnt = 0; // 이번 시간에 녹아서 사라지는 치즈를 저장할 변수
		int[][] map = new int[N][M];
		for(int i = 0; i < N; i++) {
			temp = br.readLine().split(" ");
			for(int j = 0; j < M; j++) {
				map[i][j] = Integer.parseInt(temp[j]);
				if(map[i][j] == 1)
					total++;
			}
		}
		
		while(total != 0) {
			cnt = 0; // cnt값 초기화
			answer += 1; // 1시간 증가
			int[][] t_map = new int[N][M];
			boolean[][] visited = new boolean[N][M];
			Queue<Point> bfs = new LinkedList<>();
			bfs.add(new Point(0, 0)); // {0,0}은 절대 치즈가 놓이지 않고, 반드시 외부공간임
			visited[0][0] = true;
			while(!bfs.isEmpty()) {
				int cur_i = bfs.peek().x;
				int cur_j = bfs.poll().y;
				for(int i = 0; i < 4; i++) {
					int next_i = cur_i + moves[i][0];
					int next_j = cur_j + moves[i][1];
					if(next_i < 0 || next_i >= N || next_j < 0 || next_j >= M || visited[next_i][next_j]) continue;
					visited[next_i][next_j] = true;
					
					// 만약 빈 공간이면 bfs에 추가
					if(map[next_i][next_j] == 0) bfs.add(new Point(next_i, next_j));
					// 주변 공간에 치즈가 있다면, 공기에 접촉한 치즈이므로 t_map에 표시
					else if(map[next_i][next_j] == 1) {
						cnt++;	
						t_map[next_i][next_j] = 1;
					}
				}
			}
			if(cnt == total) { // 이번에 녹는경우 다 사라지면
				System.out.println(answer);
				System.out.println(cnt);
				break;
			}
			for(int i = 0; i < N; i++) { // 치즈를 녹이는 작업
				for(int j = 0; j < M; j++) {
					if(t_map[i][j] == 1)
						map[i][j] = 0;
				}
			}
			// 녹인 치즈만큼 전체값에서 제거
			total -= cnt;
		}
	}
}
