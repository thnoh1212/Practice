import java.util.*;

class Solution {
    static ArrayList<int[]> list = new ArrayList<int[]>();
    static int idx = 0;
    public int[][] solution(int n) {
        int[][] answer = {};
        hanoi(n, 1, 3, 2);
        answer = list.toArray(answer);
        return answer;
    }

    static void hanoi(int n, int start, int target, int via){
        if(n == 1){
            int[] temp = new int[2];
            temp[0] = start;
            temp[1] = target;
            list.add(temp);
        }
        else{
            hanoi(n-1, start, via, target);
            int[] temp = new int[2];
            temp[0] = start;
            temp[1] = target;
            list.add(temp);
            hanoi(n-1, via, target, start);
        }
    }
}

