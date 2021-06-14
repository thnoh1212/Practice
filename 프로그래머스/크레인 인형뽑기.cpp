#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> backet;
    
    for(auto a = moves.begin(); a != moves.end(); a++){
        *a -= 1;
        for(int i = 0; i < board.size(); i++){
            if(board[i][*a]){
                if(backet.empty()){
                    backet.push(board[i][*a]);
                }
                else{
                    if(backet.top() == board[i][*a]){
                        backet.pop();
                        answer += 2;    
                    }
                    else{
                        backet.push(board[i][*a]);
                    }
                }
                board[i][*a] = 0;
                break;
            }
        }
    }
    return answer;
}
