import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	static int[][] answer;
	static boolean findAnswer;
	static int depth;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] board = new int[9][9];
		answer = new int[9][9];
		depth = 0;
		findAnswer = false;
		for(int i = 0; i < 9; i++) {
			String temp = br.readLine();
			for(int j = 0; j < 9; j++) {
				board[i][j] = temp.charAt(j) - '0';
				if(board[i][j] == 0) depth++;
			}
		}
		
		dfs(board, 0);
		
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				System.out.print(answer[i][j]);
			}
			System.out.println();
		}
	}
	
	static void dfs(int[][] board, int cnt) {
		if(findAnswer) return;
		if(cnt == depth) {
			findAnswer = true;
			for(int i = 0; i < 9; i++) {
				for(int j = 0; j < 9; j++)
					answer[i][j] = board[i][j];
			}
			return;
		}
		int[][] t_board = new int[9][9];
		
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				t_board[i][j] = board[i][j];
			}
		}
		
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(t_board[i][j] == 0) {
					boolean[] chk = new boolean[10];
					for(int k = 0; k < 9; k++) {
						chk[t_board[i][k]] = true;
						chk[t_board[k][j]] = true;
					}
					int tI = 0;
					int tJ = 0;
					if(i < 3) tI = 3;
					else if(i < 6) tI = 6;
					else tI = 9;
					if(j < 3) tJ = 3;
					else if(j < 6) tJ = 6;
					else tJ= 9;
					
					for(int k = tI - 3; k < tI; k++) {
						for(int l = tJ - 3; l < tJ; l++) {
							chk[t_board[k][l]] = true;
						}
					}
					
					for(int k = 1; k <= 9; k++) {
						if(!chk[k]) {
							t_board[i][j] = k;
							dfs(t_board, cnt + 1);
						}
					}
					return;
				}
			}
		}
	}
}
