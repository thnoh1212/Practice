import java.util.*;

class Solution {

    class Pos implements Comparable<Pos>{
        int i;
        int j;
        int cost;

        public Pos(int i, int j, int cost){
            this.i = i;
            this.j = j;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pos pos){
            if(this.cost < pos.cost)
                return -1;
            else if (this.cost > pos.cost)
                return 1;
            return 0;
        }
    }

    static int[][] moves = {{1,0},{0,1},{-1,0},{0,-1}};
    public int solution(int[][] maps) {
        int answer = 0;
        int n = maps.length;
        int m = maps[0].length;

        PriorityQueue<Pos> pq = new PriorityQueue<>();
        pq.add(new Pos(0, 0, 1));
        boolean[][] visited = new boolean[n][m];
        visited[0][0] = true;
        maps[n-1][m-1] = -1;
        while(!pq.isEmpty()){
            if(visited[n-1][m-1]) break;
            int curI = pq.peek().i;
            int curJ = pq.peek().j;
            int curCost = pq.poll().cost;

            for(int i = 0; i < 4; i++){
                int nextI = curI + moves[i][0];
                int nextJ = curJ + moves[i][1];

                if(nextI < 0 || nextI >= n || nextJ < 0 || nextJ >= m || maps[nextI][nextJ] == 0 ||visited[nextI][nextJ]) continue;
                else{
                    visited[nextI][nextJ] = true;
                    pq.add(new Pos(nextI, nextJ, curCost + 1));
                    maps[nextI][nextJ] = curCost + 1;
                }
            }
        }

        return maps[n-1][m-1];
    }
}