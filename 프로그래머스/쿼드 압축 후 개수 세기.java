class Solution {
    static int[] answer;
    public int[] solution(int[][] arr) {
        answer = new int[2];
        int arrLen = arr.length;
        makeQuadTree(arr, 0, arrLen, 0, arrLen);
        return answer;
    }

    static void makeQuadTree(int[][] arr, int iStart, int iEnd, int jStart, int jEnd){
        int temp = arr[iStart][jStart];
        boolean flag = true;
        for(int i =  iStart; i < iEnd; i++){
            for(int j = jStart; j < jEnd; j++){
                if(arr[i][j] != temp){
                    flag = false;
                    break;
                }
            }
            if(!flag) break;
        }

        if(flag){
            answer[temp] += 1;
            return;
        }
        else{
            int iMiddle = (iStart + iEnd) / 2;
            int jMiddle = (jStart + jEnd) / 2;
            makeQuadTree(arr, iStart, iMiddle, jStart, jMiddle);
            makeQuadTree(arr, iStart, iMiddle, jMiddle, jEnd);
            makeQuadTree(arr, iMiddle, iEnd, jStart, jMiddle);
            makeQuadTree(arr, iMiddle, iEnd, jMiddle, jEnd);
        }
        return;
    }
}