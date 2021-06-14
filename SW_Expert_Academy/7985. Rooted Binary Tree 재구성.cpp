#include<iostream>
#include<vector>
#include <cmath>

using namespace std;
vector<int> input;
vector<int> test[10];

void bin_search(int L, int R, int count){
	// 이진트리를 중위순회 한 경우. 홀수개의 배열을 기준으로 정 가운데의 인덱스 값이 root값.
	// 이를 반복해서 체크하며 트리 구성, 
	// 재귀함수를 실행하며 진행될 때 마다 횟수를 체크하여 이를 깊이로 활용
	/*
	   1 2 3 4 5 6 7
	         V
		 4
	   1 2 3  5 6 7
	         V
	         4
             2       6
	   1   3   5    7
	*/
	int mid = (L + R)/2;
	count += 1;
	if(L == R){
		test[count].push_back(input[L]);		
		return;
	}
	else{
		bin_search(L, mid-1, count);
		bin_search(mid+1, R, count);
	}
	test[count].push_back(input[mid]);
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_case;
    int T;
    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case){
	int depth, count = -1;
        cin >> depth;
        int num = pow(2, depth) - 1; // 완전이진트리의 경우 높이 k ==> 정점 2^k -1
        for(int i = 0; i < num; i++){
            int temp;
            cin >> temp;
            input.push_back(temp);
        }
        bin_search(0, input.size()-1, count); // 이진탐색 시작.
        cout << "#" << test_case << " ";
        for(int i = 0; i < depth; i++){
	    for(int j = 0; j < test[i].size(); j++){
		cout << test[i][j] << " ";
	    }
            test[i].clear(); // 함수에 벡터를 전달하지 않고 전역변수로 선언하여 사용하였으므로 출력 후 벡터 초기화 과정 진행.
	    cout << "\n";
	}
       	input.clear();
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
