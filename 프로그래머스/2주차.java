import java.awt.Point;

class Solution {
    public String solution(int[][] scores) {
        String answer = "";
        for(int i = 0; i < scores.length; i++){
            int maxScore = Integer.MIN_VALUE;
            int minScore = Integer.MAX_VALUE;
            int minIdx = -1;
            int maxIdx = -1;
            int sum = 0;
            int avg = scores[i].length;
            for(int j = 0; j < scores[i].length; j++){
                if(scores[j][i] > maxScore){
                    maxScore = scores[j][i];
                    maxIdx = j;
                }
                else if(scores[j][i] == maxScore){
                    maxIdx = -1;
                }

                if(scores[j][i] < minScore){
                    minScore = scores[j][i];
                    minIdx = j;
                }
                else if(scores[j][i] == minScore){
                    minIdx = -1;
                }
                sum += scores[j][i];
            }
            if(maxIdx == i){
                sum -= maxScore;
                avg -= 1;
            }
            else if(minIdx == i){
                sum -= minScore;
                avg -= 1;
            }
            avg = sum / avg;

            if(avg >= 90)
                answer += "A";
            else if(avg >= 80)
                answer += "B";
            else if(avg >= 70)
                answer += "C";
            else if(avg >= 50)
                answer += "D";
            else
                answer += "F";
        }
        return answer;
    }
}