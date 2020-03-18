/*
 시간에 굉장히 민감한 문제
 처음에는 2차원 배열 역시 동적할당을 통해 문제를 풀었음
 int **test_check = new int*[person];
 for(int i = 0; i < person; ++i)
    		test_check[i] = new int[quiz]();
 의 형식으로 동적할당을 했지만 하나의 반복문이 추가되어 시간제한에 걸림. 전역변수로 선언함으로써 해결
 
 tuple 형식 사용. pair와 같은 방식으로 작동하며 make_pair 함수를 통해 삽입. 벡터로 선언 가능
 cmp함수를 tuple를 이용하여 만들었는데, 비교할 순서대로 인자를 정렬하고 +인경우 큰 값 우선, -인경우 작은 값 우선으로 정렬이 들어감
*/

#include<iostream>
#include <vector>
#include<tuple>
#include <algorithm>

using namespace std;

bool cmp(const tuple<int, int, int>& a, const tuple<int, int, int>& b)
{
    return make_tuple(get<1>(a), get<2>(a),  -get<0>(a)) > make_tuple(get<1>(b), get<2>(b),  -get<0>(b));
}

int test_check[2000][2000];

int main(int argc, char** argv)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int person, quiz, num;
        vector<tuple<int, int, int> > rank;
        cin >> person >> quiz >> num;
        int *point = new int[quiz]();

        for(int i = 0; i < person; i++)
        {
        	for(int j = 0; j < quiz; j++)
            {
            	cin >> test_check[i][j];
                point[j] += test_check[i][j] ;
            }
        }
        
        for(int i = 0; i < person; i++)
        {
            int sum = 0;
            int number = 0;
          	for(int j = 0; j < quiz; j++)
            {
                if(test_check[i][j] == 1)
                {
                	sum += person - point[j];
                  number += 1;
                }
            }
            rank.push_back(make_tuple(i+1, sum, number)); 
        }
        sort(rank.begin(), rank.end(), cmp);
        for(int i = 0; i < person; i++)
        {
            if(get<0>(rank[i]) == num)
            {
                cout << "#" << test_case << " " << get<1>(rank[i]) << " " <<  i+1 << '\n';
                break;
            }
    	}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/* 
#include <stdio.h>

using namespace std;
 
int mat[2000+1][2000+1];
const int LID = 2000;
char buf[4000];
int N, T, P;
 
int main() {
    int TestCase=1;
    scanf("%d", &TestCase);
    for (int tc=1; tc<=TestCase; tc++) {
        scanf("%d %d %d", &N, &T, &P);
        getchar();
        P--;
        for (int j=0; j<T; j++)
            mat[LID][j] = N;
        for (int i=0; i<N; i++) {
            int l = 0, k;
            gets(buf);
            for (int j=0; j<T; j++) {
                if (buf[j*2] == '1') {
                    mat[LID][j]--;
                    mat[i][l] = j;
                    l++;
                }
            }
            mat[i][LID] = l;
        }
 
        int cnt = mat[P][LID];
        int score = 0;
        for (int j=0; j<cnt; j++) {
            score += mat[LID][mat[P][j]];
        }
 
        int rank = 0;
        for (int i=0; i<N; i++) {
            if (i == P) continue;
            int sum = 0;
            for (int j=0; j<mat[i][LID]; j++)
                sum += mat[LID][mat[i][j]];
             
            if (score > sum)
                continue;
            else if (score < sum)
                rank++;
            else if (cnt < mat[i][LID])
                rank++;
            else if (i < P && cnt == mat[i][LID])
                rank++;
        }
        rank++;
 
        printf("#%d %d %d\n", tc, score, rank);
    }
 
    return 0;
}
*/
