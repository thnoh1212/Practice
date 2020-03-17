/*
 병합정렬(Merge Sort)
 평균시간복잡도 O(N*logN), 퀵 정렬과 마찬가지로 분할정복 알고리즘 사용
 Pivot 값에 따라 편향된 분할이 발생하여 최악의 경우(O(N^2))가 발생할 수 있는
 퀵정렬과는 다르게 항상 절반으로 나누기 때문에 최악의 경우에도
 시간복잡도 O(N*logN)을 보장함 
 우선 배열을 반으로 나눠가며 분할한 후 병합하며 정렬 실시 
*/

#include <stdio.h>

int number = 8;
int sorted[8];

void merge(int *a, int m, int middle, int n){
	int i = m, j = middle + 1, k = m;
	
	while(i <= middle && j <= n){
		if(a[i] <= a[j])
			sorted[k] = a[i++];
		else
			sorted[k] = a[j++];
		k++;
	}
	// 남은 데이터 삽입
	
	if(i > middle){
		for(int t = j; t <= n; t++){
			sorted[k++] = a[t];
		}
	}
	else{
		for(int t = i; t <= n; t++){
			sorted[k++] = a[t];
		}
	}
	
	for(int t = m; t <= n; t++)
		a[t] = sorted[t];
}

void mergeSort(int *a, int m, int n){

	// 크기가 1보다 큰 경우
	if(m < n){
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle+1, n);
		merge(a, m, middle, n);
	}
}

int main(){
	int array[number] = {7, 6, 5, 8, 3, 4, 2, 1};
	mergeSort(array, 0, number - 1);
	for(int i = 0; i < number; i++)
		printf("%d\t", array[i]);
}
