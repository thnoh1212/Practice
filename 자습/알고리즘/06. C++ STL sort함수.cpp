/*
 algorithm ������Ͽ� ���ԵǾ� �ִ� �Լ�
 �������� ���̽��� �ϸ� �־��� ��쿡 ���� Ư����
 ó���� �Ǿ��־� �ð����⵵�� �������ִ� �Լ� 
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Student{
	public:
		string name;
		int score;
		Student(string name, int score){
			this->name = name;
			this->score = score;
		}
		// ���� ������ '������ ���� ����'
		bool operator <(Student &student){
			return this->score < student.score;
		} 
		
};

bool compare(int a, int b){ // ���� ���� �߰� 
	return a > b;
}

bool compare2(pair<string, pair<int, int> > a, pair<string, pair<int, int> > b){
	if(a.second.first == b.second.first){
		return a.second.second > b.second.second;
	}
	else
		return a.second.first > b.second.first;
}

int main(){
	int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
	
	sort(a, a + 10);	// Ư���� ���� ���� sort�Լ� ��� 
	
	for(int i = 0; i < 10; i++)
		cout << a[i] << '\n';
	
	cout << endl;
	
	sort(a, a+10, compare); // ���Լ� ��� 
	
	for(int i = 0; i < 10; i++)
		cout << a[i] << '\n';

	/*********************************************************************/
		
	Student students[] = { // ������ ������ ���Ĺ� ����. �� ������ �����ε� �ʼ� 
		Student("�� �� ��", 90),
		Student("�� �� ��", 93),
		Student("�� �� ��", 97),
		Student("�� ī Ÿ", 87),
		Student("�� �� A", 92)
	};

	sort(students, students + 5);
	
	for(int i = 0; i < 5; i++){
		cout << students[i].score << ' ';
	}
	cout << endl;
	/*********************************************************************/
		
	vector<pair<int, string> > v;
	v.push_back(pair<int, string>(50, "abc"));
	v.push_back(pair<int, string>(100, "def"));
	v.push_back(pair<int, string>(80, "ghi"));
	v.push_back(pair<int, string>(75, "jkl"));
	v.push_back(pair<int, string>(0, "mno"));
	
	for(int i = 0; i < v.size(); i++){
		cout << v[i].first << ' ' << v[i].second << endl;
	}
	
	vector<pair<string, pair<int, int> > > v_2;
	v_2.push_back(pair<string, pair<int, int> > ("abc", pair<int, int>(50, 19951212)));
	v_2.push_back(pair<string, pair<int, int> > ("def", pair<int, int>(100, 19921212)));
	v_2.push_back(pair<string, pair<int, int> > ("ghi", pair<int, int>(80, 19931212)));
	v_2.push_back(pair<string, pair<int, int> > ("jkl", pair<int, int>(75, 19991212)));
	v_2.push_back(pair<string, pair<int, int> > ("mno", pair<int, int>(0, 20021212)));

	sort(v_2.begin(), v_2.end(), compare2);
	
	for(int i = 0; i < v.size(); i++){
		cout << v_2[i].first << ' ' << endl;
	}
	
	
} 
