package algo_1029;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution
{
	static int[][] map;
	static int N;
	static int Len;
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int test_case = 1; test_case <= T; test_case++)
		{
			int answer = 0;
            String[] temp = br.readLine().split(" ");
            N = Integer.parseInt(temp[0]);
            Len = Integer.parseInt(temp[1]);
            map = new int[N][N];
            
            for(int i = 0; i < N; i++) {
            	temp = br.readLine().split(" ");
            	for(int j = 0; j < N; j++) {
            		map[i][j] = Integer.parseInt(temp[j]);
            	}
            }
            
            for(int i = 0; i < N; i++) {
            	if(findRowAirstrip(i)) answer++;
            	if(findColumnAirstrip(i)) answer++;
            }
            System.out.println("#" + test_case + " " + answer);
		}
	}
	
	public static boolean findRowAirstrip(int i){
		int temp = map[i][0];
		int cnt = 1;
		for(int j = 1; j < N; j++) {
			if(temp == map[i][j]) cnt++;
			else if(map[i][j] - temp == 1) {
				if(cnt < Len) return false;
				temp = map[i][j];
				cnt = 1;
			}
			else if(temp - map[i][j] == 1) {
				int tCnt = 0;
				for(int k = j; k < N; k++) {
					if(map[i][j] == map[i][k]) tCnt++;
					else break;
				}
				if(tCnt < Len) return false;
				j += tCnt - 1;
				temp = map[i][j];
				cnt = tCnt - Len;
			}
			else
				return false;
		}
		return true;
	}
	public static boolean findColumnAirstrip(int i){
		int temp = map[0][i];
		int cnt = 1;
		for(int j = 1; j < N; j++) {
			if(temp == map[j][i]) cnt++;
			else if(map[j][i] - temp == 1) {
				if(cnt < Len) return false;
				temp = map[j][i];
				cnt = 1;
			}
			else if(temp - map[j][i] == 1) {
				int tCnt = 0;
				for(int k = j; k < N; k++) {
					if(map[j][i] == map[k][i]) tCnt++;
					else break;
				}
				if(tCnt < Len) return false;
				j += tCnt - 1;
				temp = map[j][i];
				cnt = tCnt - Len;
			}
			else
				return false;
		}
		return true;
	}
}
