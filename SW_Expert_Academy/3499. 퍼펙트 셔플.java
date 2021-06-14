import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int words_num = Integer.parseInt(br.readLine());
			String words = br.readLine();
			StringTokenizer st = new StringTokenizer(words, " ");
			String[] answer = new String[words_num];
			for(int i = 0; i < words_num / 2; i++) 
				answer[i * 2] = st.nextToken();
			
			if(words_num % 2 == 1)
				answer[words_num - 1] = st.nextToken();
			for(int i = 0; i < words_num / 2; i++) 
				answer[i * 2 + 1] = st.nextToken();
			
        	System.out.print("#" + test_case);
			for(int i = 0; i <words_num; i++)
				System.out.print(" " + answer[i]);
			System.out.println();
		}
		br.close();
	}
}
