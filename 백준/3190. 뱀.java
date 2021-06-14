import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Main {
	public static class turnDir{
		int time;
		String dir;
		public turnDir(int time, String temp) {
			super();
			this.time = time;
			this.dir = temp;
		}
	}
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int K = Integer.parseInt(br.readLine());
		int[][] map = new int[N][N];
		int[][] moves = {{0,1},{1,0},{0,-1},{-1,0}};
		// 오른쪽 -> 증가, 왼쪽 -> 감소
		// 사과 = 1, 뱀 = 2, 공백 = 0;
		for(int i = 0; i < K; i++) {
			String[] temp = br.readLine().split(" ");
			map[Integer.parseInt(temp[0])-1][Integer.parseInt(temp[1])-1] = 1;
		}
		
		int L = Integer.parseInt(br.readLine());
		List<turnDir> list = new ArrayList<>();
		for(int i = 0; i < L; i++) {
			String[] temp = br.readLine().split(" ");
			list.add(new turnDir(Integer.parseInt(temp[0]), temp[1]));
		}
		int time = 0;
		int idx = 0;
		int dir = 0;
		int curI = 0, curJ = 0;
		Queue<Point> snake = new LinkedList<>();
		snake.add(new Point(0,0));
		map[0][0] = 2;
		while(true) {
			//시간 증가
			time++;
			// 뱀 이동
			curI += moves[dir][0];
			curJ += moves[dir][1];
			if(curI < 0 || curI >= N || curJ < 0 || curJ >= N || map[curI][curJ] == 2) {
				System.out.println(time);
				break;
			}
			else if(map[curI][curJ] == 0) {
				int delI = snake.peek().x;
				int delJ = snake.poll().y;
				map[delI][delJ] = 0;
				map[curI][curJ] = 2;
				snake.add(new Point(curI, curJ));
			}
			else {
				map[curI][curJ] = 2;
				snake.add(new Point(curI, curJ));
			}
			
			if(idx < list.size() && list.get(idx).time == time) {
				if(list.get(idx).dir.equals("L")) {
					dir -= 1;
					if(dir < 0)
						dir += 4;
				}
				else {
					dir += 1;
					if(dir > 3)
						dir -= 4;
				}
				idx++;
			}
		}

	}
}
