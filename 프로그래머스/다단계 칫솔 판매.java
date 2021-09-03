import java.util.Map;
import java.util.HashMap;
import java.util.LinkedHashMap;

class Solution {
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        int[] answer = new int[enroll.length];
        Map<String, String> map = new HashMap<>();
        Map<String, Integer> answerMap = new LinkedHashMap<>();

        for(int i = 0; i < enroll.length; i++){
            map.put(enroll[i], referral[i]);
            answerMap.put(enroll[i], 0);
        }
        for(int i = 0; i < seller.length; i++){
            String name = seller[i];
            int value = amount[i] * 100;
            while(!name.equals("-")){
                if(!map.get(name).equals("-")){
                    if(value / 10 >= 1){
                        int temp = value / 10;
                        value -= temp;
                        answerMap.put(name, answerMap.get(name) + value);
                        name = map.get(name);
                        value = temp;
                    }
                    else{
                        answerMap.put(name, answerMap.get(name) + value);
                        name = "-";
                    }
                }
                else{
                    int temp = value / 10;
                    value -= temp;
                    answerMap.put(name, answerMap.get(name) + value);
                    name = "-";
                }
            }

        }
        int idx = 0;
        for(String key : answerMap.keySet())
            answer[idx++] = answerMap.get(key);
        return answer;
    }
}