package 프로그래머스;

import java.util.Queue;
import java.util.LinkedList;
import java.awt.Point;

class Solution {
    public int solution(int n, int[][] results) {
        int answer = 0;
        int[][] graph = new int[n+1][n+1];
        for(int i = 0; i < results.length; i++){
            graph[results[i][0]][results[i][1]] = -1;
            graph[results[i][1]][results[i][0]] = 1;
        }
        for(int i = 1; i <= n; i++){
            int temp = 1;
            Queue<Point> que = new LinkedList<>();
            boolean[] visited = new boolean[n+1];
            que.add(new Point(i, 0));
            visited[i] = true;
            while(!que.isEmpty()){
                int cur = que.peek().x;
                int state = que.poll().y;
                for(int j = 1; j <= n; j++){
                    if(visited[j]) continue;
                    if(state == 0){
                        if(graph[cur][j] != 0){
                            temp += 1;
                            visited[j] = true;
                            que.add(new Point(j, graph[cur][j]));
                        }
                    }
                    else{
                        if(graph[cur][j] * state == 1){
                            temp += 1;
                            visited[j] = true;
                            que.add(new Point(j, graph[cur][j]));
                        }
                    }
                }
            }
            if(temp == n) answer += 1;
        }
        return answer;
    }
}