/*
 입력받는 수가 굉장히 많아 일반적인 정렬을 사용하면 시간 초과
 계수정렬 사용
 출력초과의 이유 확인 X
*/

#include <iostream>

using namespace std;

int array[10001];	
int number, temp;

int main()
{
	scanf("%d", &number);
	for(int i = 0; i < number; i++){
		scanf("%d", &temp);
		array[temp]++;
	}
	
	for(int i = 0; i < 10001; i++){
		while(array[i] != 0){
			printf("%d\n", i);
			array[i]--;
		}
	}
	
}
