package algo_0927;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[][] triangle = new int[500][500];
		int[][] answer = new int[500][500];
		int res = 0;
		int N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < N; i++) {
			String[] temp = br.readLine().split(" ");
			for(int j = 0; j <= i; j++) {
				triangle[i][j] = Integer.parseInt(temp[j]);
			}
		}
		answer[0][0] = triangle[0][0];
		for(int i = 1; i < N; i++) {
			for(int j = 0; j <= i; j++) {
				if(j == 0)
					answer[i][j] = triangle[i][j] + answer[i-1][j];
				else if(j == i)
					answer[i][j] = triangle[i][j] + answer[i-1][j-1];
				else
					answer[i][j] = triangle[i][j] + Math.max(answer[i-1][j-1], answer[i-1][j]);
			}
		}
		
		
		for(int i = 0; i < N; i++) 
			res = Math.max(res, answer[N-1][i]);
		
		System.out.println(res);
	}
}
