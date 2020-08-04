import java.util.Scanner;
import java.io.InputStreamReader;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for(int test_case = 1; test_case <= T; test_case++)
		{
			System.out.print("#" + test_case + " ");
			int n = sc.nextInt();
			int m = sc.nextInt();
			int[] parent = new int[n+1];
			int temp, a, b;
			for(int i = 1; i <= n; i++)
				parent[i] = i;
			for(int i = 0; i < m; i++) {
				temp = sc.nextInt();
				a = sc.nextInt();
				b = sc.nextInt();
				if(temp == 1) {
					temp = findParent(parent, a, b);
					System.out.print(temp);
				}
				else 
					unionParent(parent, a, b);
			}
			
			System.out.println();
		}
		
		sc.close();
	}
	
	static int getParent(int[] parent, int x){
		if(parent[x] == x)
			return x;
		else
			return parent[x] = getParent(parent, parent[x]);
	}

	static void unionParent(int[] parent, int a, int b){
		a = getParent(parent, a);
		b = getParent(parent, b);
		if(a < b)
			parent[b] = a;
		else
			parent[a] = b;
	} 

	static int findParent(int[] parent, int a, int b){
		a = getParent(parent, a);
		b = getParent(parent, b);
		if(a == b)
			return 1;
		else
			return 0;
	} 
}
