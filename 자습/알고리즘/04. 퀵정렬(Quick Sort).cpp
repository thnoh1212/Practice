/*
 �� ����(Quick Sort)
 ��ǥ���� ���� ���� �˰���. ��� �ð����⵵ O(N*logN) 
 �� ������ Ư���� ��(���ذ�, Pivot)�� �������� ���� ���ڿ�
 ū ���ڸ� ���� ��ȯ�� �� �迭�� ������ ������ ���
 Pivot���� ������ ���� �־� �ð� ���⵵ O(N^2)�� ���� �� ����
 �̹� ���ĵǾ��ִ� �迭�� ��� �־� �ð� ���⵵
  
*/

#include <iostream>

using namespace std;

void quickSort(int *data, int start, int end){
	if(start >= end)// ���Ұ� 1���� ��� 
		return;
		
	int pivot = start; // Pivot(����)���� ó�� ������ ����
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){// ������ �� ���� �ݺ� 
		while(data[i] >= data[pivot]){ // Ű ������ ū �� Ž�� 
			i++;
		}
		while(data[j] <= data[pivot] && j > start){// Ű ������ ���� �� Ž�� 
			j--;
		}
		if(i > j){ // ������ ��� Pivot���� ��ü 
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		}
		else{// ū���� ������ ��� Ž���� ��� ���� ��ġ ���� 
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;	
		}
	}
	// Pivot���� �������� �������� �� ���� �迭�� ���� �ٽ� ���� ���� 
	quickSort(data, start, j-1);
	quickSort(data, j+1, end);
} 

int main(){
	 int array[10] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	 
	 quickSort(array, 0, 9); 
	 
	 for(int i = 0; i < 10; i++)
	 	cout << array[i] << endl;
	 
}
