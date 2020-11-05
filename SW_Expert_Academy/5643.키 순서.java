import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	
	static boolean[] chk;
	static int[][] magnets;
	static int[][] magnetPos;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			int K = Integer.parseInt(br.readLine());
			int answer = 0;
			magnets = new int[4][8];
			magnetPos = new int[4][3];
			for(int i = 0; i < 4; i++){
				magnetPos[i][0] = 0;
				magnetPos[i][1] = 2;
				magnetPos[i][2] = 6;
			}
			for(int i = 0; i < 4; i++) {
				String[] temp = br.readLine().split(" ");
				for(int j = 0; j < 8; j++) {
					magnets[i][j] = Integer.parseInt(temp[j]);
				}
			}
			
			for(int i = 0; i < K; i++) {
				chk = new boolean[4];
				String[] temp = br.readLine().split(" ");
				int idx = Integer.parseInt(temp[0]) - 1;
				int dir = Integer.parseInt(temp[1]);
				dfs(idx);
				rotate(idx, -1 * dir);
			}
			for(int i = 0; i < 4; i++) {
				if(magnets[i][magnetPos[i][0]] == 1)
					answer += (int)Math.pow(2, i);
			}
			System.out.println("#" + tc + " " + answer);
		}
	}
	static void dfs(int idx) {
		if(idx == -1 || idx == 4) return;
		if(chk[idx]) return;
		chk[idx] = true;
		if(idx == 0) {
			if(right_chk(idx))  dfs(idx + 1);
		}
		else if(idx == 3) {
			if(left_chk(idx)) dfs(idx - 1);
		}
		else {
			if(right_chk(idx)) dfs(idx + 1);
			if(left_chk(idx)) dfs(idx - 1);
		}
	}
	
	static void rotate(int idx, int dir) {
		if(idx == -1 || idx == 4) return;
		if(!chk[idx]) return;
		chk[idx] = false;
		for(int i = 0; i < 3; i++) {
			magnetPos[idx][i] += dir;
			if(magnetPos[idx][i] < 0) magnetPos[idx][i] = 7;
			if(magnetPos[idx][i] > 7) magnetPos[idx][i] = 0;
		}
		rotate(idx + 1, dir * -1);
		rotate(idx - 1, dir * -1);
	}
	
	static boolean right_chk(int idx) {
		if(magnets[idx][magnetPos[idx][1]] != magnets[idx+1][magnetPos[idx+1][2]])
			return true;
		return false;
	}
	static boolean left_chk(int idx) {
		if(magnets[idx][magnetPos[idx][2]] != magnets[idx-1][magnetPos[idx-1][1]])
			return true;
		return false;
	}
}
