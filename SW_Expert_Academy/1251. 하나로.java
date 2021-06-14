import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Solution {
	static class Point {
		double i;
		double j;

		public Point(double i, double j) {
			this.i = i;
			this.j = j;
		}
	}

	public static void main(String args[]) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine());
			String[] islandI = br.readLine().split(" ");
			String[] islandJ = br.readLine().split(" ");
			double E = Double.parseDouble(br.readLine());
			double[][] map = new double[N][N];
			ArrayList<Point> island = new ArrayList<>();

			for (int i = 0; i < N; i++)
				island.add(new Point(Integer.parseInt(islandI[i]), Integer.parseInt(islandJ[i])));
			for (int i = 0; i < N - 1; i++) {
				for (int j = i + 1; j < N; j++) {
					double temp = (Math.pow((island.get(i).i - island.get(j).i), 2)
							+ Math.pow((island.get(i).j - island.get(j).j), 2));
					map[i][j] = map[j][i] = temp;
				}
			}

			boolean[] visited = new boolean[N];
			double[] dis = new double[N];
			for (int i = 1; i < N; i++) dis[i] = Double.MAX_VALUE;
			dis[0] = 0.0;
			for (int i = 0; i < N; i++) {
				double min = Double.MAX_VALUE;
				int idx = 0;
				for (int j = 0; j < N; j++) {
					if (!visited[j] && min > dis[j]) {
						min = dis[j];
						idx = j;
					}
				}
				visited[idx] = true;
				for (int j = 0; j < N; j++) {
					if (!visited[j] && map[idx][j] != 0 && dis[j] > map[idx][j]) 
						dis[j] = map[idx][j];
				}
			}
			double sum = 0.0;
			for (int i = 0; i < N; i++) sum += dis[i];
			sum *= E;
			System.out.println("#" + test_case + " " + Math.round(sum));
		}
	}
}
