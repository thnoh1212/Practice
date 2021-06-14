import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

class info{
	int r;
	int c;
	int s;
	public info(int r, int c, int s) {
		this.r = r;
		this.c = c;
		this.s = s;
	}
}

public class 백준_17406_배열돌리기4 {
	public static void main(String[] args) throws Exception {
		int[][] moves = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		int[][] arr = new int[N][M];
		int answer = 5000;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		List<info> Data = new ArrayList<info>();
		for (int i = 0; i < K; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int r = Integer.parseInt(st.nextToken()) - 1;
			int c = Integer.parseInt(st.nextToken()) - 1;
			int s = Integer.parseInt(st.nextToken());
			Data.add(new info(r, c, s));
		}
		int[] chk = new int[K];
		for(int i = 0; i < K; i++)
			chk[i] = i;
		Arrays.sort(chk);
		do {
			int[][] t_arr = new int[N][M];
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					t_arr[i][j] = arr[i][j];
				}
			}
			for (int i = 0; i < K; i++) {
				int r = Data.get(chk[i]).r;
				int c = Data.get(chk[i]).c;
				int s = Data.get(chk[i]).s;
				int i_start = r - s;
				int j_start = c - s;
	
				int i_cur = r - s;
				int j_cur = c - s;
	
				int i_end = r + s;
				int j_end = c + s;
				
				int k = 0;
				int save = t_arr[i_cur][j_cur];
				while (i_start < i_end && j_start < j_end) {
					i_cur += moves[k][0];
					j_cur += moves[k][1];
					
					if (i_cur < i_start || i_cur > i_end || j_cur < j_start || j_cur > j_end) {
						i_cur -= moves[k][0];
						j_cur -= moves[k][1];
						k += 1;
					} else {
						int temp = save;
						save = t_arr[i_cur][j_cur];
						t_arr[i_cur][j_cur] = temp;
					}
					if(k == 4) {
						i_start = i_start + 1;
						j_start = j_start + 1;
						i_end = i_end - 1;
						j_end = j_end - 1;
						i_cur = i_start;
						j_cur = j_start;
						save = t_arr[i_cur][j_cur];
						k = 0;
					}
				}
			}
			for(int a = 0; a < N; a++) {
				int sum = 0;
				for(int b = 0; b < M; b++) {
					sum += t_arr[a][b];
				}
				answer = Math.min(sum, answer);
			}
			
		}while(nextPermutation(chk, Data.size()));
		
		System.out.println(answer);
	}
	
	private static boolean nextPermutation(int[] numbers, int N) {
		int i = N - 1;
		while(i > 0 && numbers[i-1] >= numbers[i]) --i;
		if(i == 0) return false;

        int j = N - 1;
		while(numbers[i-1] >= numbers[j]) --j;
		
	
		swap(numbers, i-1, j);
		
		int k = N - 1;
		while(i < k) {
			swap(numbers, i++, k--);
		}
		return true;
		
	}
	
	public static void swap(int[] numbers, int i, int j) {
		int temp = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = temp;
	}
}

