/*
  플로이드 워샬 알고리즘 사용
  모든 지점에서 최단 경로 사이클을 찾을 수 있음
  중간지점인 k를 이용하여 [i][k] -> [k][j]의 값이 [i][j]보다 작은 경우 [i][j]에 해당값을 저장
*/


#include<iostream>

using namespace std;

int map[400][400] = { 0 };

int floyd(int N){
	int result[N][N];
    int answer = 4000000;
    for(int i = 0; i < N; i++){
    	for(int j = 0; j < N; j++){
        	result[i][j] = map[i][j];
        }
    }
    
    for(int k = 0; k < N; k++){
    	for(int i = 0; i < N; i++){
        	for(int j = 0; j < N; j++){
            	if(result[i][k] + result[k][j] < result[i][j]){
                	result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
    	if(result[i][i] < answer)
            answer = result[i][i];
    }
    return answer;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        
        int N, M, answer = 0;
        cin >> N >> M;
        fill(&map[0][0], &map[N][N], 4000000);
        for(int i = 0; i < M; i++){
        	int x, y, c;
            cin >> x >> y >> c;
            map[x-1][y-1] = c;
        }
        
        answer = floyd(N);
        cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
