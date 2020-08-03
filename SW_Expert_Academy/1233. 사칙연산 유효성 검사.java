import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		for(int test_case = 1; test_case <= 10; test_case++)
		{
			int N = sc.nextInt();
			boolean flag = true;
			int skip;
			char temp;
			String trash;
			for(int i = 0; i < N; i++) {
				if(N/2 > i) {
					skip = sc.nextInt();
					temp = sc.next().charAt(0);
					if(temp >= '0' && temp <= '9') 
						flag = false;
					trash = sc.nextLine();
				}
				else {
					skip = sc.nextInt();
					temp = sc.next().charAt(0);
					if(temp == '+' || temp == '-' || temp == '*' || temp == '/') 
						flag = false;
					
				}
			}
			if(flag) 
				System.out.println("#" + test_case + " 1");
			else
				System.out.println("#" + test_case + " 0");
				
		}
        sc.close();
	}
}
