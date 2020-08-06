import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class taste{
	int sour;
	int bitter;
	
	public taste(int sour, int bitter) {
		this.sour = sour;
		this.bitter = bitter;
	}
}

class Main
{
	static taste[] ingredients;
	static boolean chk[];
	static int answer;
	static int T;
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		answer = 1000000000;
		ingredients = new taste[T];
		chk = new boolean[T];
		for(int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			ingredients[i] = new taste(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		dfs(false, 0, 1, 0);
		
		System.out.println(answer);
		br.close();
	}
	
	public static void dfs(boolean flag, int index, int sour, int bitter) {
		
		if(flag) {
			int temp = Math.abs(bitter - sour);
			answer = Math.min(answer, temp);
		}
		
		for(int i = index; i < T; i++) {
			if(!chk[i]) {
				chk[i] = true;
				dfs(true, i, sour * ingredients[i].sour, bitter + ingredients[i].bitter);
				chk[i] = false;
			}
		}
	}
}
