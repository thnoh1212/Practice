import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static class shark {
		int s;
		int d;
		int z;
		public shark(int s, int d, int z) {
			this.s = s;
			this.d = d;
			this.z = z;
		}
		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] moves = {{-1,0},{1,0},{0,1},{0,-1}};
		String[] temp = br.readLine().split(" ");
		int answer = 0;
		int R = Integer.parseInt(temp[0]);
		int C = Integer.parseInt(temp[1]);
		int M = Integer.parseInt(temp[2]);
		shark[][] map = new shark[R][C];
		
		for(int i = 0; i < M; i++) {
			temp = br.readLine().split(" ");
			int r = Integer.parseInt(temp[0]) - 1;
			int c = Integer.parseInt(temp[1]) - 1;
			int s = Integer.parseInt(temp[2]);
			int d = Integer.parseInt(temp[3]) - 1;
			int z = Integer.parseInt(temp[4]);
			if((d == 0 || d == 1) && s > 2*R-2) {
				s %= (2*R-2);
			}
			else if((d == 2 || d == 3) && s > 2*C-2) {
				s %= (2*C-2);
			}
			map[r][c] = new shark(s, d, z);
		}
		int idx = 0;
		while(idx < C) {
			
			for(int i = 0; i < R; i++) {
				if(map[i][idx] != null) {
					answer += map[i][idx].z;
					map[i][idx] = null;
					break;
				}
			}
			shark[][] t_map = new shark[R][C];
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					if(map[i][j] != null) {
						int cI = i;
						int cJ = j;
						for(int k = 0; k < map[i][j].s; k++) {
							cI += moves[map[i][j].d][0];
							cJ += moves[map[i][j].d][1];
							if(cI < 0 || cI >= R || cJ < 0 || cJ >= C) {
								cI -= moves[map[i][j].d][0];
								cJ -= moves[map[i][j].d][1];
								if(map[i][j].d % 2 == 0) map[i][j].d += 1;
								else map[i][j].d -= 1;
								k--;
							}
						}
						
						if(t_map[cI][cJ] == null)
							t_map[cI][cJ] = new shark(map[i][j].s, map[i][j].d, map[i][j].z);
						else {
							if(map[i][j].z > t_map[cI][cJ].z) 
								t_map[cI][cJ] = new shark(map[i][j].s, map[i][j].d, map[i][j].z);
						}
					}
				}
			}
			
			for(int i = 0; i < R; i++) {
				for(int j = 0; j < C; j++) {
					if(t_map[i][j] == null)
						map[i][j] = null;
					else
						map[i][j] = new shark(t_map[i][j].s, t_map[i][j].d, t_map[i][j].z);
				}
			}
			idx++;
		}
		System.out.println(answer);
	}
}
