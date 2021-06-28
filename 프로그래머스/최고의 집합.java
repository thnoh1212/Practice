class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];
        int temp = s / n;
        int mod = s % n;
        if(temp == 0) {
            int[] res = new int[1];
            res[0] = -1;
            return res;
        }
        int idx = 0;
        for(int i = 0; i < n - mod; i++)
            answer[idx++] = temp;
        for(int i = 0; i < mod; i++)
            answer[idx++] = temp + 1;

        return answer;
    }
}