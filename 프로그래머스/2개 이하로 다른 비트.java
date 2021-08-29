class Solution {
    public long[] solution(long[] numbers) {
        long[] answer = new long[numbers.length];

        for(int i = 0; i < numbers.length; i++){
            if(numbers[i] % 2 == 0){
                answer[i] = numbers[i] + 1;
            }
            else{
                String binaryNum = Long.toBinaryString(numbers[i]);
                if(binaryNum.contains("0")){
                    StringBuffer sb = new StringBuffer(binaryNum);
                    sb = sb.reverse();
                    sb = new StringBuffer(sb.toString().replaceFirst("10", "01"));
                    sb = sb.reverse();
                    answer[i] = Long.parseLong(sb.toString(), 2);
                }
                else{
                    binaryNum = binaryNum.replaceFirst("1", "10");
                    answer[i] = Long.parseLong(binaryNum, 2);
                }
            }
        }
        return answer;
    }
}