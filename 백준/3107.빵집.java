import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main3109 {
	static int[][] moves = {{-1, 1}, {0, 1}, {1,1}};
	static char[][] map;
	static boolean[][] visited;
	static int R;
	static int C;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int answer = 0;
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		map = new char[R][];
		visited = new boolean[R][C];
		for(int i = 0; i < R ; i++) 
			map[i] = br.readLine().toCharArray();
		
		for(int i = 0; i < R; i++) {
			visited[i][0] = true;
			answer += dfs(i, 0);
		}
		System.out.println(answer);
	}
	
	static int dfs(int i, int j) {
		
		if(j == C-1) 
			return 1;
		for(int k = 0; k < 3; k++) {
			int next_i = i + moves[k][0];
			int next_j = j + moves[k][1];
			if(next_i < 0 || next_i >= R || map[next_i][next_j] == 'x' || visited[next_i][next_j]) continue;
			visited[i][j] = true;
			if(dfs(next_i, next_j) == 1) return 1;
		}
		return 0;
	}
}
