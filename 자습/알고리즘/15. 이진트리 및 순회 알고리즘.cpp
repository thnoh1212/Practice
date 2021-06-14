/*
이진트리는 가장 많이 사용되는 비선형 자료구조
데이터의 탐색 속도 증진을 위해 사용하는 구조.
제대로 트리를 구현하기 위해서는 필수적으로 포인터 사용 
포인터를 사용해야 메모리를 효율적으로 사용할 수 있음
전위 순회, 중위 순회, 후위 순회가 있음
각각 자신-왼쪽-오른쪽,  왼쪽-자신-오른쪽, 왼쪽-오른쪽-자신
의 순서로 탐색 
*/ 

#include <iostream>

using namespace std;

int number = 15;

typedef struct node *treePointer;
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
}node;

void preorder(treePointer ptr){
	if(ptr){
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void inorder(treePointer ptr){
	if(ptr){
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr){
	if(ptr){
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}



int main(void){
	node nodes[number + 1];
	for(int i = 1; i <= number; i++){
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}
	
	for(int i = 1; i <= number; i++){
		if(i % 2 == 0){
			nodes[i/2].leftChild = &nodes[i];
		}
		else{
			nodes[i/2].rightChild = &nodes[i];
		}
	}
	
	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;
	 
	 return 0;
}
