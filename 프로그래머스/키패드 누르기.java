class Solution {
    public String solution(int[] numbers, String hand) {
        String answer = "";
        int[][] numberPad = {
                {1, 2 ,3},
                {4, 5, 6},
                {7, 8, 9},
                {10, 0, 11}
        };
        int[] leftHandPos = {3, 0};
        int[] rightHandPos = {3, 2};
        for(int i = 0; i < numbers.length; i++){
            int target = numbers[i];
            int[] targetPos = new int[2];
            boolean find = false;
            for(int j = 0; j < 4; j++){
                for(int k = 0; k < 3; k++){
                    if(numberPad[j][k] == target){
                        targetPos[0] = j;
                        targetPos[1] = k;
                        find = true;
                        break;
                    }
                    if(find) break;
                }
            }
            switch(target){
                case 1:
                case 4:
                case 7:
                    answer += 'L';
                    leftHandPos = targetPos;
                    break;
                case 3:
                case 6:
                case 9:
                    answer += 'R';
                    rightHandPos = targetPos;
                    break;
                default:
                    int rightHandMove = Math.abs(rightHandPos[0] - targetPos[0]) +
                            Math.abs(rightHandPos[1] - targetPos[1]);
                    int leftHandMove = Math.abs(leftHandPos[0] - targetPos[0]) +
                            Math.abs(leftHandPos[1] - targetPos[1]);
                    if(rightHandMove > leftHandMove){
                        answer += 'L';
                        leftHandPos = targetPos;
                    }
                    else if(rightHandMove < leftHandMove){
                        answer += 'R';
                        rightHandPos = targetPos;
                    }
                    else{
                        if(hand.equals("right")){
                            answer += 'R';
                            rightHandPos = targetPos;
                        }
                        else if(hand.equals("left")){
                            answer += 'L';
                            leftHandPos = targetPos;
                        }
                    }
            }



        }
        return answer;
    }
}