import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution
{
	static int[][] arr;
	static int answer;
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = Integer.parseInt(br.readLine());           
            arr = new int[N][N];
            answer = Integer.MAX_VALUE;
            boolean[] visited = new boolean[N];
            int[] food = new int[N];
            for(int i = 0; i < N; i++) {
            	food[i] = i + 1;
            	String[] temp = br.readLine().split(" ");
            	for(int j = 0; j < N; j++) {
            		arr[i][j] = Integer.parseInt(temp[j]);
            	}
            }   
            combination(food, visited, 0, N, N/2);
            System.out.println("#" + test_case + " " + answer);
		}
	}
	static void combination(int[] food, boolean[] visited, int start, int N, int r) {
		if(r == 0) {
			Calc(food, visited, N);
			return;
		}
		
		for(int i = start; i < N; i++) {
			visited[i] = true;
			combination(food, visited, i+1, N, r-1);
			visited[i] = false;
		}
	}
	static void Calc(int[] food, boolean[] visited, int N) {
		int[] food1 = new int[N/2];
		int[] food2 = new int[N/2];
		int idx1 = 0, idx2 = 0;
		for (int i = 0; i < N; i++) {
			 if (visited[i]) 
				 food1[idx1++] = food[i];
			 else
				 food2[idx2++] = food[i];
		}
		
		int taste1 = 0;
		int taste2 = 0;
		for(int i = 0; i < N/2 - 1; i++) {
			for(int j = i+1; j < N/2; j++) {
				taste1 += arr[food1[i] - 1][food1[j] - 1] + arr[food1[j] - 1][food1[i] - 1];
				taste2 += arr[food2[i] - 1][food2[j] - 1] + arr[food2[j] - 1][food2[i] - 1];
			}
		}
		answer = Math.min(Math.abs(taste1 - taste2), answer);
		
	 }
	
}
