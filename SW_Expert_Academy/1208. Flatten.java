import java.util.Scanner;
import java.util.Arrays;

class Solution
{
	public static void main(String args[]) throws Exception
	{
        Scanner sc = new Scanner(System.in);
		for(int test_case = 1; test_case <= 10; test_case++)
		{
            int dump = sc.nextInt();
			int[] box = new int[100];
            for(int i = 0; i < 100; i++)  box[i] = sc.nextInt();
            Arrays.sort(box);
            while(dump > 0){
                box[0]++;
                box[99]--;
                dump--; 
                Arrays.sort(box);
            }
            System.out.println("#"+test_case+" "+(box[99]-box[0]));
        }
	}
}
