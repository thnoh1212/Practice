import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
		StringTokenizer st = new StringTokenizer(br.readLine(), " "); 
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken()); 
		int[] shop = new int[N];
		int[] chk = new int[N+1];
		long answer = 0; 
		
		st = new StringTokenizer(br.readLine(), " ");
		for(int i = 0; i < N; i++) 
			shop[i] = Integer.parseInt(st.nextToken()); 
		
		Arrays.sort(shop); 
		Set<Integer> set = new HashSet<Integer>();
		
		for(int i = 1; i < N; i++)
			chk[i] = Math.abs(shop[i] - shop[i-1]);
		chk[0] = Math.abs(shop[0] + 100000000); 
		chk[N] = Math.abs(shop[N-1] - 100000000);
		
		for(int i = 0; i <= N; i++) {
			if(chk[i] > 1)
				set.add(i);
		}
		int len = 1;
		while(K != 0) {
			Iterator<Integer> it = set.iterator();
			List<Integer> temp = new ArrayList<Integer>();
			while(it.hasNext()) {
				int i = it.next();
				if(chk[i] == 1) {
					temp.add(i);
					continue;
				}
				if((i == 0 || i == N) && chk[i] > 0) { 
					chk[i] -= 1;
					K -= 1;
					answer += len; 
				}
				else if(chk[i] >= 3 && K >= 2) { 
					chk[i] -= 2; 
					K -= 2; 
					answer += 2 * len;
				}
				else if(chk[i] == 2 || K == 1) {
					chk[i] -= 1; 
					K -= 1;
					answer += 1 * len; 
				}
				if(K == 0) break;
			}
			len++; 
			for(int i = 0; i < temp.size(); i++) {
				set.remove(temp.get(i));
			}
			temp.clear();
		}
		System.out.println(answer); 
	}
}
