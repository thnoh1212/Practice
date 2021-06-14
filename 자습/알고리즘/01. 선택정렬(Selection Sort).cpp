/*
 선택 정렬(Selection Sort)
 배열 안을 순차적으로 탐색하며 위치가 고정된 수를 제외한
 가장 작은 수를 선택하여 정해진 위치로 보내는 형식의 정렬
 시간복잡도는 O(N^2)로 효율적이지 않음 
*/
#include <iostream>

using namespace std;

int main(){
	int min, index, temp;
	int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(int i = 0; i < 10; i++){
		min = INT_MAX;
		for(int j = i; j < 10; j++){
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	
	for(int i = 0; i < 10; i++)
		cout << array[i] << " ";
	return 0;
} 
