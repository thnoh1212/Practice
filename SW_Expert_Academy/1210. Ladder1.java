import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		for(int test_case = 1; test_case <= 10; test_case++)
		{
			int Tc = sc.nextInt();
			char[][] maze = new char[102][102];
			int cur_i = 0;
			int cur_j = 0;
			for(int i = 1; i <= 100; i++){
				for(int j = 1; j <= 100; j++){
					maze[i][j] = sc.next().charAt(0);
					if(maze[i][j] == '2'){
						cur_i = i;
						cur_j = j;
					}
				}
			}
			while(cur_i != 1){
            	if(maze[cur_i][cur_j + 1] == '1'){
					while(maze[cur_i][cur_j] != '0'){
						if(cur_j + 1 < 101) cur_j += 1;
                        	else{
								cur_j += 1;
								break;
							}
						}
						cur_j -= 1;
                    	cur_i -= 1;
					}
					else if(maze[cur_i][cur_j - 1] == '1'){
						while(maze[cur_i][cur_j] != '0'){
							if(cur_j - 1 > 1)  cur_j -= 1;
							else{
								cur_j -= 1;
								break;
							}
						}
						cur_j += 1;
                        cur_i -= 1;
					}
					else{
						while(maze[cur_i][cur_j-1] != '1' && maze[cur_i][cur_j+1] != '1' && cur_i - 1 != 0){
                            cur_i -= 1;
                        }
					}
            }
            System.out.println("#" + test_case + " " + (cur_j - 1));
		}
	}
}
