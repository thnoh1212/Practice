/*
 계수 정렬(Counting Sort)
 범위 조건이 있는 경우에 한해서 굉장히 빠른 알고리즘.
 시간복잡도 O(N)
 단순히 숫자의 크기를 세는 알고리즘
 배열의 인자 값에 큰 영향을 받는 정렬방식이기 때문에 많이 사용되지 않음 
*/

#include <iostream>

using namespace std;

int main(){
	int temp;
	int count[5] = {};
	int array[30] = { 1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
	 				  3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
					  3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
	for(int i = 1; i <= 5; i++)
		count[i] = 0;
		
	for(int i = 0; i < 30; i++){
		count[array[i]- 1]++;
	}
	
	for(int i = 0; i < 5; i++){
		if(count[i] != 0){
			for(int j = 0; j < count[i]; j++){
				cout << i+1 << " ";
			}
		}
	}
}
