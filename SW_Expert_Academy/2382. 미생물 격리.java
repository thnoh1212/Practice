import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.StringTokenizer;

class Solution
{
	static class microbe{
		int i;
		int j;
		int cnt;
		int dir;
		public microbe(int i, int j, int cnt, int dir) {
			this.i = i;
			this.j = j;
			this.cnt = cnt;
			this.dir = dir;
		}
	}
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int K = Integer.parseInt(st.nextToken());
			int[][] map = new int[N][N];
			ArrayList<microbe> info = new ArrayList<>();
			
			for(int i = 0; i < K; i++) {
				st = new StringTokenizer(br.readLine(), " ");
				int temp_i = Integer.parseInt(st.nextToken());
				int temp_j = Integer.parseInt(st.nextToken());
				int temp_cnt = Integer.parseInt(st.nextToken());
				int temp_dir = Integer.parseInt(st.nextToken());
				info.add(new microbe(temp_i, temp_j, temp_cnt, temp_dir));
				map[temp_i][temp_j] = 1;
			}
			
			while(M > 0) {
				M--;
				ArrayList<Point> temp = new ArrayList<>();
				for(microbe m : info) { // 이동작업
					switch(m.dir) {
					case 1: // 상
						map[m.i][m.j] -= 1;
						m.i -= 1;
						map[m.i][m.j] += 1;
						if(m.i == 0) {
							m.cnt /= 2;
							m.dir = 2;
						}
						break;
					case 2: // 하
						map[m.i][m.j] -= 1;
						m.i += 1;
						map[m.i][m.j] += 1;
						if(m.i == N-1) {
							m.cnt /= 2;
							m.dir = 1;
						}
						break;
					case 3: // 좌
						map[m.i][m.j] -= 1;
						m.j -= 1;
						map[m.i][m.j] += 1;
						if(m.j == 0) {
							m.cnt /= 2;
							m.dir = 4;
						}
						break;
					case 4: // 우
						map[m.i][m.j] -= 1;
						m.j += 1;
						map[m.i][m.j] += 1;
						if(m.j == N-1) {
							m.cnt /= 2;
							m.dir = 3;
						}
						break;
					}
				}
				
				for(int i = 1; i < N-1; i++) { // 미생물 군집간 합 연산 필요 여부 확인
					for(int j = 1; j < N-1; j++) {
						if(map[i][j] > 1) {
							temp.add(new Point(i, j));
						}
					}
				}
				if(temp.size() != 0) {
					for(Point pos : temp) {
						int i = pos.x;
						int j = pos.y;
						int cnt = 0;
						int dir = 0;
						int max = 0;
						for(Iterator<microbe> it = info.iterator();it.hasNext();) {
							microbe m = it.next();
							if(m.i == i && m.j == j) {
								cnt += m.cnt;
								if(max < m.cnt) {
									max = m.cnt;
									dir = m.dir;
								}
								it.remove();
							}
						}
						info.add(new microbe(i, j, cnt, dir));
					}
				}
			}
			int answer = 0;
			for(microbe m : info)
				answer += m.cnt;
			System.out.println("#" + test_case + " " + answer);
			
		}
		br.close();
	}
}
