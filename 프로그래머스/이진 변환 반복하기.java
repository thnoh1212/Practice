class Solution {
    public int[] solution(String s) {
        int[] answer = new int[2];

        while(!s.equals("1")){
            answer[0] += 1;
            int zeroCnt = 0;
            int oneCnt = 0;
            for(int i = 0; i < s.length(); i++){
                if(s.charAt(i) == '1')
                    oneCnt += 1;
                else
                    zeroCnt += 1;
            }
            answer[1] += zeroCnt;
            s = Integer.toBinaryString(oneCnt);
        }

        return answer;
    }
}