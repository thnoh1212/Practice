/*
 삽입 정렬(Bubble Sort)
 각 숫자를 적절한 위치에 삽입하는 방법.
 다른 정렬법과는 다르게 필요한 경우에만 위치를 바꾸는
 작업을 수행. 하나의 인자값을 기준으로 자신보다 작은 값을
 만나기 전까지 위치를 변경. 
 데이터가 어느정도 정렬 된 상태에서는 효율이 높음 
 상대적으로 작은 시간 소요
*/

#include <iostream> 

using namespace std; 

int main(){
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	for(int i = 0; i < 9; i ++){
		int j = i;
		while(array[j] > array[j+1]){
		 	int temp = array[j];
		 	array[j] = array[j+1];
		 	array[j+1] = temp;
		 	j--;
		}
	}
	for(int i = 0; i < 10; i++)
		cout << array[i] << " ";
	return 0;
}
