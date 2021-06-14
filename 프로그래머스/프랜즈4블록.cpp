#include <string>
#include <vector>
#include <iostream>

using namespace std;

int moves[4][2] = {{1,0},{0,1},{1,1}};

int chk(int m, int n, vector<string> &board){
    int result = 0; 
    bool map[30][30] = {0};
    
     for(int i = 0; i < m; i++){
        for(int j = 0; j < n - 1; j++){
            if(board[i][j] == ' ' || board[i][j] != board[i][j+1]) continue;
            int cnt = 1;
            for(int k = 0; k < 3; k++){
                int chk_i = i + moves[k][0];
                int chk_j = j + moves[k][1];
                if(chk_i >= 0 && chk_i < m && chk_j >= 0 && chk_j < n){
                    if(board[i][j] != board[chk_i][chk_j])
                        break;
                    cnt++;
                }
            }
            if(cnt == 4)
                map[i][j] = map[i+1][j] = map[i][j+1] = map[i+1][j+1] = 1;
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(map[i][j] == 1){
                board[i][j] = ' ';
                result++;
            }
        }
    }
    
    for(int i = m - 2; i >= 0; i--){
        for(int j = 0; j < n; j++){
            if(board[i][j] == ' ') continue;
            int cur_i = i;
            do{
                cur_i++;
            }while(cur_i < m - 1 && board[cur_i][j] == ' ');
            if(cur_i == m - 1 && board[cur_i][j] == ' '){
                board[cur_i][j] = board[i][j];
                board[i][j] = ' ';
            }
            else if(board[cur_i - 1][j] == ' ') {
                board[cur_i - 1][j] = board[i][j];
                board[i][j] = ' ';
            }
            
        }
    }    
    return result;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int temp = 0;
    while(temp = chk(m,n,board)){
        answer += temp;
    }
    return answer;
}
