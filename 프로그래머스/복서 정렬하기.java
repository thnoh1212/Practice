import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Solution {
    static class info implements Comparable<info>{
        int number;
        int weightCnt;
        int weight;
        double winRate;
        public info(int number, int weight, int weightCnt, double winRate){
            this.number = number;
            this.weight = weight;
            this.weightCnt = weightCnt;
            this.winRate = winRate;
        }
        public int getNumber(){
            return this.number;
        }
        public int getWeight(){
            return this.weight;
        }
        public int getWeightCnt(){
            return this.weightCnt;
        }
        public double getWinRate(){
            return this.winRate;
        }


        @Override
        public int compareTo(info i) {
            if (this.winRate > i.getWinRate()) {
                return -1;
            } else if (this.winRate < i.getWinRate()) {
                return 1;
            }
            else{
                if (this.weightCnt > i.getWeightCnt()) {
                    return -1;
                } else if (this.weightCnt < i.getWeightCnt()) {
                    return 1;
                }
                else{
                    if (this.weight > i.getWeight()) {
                        return -1;
                    } else if (this.weight < i.getWeight()) {
                        return 1;
                    }
                    else{
                        if (this.number > i.getNumber()) {
                            return 1;
                        } else if (this.number < i.getNumber()) {
                            return -1;
                        }
                        else
                            return 0;
                    }
                }
            }
        }


    }
    public int[] solution(int[] weights, String[] head2head) {
        int[] answer;
        List<info> list = new ArrayList<>();
        for(int i = 0; i < head2head.length; i++){
            double temp = 0f;
            double win = 0;
            double lose = 0;
            int cnt = 0;
            for(int j = 0; j < head2head[i].length(); j++){
                if(head2head[i].charAt(j) == 'W'){
                    win += 1;
                    if(weights[i] < weights[j])
                        cnt += 1;
                }
                if(head2head[i].charAt(j) == 'L'){
                    lose += 1;
                }
            }
            if(lose + win != 0)
                temp = win / (win + lose);
            list.add(new info(i+1, weights[i], cnt, temp));
        }
        Collections.sort(list);
        answer = new int[list.size()];
        for(int i = 0; i < list.size(); i++){
            answer[i] = list.get(i).getNumber();
        }
        return answer;
    }
}