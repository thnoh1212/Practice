import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		int[][] moves = {{2,0}, {0,2}};
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N, M;
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			boolean[][] arr = new boolean[M][N];
			int count = M * N;
			for(int i = 0; i < M; i++) {
				for(int j = 0; j < N; j++) {
					if(!arr[i][j]) {
						for(int k = 0; k < 2; k++) {
							int next_i = i + moves[k][0];
							int next_j = j + moves[k][1];
							if(next_i < M && next_j < N) {
								if(!arr[next_i][next_j]) {
									arr[next_i][next_j] = true;
									count -= 1;
								}
							}
						}
					}
				}
			}
			System.out.println("#" + test_case + " " + count);
		}
		br.close();
	}
}
