import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class cur_pos{
	int i;
	int j;
	String chk;
	public cur_pos(int i, int j, String chk){
		this.i = i;
		this.j = j;
		this.chk = chk;
	}
}

public class Main {
	static int R;
	static int C;
	static int answer;
	static char[][] board;
	static int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
	public static void main(String[] args) throws Exception {
		answer = 0;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		board = new char[R][];
		for(int i = 0; i < R; i++)
			board[i] = br.readLine().toCharArray();
		String temp = "";
		temp += board[0][0];	
		dfs(0, 0, temp);
		
		System.out.println(answer);
	}
	static void dfs(int i, int j, String chk) {

		answer = (answer > chk.length()) ? answer : chk.length();
		for(int k = 0; k < 4; k++) {
			int next_i = i + moves[k][0];
			int next_j = j + moves[k][1];
			if(next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) continue;
			
			String temp = "";
			temp += board[next_i][next_j];
			if(!chk.contains(temp)) 
				dfs(next_i, next_j, chk + temp);
		}
	}

}
// bfs사용 --> 메모리 초과 발생
//Queue<cur_pos> que = new LinkedList<>();
//String temp = "";
//temp += board[0][0];
//que.add(new cur_pos(0, 0, temp));
//while(!que.isEmpty()) {
//	int i = que.peek().i;
//	int j = que.peek().j;
//	String chk = que.poll().chk;
//	answer = (answer > chk.length()) ? answer : chk.length();
//	for(int k = 0; k < 4; k++) {
//		int next_i = i + moves[k][0];
//		int next_j = j + moves[k][1];
//		if(next_i < 0 || next_i >= R || next_j < 0 || next_j >= C) continue;
//		
//		if(!chk.contains(String.valueOf(board[next_i][next_j]))) 
//			que.add(new cur_pos(next_i, next_j, chk + board[next_i][next_j]));
//	}
//}
