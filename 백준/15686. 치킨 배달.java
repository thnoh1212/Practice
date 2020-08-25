import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	static int per_n;
	static int[] arr;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[][] map = new int[N][N];
		int answer = 2500;
		List<Point> house = new ArrayList<Point>();
		List<Point> chicken = new ArrayList<Point>();
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if(map[i][j] == 1)
					house.add(new Point(i, j));
				else if(map[i][j] == 2)
					chicken.add(new Point(i, j));
			}
		}
		per_n = chicken.size();
		arr = new int[per_n];
		for(int i = 0; i < M; i++)
			arr[i] = 1;
		Arrays.sort(arr);
		
		do {// 조합용 arr 완성
			int sum = 0;
			int[] chicken_len = new int[house.size()];
			for(int i = 0; i < chicken.size(); i++) {
				if(arr[i] == 1) {
					for(int j = 0; j < house.size(); j++) {
						if(chicken_len[j] == 0)
							chicken_len[j] = Math.abs(chicken.get(i).x - house.get(j).x) + Math.abs(chicken.get(i).y - house.get(j).y);
						else
							chicken_len[j] = Math.min(chicken_len[j], Math.abs(chicken.get(i).x - house.get(j).x) + Math.abs(chicken.get(i).y - house.get(j).y));
					}
				}
			}
			for(int i = 0; i < house.size(); i++) {
				sum += chicken_len[i];
			}
			answer = Math.min(answer, sum);
			
		}while(nextPermutation(arr));
		
		System.out.println(answer);
		
	}
	private static boolean nextPermutation(int[] numbers) {
		int i = per_n - 1;
		while(i > 0 && numbers[i-1] >= numbers[i]) --i;
		if(i == 0) return false; 
		
		int j = per_n - 1;
		while(numbers[i-1] >= numbers[j]) --j;
		
		swap(numbers, i-1, j);
		
		int k = per_n - 1;
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

