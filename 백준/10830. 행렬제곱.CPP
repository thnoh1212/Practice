#include <iostream>
#include <stack>

using namespace std;
/*
* 백준 10830, 행렬제곱
* 
* 입력받는 B의 값의 범위가 최대 100000000000(천억) 이므로 단순 계산시 반드시 시간초과 발생
* 이를 방지하기 위해 제곱식 사용. B값을 받을때는 값의 범위때문에 int형이 아닌 long long형 사용
* 
* EX)
* 2^16 = 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2
*	   = (((2^2)^2)^2)^2
* 
* 받은 B의 값을 바탕으로 순서 제작
* B의 값이 2로 나눠지는 수일 경우 stack에 2 저장 및 B /= 2
* B의 값이 2로 나눠지지 않는 경우 stack에 1 저장 및 B -= 1
* 이 과정을 B의 값이 1이 될때까지 반복
* 
* 그 후 stack에 쌓인 값을 기반으로 2인 경우 현재 가지고 있는 배열을 제곱, 1인 경우에는 처음 입력받은 배열의 정보를 현재 배열에 곱셈
* 이를 진행하기 위해 처음 입력받은 배열을 따로 저장해 둘 필요가 있음.
* 
* 값을 계산할 떄 B의값이 큰 경우 long long형으로도 담을 수 없을 정도의 값이 나와 오버플로우가 발생하므로
* 이를 방지하기 위해 행렬의 곱셈이 수행될 때 마다 매번 1000으로 나눈 나머지 값으로 저장
*/


int **mult(int **A, int **B, int N) {

	int **arr = new int *[N];

	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		for (int j = 0; j < N; j++) {
			arr[i][j] = 0;
			for (int k = 0; k < N; k++) {
				arr[i][j] += A[i][k] * B[k][j];
			}
			arr[i][j] %= 1000;
		}
	}
	return arr;
}

int main() {
	int N;
	long long B;
	stack<int> chk;
	cin >> N >> B;
	
	while (B != 1) { // B의 값을 기준으로 곱셈 순서 생성
		if (B % 2 == 0){ // 제곱해야하는 경우
			chk.push(2);
			B /= 2;
		}
		else { // 기존값을 곱해야 하는 경우
			chk.push(1);
			B -= 1;
		}
	}
	int **arr = new int*[N]; // 계산에 사용 될 배열
	int **standard = new int*[N]; // 처음 입력받은 행렬의 정보를 저장해 둘 배열
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
		standard[i] = new int[N];
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			standard[i][j] = arr[i][j];
		}
	}
	while (!chk.empty()) { // 모든 연산을 수행할 때 까지
		int temp = chk.top();
		chk.pop();
		if (temp == 1) // (A)^(N+1)
			arr = mult(arr, standard, N);
		else  // ((A)^N)^2
			arr = mult(arr, arr, N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] %= 1000;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
