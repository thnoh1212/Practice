package algo_0902;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

class Solution
{
	static int N, maxConnect, answer;
	static List<Point> core;
	static int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
	static int[][] map;
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			answer = Integer.MAX_VALUE;
            N = Integer.parseInt(br.readLine());
            map = new int[N][N];
            maxConnect = 0 ;
            core = new ArrayList<Point>();
            for(int i = 0; i < N; i++) {
            	String[] temp = br.readLine().split(" ");
            	for(int j = 0; j < N; j++) {
            		map[i][j] = Integer.parseInt(temp[j]);
            		if(map[i][j] == 1 && i != 0 && j != 0 && i != N-1 && j != N-1) 
            			core.add(new Point(i, j));         	
            	}
            }
            dfs(0, 0, 0);
            
            System.out.println("#" + test_case + " " + answer);
		}
	}
	
	static void dfs(int curIdx, int coreCnt, int lineCnt) {
		if(coreCnt + N - curIdx < maxConnect) return;
		if(curIdx == core.size()) {
			if(coreCnt > maxConnect) {
				maxConnect = coreCnt;
				answer = lineCnt;
			}
			else if(coreCnt == maxConnect) {
				if(lineCnt < answer)
					answer = lineCnt;
			}
			return;
		}
		
		for(int i = 0; i < 4; i++) {
			int curI = core.get(curIdx).x;
			int curJ = core.get(curIdx).y;
			boolean flag = true;
			while(true) {
				curI += moves[i][0];
				curJ += moves[i][1];
				if(curI < 0 || curI >= N || curJ < 0 || curJ >= N) break;
				if(map[curI][curJ] != 0) {
					flag = false;
					break;
				}
			}
			if(flag) {
				int temp = fill(core.get(curIdx).x, core.get(curIdx).y, i, 2);
				dfs(curIdx + 1, coreCnt + 1, lineCnt + temp);
				fill(core.get(curIdx).x, core.get(curIdx).y, i, 0);
			}
		}
		dfs(curIdx + 1, coreCnt, lineCnt);
	}
	
	static int fill(int curI, int curJ, int k, int F) {
		int nextI = curI + moves[k][0];
		int nextJ = curJ + moves[k][1];
		int cnt = 0;
		while(nextI >= 0 && nextI < N && nextJ >= 0 && nextJ < N) {
			map[nextI][nextJ] = F;
			cnt++;
			nextI += moves[k][0];
			nextJ += moves[k][1];
		}
		
		return cnt;
	}
}
