import java.awt.Point;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int[][] moves = {{0,0},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    static int[][] check = {{-1,1}, {1,-1}, {1,1}, {-1,-1}};
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] temp = br.readLine().split(" ");
        int answer = 0;
        int N = Integer.parseInt(temp[0]);
        int M = Integer.parseInt(temp[1]);

        int[][] map = new int[N][N];

        for(int i = 0; i < N; i++){
            temp = br.readLine().split(" ");
            for(int j = 0; j < N; j++){
                map[i][j] = Integer.parseInt(temp[j]);
            }
        }

        Queue<Point> que = new LinkedList<>();
        que.add(new Point(N-1, 0));
        que.add(new Point(N-1, 1));
        que.add(new Point(N-2, 0));
        que.add(new Point(N-2, 1));

        for(int i = 0; i < M; i++) {
            temp = br.readLine().split(" ");
            int dir = Integer.parseInt(temp[0]);
            int move = Integer.parseInt(temp[1]);
            int size = que.size();
            for(int j = 0; j < size; j++) {
                int curX = que.peek().x;
                int curY = que.poll().y;
                curX = ((moves[dir][0] * move) + curX) % N;
                curY = ((moves[dir][1] * move) + curY) % N;
                if(curX < 0) curX += N;
                if(curY < 0) curY += N;
                que.add(new Point(curX, curY));
                map[curX][curY] += 1;
            }

            while(!que.isEmpty()) {
                int curX = que.peek().x;
                int curY = que.poll().y;
                map[curX][curY] += 100000000;
                for(int k = 0; k < 4; k++) {
                    int checkX = curX + check[k][0];
                    int checkY = curY + check[k][1];
                    if(checkX < 0 || checkX >= N || checkY < 0 || checkY >= N || map[checkX][checkY] <= 0) continue;
                    map[curX][curY] += 1;
                }
            }

            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    if(map[j][k] >= 2 && map[j][k] < 100000000) {
                        que.add(new Point(j, k));
                        map[j][k] -= 2;
                    }
                    if(map[j][k] >= 100000000)
                        map[j][k] -= 100000000;
                }
            }
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                answer += map[i][j];
            }
        }
        System.out.println(answer);
    }
}
