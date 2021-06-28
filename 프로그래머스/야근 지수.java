class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        long[] countSort = new long[50001];
        int maxNum = 0;
        for(int i = 0; i < works.length; i++){
            if(maxNum < works[i])
                maxNum = works[i];
            countSort[works[i]]++;
        }

        for(int i = maxNum; i >= 0; i--){
            if(countSort[i] >= n){
                countSort[i] -= n;
                if(i-1 >= 0)
                    countSort[i-1] += n;
                n = 0;
            }
            else{
                n -= countSort[i];
                if(i - 1 >= 0)
                    countSort[i-1] += countSort[i];
                countSort[i] = 0;
            }
            maxNum = i;
            if(n == 0) break;
        }

        for(int i = 1; i <= maxNum; i++){
            answer += i*i*countSort[i];
        }

        return answer;
    }
}