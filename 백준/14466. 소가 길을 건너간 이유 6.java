import java.util.List;
import java.util.Queue;
import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;

public class Main {

    static int moves[][] = {{1,0},{0,1},{-1,0},{0,-1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int answer = 0;
        String[] temp = br.readLine().split(" ");
        int N = Integer.parseInt(temp[0]);
        int K = Integer.parseInt(temp[1]);
        int R = Integer.parseInt(temp[2]);
        boolean[][][][] road = new boolean[N][N][N][N];
        for(int i = 0; i < R; i++) {
            temp = br.readLine().split(" ");
            int r = Integer.parseInt(temp[0]);
            int c = Integer.parseInt(temp[1]);
            int r2 = Integer.parseInt(temp[2]);
            int c2 = Integer.parseInt(temp[3]);
            road[r-1][c-1][r2-1][c2-1] = road[r2-1][c2-1][r-1][c-1] = true;
        }
        List<Point> cow = new ArrayList<>();
        for(int i = 0; i < K; i++) {
            temp = br.readLine().split(" ");
            int r = Integer.parseInt(temp[0]);
            int c = Integer.parseInt(temp[1]);
            cow.add(new Point(r-1,c-1));
        }
        for(int i = 0; i < K-1; i++) {
            for(int j = i+1; j < K; j++) {
                Queue<Point> que = new LinkedList<>();
                que.add(cow.get(i));
                Point target = cow.get(j);
                boolean[][] visited = new boolean[N][N];
                visited[cow.get(i).x][cow.get(i).y] = true;
                boolean chk = false;
                while(!que.isEmpty() && !chk) {
                    int cI = que.peek().x;
                    int cJ = que.poll().y;
                    for(int k = 0; k < 4; k++) {
                        int nI = cI + moves[k][0];
                        int nJ = cJ + moves[k][1];
                        if(nI >= N || nI < 0 || nJ >= N || nJ < 0 || visited[nI][nJ]) continue;
                        if(road[cI][cJ][nI][nJ]) continue;
                        if(nI == target.x && nJ == target.y) {
                            chk = true;
                            break;
                        }
                        visited[nI][nJ] = true;
                        que.add(new Point(nI, nJ));
                    }
                }
                if(!chk) answer += 1;
            }
        }
        System.out.println(answer);
    }
}
