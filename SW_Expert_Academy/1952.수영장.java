import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	public static void main(String[] args) throws Exception, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			int[] costs = new int[4];
			int[] month = new int[13];
			int[] answer = new int[13];
			String[] temp = br.readLine().split(" ");
			for(int i = 0; i < 4; i++)
				costs[i] = Integer.parseInt(temp[i]);
			temp = br.readLine().split(" ");
			for(int i = 1; i <= 12; i++) {
				month[i] = Math.min(costs[1], Integer.parseInt(temp[i-1]) * costs[0]);
			}
			for(int i = 1; i <= 12; i++) {
				if(i - 3 >= 0) 
					answer[i] = Math.min(answer[i-1] + month[i], answer[i-3] + costs[2]);
				else
					answer[i] = answer[i-1] + month[i];
			}
			answer[12] = Math.min(answer[12], costs[3]);
			
			System.out.println("#" + tc + " " + answer[12]);
		}
	}
}
