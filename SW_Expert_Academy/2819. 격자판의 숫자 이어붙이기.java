import java.util.Scanner;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;
import java.util.LinkedList;

class check_map{
	int i;
	int j;
	String key;
	public check_map(int i, int j, String key) {
		this.i = i;
		this.j = j;
		this.key = key;
	}
}

class Solution
{
	public static void main(String args[]) throws Exception
	{
		int[][] moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			Map<String, Integer> check = new HashMap<>();
			Queue<check_map> que = new LinkedList<>();
			int answer = 0;
			char[][] arr = new char[4][4];
            
			
            for(int i = 0; i < 4; i++){
                for(int j = 0; j < 4; j++){
             		arr[i][j] = sc.next().charAt(0);   
                }
            }
            int count = 0;
            for(int i = 0; i < 4; i++) {
            	for(int j = 0; j < 4; j++) {
            		String key = "" + arr[i][j];
            		que.add(new check_map(i, j, key));
            		while(!que.isEmpty()) {
            			int cur_i = que.peek().i;
            			int cur_j = que.peek().j;
            			String temp_key = que.peek().key;
            			que.poll();
            			
            			if(temp_key.length() == 7) {
            				if(check.containsKey(temp_key)) continue;
            				else
            					check.put(temp_key, 1);
            			}
            			else {
            				for(int k = 0; k < 4; k++) {
            					int next_i = cur_i + moves[k][0];
            					int next_j = cur_j + moves[k][1];
            					if(next_i >= 0 && next_i < 4 && next_j >= 0 && next_j < 4) 
            						que.add(new check_map(next_i, next_j, temp_key + arr[next_i][next_j]));
            					
            				}
            			}
            		}
            	}
            }
            System.out.println("#" + test_case + " " + check.size()); 
        }
	}
}
