import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class cur_info{
	int i;
	int j;
	boolean crush;
	int dis;
	public cur_info(int i, int j, boolean crush, int dis) {
		this.i = i;
		this.j = j;
		this.crush = crush;
		this.dis = dis;
	}
}

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int answer = 1000000;
		
		int[][] arr = new int[N][M];
		int[][] chk = new int[N][M];
		for(int i = 0; i < N; i++) {
			String temp = br.readLine();
			for(int j = 0; j < M ; j++) {
				arr[i][j] = temp.charAt(j) - '0';
			}
		}
		
		Queue<cur_info> que = new LinkedList<cur_info>();
		que.add(new cur_info(0, 0, false, 1));
		chk[0][0] = 2;
		while(!que.isEmpty()) {
			int i = que.peek().i;
			int j = que.peek().j;
			boolean crush = que.peek().crush;
			int dis = que.poll().dis;
			if(i == N-1 && j == M - 1) {
				answer = Math.min(answer, dis);
				continue;
			}	
			
			for(int k = 0; k < 4; k++) {
				int next_i = i + moves[k][0];
				int next_j = j + moves[k][1];
				
				if(next_i >= 0 && next_i < N && next_j >= 0 && next_j < M) {
					if(chk[next_i][next_j] != 2) {
						if(arr[next_i][next_j] == 1 && !crush) {
							que.add(new cur_info(next_i, next_j, !crush, dis+1));
							chk[next_i][next_j] = 2;
						}
						else if(arr[next_i][next_j] == 0) {
							if(crush) {
								if(chk[next_i][next_j] != 1) {
									que.add(new cur_info(next_i, next_j, crush, dis+1));
									chk[next_i][next_j] = 1;
								}
							}
							else {
								que.add(new cur_info(next_i, next_j, crush, dis+1));
								chk[next_i][next_j] = 2;
							}
						}
					}
				}
			}
		}
		if(answer == 1000000)
			answer = -1;
		System.out.println(answer);
		
	}
}
