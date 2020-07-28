import java.util.Scanner;
import java.io.FileInputStream;
class Solution
{
	public static void main(String args[]) throws Exception
	{
		int[][] moves = {{0,1}, {1, 0}, {0, -1}, {-1, 0}};
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
            int N = sc.nextInt();
            int[][] arr = new int[N][N];
            int Number = 1;
            int i = 0;
            int j = 0;
            int flag = 0;
            arr[i][j] = Number++;
            while(Number != (N*N + 1)) {
            	i += moves[flag][0];
            	j += moves[flag][1];
            	
            	if(i < 0 || i >= N || j < 0 || j >= N) {
            		i -= moves[flag][0];
            		j -= moves[flag][1];
            		flag = (flag + 1) % 4;
            	}
            	else if(arr[i][j] != 0) {
            		i -= moves[flag][0];
            		j -= moves[flag][1];
            		flag = (flag + 1) % 4;
            	}
            	else
            		arr[i][j] = Number++;
            }
            System.out.println("#" + test_case);
            for(int x = 0; x < N; x++) {
            	for(int y = 0; y < N; y++) {
            		System.out.print(arr[x][y] + " ");
            	}
            	System.out.println();
            }
		}
        sc.close();
	}
}
