/*
 algorithm 헤더파일에 포함되어 있는 함수
 퀵정렬을 베이스로 하며 최악의 경우에 대해 특정한
 처리가 되어있어 시간복잡도를 보장해주는 함수 
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
		// 정렬 기준은 '점수가 작은 순서'
		bool operator <(Student &student){
			return this->score < student.score;
		} 
		
};

bool compare(int a, int b){ // 정렬 기준 추가 
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
	
	sort(a, a + 10);	// 특별한 조건 없이 sort함수 사용 
	
	for(int i = 0; i < 10; i++)
		cout << a[i] << '\n';
	
	cout << endl;
	
	sort(a, a+10, compare); // 비교함수 사용 
	
	for(int i = 0; i < 10; i++)
		cout << a[i] << '\n';

	/*********************************************************************/
		
	Student students[] = { // 묶여진 데이터 정렬법 예제. 비교 연산자 오버로딩 필수 
		Student("가 나 다", 90),
		Student("라 마 바", 93),
		Student("사 아 자", 97),
		Student("차 카 타", 87),
		Student("파 하 A", 92)
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
