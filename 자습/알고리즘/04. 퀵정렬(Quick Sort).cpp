/*
 퀵 정렬(Quick Sort)
 대표적인 분할 정복 알고리즘. 평균 시간복잡도 O(N*logN) 
 퀵 정렬은 특정한 값(기준값, Pivot)을 기준으로 작은 숫자와
 큰 숫자를 서료 교환한 뒤 배열을 반으로 나누는 방식
 Pivot값의 설정에 따라 최악 시간 복잡도 O(N^2)가 나올 수 있음
 이미 정렬되어있는 배열의 경우 최악 시간 복잡도
  
*/

#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end){
	if(start >= end)// 원소가 1개인 경우 
		return;
		
	int pivot = start; // Pivot(기준)값을 처음 값으로 정함
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){// 엇갈릴 때 까지 반복 
		while(data[i] >= data[pivot]){ // 키 값보다 큰 값 탐색 
			i++;
		}
		while(data[j] <= data[pivot] && j > start){// 키 값보다 작은 값 탐색 
			j--;
		}
		if(i > j){ // 엇갈린 경우 Pivot값과 교체 
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else{// 큰값과 작은값 모두 탐색된 경우 서로 위치 변경 
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;	
		}
	}
	// Pivot값을 기준으로 나뉘어진 두 개의 배열에 대해 다시 정렬 시작 
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
} 

int main(){
	 int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	 
	 quickSort(array, 0, 9); 
	 
	 for(int i = 0; i < 10; i++)
	 	cout << array[i] << endl;
	 
}
