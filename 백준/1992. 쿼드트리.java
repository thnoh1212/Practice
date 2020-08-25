import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	static List<Character> answer;
	static String[] map;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		map = new String[N];
		for(int i = 0; i < N; i++) 
			map[i] = br.readLine();
		
		answer = new ArrayList<>();
		make_answer(0, 0, N);
		for(int i = 0; i < answer.size(); i++)
			System.out.print(answer.get(i));
		
	}
	
	static void make_answer(int i, int j, int N) {
		if(N == 0) {
			answer.add(map[i].charAt(j));
			return;
		}
		
		boolean chk_one = true;
		boolean chk_zero = true;
		for(int x = i; x < i + N; x++) {
			for(int y = j; y < j + N; y++) {
				if(map[x].charAt(y) == '1')
					chk_zero = false;
				else
					chk_one = false;
			}
		}
		if(chk_one)
			answer.add('1');
		else if(chk_zero)
			answer.add('0');
		else {
			answer.add('(');
			make_answer(i, j, N/2);
			make_answer(i, j+N/2, N/2);
			make_answer(i+N/2, j, N/2);
			make_answer(i+N/2, j+N/2, N/2);
			answer.add(')');
		}
	}
}
