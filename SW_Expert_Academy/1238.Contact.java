import java.io.FileInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

class graph{
	public int from;
	public int to;
	public int count;
	public graph(int from, int to, int count) {
		this.from = from;
		this.to = to;
		this.count = count;
	}
}

class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		for(int test_case = 1; test_case <= 10; test_case++)
		{
			Queue<graph> Graph = new LinkedList<graph>();
			int answer = 0;
			int index = 0;
			int max = 0;
			int[][] arr = new int[101][101];
			boolean[] visited = new boolean[101];
			String Numbers = br.readLine();
			StringTokenizer st = new StringTokenizer(Numbers, " ");
			int N = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());
			visited[start] = true;
			Numbers = br.readLine();
			st = new StringTokenizer(Numbers, " ");
			for(int i = 0; i < N/2; i++) {
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				arr[x][y] = 1;
				max = Math.max(max, (Math.max(x, y)));
			}
			for(int i = 0; i < max; i++) {
				if(arr[start][i] == 1) {
					Graph.add(new graph(start, i, 1));
				}
			}
			
			while(!Graph.isEmpty()) {
				int from = Graph.peek().from;
				int to = Graph.peek().to;
				int count = Graph.peek().count;
				Graph.poll();
				if(visited[to]) continue;
				if(count > answer) {
					answer = count;
					index = to;
				}
				else if(count == answer) {
					if(index < to) {
						index = to;
					}
				}
				visited[to] = true;
				for(int i = 0; i < max; i++) {
					if(arr[to][i] == 1) {
						Graph.add(new graph(to, i, count+1));
					}
				}
				
			}	
			System.out.println("#" + test_case + " " + index);
		}
	}
}
