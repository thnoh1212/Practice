import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;
import java.util.StringTokenizer;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int answer = 0;
			String Numbers = br.readLine();
			StringTokenizer st = new StringTokenizer(Numbers, " ");
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			
			int[][] arr = new int[N+1][N+1];
			boolean[] map = new boolean[N+1];
			Queue<Integer> check = new LinkedList<>();
			
			for(int i = 0; i < M; i++) {
				Numbers = br.readLine();
				st = new StringTokenizer(Numbers, " ");
				int num_1 = Integer.parseInt(st.nextToken());
				int num_2 = Integer.parseInt(st.nextToken());
				
				arr[num_1][num_2] = arr[num_2][num_1] = 1;
			}
			
			for(int i = 1; i <= N; i++) {
				if(!map[i]) {
					answer += 1;
					map[i] = true;
					check.add(i);
					while(!check.isEmpty()) {
						int cur_loc = check.peek();
						check.poll();
						
						for(int j = 1; j <= N; j++) {
							if(arr[cur_loc][j] == 1 && !map[j]) {
								map[j] = true;
								check.add(j);
							}
						}
					}
				}
			}
			System.out.println("#" + test_case + " " + answer);
        }
	}
}
