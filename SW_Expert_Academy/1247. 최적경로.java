import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class SWEA1247 {
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		for(int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			List<Point> pixed_point = new ArrayList<>();
			List<Point> customer = new ArrayList<>();
			int answer = 10000;
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			
			for(int i = 0; i < 2; i++) 
				pixed_point.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
			for(int i = 0; i < N; i++) 
				customer.add(new Point(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));	
			
			int[] index = new int[N];
			for(int i = 1; i < N; i++)
				index[i] = i;
			Arrays.sort(index);
			do {
				int sum = Math.abs(pixed_point.get(0).x - customer.get(index[0]).x) +
						Math.abs(pixed_point.get(0).y - customer.get(index[0]).y);
				for(int i = 0; i < N-1; i++) {
					sum += Math.abs(customer.get(index[i]).x - customer.get(index[i+1]).x) +
							Math.abs(customer.get(index[i]).y - customer.get(index[i+1]).y);
				}
				sum += Math.abs(pixed_point.get(1).x - customer.get(index[N-1]).x) +
						Math.abs(pixed_point.get(1).y - customer.get(index[N-1]).y);
				
				answer = Math.min(sum, answer);
				
			}while(nextPermutation(index, N));
			System.out.println(answer);
		}
		br.close();

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
