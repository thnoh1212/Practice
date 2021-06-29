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
        if(depth == N){// N개 배치 성공 -> 배치방법 찾음. 정답 + 1
            answer += 1;
            return;
        }
        for(int i = 0; i < N; i++){ // depth = y좌표, i = x좌표
            arr[depth] = i;
            if(checkPossible(depth)){ // 해당
                nqueen(depth + 1);
            }
        }
    }

    static boolean checkPossible(int depth){
        for(int i = 0; i < depth; i++){ // 같은 열에 Queen이 배치되어 있는지 확인
            if(arr[depth] == arr[i]){
                return false;
            }

            if(Math.abs(depth - i) == Math.abs(arr[depth] - arr[i])){
                // 대각선에 Queen이 배치되어 있는지 확인
                // x - y 값의 절대값이 같다면 대각선에 위치
                return false;
            }
        }
        return true;
    }
}