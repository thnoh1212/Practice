import java.util.Arrays;

class Solution {
    public int[] solution(int[] numbers) {
        int[] answer = {};
        int size = 0;
        boolean[] check = new boolean[201];
        for(int i = 0; i < numbers.length-1; i++){
            for(int j = i+1; j < numbers.length; j++){
                if(!check[numbers[i] + numbers[j]]){
                    check[numbers[i] + numbers[j]] = true;
                    size += 1;
                }
            }
        }
        answer = new int[size];
        int idx = 0;
        for(int i = 1; i <= 200; i++){
            if(check[i]) answer[idx++] = i;
        }
        Arrays.sort(answer);
        return answer;
    }
}