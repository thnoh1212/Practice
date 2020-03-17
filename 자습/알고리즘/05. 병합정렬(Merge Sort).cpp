/*
 ��������(Merge Sort)
 ��սð����⵵ O(N*logN), �� ���İ� ���������� �������� �˰��� ���
 Pivot ���� ���� ����� ������ �߻��Ͽ� �־��� ���(O(N^2))�� �߻��� �� �ִ�
 �����İ��� �ٸ��� �׻� �������� ������ ������ �־��� ��쿡��
 �ð����⵵ O(N*logN)�� ������ 
 �켱 �迭�� ������ �������� ������ �� �����ϸ� ���� �ǽ� 
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
	// ���� ������ ����
	
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

	// ũ�Ⱑ 1���� ū ���
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
