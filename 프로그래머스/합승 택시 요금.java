import java.util.List;
import java.util.ArrayList;
import java.awt.Point;

class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        int maxValue = 100000000;
        int[][] map = new int[201][201];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++)
                map[i][j] = maxValue;
            map[i][i] = 0;
        }
        for(int i = 0; i < fares.length; i++){
            map[fares[i][0]][fares[i][1]] = fares[i][2];
            map[fares[i][1]][fares[i][0]] = fares[i][2];
        }

        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    map[i][j] = Math.min(map[i][j], (map[i][k] + map[k][j]));
                }
            }
        }

        for(int i = 1; i <= n; i++){
            answer = Math.min(answer, map[a][i] + map[b][i] + map[i][s]);
        }
        return answer;
    }
}