/*
 ���� ����(Bubble Sort)
 �� ���ڸ� ������ ��ġ�� �����ϴ� ���.
 �ٸ� ���Ĺ����� �ٸ��� �ʿ��� ��쿡�� ��ġ�� �ٲٴ�
 �۾��� ����. �ϳ��� ���ڰ��� �������� �ڽź��� ���� ����
 ������ ������ ��ġ�� ����. 
 �����Ͱ� ������� ���� �� ���¿����� ȿ���� ���� 
 ��������� ���� �ð� �ҿ�
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
