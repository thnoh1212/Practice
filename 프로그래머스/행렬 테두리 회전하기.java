import java.util.*;

class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int temp = 1;
        int[][] table = new int[rows+1][columns+1];
        for(int i = 1; i <= rows; i++){
            for(int j = 1; j <= columns; j++){
                table[i][j] = temp++;
            }
        }

        for(int i = 0; i < queries.length; i++){
            int min = Integer.MAX_VALUE;
            int TI = queries[i][0];
            int TJ = queries[i][1];
            int BI = queries[i][2];
            int BJ = queries[i][3];
            Deque<Integer> deque = new ArrayDeque<>();
            // 삽입과정
            for(int j = TJ; j < BJ; j++){
                deque.addLast(table[TI][j]);
                min = Math.min(min, table[TI][j]);
            }
            for(int j = TI; j < BI; j++){
                deque.addLast(table[j][BJ]);
                min = Math.min(min, table[j][BJ]);
            }
            for(int j = BJ; j > TJ; j--){
                deque.addLast(table[BI][j]);
                min = Math.min(min, table[BI][j]);
            }
            for(int j = BI; j > TI; j--){
                deque.addLast(table[j][TJ]);
                min = Math.min(min, table[j][TJ]);
            }
            deque.addFirst(deque.removeLast());

            for(int j = TJ; j < BJ; j++) table[TI][j] = deque.removeFirst();
            for(int j = TI; j < BI; j++) table[j][BJ] = deque.removeFirst();
            for(int j = BJ; j > TJ; j--) table[BI][j] = deque.removeFirst();
            for(int j = BI; j > TI; j--) table[j][TJ] = deque.removeFirst();

            answer[i] = min;
        }
        return answer;
    }
}