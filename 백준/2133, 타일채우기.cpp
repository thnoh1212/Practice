#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int answer[31] = {0};
	
	answer[0] = 1;
	answer[2] = 3;
	for(int i = 4; i <= N; i += 2){
		answer[i] = answer[i - 2] * 3;
		for(int j = i - 4; j >= 0; j -= 2){
			answer[i] += answer[j] * 2;
		}
	}
	cout << answer[N];	
}
