class Solution
{
    public int solution(int [][]board)
    {
        int answer = 0;
        for(int i = 1; i < board.length; i++){
            for(int j = 1; j < board[i].length; j++){
                if(board[i][j] > 0){
                    int up = board[i-1][j];
                    int left = board[i][j-1];
                    int upLeft = board[i-1][j-1];
                    int min = Math.min(up, Math.min(left, upLeft));
                    board[i][j] = Math.max(min + 1, board[i][j]);
                    answer = Math.max(answer, min+1);
                }
            }
        }
        if(answer == 0){
            for(int i = 0; i < board.length; i++){
                for(int j = 0; j < board[i].length; j++){
                    if(board[i][j] == 1)
                        return 1;
                }
            }
        }
        return answer * answer;
    }
}