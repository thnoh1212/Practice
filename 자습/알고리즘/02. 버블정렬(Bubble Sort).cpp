/*
 버블 정렬(Bubble Sort)
 배열 안을 순차적으로 탐색하며 인접한 인자간의 값을 비교
 하여 더 작은 값의 인자를 앞으로 보내주는 방식의 정렬 
 시간복잡도는 O(N^2)로 효율적이지 않음 
 시간복잡도는 선택 정렬과 같지만 수행 작업이 많아
 더 비효율적. 
*/

#include <iostream> 

using namespace std; 

int main(){
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	
	for(int i = 0;i < 10; i ++){
		for(int j = 0; j < 9 - i;  j++){
			if(array[j] > array[j+1]){
				int temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;	
			}
		}
	}
	for(int i = 0; i < 10; i++)
		cout << array[i] << " ";
	return 0;
}
