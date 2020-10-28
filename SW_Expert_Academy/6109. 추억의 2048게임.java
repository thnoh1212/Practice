import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution
{
	public static void main(String args[]) throws Exception
	{	
		// 0 - up, 1 - down, 2 - left, 3 - right
		int[][] moves = {{-1,0},{1,0},{0,-1},{0,1}};
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T;
		T=Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
            String[] temp = br.readLine().split(" ");
            int N = Integer.parseInt(temp[0]);
            String dir = temp[1];
            int[][] board = new int[N][N];
            
            for(int i = 0; i < N; i++) {
            	temp = br.readLine().split(" ");
            	for(int j = 0; j < N; j++) {
            		board[i][j] = Integer.parseInt(temp[j]);
            	}
            }
            int[][] answer = new int[N][N];
            if(dir.equals("up")) {
            	for(int i = 0; i < N; i++) {
            		Queue<Integer> list = new LinkedList<>();
            		int idx = 0;
            		for(int j = 0; j < N; j++) {
            			if(board[j][i] != 0)
            				list.add(board[j][i]);
            		}
            		
            		while(list.size() > 1) {
            			int num1 = list.poll();
            			int num2 = list.peek();
            			if(num1 == num2) {
            				num1 += num2;
            				list.poll();
            				answer[idx++][i] = num1;
            			}else {
            				answer[idx++][i] = num1;
            			}
            		}
            		if(!list.isEmpty()) answer[idx][i] = list.poll();
            	}
            }
            else if(dir.equals("down")){
            	for(int i = 0; i < N; i++) {
            		Stack<Integer> list = new Stack<>();
            		int idx = N-1;
            		for(int j = 0; j < N; j++) {
            			if(board[j][i] != 0)
            				list.add(board[j][i]);
            		}
            		
            		while(list.size() > 1) {
            			int num1 = list.peek();
            			list.pop();
            			int num2 = list.peek();
            			if(num1 == num2) {
            				num1 += num2;
            				list.pop();
            				answer[idx--][i] = num1;
            			}else {
            				answer[idx--][i] = num1;
            			}
            		}
            		if(!list.isEmpty()) {
            			answer[idx][i] = list.peek();
            			list.pop();
            		}
            	}
            }
            else if(dir.equals("left")) {
            	for(int i = 0; i < N; i++) {
            		Queue<Integer> list = new LinkedList<>();
            		int idx = 0;
            		for(int j = 0; j < N; j++) {
            			if(board[i][j] != 0)
            				list.add(board[i][j]);
            		}
            		
            		while(list.size() > 1) {
            			int num1 = list.poll();
            			int num2 = list.peek();
            			if(num1 == num2) {
            				num1 += num2;
            				list.poll();
            				answer[i][idx++] = num1;
            			}else {
            				answer[i][idx++] = num1;
            			}
            		}
            		if(!list.isEmpty()) answer[i][idx] = list.poll();
            	}
            }
            else {
            	for(int i = 0; i < N; i++) {
            		Stack<Integer> list = new Stack<>();
            		int idx = N-1;
            		for(int j = 0; j < N; j++) {
            			if(board[i][j] != 0)
            				list.add(board[i][j]);
            		}
            		
            		while(list.size() > 1) {
            			int num1 = list.peek();
            			list.pop();
            			int num2 = list.peek();
            			if(num1 == num2) {
            				num1 += num2;
            				list.pop();
            				answer[i][idx--] = num1;
            			}else {
            				answer[i][idx--] = num1;
            			}
            		}
            		if(!list.isEmpty()) {
            			answer[i][idx] = list.peek();
            			list.pop();
            		}
            	}
            }
            System.out.println("#" + test_case);
            for(int i = 0; i < N; i++) {
            	for(int j = 0; j < N; j++) {
            		System.out.print(answer[i][j] + " ");
            	}
                System.out.println();
            }
            
		}
	}
}
