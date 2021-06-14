package algo_0924;

import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main2564 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N, M;
		String[] temp = br.readLine().split(" ");
		N = Integer.parseInt(temp[0]);
		M = Integer.parseInt(temp[1]);
		int T = Integer.parseInt(br.readLine());
		int answer = 0;
		Queue<Point> que = new LinkedList<>();
		for(int i = 0; i < T; i++) {
			temp = br.readLine().split(" ");
			int dir = Integer.parseInt(temp[0]);
			int pos = Integer.parseInt(temp[1]);
			que.add(new Point(dir,pos));
		}
		temp = br.readLine().split(" ");
		int curDir = Integer.parseInt(temp[0]);
		int curPos = Integer.parseInt(temp[1]);
		while(!que.isEmpty()) {
			int targetDir = que.peek().x;
			int targetPos = que.poll().y;
			if((curDir == 1 && targetDir == 2) || ((curDir == 2 && targetDir == 1))) {
				int temp1 = targetPos + curPos;
				int temp2 = 2 * N - temp1;
				answer += Math.min(temp1, temp2) + M;
			}
			else if((curDir == 3 && targetDir == 4) || ((curDir == 4 && targetDir == 3))) {
				int temp1 = targetPos + curPos;
				int temp2 = 2 * M - temp1;
				answer += Math.min(temp1, temp2) + N;
			}
			else {
				int curI, curJ;
				int targetI, targetJ;
				if(curDir == 1) {
					curI = 0;
					curJ = curPos;
				}
				else if(curDir == 2) {
					curI = M;
					curJ = curPos;	
				}
				else if(curDir == 3) {
					curI = curPos;
					curJ = 0;
				}
				else {
					curI = curPos;
					curJ = N;
				}
				
				if(targetDir == 1) {
					targetI = 0;
					targetJ = targetPos;
				}
				else if(targetDir == 2) {
					targetI = M;
					targetJ = targetPos;	
				}
				else if(targetDir == 3) {
					targetI = targetPos;
					targetJ = 0;
				
				}
				else {
					targetI = targetPos;
					targetJ = N;
				}
				answer += Math.abs(curI - targetI) + Math.abs(curJ - targetJ);
			}
		}
		System.out.println(answer);
	}
}
