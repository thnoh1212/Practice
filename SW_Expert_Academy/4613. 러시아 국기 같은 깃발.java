package algo_0923;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N, M;
            int answer = 2500;
            String[] temp = br.readLine().split(" ");
            N = Integer.parseInt(temp[0]);
            M = Integer.parseInt(temp[1]);
            char[][] flag = new char[N][M];
            int[][] flagColor = new int[N][3];
            // W -> 0, B -> 1, R -> 2;
            for(int i = 0; i < N; i++) {
            	String line = br.readLine();
            	for(int j = 0; j < M; j++) {
            		
            		if(line.charAt(j) == 'W')
            			flagColor[i][0] += 1;
            		else if(line.charAt(j) == 'B')
            			flagColor[i][1] += 1;
            		else
            			flagColor[i][2] += 1;
            	}
            }
            
            for(int i = 1; i < N-1; i++) {
            	int limit = i + 1;
            	int sum = 0;
            	for(int j = 0; j < i; j++) {
            		sum += flagColor[j][1] + flagColor[j][2];
            	}
            	while(limit != N) {
            		int tSum = sum;
            		for(int j = i; j < limit; j++) 
            			tSum += flagColor[j][0] + flagColor[j][2];
            		for(int j = limit; j < N; j++) 
            			tSum += flagColor[j][0] + flagColor[j][1];
            		limit++;
            		
            		if(answer > tSum)
            			answer = tSum;
            	}
            }
            System.out.println("#" + test_case + " " + answer);
		}
		br.close();
	}
}
