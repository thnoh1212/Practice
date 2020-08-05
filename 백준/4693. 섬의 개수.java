import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.StringTokenizer;
import java.util.LinkedList;


class Main
{
	public static void main(String args[]) throws Exception
	{
		int[][] moves = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String Numbers = br.readLine();
		StringTokenizer st = new StringTokenizer(Numbers, " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		while(N != 0) {
			int count = 0;
			int[][] map = new int[M][N];
			boolean[][] check = new boolean[M][N];
			Queue<Point> island = new LinkedList<>();
			for(int i = 0; i < M; i++) {
				Numbers = br.readLine();
				st = new StringTokenizer(Numbers, " ");
				for(int j = 0; j < N; j++)
					map[i][j] = Integer.parseInt(st.nextToken());
			}
			for(int i = 0; i < M; i++) {
				for(int j = 0; j < N; j++) {
					if(!check[i][j] && map[i][j] == 1) {
						count++;
						island.add(new Point(i,j));
						check[i][j] = true;
						while(!island.isEmpty()) {
							int cur_i = island.peek().x;
							int cur_j = island.peek().y;
							island.poll();
							for(int k = 0; k < 8; k++) {
								int next_i = cur_i + moves[k][0];
								int next_j = cur_j + moves[k][1];
								if(next_i >= 0 && next_j >= 0 && next_i < M && next_j < N) {
									if(map[next_i][next_j] == 1 && !check[next_i][next_j]) {
										check[next_i][next_j] = true;
										island.add(new Point(next_i,next_j));
									}
								}
							}
						}
					}
				}
			}
			System.out.println(count);
			Numbers = br.readLine();
			st = new StringTokenizer(Numbers, " ");
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
		}
	}
}
