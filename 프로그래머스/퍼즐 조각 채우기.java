import java.util.List;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
import java.util.Arrays;
import java.awt.Point;

class Solution {
    static int[][] moves = {
            {0,1},{-1,0},{0,-1},{1,0}
    };

    public int solution(int[][] game_board, int[][] table) {
        int answer = 0;
        int n = game_board.length;
        int m = table.length;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(table[i][j] == 1){
                    // Record Figure
                    List<Point>[] list = new ArrayList[4];
                    for(int k = 0; k < 4; k++){
                        list[k] = new ArrayList<Point>();
                    }
                    Queue<Point> que = new LinkedList<>();
                    que.add(new Point(i, j));
                    while(!que.isEmpty()){
                        int cI = que.peek().x;
                        int cJ = que.poll().y;
                        table[cI][cJ] = 0;
                        for(int k = 0; k < 4; k++){
                            int nI = cI + moves[k][0];
                            int nJ = cJ + moves[k][1];
                            if(nI < 0 || nI >= m || nJ < 0 || nJ >= m || table[nI][nJ] == 0) continue;
                            table[nI][nJ] = 0;
                            list[0].add(new Point(i - nI, j - nJ));
                            list[1].add(new Point((j - nJ), -1 * (i - nI)));
                            list[2].add(new Point(-1 * (i - nI), -1 * (j - nJ)));
                            list[3].add(new Point(-1 * (j - nJ), (i - nI)));
                            que.add(new Point(nI, nJ));
                        }
                    }

                    //Find Figure
                    boolean find = false;
                    Queue<Point> checkQue = new LinkedList<>();
                    for(int a = 0; a < n; a++){
                        for(int b = 0; b < n; b++){
                            if(game_board[a][b] == 0){
                                boolean visited[][] = new boolean[n][n];
                                que = new LinkedList<>();
                                checkQue = new LinkedList<>();
                                que.add(new Point(a, b));
                                checkQue.add(new Point(a, b));
                                List<Point> temp = new ArrayList<>();
                                visited[a][b] = true;
                                while(!que.isEmpty()){
                                    int cI = que.peek().x;
                                    int cJ = que.poll().y;
                                    for(int k = 0; k < 4; k++){
                                        int nI = cI + moves[k][0];
                                        int nJ = cJ + moves[k][1];
                                        if(nI < 0 || nI >= m || nJ < 0 || nJ >= m || visited[nI][nJ] || game_board[nI][nJ] == 1) continue;
                                        temp.add(new Point(a - nI, b - nJ));
                                        que.add(new Point(nI, nJ));
                                        checkQue.add(new Point(nI, nJ));
                                        visited[nI][nJ] = true;
                                    }
                                    if(temp.size() > list[0].size()) break;
                                }

                                if(temp.size() == list[0].size()){
                                    for(int c = 0; c < 4; c++){
                                        find = temp.containsAll(list[c]);
                                        if(find) break;
                                    }
                                }
                            }
                            if(find) break;
                        }
                        if(find) break;
                    }
                    if(find){
                        while(!checkQue.isEmpty()){
                            answer += 1;
                            game_board[checkQue.peek().x][checkQue.poll().y] = 1;
                        }
                    }
                }
            }
        }
        return answer;
    }
}