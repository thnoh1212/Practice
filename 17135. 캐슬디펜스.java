import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

class Pos{
	int x, y;
	public Pos(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class Pos2{
	int x, y, count;
	public Pos2(int x, int y, int count) {
		this.x = x;
		this.y = y;
		this.count = count;
	}
}

public class Main {
	
	static int answer = 0;
	static int[][] arr;
	static int[][] temp_arr;
	static boolean[] chk;
	static int [][]moves = {{0,-1}, {-1,0}, {0,1}};
	static int N;
	static int M;
	static int range;
	static int cnt;
	static int qwe = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st =  new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		range = Integer.parseInt(st.nextToken());
		cnt = N * M;
		
		arr = new int[N+1][M];
		temp_arr = new int[N+1][M];
		chk = new boolean[M];
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for(int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
				temp_arr[i][j] = arr[i][j];
				if(arr[i][j] == 0)
					cnt-= 1;
			}
		}
		if(cnt != 0)
			dfs(0, 0);
		System.out.println(answer);
	}
	
	public static void dfs(int count, int index) {
		if(cnt == answer)
			return;
		if(count == 3){
			for(int i = 0; i <= N; i++)
				for(int j = 0; j < M; j++)
					temp_arr[i][j] = arr[i][j];
			int res = solve();
			answer = Math.max(res, answer);
			
		}
		else {
			for(int i = index; i < M; i++) {
				if(chk[i]) continue;
				else {
					chk[i] = true;
					arr[N][i] = 2;
					dfs(count + 1, i);
					arr[N][i] = 0;
					chk[i] = false;
				}
			}
		}
	}
	public static int solve() {
		int kill = 0;
		int height = N;
		System.out.println(qwe++);
		while(height > 0) {
			if(cnt == kill) break;
			Queue<Pos> kills = new LinkedList<>();
			Queue<Pos> Archers = new LinkedList<>();
			for(int i = 0; i < M; i++) {
				if(temp_arr[height][i] == 2) { 
					Archers.add(new Pos(height, i));
				}
			}
			while(!Archers.isEmpty()) {
				Queue<Pos2> Archers_kill = new LinkedList<>();
				int arc_xpos = Archers.peek().x;
				int arc_ypos = Archers.peek().y;
				Archers_kill.add(new Pos2(arc_xpos, arc_ypos, 0));
				
				Archers.poll();
				boolean flag = true;
				while(!Archers_kill.isEmpty() && flag) {
					boolean[][] test = new boolean[N+1][M];
					int cur_x = Archers_kill.peek().x;
					int cur_y = Archers_kill.peek().y;
					int t_cnt = Archers_kill.peek().count;
					test[cur_x][cur_y] = true;
					Archers_kill.poll();
					if((Math.abs(arc_ypos - cur_y) + Math.abs(arc_xpos - cur_x)) >= range) break;
					for(int k = 0; k < 3; k++) {
						int next_x = cur_x + moves[k][0];
						int next_y = cur_y + moves[k][1];
						if(next_y >= 0 && next_y < M && next_x >= 0) {							
							if(temp_arr[next_x][next_y] == 1) {							
								kills.add(new Pos(next_x, next_y));
								flag = false;
								break;
							}
							else {
								if(!test[next_x][next_y] && t_cnt <= range && temp_arr[next_x][next_y] != 2) {
									test[next_x][next_y] = true;
									Archers_kill.add(new Pos2(next_x, next_y, t_cnt + 1));
								}
							}
								
						}
					}
				}
				
				while(!Archers_kill.isEmpty())
					Archers_kill.poll();
			}
			while(!kills.isEmpty()) {
				if(temp_arr[kills.peek().x][kills.peek().y] == 1) {
					kill += 1;
					temp_arr[kills.peek().x][kills.peek().y] = 0;
				}
				kills.poll();
			}
			
			
			for(int i = 0; i < M; i++) {
				if(temp_arr[height][i] == 2)
					temp_arr[height-1][i] = 2;
				else
					temp_arr[height-1][i] = 0;
			}
			height -= 1;
			
		}
		return kill;
	}
}
