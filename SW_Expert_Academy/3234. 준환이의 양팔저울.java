import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
	static int answer;
	static int[] factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
	static int[] pow_2 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine());
			answer = 0;
			int[] arr = new int[N];
			boolean[] visited = new boolean[N];
			int remain = 0;
			String[] temp = br.readLine().split(" ");
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(temp[i]);
				remain += arr[i];
			}
			permutation(arr, visited, 0, N, 0, 0, remain);
			System.out.println("#" + test_case + " " + answer);
		}
		br.close();
	}

	public static void permutation(int[] arr, boolean[] visited, int cnt, int N, int left, int right, int remain) {
		if (left >= right + remain) {
			answer += factorial[N - cnt] * pow_2[N - cnt];
            return;
		}
		if (cnt == N) {
			answer += 1;
			return;
		}
		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			permutation(arr, visited, cnt + 1, N, left + arr[i], right, remain - arr[i]);
			if (left >= right + arr[i])
				permutation(arr, visited, cnt + 1, N, left, right + arr[i], remain - arr[i]);
			visited[i] = false;
		}
	}
}
