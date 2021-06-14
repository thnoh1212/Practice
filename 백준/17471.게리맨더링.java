import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class 백준_17471_게리맨더링 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int answer = Integer.MAX_VALUE;
		int[] arr = new int[N+1];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for(int i = 1; i <= N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		
		boolean[][] map = new boolean[N+1][N+1];
		
		for(int i = 1; i <= N; i++) {
			String[] temp = br.readLine().split(" ");
			for(int j = 1; j <= Integer.parseInt(temp[0]); j++) 
				map[i][Integer.parseInt(temp[j])] = true;
			
		}
		for(int i = 1; i <= N/2; i++) {
			int[] comb = new int[N];
			for(int j = 0; j < i; j++)
				comb[j] = 1;
			Arrays.sort(comb);
			do {
				List<Integer> left = new ArrayList<>();
				List<Integer> right = new ArrayList<>();
				boolean[] chkLeft = new boolean[N+1];
				boolean[] chkRight = new boolean[N+1];
				int leftSum = 0;
				int rightSum = 0;
				
				for(int k = 0; k < N; k++) {
					if(comb[k] == 0)
						right.add(k+1);
					else
						left.add(k+1);
				}
				
				if(left.size() != 1) {
					Queue<Integer> lchk = new LinkedList<Integer>();
					lchk.add(left.get(0));
					while(!lchk.isEmpty()) {
						int lTemp = lchk.poll();
						chkLeft[lTemp] = true;
						for(int k = 1; k <= N; k++) {
							if(map[lTemp][k] && !chkLeft[k] && left.contains(k))
								lchk.add(k);
						}
					}
					boolean lFlag = false;
					for(int a : left) {
						if(!chkLeft[a]) {
							lFlag = true;
							break;
						}
						leftSum += arr[a];
					}
					if(lFlag) continue; 
				}
				else
					leftSum = arr[left.get(0)];
		
				///// 오른쪽
				if(right.size() != 1) {
					Queue<Integer> rchk = new LinkedList<Integer>();
					rchk.add(right.get(0));
					while(!rchk.isEmpty()) {
						int rTemp = rchk.poll();
						chkRight[rTemp] = true;
						for(int k = 1; k <= N; k++) {
							if(map[rTemp][k] && !chkRight[k] && right.contains(k))
								rchk.add(k);
						}
					}
					boolean rFlag = false;
					for(int b : right) {
						if(!chkRight[b]) {
							rFlag = true;
							break;
						}
						rightSum += arr[b];
					}
					if(rFlag) continue;
				}
				else rightSum = arr[right.get(0)];
				answer = Math.min(Math.abs(leftSum - rightSum), answer);
			}while(nextPermutation(comb, N));	
		}
		if(answer == Integer.MAX_VALUE) answer = -1;
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
