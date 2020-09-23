package algo_0923;

import java.util.Arrays;
import java.util.Scanner;

public class Main2309 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int[] answer = new int[9];
		int[] arr = new int[9];
		for(int i = 0; i < 9; i++)
			arr[i] = sc.nextInt();
	
		end:
		for(int i = 0; i < 8; i++) {
			for(int j = i+1; j < 9; j++) {
				int sum = 0;
				for(int k = 0; k < 9; k++) {
					if(k == i || k == j) continue;
					sum += arr[k];
				}
				if(sum == 100){
					for(int k = 0; k < 9; k++) {
						if(k == i || k == j) continue;
						answer[k] = arr[k];
					}
					break end;
				}
						
			}
		}
		Arrays.sort(answer);
		for(int i = 2; i < 9; i++) {
			System.out.println(answer[i]);
		}
	}
}
