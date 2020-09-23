package algo_0923;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[][] map = new int[100][100];
		int sum = 0;
		int N = sc.nextInt();
		
		for(int i = 0; i < N; i++) {
			int x = sc.nextInt()-1;
			int y = sc.nextInt()-1;
			for(int k = x; k < x+10; k++) {
				for(int l = y; l < y+10; l++) {
					map[k][l] = 1;
				}
			}
		}
		
		for(int i = 0; i < 100; i++) {
			for(int j = 0; j < 100; j++) {
				if(map[i][j] == 0)
					sum += 1;
			}
		}
		System.out.println(10000 - sum);
		sc.close();
	}
}
