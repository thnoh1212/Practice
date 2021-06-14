import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int N = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int answer = 0;
		
		int[] belt = new int[N];
		for(int i = 0; i < N; i++) 
			belt[i] = Integer.parseInt(br.readLine());
		
		
		for(int i = 0; i < N; i++) {
			boolean[] type = new boolean[3001];
			boolean flag = true;
			int cnt = 0;
			for(int j = 0; j < k; j++) {
				if(!type[belt[(i + j) % N]]) {
					type[belt[(i + j) % N]] = true;
					cnt++;
				}
				if(belt[(i + j) % N] == c) flag = false;		
			}
			if(flag) cnt += 1;
			
			answer = Math.max(answer, cnt);
			if(answer == d) break;
		}
		System.out.println(answer);	
	}
}
