#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    // coredump를 방지하기 위해, answer의 사이즈를 미리 정해둠
    answer.resize(arr1.size());
    for(int i = 0; i < answer.size(); i++)
        answer[i].resize(arr2[0].size());
    //행렬의 곱에 맞게 resize함수 사용하여 크기 지정.
    
    for(int i = 0; i < arr1.size(); i++){
        for(int j = 0; j < arr2[0].size(); j++){
            for(int k = 0; k < arr1[0].size(); k++){
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    return answer;
}
