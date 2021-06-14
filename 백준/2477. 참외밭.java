package algo_0924;

import java.awt.Point;
import java.util.Scanner;

public class Main2477 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int answer = 0;
		Point[] arr = new Point[6];
		int maxWidth = 0, maxHeight = 0;
		for(int i = 0; i < 6; i++) {
			int temp1 = sc.nextInt();
			int temp2 = sc.nextInt();
			arr[i] = new Point(temp1, temp2);
			if((arr[i].x == 1 || arr[i].x == 2) && arr[i].y > maxWidth) 
				maxWidth = arr[i].y;
			else if((arr[i].x == 3 || arr[i].x == 4) && arr[i].y > maxHeight)
				 maxHeight = arr[i].y;
		}
		
		for(int i = 0; i < 6; i++) {
			int temp = (i+1)%6;
			answer += arr[i].y * arr[temp].y;
		}
		int less = answer - (maxWidth * maxHeight * 2);
		less = maxWidth * maxHeight - less;
		answer = (maxWidth * maxHeight - less) * N;
		System.out.println(answer);
		
		sc.close();
	}
}
