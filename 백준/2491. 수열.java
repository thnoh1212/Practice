package algo_0924;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main2491 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] arr = new int [N];
		int answer = 1;
		String[] temp = br.readLine().split(" ");
		for(int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(temp[i]);
		
		for(int i = 0; i < N-1; i++) {
			int flag = 1;
			//1은 같은경우, 2는 커짐, 3은 작아짐
			if(arr[i] > arr[i+1])
				flag = 3;
			else if(arr[i] < arr[i+1])
				flag = 2;
			int cnt = 1;
			if(answer > N - i) break;
			for(int j = i; j < N-1; j++) {
				if(arr[j] == arr[j+1] && flag == 1) 
					cnt++;
				else if(arr[j] >= arr[j+1] && (flag == 1 || flag == 3)) {
					flag = 3;
					cnt++;
				}
				else if(arr[j] <= arr[j+1] && (flag == 1 || flag == 2)) {
					flag = 2;
					cnt++;
				}
				else {
					answer = Math.max(cnt, answer);
					break;
				}
			}
			answer = Math.max(cnt, answer);
		}
		System.out.println(answer);
		br.close();
	}
}
