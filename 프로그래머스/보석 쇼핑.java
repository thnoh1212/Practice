import java.util.Set;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        int min = Integer.MAX_VALUE;
        int len = Integer.MAX_VALUE;
        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();

        for(String temp : gems){
            set.add(temp);
        }
        int idx = 0;
        int start = 0;
        int limit = gems.length;
        while(idx < limit){
            if(map.containsKey(gems[idx])){
                map.put(gems[idx], map.get(gems[idx]) + 1);
            }
            else{
                map.put(gems[idx], 1);
            }

            if(map.size() == set.size()){
                while(map.size() == set.size()){
                    if(map.get(gems[start]) == 1){
                        map.remove(gems[start]);
                    }
                    else{
                        map.put(gems[start], map.get(gems[start]) - 1);
                    }
                    start++;
                }
                if(len > idx - start){
                    len = idx - start;
                    min = start;
                }
            }
            idx++;
        }
        answer[0] = min;
        answer[1] = min + len + 1;
        return answer;
    }
}