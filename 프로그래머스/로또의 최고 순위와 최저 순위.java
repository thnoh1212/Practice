import java.util.Arrays;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        Arrays.sort(lottos);
        Arrays.sort(win_nums);
        int tempNum = 0;
        int sameNum = 0;
        for(int i = 0; i < 6; i++){
            if(lottos[i] == 0){
                tempNum += 1;
                continue;
            }
            else{
                for(int j = 0; j < 6; j++){
                    if(lottos[i] == win_nums[j]){
                        sameNum += 1;
                        break;
                    }
                }
            }
        }
        answer[0] = 7 - sameNum - tempNum;
        answer[1] = 7 - sameNum;
        if(answer[0] > 5) answer[0] = 6;
        if(answer[1] > 5) answer[1] = 6;

        return answer;
    }
}