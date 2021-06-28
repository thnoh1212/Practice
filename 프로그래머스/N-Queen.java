class Solution {

    static int[] arr;
    static int answer;
    static int N;
    public int solution(int n) {
        answer = 0;
        arr = new int[n];
        N = n;
        nqueen(0);
        return answer;
    }

    static void nqueen(int depth){
        if(depth == N){
            answer += 1;
            return;
        }
        for(int i = 0; i < N; i++){
            arr[depth] = i;
            if(checkPossible(depth)){
                nqueen(depth + 1);
            }
        }
    }

    static boolean checkPossible(int depth){
        for(int i = 0; i < depth; i++){
            if(arr[depth] == arr[i]){
                return false;
            }

            if(Math.abs(depth - i) == Math.abs(arr[depth] - arr[i])){
                return false;
            }
        }
        return true;
    }
}