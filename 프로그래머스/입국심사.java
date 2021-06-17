class Solution {
    public long solution(int n, int[] times) {
        long answer = Long.MAX_VALUE;
        long max = Long.MIN_VALUE;
        long min = 0;
        for(int i = 0; i < times.length; i++){
            if(times[i] > max)
                max = times[i];
        }
        max *= n;

        while(max >= min){
            long middle = (max + min) / 2;
            long sum = 0;
            for(int i = 0; i < times.length; i++){
                sum += (Long) middle/times[i];
            }
            if(sum >= n){
                max = middle - 1;
                if(answer > middle){
                    answer = middle;
                }
            }
            else{
                min = middle + 1;
            }
        }
        return answer;
    }
}