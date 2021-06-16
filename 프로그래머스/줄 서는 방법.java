import java.util.ArrayList;

class Solution {
    public int[] solution(int n, long k) {
        int[] answer = {};
        ArrayList<Integer> array = new ArrayList<>();
        answer = new int[n];
        long cur = 1;
        for(int i = 1; i <= n; i++){
            cur *= i;
            array.add(i);
        }
        k--;

        int idx = 0;
        while(n > 0){
            cur /= n;
            answer[idx++] = array.get((int) (k / cur));
            array.remove((int)(k / cur));
            k %= cur;
            n--;
        }
        return answer;
    }
}