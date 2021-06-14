import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.FileInputStream;
import java.util.Queue;
import java.util.LinkedList;

class Point{
	public int x;
	public int y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int max = 0;
			int answer = 0;
			int N = Integer.parseInt(br.readLine());
			int[][] arr = new int[N][N];
			
			for(int i = 0; i < N; i++) {
				String Numbers = br.readLine();
				StringTokenizer st = new StringTokenizer(Numbers, " ");
				for(int j = 0; j < N; j++)
					arr[i][j] = Integer.parseInt(st.nextToken());
			}
			
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					Queue<Point> q = new LinkedList<Point>();
					q.add(new Point(i, j));
					int count = 1;
					while(!q.isEmpty()) {
						int cur_i = q.peek().x;
						int cur_j = q.peek().y;
						q.remove();
						for(int k = 0; k < 4; k++) {
							int next_i = cur_i + moves[k][0];
							int next_j = cur_j + moves[k][1];
							if(next_i < 0 || next_i >= N || next_j < 0 || next_j >= N) continue;
							else if(arr[next_i][next_j] == arr[cur_i][cur_j] + 1){
								q.add(new Point(next_i, next_j));
								count++;
							}
						}
					}
					if(count > max) {
						max = count;
						answer = arr[i][j];
					}
					else if (count == max) {
						if(answer > arr[i][j])
							answer = arr[i][j];
					}
				}
				
			}
			System.out.println("#" + test_case + " " + answer + " " + max);
		}
		
		br.close();
	}
}
