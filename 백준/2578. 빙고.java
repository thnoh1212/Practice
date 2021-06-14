package algo_0923;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main2578 {
	static int[][] p;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		p = new int[5][5];
		int[][] chk = new int[5][5];
		int answer = 10;
		for(int i = 0; i < 5; i++) {
			String[] temp = br.readLine().split(" ");
			for(int j = 0; j < 5; j++) {
				p[i][j] = Integer.parseInt(temp[j]);
			}
		}
		
		for(int i = 0; i < 5; i++) {
			String[] temp = br.readLine().split(" ");
			for(int j = 0; j < 5; j++) {
				chk[i][j] = Integer.parseInt(temp[j]);
			}
		}
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 5; j++) {
				for(int k = 0; k < 5; k++) {
					for(int l = 0; l < 5; l++) {
						if(chk[i][j] == p[k][l])
							p[k][l] = 0;
					}
				}
			}
		}
		top:
		for(int i = 2; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				for(int k = 0; k < 5; k++) {
					for(int l = 0; l < 5; l++) {
						if(chk[i][j] == p[k][l]) {
							p[k][l] = 0;
							answer++;
							boolean flag = findBingo();
							if(flag)
								break top;
						}
					}
				}
			}
		}
		System.out.println(answer);
	}
	public static boolean findBingo() {
		int cnt = 0;
		for(int i = 0; i < 5; i++) {
			int sumx = p[i][0] + p[i][1] + p[i][2] + p[i][3] + p[i][4];
			int sumy = p[0][i] + p[1][i] + p[2][i] + p[3][i] + p[4][i];
			if(sumx == 0) cnt++;
			if(sumy == 0) cnt++;
			if(cnt >= 3)
				return true;
		}
		int sumd1 = p[0][0] + p[1][1] + p[2][2] + p[3][3] + p[4][4];
		int sumd2 = p[4][0] + p[3][1] + p[2][2] + p[1][3] + p[0][4];
		if(sumd1 == 0) cnt++;
		if(sumd2 == 0) cnt++;
		if(cnt >= 3)
			return true;
		return false;
	}
}
